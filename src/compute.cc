#include <compute.h>

namespace perf {

void ComputeTaskHash::RunImpl() {
    auto start_time = std::chrono::steady_clock::now();

    for (;;) {
        int64_t tmp;
        for (size_t i = 0; i < 100'000'000; i++) {
            tmp *= (i << 2345 >> 1234) & (i / 4567 + i);
        }

        if (auto now = std::chrono::steady_clock::now();
            std::chrono::duration_cast<std::chrono::milliseconds>(
                now - start_time) >= duration) {
            return;
        }
    }
}

}  // namespace perf