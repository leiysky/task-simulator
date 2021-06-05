#include <pipeline.h>

namespace perf {

void Pipeline::Run() {
    for (auto& [task, mode] : tasks) {
        switch (mode) {
            case TaskMode::Sync: {
                task.Run();
                break;
            }

            case TaskMode::Async: {
                auto t = task.RunInNewThread();
                t.join();
                break;
            }

            case TaskMode::Pooling: {
                task.RunInThreadPool(*thread_pool);
                break;
            }
        }
    }
}

}  // namespace perf