#include <string>
#include <vector>
namespace igg {

class Image {
public:
    Image() = default;
    Image(int rows, int cols) : rows_{rows}, cols_{cols} {
        data_.resize(rows * cols);
    }
    int rows() const;
    int cols() const;
    uint8_t& at(int rows, int cols);
    uint8_t at(int rows, int cols) const;
    bool FillFromPgm(const std::string& file_name);
    void WriteToPgm(const std::string& file_name) const;
    std::vector<float> ComputeHistogram(int bins) const;
    void DownScale(int scale);
    void UpScale(int scale);

private:
    int rows_ = 0;
    int cols_ = 0;
    std::vector<uint8_t> data_;
};

}  // namespace igg