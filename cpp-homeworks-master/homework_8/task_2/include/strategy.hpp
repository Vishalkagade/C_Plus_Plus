#pragma once
#include <png++/png.hpp>
#include <string>
#include <vector>

namespace igg {

class IoStrategy {
public:
    virtual bool ReadFromDisk(const std::string& filename) = 0;
    virtual void WriteToDisk(const std::string& filename) const = 0;
    int rows = 0;
    int cols = 0;
    int max_value = 0;
    std::vector<png::rgb_pixel> data;
};
class PngIoStrategy : public igg::IoStrategy {
    bool ReadFromDisk(const std::string& filename) override;
    void WriteToDisk(const std::string& filename) const override;
};
class PpmIoStrategy : public igg::IoStrategy {
    bool ReadFromDisk(const std::string& filename) override;
    void WriteToDisk(const std::string& filename) const override;
};

}  // namespace igg