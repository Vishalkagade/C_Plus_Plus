#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "html_writer.hpp"
#include "image_browser.hpp"

int main() {
    std::string title = "Images website";
    std::string style = "style.css";

    image_browser::ScoredImage img0 = {"data/000000.png", 0.77655};
    image_browser::ScoredImage img1 = {"data/000100.png", 0.77655};
    image_browser::ScoredImage img2 = {"data/000200.png", 0.77655};
    image_browser::ScoredImage img3 = {"data/000300.png", 0.77655};
    image_browser::ScoredImage img4 = {"data/000400.png", 0.77655};
    image_browser::ScoredImage img5 = {"data/000500.png", 0.77655};
    image_browser::ScoredImage img6 = {"data/000600.png", 0.77655};
    image_browser::ScoredImage img7 = {"data/000700.png", 0.77655};
    image_browser::ScoredImage img8 = {"data/000800.png", 0.77655};

    image_browser::ImageRow row1 = {img0, img1, img2};
    image_browser::ImageRow row2 = {img3, img4, img5};
    image_browser::ImageRow row3 = {img6, img7, img8};

    std::vector<image_browser::ImageRow> input_rows = {row1, row2, row3};

    image_browser::CreateImageBrowser(title, style, input_rows);

    return 0;
}