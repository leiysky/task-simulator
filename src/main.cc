#include <compute.h>
#include <io.h>
#include <pipeline.h>

using namespace perf;

int main() {
    std::shared_ptr<ThreadPool> thread_pool = std::make_shared<ThreadPool>(1);

    std::vector<std::thread> threads;
    for (size_t i = 0; i < 10; i++) {
        threads.emplace_back([i, thread_pool]() {
            Pipeline pipeline(
                {{TaskPtr(new TaskComputeHash(
                      std::chrono::milliseconds(10000 - i * 1000))),
                  Pipeline::TaskMode::Sync},
                 {TaskPtr(new TaskWriteFile(
                      std::chrono::milliseconds(10000 - i * 1000))),
                  Pipeline::TaskMode::Pooling}},
                thread_pool);
            for (;;) pipeline.Run();
        });
    }
    for (auto& t : threads) {
        t.join();
    }
    return 0;
}
