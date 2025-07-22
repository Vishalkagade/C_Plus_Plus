#include <filesystem>
#include <iomanip>
#include <iostream>
#include "homework_3.h"
using std::cout;
using std::endl;


void html_writer::OpenDocument() {
  cout << "<!DOCTYPE html>" << endl;
  cout << "<html>" << endl;
}

void html_writer::CloseDocument() { cout << "</html>" << endl; }

void html_writer::AddCSSStyle(const std::string &stylesheet) {

      // see html file for adding it
      std::cout << "<head>" << std::endl;
      std::cout << R"(<link rel="stylesheet" type="text/css" href=")"
                << stylesheet << R"(" />)" << std::endl;
      std::cout << "</head>" << std::endl;
}

void html_writer::AddTitle(const std::string  &title) {
  cout << "<title>" << title << "<title>" << endl;
}

void html_writer::OpenBody() { cout << "<body>" << endl; }

void html_writer::CloseBody() { cout << "<body>" << endl; }

void html_writer::OpenRow() { cout << R"(<div class="row">)" << endl; }

void html_writer::CloseRow() { cout << "</div>" << endl; }

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

