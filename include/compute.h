#pragma once

#include <common.h>
#include <task.h>

namespace perf {

class TaskComputeHash : public Task {
  public:
    explicit TaskComputeHash(std::chrono::milliseconds _duration)
        : Task(_duration) {}

  private:
    void RunImpl() override;
};

}  // namespace perf