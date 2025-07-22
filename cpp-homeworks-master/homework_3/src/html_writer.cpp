#include <filesystem>
#include <iomanip>
#include <iostream>

#include "homework_3.h"

void html_writer::OpenDocument() {
    std::cout << "<!DOCTYPE html>" << std::endl;
    std::cout << "<html>" << std::endl;
}

void html_writer::CloseDocument() { std::cout << "</html>" << std::endl; }

void html_writer::AddCSSStyle(const std::string &stylesheet) {
    // see html file for adding it
    std::cout << "<head>" << std::endl;
    std::cout << R"(<link rel="stylesheet" type="text/css" href=")"
              << stylesheet << R"(" />)" << std::endl;
    std::cout << "</head>" << std::endl;
}

void html_writer::AddTitle(const std::string &title) {
    std::cout << "<title>" << title << "</title>" << std::endl;
}

void html_writer::OpenBody() { std::cout << "<body>" << std::endl; }

void html_writer::CloseBody() { std::cout << "</body>" << std::endl; }

void html_writer::OpenRow() {
    std::cout << R"(<div class="row">)" << std::endl;
}

void html_writer::CloseRow() { std::cout << "</div>" << std::endl; }

void html_writer::AddImage(const std::string &img_path,
                           float score,
                           bool highlight) {
    std::filesystem::path img_p = img_path;
    std::string filename = img_p.filename();
    std::string ext = img_p.extension();

    if (((ext == ".png") || (ext == ".jpg")) &&
        ((score >= 0.0) && (score <= 1.0))) {
        if (highlight) {
            std::cout << R"(<div class="column")"
                      << R"(style="border: 5px solid green;">)" << std::endl;
            std::cout << "<h2>" << filename << "</h2>" << std::endl;
            std::cout << "<img src=" << img_p << " />" << std::endl;
            std::cout << std::setprecision(2) << std::fixed
                      << "<p>score = " << score << "</p>" << std::endl;
            std::cout << " </div> " << std::endl;

        } else {
            std::string col = "column";
            std::cout << R"(<div class="column">)" << std::endl;
            std::cout << "<h2>" << filename << "</h2>" << std::endl;
            std::cout << "<img src=" << img_p << " />" << std::endl;
            std::cout << std::setprecision(2) << std::fixed
                      << "<p>score = " << score << "</p>" << std::endl;
            std::cout << " </div> " << std::endl;
        }

    } else {
        std::cerr << "ERROR" << std::endl;
    }
}