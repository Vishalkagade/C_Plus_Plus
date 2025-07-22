#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main() {
    Mat image1 = imread("instance1_lidar.png", IMREAD_GRAYSCALE);
    std::cout << "Image 1: " << image1.size() << std::endl;

    Mat image2 = imread("instance1_lidar.png", IMREAD_COLOR);
    std::cout << "Image 2: " << image2.size() << std::endl;
    if (image2.empty()) {
        std::cerr << "Error loading images!" << std::endl;
        return -1;
    }

    return 0;
}