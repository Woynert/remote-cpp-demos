#include <iostream>
#include <pdf.h>
#include <worker.h>

std::mutex concurrency::mtx;

void concurrency::worker_item_convertor (
	int worker_id, bool url_or_doc, std::unordered_set<std::string>* items)
{
	concurrency::mtx.lock ();

	while (items->size ()) {
		// extract an element

		std::string item = *(items->begin ());
		items->erase (item);
		concurrency::mtx.unlock ();

		// process

		int exit;
		if (url_or_doc)
			exit = pdf::url_to_pdf (item);
		else
			exit = pdf::doc_to_pdf (item);

		std::cout << "worker " << worker_id << ", exit " << exit << ", item "
				  << item << std::endl;

		// if failed reverse operation

		if (exit) {
			concurrency::mtx.lock ();
			items->insert (item);
			concurrency::mtx.unlock ();
		}
	}

	concurrency::mtx.unlock ();
}
