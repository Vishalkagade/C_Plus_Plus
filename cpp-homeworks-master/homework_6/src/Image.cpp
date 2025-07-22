#include "Image.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

#include "io_tools.hpp"

namespace igg {

int Image::rows() const { return rows_; }
int Image::cols() const { return cols_; }

uint8_t Image::at(int rows, int cols) const {
    int single_idx = cols_ * rows + cols;

    return data_.at(single_idx);
}
uint8_t &Image::at(int rows, int cols) {
    int single_idx = cols_ * rows + cols;
    return data_.at(single_idx);
}

bool Image::FillFromPgm(const std::string &file_name) {
    igg::io_tools::ImageData data;

    data = igg::io_tools::ReadFromPgm(file_name);
    if ((data.rows == 0) && (data.cols == 0)) {
        return false;
    }

    rows_ = data.rows;
    cols_ = data.cols;
    data_ = std::move(data.data);
    return true;
}

void Image::WriteToPgm(const std::string &file_name) const {
    igg::io_tools::ImageData writedata;
    writedata.rows = rows_;
    writedata.cols = cols_;
    auto result = std::max_element(data_.begin(), data_.end());
    writedata.max_val = std::distance(data_.begin(), result);
    writedata.data = data_;

    std::cout << (writedata.max_val) << std::endl;

    bool written = igg::io_tools::WriteToPgm(writedata, file_name);
    if (written) {
        std::cout << "Written Data" << std::endl;
    } else {
        std::cout << "Data not written" << std::endl;
    }
}

std::vector<float> Image::ComputeHistogram(int bins) const {
    std::vector<float> hist(bins, 0.0);
    auto total_pixels = float(rows_ * cols_);

    for (int i = 0; i < bins; i++) {
        int count = std::count_if(data_.begin(), data_.end(), [&](int c) {
            return ((c >= (255.0 / bins) * i) &&
                    (c <= (255.0 / bins) * (i + 1)))
                           ? 1
                           : 0;
        });
        hist[i] = float(count) / total_pixels;
    }

    return hist;
}

void Image::DownScale(int scale) {
    int rows_d = rows_ / scale;
    int cols_d = cols_ / scale;

    std::vector<uint8_t> data_d;

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

    std::vector<uint8_t> data_u;

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