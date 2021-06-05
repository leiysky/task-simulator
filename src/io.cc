#include <io.h>

#include <fstream>

namespace perf {

void TaskSleep::RunImpl() {
    std::this_thread::sleep_for(
        std::chrono::duration_cast<std::chrono::nanoseconds>(duration));
}

void TaskWriteFile::RunImpl() {
    auto start_time = std::chrono::steady_clock::now();

    static constexpr auto size = 100 * (1 << 20);

    for (;;) {
        char* buffer = new char[size];
        // for (size_t i = 0; i < size; i++) {
        //     buffer[i] = i % 255;
        // }
        std::ofstream file("tmp");
        file.write(buffer, size);
        delete[] buffer;

        if (auto now = std::chrono::steady_clock::now();
            std::chrono::duration_cast<std::chrono::milliseconds>(
                now - start_time) >= duration) {
            return;
        }
    }
}

}  // namespace perf