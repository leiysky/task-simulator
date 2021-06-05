#pragma once

#include <bits/stdc++.h>

namespace perf {

class ComputeTask {
 public:
  virtual void Run(const std::chrono::milliseconds &time) = 0;
};

}  // namespace perf