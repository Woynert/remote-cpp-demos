#include "music_storage.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <stdio.h>
#include <string>

#include "types.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

class MusicStorageClient
{
  public:
	MusicStorageClient (std::shared_ptr<Channel> channel)
		: stub_ (MusicStorage::NewStub (channel))
	{
	}

	void GetList ()
	{
		GetListRequest request;
		GetListReply reply;
		ClientContext context;
		Status status = stub_->GetList (&context, request, &reply);

		if (status.ok ()) {

			// retrieve item list

			for (int i = 0; i < reply.items_size (); i++) {
				MusicItem item = reply.items (i);

				printf (
					"%s - %s (%d)\n", item.title ().c_str (),
					item.autor ().c_str (), item.duration ());
			}

			return;
		} else {
			std::cout << status.error_code () << ": " << status.error_message ()
					  << std::endl;
			return;
		}
	}

  private:
	std::unique_ptr<MusicStorage::Stub> stub_;
};

void Run ()
{
	// connect

	std::string address ("0.0.0.0:5000");
	MusicStorageClient client (
		grpc::CreateChannel (address, grpc::InsecureChannelCredentials ()));

	// get list

	client.GetList ();
}

int main (int argc, char* argv[])
{
	Run ();
	return 0;
}
