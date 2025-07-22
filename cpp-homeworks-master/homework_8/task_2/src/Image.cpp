#include "Image.hpp"

#include <algorithm>
#include <iostream>
#include <png++/png.hpp>
#include <vector>

// #include "io_tools.hpp"

namespace igg {

int Image::rows() const { return rows_; }
int Image::cols() const { return cols_; }

int IndexVal(int i, int j, int n) { return n * i + j; }

png::rgb_pixel Image::at(int rows, int cols) const {
    int index = IndexVal(rows, cols, cols_);
    return data_[index];
}
png::rgb_pixel &Image::at(int rows, int cols) {
    int index = IndexVal(rows, cols, cols_);
    return data_[index];
}
void Image::SetIoStrategy(std::shared_ptr<IoStrategy> strategy_ptr) {
    shared_ptr = std::move(strategy_ptr);
}
bool Image::ReadFromDisk(const std::string &filename) {
    shared_ptr->ReadFromDisk(filename);
    rows_ = shared_ptr->rows;
    cols_ = shared_ptr->cols;
    data_ = shared_ptr->data;
    return true;
}
void Image::WriteToDisk(const std::string &filename) {
    shared_ptr->rows = rows_;
    shared_ptr->cols = cols_;
    shared_ptr->data = data_;
    shared_ptr->WriteToDisk(filename);
}

void Image::DownScale(int scale) {
    int rows_d = rows_ / scale;
    int cols_d = cols_ / scale;

    std::vector<png::rgb_pixel> data_d;

    for (int i = 0; i < rows_; i += scale) {
        for (int j = 0; j < cols_; j += scale) {
            data_d.emplace_back(this->at(i, j));
        }
    }

    data_ = std::move(data_d);
    rows_ = rows_d;
    cols_ = cols_d;
}

void Image::UpScale(int scale) {
    int rows_u = rows_ * scale;
    int cols_u = cols_ * scale;

    std::vector<png::rgb_pixel> data_u;

    for (int i = 0; i < rows_u; i++) {
        for (int j = 0; j < cols_u; j++) {
            int i_c = i / scale;
            int j_c = j / scale;
            data_u.emplace_back(this->at(i_c, j_c));
        }
    }

    data_ = std::move(data_u);
    rows_ = rows_u;
    cols_ = cols_u;
}
}  // namespace igg