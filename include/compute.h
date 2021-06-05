#pragma once

#include <common.h>
#include <task.h>

namespace perf {

class ComputeTask : public Task {
  private:
    void RunImpl() override;
};

class ComputeTaskHash : public ComputeTask {
  private:
    void RunImpl() override;
};

}  // namespace perf