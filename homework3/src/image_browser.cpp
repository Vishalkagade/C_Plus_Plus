#include <array>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include "html_writer.hpp"
#include "image_browser.hpp"

using std::cout;
using std::endl;

void image_browser::AddFullRow(const ImageRow &row, bool first_row) {
  html_writer::OpenRow();
  for (const auto& elem : row) {
    std::string imagefile = std::get<0>(elem);
    float score = std::get<1>(elem);
    html_writer::AddImage(imagefile, score, first_row);
    first_row = false;
  }
  html_writer::CloseRow();
}

void image_browser::CreateImageBrowser(const std::string &title,
                                       const std::string &stylesheet,
                                       const std::vector<ImageRow> &rows) {

  html_writer::OpenDocument();
  html_writer::AddTitle(title);
  html_writer::AddCSSStyle(stylesheet);
  html_writer::OpenBody();
  bool first_row = true;
  for (const auto &elem : rows) {
    image_browser::AddFullRow(elem, first_row);
    first_row = false;
    }
    html_writer::CloseBody();
    html_writer::CloseDocument();
}
