#pragma once

#include <common.h>
#include <task.h>
#include <thread_pool.h>

namespace perf {

class Pipeline {
  public:
    enum TaskMode { Sync, Async, Pooling };

    Pipeline(std::vector<std::pair<Task, Pipeline::TaskMode>> _tasks,
             std::shared_ptr<ThreadPool> _thread_pool)
        : tasks(_tasks), thread_pool(_thread_pool) {}

    void Run();

  private:
    std::vector<std::pair<Task, TaskMode>> tasks;
    std::shared_ptr<ThreadPool> thread_pool;
};

}  // namespace perf