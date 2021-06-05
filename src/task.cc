#include <task.h>

namespace perf {

void Task::Run() { RunImpl(); }

void Task::RunInThreadPool(ThreadPool& pool) {
    auto res = pool.Enqueue(&Task::Run, this);
    res.wait();
}

std::thread Task::RunInNewThread() { return std::thread(&Task::Run, this); }

}  // namespace perf