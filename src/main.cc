#include <compute.h>
#include <pipeline.h>

using namespace perf;

int main() {
    std::shared_ptr<ThreadPool> thread_pool = std::make_shared<ThreadPool>(1);
    Pipeline pipeline({{ComputeTaskHash(std::chrono::milliseconds(10000)),
                        Pipeline::TaskMode::Sync}},
                      thread_pool);
    return 0;
}
