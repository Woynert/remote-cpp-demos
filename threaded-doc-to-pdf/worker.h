#ifndef WORKER_H
#define WORKER_H

#include <mutex>
#include <string>
#include <unordered_set>

namespace concurrency {
extern std::mutex mtx;

void worker_item_convertor (
	int worker_id, bool url_or_doc, std::unordered_set<std::string>* urls);

}; // namespace concurrency

#endif // !WORKER_H
