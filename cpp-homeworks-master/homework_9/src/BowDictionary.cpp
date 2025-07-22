#include "BowDictionary.hpp"

#include <kmeans.hpp>
#include <opencv2/core/mat.hpp>
#include <vector>

namespace ipb {

int BowDictionary::size() const { return BowDict_.rows; }
bool BowDictionary::empty() const { return BowDict_.empty(); }
cv::Mat BowDictionary::vocabulary() const { return BowDict_; }

void BowDictionary::set_vocabulary(const cv::Mat& vocabulary) {
    BowDict_ = vocabulary;
}
void BowDictionary::build(int iter,
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