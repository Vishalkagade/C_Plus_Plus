#include "serialize.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

void ipb::serialization::Serialize(const cv::Mat& m,
                                   const std::string& filename) {
    std::ofstream file(filename, std::ios_base::out | std::ios_base::binary);
    int rows = m.rows;
    int cols = m.cols;
    int type = m.type();

    file.write(reinterpret_cast<char*>(&rows), sizeof(rows));
    file.write(reinterpret_cast<char*>(&cols), sizeof(cols));
    file.write(reinterpret_cast<char*>(&type), sizeof(type));
    if (type == 0) {
        file.write(reinterpret_cast<char*>(m.data),
                   (rows * cols) * sizeof(unsigned char));
    } else {
        file.write(reinterpret_cast<char*>(m.data),
                   (rows * cols) * sizeof(float));
    }
}

cv::Mat ipb::serialization::Deserialize(const std::string& filename) {
    int rows = 0;
    int cols = 0;
    int type = 0;
    std::ifstream in(filename, std::ios_base::in | std::ios_base::binary);
    in.read(reinterpret_cast<char*>(&rows), sizeof(rows));
    in.read(reinterpret_cast<char*>(&cols), sizeof(cols));
    in.read(reinterpret_cast<char*>(&type), sizeof(type));
    cv::Mat mat = cv::Mat::zeros(rows, cols, type);
    if (type == 0) {
        in.read(reinterpret_cast<char*>(mat.data),
                (rows * cols) * sizeof(unsigned char));

    } else {
        in.read(reinterpret_cast<char*>(mat.data),
                (rows * cols) * sizeof(float));
    }
    return mat;
}