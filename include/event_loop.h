#pragma once

#include <bits/stdc++.h>
#include <thread_pool.h>
#include <unistd.h>

namespace perf {

class EventLoop {
 public:
  EventLoop(ThreadPool&& _thread_pool);
  EventLoop(const EventLoop&) = delete;

  void Loop();

  void Register(int fd, );

 private:
};

}  // namespace perf