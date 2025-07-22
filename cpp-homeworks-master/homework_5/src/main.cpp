#include <filesystem>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

#include "convert_dataset.hpp"
#include "serialize.hpp"

int main() {
    // auto image = cv::imread("../data/lenna.png", cv::IMREAD_GRAYSCALE);
    // const std::string filename = "xyz.bin";
    // ipb::serialization::Serialize(image, filename);
    // auto img_d = ipb::serialization::Deserialize(filename);

    // cv::namedWindow("Window Name", cv::WINDOW_AUTOSIZE);
    // cv::imshow("Window Name", img_d);

    // cv::waitKey(0);

    std::filesystem::path img_path =
            "/ipb245/home_domuser/s7dhdesa/tmp/cpp-homeworks/homework_5/data/"
            "freiburg/images/";
    std::filesystem::path bin_path =
            "/ipb245/home_domuser/s7dhdesa/tmp/cpp-homeworks/homework_5/data/"
            "freiburg/bin/";

    ipb::serialization::sifts::ConvertDataset(img_path);
    auto out = ipb::serialization::sifts::LoadDataset(bin_path);

    cv::namedWindow("Window Name", cv::WINDOW_AUTOSIZE);
    cv::imshow("Window Name", out[0]);

    cv::waitKey(0);

    return 0;
}