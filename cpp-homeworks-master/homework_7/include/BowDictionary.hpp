#include <opencv2/core/mat.hpp>
#include <vector>

namespace ipb {

class BowDictionary {
public:
    BowDictionary(const BowDictionary&) = delete;
    void operator=(const BowDictionary&) = delete;
    BowDictionary(BowDictionary&& other) = default;
    BowDictionary& operator=(BowDictionary&& other) = default;

    static BowDictionary& GetInstance() {
        static BowDictionary instance;
        return instance;
    }

    int max_iterations() const;
    int size() const;
    int total_features() const;
    std::vector<cv::Mat> descriptors() const;
    cv::Mat vocabulary() const;
    bool empty() const;
    void set_max_iterations(int iter);
    void set_size(int words);
    void set_descriptors(const std::vector<cv::Mat>& descriptor);
    void set_params(int iter,
                    int words,
                    const std::vector<cv::Mat>& descriptor);
    void UpdateBow();

private:
    BowDictionary() = default;
    ~BowDictionary() = default;
    int max_iter_ = 0;
    int num_words_ = 0;
    std::vector<cv::Mat> descriptors_;
    cv::Mat BowDict_;
};
}  // namespace ipb