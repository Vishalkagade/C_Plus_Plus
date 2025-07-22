#include <array>
#include <iostream>
#include <vector>

#include "homework_3.h"

void image_browser::AddFullRow(const image_browser::ImageRow &row,
                               bool first_row) {
    html_writer::OpenRow();
    for (const auto &elem : row) {
        const auto &[imagefile, score] = elem;
        html_writer::AddImage(imagefile, score, first_row);
        first_row = false;
    }
    html_writer::CloseRow();
}

void image_browser::CreateImageBrowser(
        const std::string &title,
        const std::string &stylesheet,
        const std::vector<image_browser::ImageRow> &rows) {
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
