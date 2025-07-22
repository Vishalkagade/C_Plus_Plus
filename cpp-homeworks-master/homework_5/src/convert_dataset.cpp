#include "convert_dataset.hpp"

#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

#include "opencv2/xfeatures2d.hpp"
#include "serialize.hpp"

namespace fs = std::filesystem;
using cv::xfeatures2d::SiftDescriptorExtractor;
using cv::xfeatures2d::SiftFeatureDetector;

namespace ipb::serialization::sifts {
void ConvertDataset(const std::filesystem::path& img_path) {
    if (!fs::exists(img_path.parent_path().parent_path() / "bin")) {
        std::filesystem::create_directories(
                img_path.parent_path().parent_path() / "bin");
    }
    for (const auto& p : fs::directory_iterator(img_path.parent_path())) {
        std::cout << p.path().filename().extension() << std::endl;
        std::filesystem::path save_path =
                img_path.parent_path().parent_path() / "bin";

        if (p.path().filename().extension() != ".png") {
            std::cerr << "ERROR only .png files accepted" << std::endl;
            continue;
        }

        const cv::Mat input_img = cv::imread(p.path(), cv::IMREAD_UNCHANGED);
        auto detector = SiftFeatureDetector::create();
        std::vector<cv::KeyPoint> keypoints;
        detector->detect(input_img, keypoints);

        cv::Mat descriptors;
        auto extractor = SiftDescriptorExtractor::create();
        extractor->compute(input_img, keypoints, descriptors);

        save_path /= p.path().filename();
        save_path.replace_extension(".bin");
        std::cout << save_path << std::endl;
        ipb::serialization::Serialize(descriptors, save_path);
    }
}
std::vector<cv::Mat> LoadDataset(const std::filesystem::path& bin_path) {
    std::vector<cv::Mat> vec_out;
    for (const auto& p : fs::directory_iterator(bin_path.parent_path())) {
        if (p.path().filename().extension() != ".bin") {
            std::cerr << "ERROR only .bin files accepted" << std::endl;
            continue;
        }
        std::cout << p.path() << std::endl;
        vec_out.emplace_back(ipb::serialization::Deserialize(p.path()));
    }

    return vec_out;
}
}  // namespace ipb::serialization::sifts