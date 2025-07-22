#include <memory>
#include <png++/png.hpp>
#include <string>
#include <vector>

#include "strategy.hpp"

namespace igg {

class Image {
public:
    Image() = default;
    Image(int rows, int cols) : rows_{rows}, cols_{cols} {
        data_.resize(rows * cols);
    }
    [[nodiscard]] int rows() const;
    [[nodiscard]] int cols() const;
    [[nodiscard]] png::rgb_pixel& at(int rows, int cols);
    [[nodiscard]] png::rgb_pixel at(int rows, int cols) const;
    bool ReadFromDisk(const std::string& filename);
    void WriteToDisk(const std::string& filename);

    void SetIoStrategy(std::shared_ptr<IoStrategy> strategy_ptr);
    void DownScale(int scale);
    void UpScale(int scale);

private:
    int rows_ = 0;
    int cols_ = 0;
    std::vector<png::rgb_pixel> data_;
    std::shared_ptr<IoStrategy> shared_ptr = nullptr;
};

}  // namespace igg