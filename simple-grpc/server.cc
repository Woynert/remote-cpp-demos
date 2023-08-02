#include "music_storage.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <stdio.h>
#include <string>

#include "state.h"
#include "types.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

class MusicStorageServiceImpl final : public MusicStorage::Service
{

	Status GetList (
		ServerContext* context, const GetListRequest* request,
		GetListReply* reply) override
	{
		MusicItem* music;

		// recopile all music items

		for (auto item : State::music_vector) {

			printf (
				"%s - %s (%d)\n", item.title.c_str (), item.autor.c_str (),
				item.duration);

			music = reply->add_items ();
			music->set_title (item.title);
			music->set_autor (item.autor);
			music->set_duration (item.duration);
		}

		printf ("Sending music items...");

		return Status::OK;
	}
};

void Run ()
{
	std::string address ("0.0.0.0:5000");
	MusicStorageServiceImpl service;

	ServerBuilder builder;

	builder.AddListeningPort (address, grpc::InsecureServerCredentials ());
	builder.RegisterService (&service);

	std::unique_ptr<Server> server (builder.BuildAndStart ());
	std::cout << "Server listening on port: " << address << std::endl;

	server->Wait ();
}

int main (int argc, char** argv)
{
	// sample music

	std::vector<Music>* music_vector = &State::music_vector;
	Music* music = nullptr;

	music = new Music ();
	music->title = "Avena";
	music->autor = "Ataquemos";
	music->duration = 420;
	music_vector->push_back (*music);

	music = new Music ();
	music->title = "Flamingo";
	music->autor = "Kero Kero Bonito";
	music->duration = 312;
	music_vector->push_back (*music);

	music = new Music ();
	music->title = "Cheeseburger family";
	music->autor = "Jack Stauber";
	music->duration = 345;
	music_vector->push_back (*music);

	// run server

	Run ();
	return 0;
}
