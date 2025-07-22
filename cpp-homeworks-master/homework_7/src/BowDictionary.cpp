#include "BowDictionary.hpp"

#include <opencv2/core/mat.hpp>
#include <vector>

#include "kmeans.hpp"

namespace ipb {

int BowDictionary::max_iterations() const { return max_iter_; }
int BowDictionary::size() const { return num_words_; }
std::vector<cv::Mat> BowDictionary::descriptors() const { return descriptors_; }
int BowDictionary::total_features() const { return BowDict_.rows; }
bool BowDictionary::empty() const { return BowDict_.empty(); }
cv::Mat BowDictionary::vocabulary() const { return BowDict_; }
void BowDictionary::set_max_iterations(int iter) {
    max_iter_ = iter;
    this->UpdateBow();
}
void BowDictionary::set_size(int words) {
    num_words_ = words;
    this->UpdateBow();
}
void BowDictionary::set_descriptors(const std::vector<cv::Mat>& descriptor) {
    descriptors_ = descriptor;
    this->UpdateBow();
}
void BowDictionary::set_params(int iter,
                               int words,
                               const std::vector<cv::Mat>& descriptor) {
    num_words_ = words;
    max_iter_ = iter;
    descriptors_ = descriptor;
    this->UpdateBow();
}

void BowDictionary::UpdateBow() {
    BowDict_ = kMeans(descriptors_, num_words_, max_iter_);
}
}  // namespace ipb