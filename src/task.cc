#include <task.h>

namespace perf {

void Task::RunInThreadPool(ThreadPool& pool) { pool.Enqueue(Run, this); }

std::thread Task::RunInNewThread() { return std::thread(Run, this); }

void Task::Run() { RunImpl(); }

}  // namespace perf