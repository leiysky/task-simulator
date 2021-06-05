#pragma once

#include <bits/stdc++.h>

namespace {

class IOTask {
 public:
  IOTask(size_t _bytes_read, size_t _bytes_write);

 private:
};

class SyncReader {
 public:
  virtual size_t Read(char *buff, size_t n) = 0;
};

class SyncWriter {
 public:
  virtual void Write(char *buff, size_t n) = 0;
};

class AsyncReader {
 public:
  virtual void ReadAsync(char *buff, size_t n,
                         std::function<void(size_t)> callback) = 0;
};

class AsyncWriter {
 public:
  virtual void WriteAsync(char *buff, size_t n,
                          std::function<void()> callback) = 0;
};

}  // namespace