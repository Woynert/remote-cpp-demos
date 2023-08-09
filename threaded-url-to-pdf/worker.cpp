#include <iostream>
#include <worker.h>
#include <pdf.h>

std::mutex concurrency::mtx;

void concurrency::worker_convertor (
	int worker_id,
	std::unordered_set<std::string>* urls
) {
	while (urls->size())
	{
		// extract an element

		concurrency::mtx.lock();

		if (!urls->size()) {
			concurrency::mtx.unlock();
			break;
		}

		std::string url = *(urls->begin());
		urls->erase(url);
		concurrency::mtx.unlock();

		// process

		int exit = pdf::url_to_pdf (url);
		std::cout << "worker " << worker_id << ", exit " << exit << ", url " << url << std::endl;
	}
}
