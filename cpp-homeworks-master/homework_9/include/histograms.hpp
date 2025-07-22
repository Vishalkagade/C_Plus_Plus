#pragma once

#include <iterator>
#include <opencv2/core/mat.hpp>
#include <string>
#include <vector>

#include "BowDictionary.hpp"
namespace ipb {

class Histogram {
public:
    Histogram() = default;
    explicit Histogram(const std::vector<int>& data);
    Histogram(const cv::Mat& descriptors, const ipb::BowDictionary& dictionary);
    friend std::ostream& operator<<(std::ostream& os, Histogram& hist);
    void WriteToCSV(std::string& filename) const;
    static Histogram ReadFromCSV(std::string& filename);
    bool empty() const;
    size_t size() const;
    std::vector<int>& data();
    std::vector<int>::const_iterator cbegin() const;
    std::vector<int>::const_iterator cend() const;
    std::vector<int>::const_iterator begin() const;
    std::vector<int>::const_iterator end() const;
    int operator[](int i) const;
    int& operator[](int i);
    void compute_Histogram(const cv::Mat& descriptors,
                           const cv::Mat& dictionary);

private:
    std::vector<int> data_;
};
}  // namespace ipb