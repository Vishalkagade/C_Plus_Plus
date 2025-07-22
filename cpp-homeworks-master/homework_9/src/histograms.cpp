#include "histograms.hpp"

#include <fstream>
#include <iostream>
#include <opencv2/core.hpp>
#include <sstream>
#include <string>
#include <vector>

namespace ipb {
Histogram::Histogram(const std::vector<int>& data) { data_ = data; }
Histogram::Histogram(const cv::Mat& descriptors,
                     const ipb::BowDictionary& dictionary) {
    this->compute_Histogram(descriptors, dictionary.vocabulary());
}
bool Histogram::empty() const { return data_.empty(); }
size_t Histogram::size() const { return data_.size(); }
std::vector<int>& Histogram::data() { return data_; }
std::vector<int>::const_iterator Histogram::cbegin() const {
    return data_.cbegin();
};
std::vector<int>::const_iterator Histogram::cend() const {
    return data_.cend();
};
std::vector<int>::const_iterator Histogram::begin() const {
    return data_.begin();
};
std::vector<int>::const_iterator Histogram::end() const { return data_.end(); };
int Histogram::operator[](int i) const { return data_[i]; }
int& Histogram::operator[](int i) {
    int& value = data_[i];
    return value;
}
void Histogram::compute_Histogram(const cv::Mat& descriptors,
                                  const cv::Mat& dictionary) {
    if (descriptors.empty()) {
        return;
    }
    cv::Mat dist;
    cv::Mat nidx;

    cv::batchDistance(descriptors, dictionary, dist, CV_32F, nidx, cv::NORM_L2,
                      1, cv::noArray());

    for (int i = 0; i < dictionary.rows; i++) {
        int count = 0;
        for (int j = 0; j < nidx.rows; j++) {
            if (nidx.at<int>(j, 0) != i) {
                continue;
            }
            count += 1;
        }
        data_.emplace_back(count);
    }
}

void Histogram::WriteToCSV(std::string& filename) const {
    std::ofstream out(filename);

    for (size_t i = 0; i < this->size(); i++) {
        if (i != this->size() - 1) {
            out << data_[i] << ",";
        } else {
            out << data_[i];
        }
    }
}

Histogram Histogram::ReadFromCSV(std::string& filename) {
    std::ifstream in(filename, std::ios_base::in);
    if (!in) {
        return Histogram();
    }

    std::vector<int> data;
    std::string line;
    std::string word;

    while (std::getline(in, line)) {
        std::stringstream str(line);
        while (std::getline(str, word, ',')) {
            int bin = std::stoi(word);
            data.emplace_back(bin);
        }
    }
    return Histogram(data);
}

std::ostream& operator<<(std::ostream& os, ipb::Histogram& hist) {
    for (size_t i = 0; i < hist.size(); i++) {
        if (i != hist.size() - 1) {
            os << hist.data()[i] << ","
               << " ";
        } else {
            os << hist.data()[i];
        }
    }
    return os;
}

}  // namespace ipb
