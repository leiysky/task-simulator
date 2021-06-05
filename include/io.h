#pragma once

#include <common.h>
#include <task.h>

namespace perf {

class IOTask : public Task {
  private:
    void RunImpl() override;
};

}  // namespace perf