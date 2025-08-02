#if !defined(CIRCULAR_BUFFER_H)
#define CIRCULAR_BUFFER_H
#include <stdexcept>
#include <vector>

namespace circular_buffer {
    template <typename T>
    class circular_buffer {
    public:
        explicit circular_buffer(size_t size) : buffer(size), read_pos(0), write_pos(0), count(0) {}

        T read() {
            if (count == 0) {
                throw std::domain_error("Buffer is empty.");
            }
            T value = buffer[read_pos];
            read_pos = (read_pos + 1) % buffer.size();
            --count;
            return value;
        }

        void write(T value) {
            if (count >= buffer.size()) {
                throw std::domain_error("Buffer is full.");
            }
            buffer[write_pos] = value;
            write_pos = (write_pos + 1) % buffer.size();
            ++count;
        }

        void overwrite(T value) {
            if (count < buffer.size()) {
                write(value);
                return;
            }
            buffer[read_pos] = value;
            read_pos = (read_pos + 1) % buffer.size();
        }

        void clear() {
            read_pos = 0;
            write_pos = 0;
            count = 0;
        }

    private:
        std::vector<T> buffer;
        size_t read_pos;
        size_t write_pos;
        size_t count;
    };
}  // namespace circular_buffer

#endif // CIRCULAR_BUFFER_H