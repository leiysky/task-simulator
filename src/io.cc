#include <io.h>

namespace {

class IOTask {
 public:
  virtual void Run(size_t bytes_read, size_t bytes_write);
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

}