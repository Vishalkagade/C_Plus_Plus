#include "strategy.hpp"

#include <fstream>
#include <string>

#include "png++/png.hpp"

namespace igg {

bool PpmIoStrategy::ReadFromDisk(const std::string& filename) {
    std::ifstream in(filename, std::ios_base::in);
    if (!in) {
        return false;
    }
    int red = 0;
    int blue = 0;
    int green = 0;
    std::string type;

    in >> type >> rows >> cols >> max_value;

    data.resize(rows * cols);

    for (int s = 0; s < rows * cols; s++) {
        in >> red >> green >> blue;
        png::rgb_pixel pixel;
        pixel.red = red;
        pixel.green = green;
        pixel.blue = blue;
        data[s] = pixel;
    }
    // std::cout << std::endl;

    return true;
}

void PpmIoStrategy::WriteToDisk(const std::string& filename) const {
    std::ofstream out(filename);
    out << "P3" << std::endl
        << rows << " " << cols << std::endl
        << max_value << std::endl;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            png::rgb_pixel pixel{data[r * cols + c]};
            out << pixel.red << " " << pixel.green << " " << pixel.blue << " ";
        }
        out << std::endl;
    }
}
bool PngIoStrategy::ReadFromDisk(const std::string& filename) {
    png::image<png::rgb_pixel> image(
            filename, png::require_color_space<png::rgb_pixel>());
    rows = image.get_height();
    cols = image.get_width();
    data.resize(rows * cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[cols * i + j] = image.get_pixel(i, j);
        }
    }

    return true;
}

void PngIoStrategy::WriteToDisk(const std::string& filename) const {
    png::image<png::rgb_pixel> image(rows, cols);

    for (png::uint_32 y = 0; y < image.get_height(); ++y) {
        for (png::uint_32 x = 0; x < image.get_width(); ++x) {
            image[y][x] = data[cols * y + x];
            // non-checking equivalent of image.set_pixel(x, y, ...);
        }
    }
    image.write(filename);
}
}  // namespace igg