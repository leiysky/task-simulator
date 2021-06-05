#pragma once

#include <common.h>
#include <thread_pool.h>

namespace perf {

// Task descriptor, can be copied and reused.
class Task {
  public:
    explicit Task(std::chrono::milliseconds _duration) : duration(_duration) {}

    virtual ~Task() {}

    virtual void RunInThreadPool(ThreadPool& pool);

    virtual std::thread RunInNewThread();

    virtual void Run();

  protected:
    std::chrono::milliseconds duration;

  private:
    virtual void RunImpl() = 0;
};

using TaskPtr = std::shared_ptr<Task>;

}  // namespace perf