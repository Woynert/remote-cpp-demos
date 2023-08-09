#ifndef WORKER_H
#define WORKER_H

#include <mutex>
#include <string>
#include <unordered_set>

namespace concurrency {
	extern std::mutex mtx;

	void worker_convertor (
		int worker_id,
		std::unordered_set<std::string>* urls
	);
};

#endif // !WORKER_H
