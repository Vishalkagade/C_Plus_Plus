#include <opencv2/core/mat.hpp>
#include <vector>

#include "BowDictionary.hpp"
#include "histograms.hpp"

cv::Mat Get5Kmeans() {
    // init some parameters
    const int rows_num = 1;
    const int cols_num = 10;
    cv::Mat data;

    for (int i = 0; i < 100; i += 20) {
        cv::Mat_<float> vec(rows_num, cols_num, i);
        data.push_back(vec);
    }

    return data;
}

cv::Mat GetAllFeatures() {
    // init some parameters
    const int rows_num = 1;
    const int cols_num = 10;
    cv::Mat data;

    for (int i = 0; i < 100; i += 20) {
        for (size_t j = 0; j < 5; j++) {
            data.push_back(cv::Mat_<float>(rows_num, cols_num, i));
        }
    }

    return data;
}

int main() {
    auto& dictionary = ipb::BowDictionary::GetInstance();
    std::vector<int> gt_histogram_data{5, 5, 5, 5, 5};

    dictionary.set_vocabulary(Get5Kmeans());
    auto histogram = ipb::Histogram(GetAllFeatures(), dictionary);

    std::string filename("/tmp/test_histogram.csv");
    ipb::Histogram csv_histogram;
    histogram.WriteToCSV(filename);
    csv_histogram = ipb::Histogram::ReadFromCSV(filename);
}