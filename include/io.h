#pragma once

#include <common.h>
#include <task.h>

namespace perf {

class TaskSleep : public Task {
  public:
    explicit TaskSleep(std::chrono::milliseconds _duration) : Task(_duration) {}

  private:
    void RunImpl() override;
};

class TaskWriteFile : public Task {
  public:
    explicit TaskWriteFile(std::chrono::milliseconds _duration) : Task(_duration) {}

  private:
    void RunImpl() override;
};

}  // namespace perf