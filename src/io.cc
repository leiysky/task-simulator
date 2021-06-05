#include <io.h>

namespace perf {
void IOTask::RunImpl() {
    std::this_thread::sleep_for(
        std::chrono::duration_cast<std::chrono::nanoseconds>(duration));
}
}  // namespace perf