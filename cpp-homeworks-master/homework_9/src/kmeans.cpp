#include "kmeans.hpp"

#include <array>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>

namespace ipb {
cv::Mat kMeans(const std::vector<cv::Mat>& descriptors, int k, int max_iter) {
    cv::Mat_<float> out;
    cv::Mat labels;

    cv::Mat features;
    cv::vconcat(descriptors, features);
    cv::kmeans(features, k, labels,
               cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT,
                                max_iter, 0.001),
               1, cv::KmeansFlags::KMEANS_PP_CENTERS, out);

    return std::move(out);
}
}  // namespace ipb