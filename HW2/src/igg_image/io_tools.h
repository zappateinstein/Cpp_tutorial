#pragma once

#include <fstream>
#include <string>
#include <vector>

namespace igg {
namespace io_tools {

/// Stores relevant image data for a PGM (greyscale) image.
struct ImageData {
  int rows = 0;
  int cols = 0;
  int max_val = 255;
  std::vector<int> data;
};

/// Reads a greyscale image from an ASCII PGM file.
/// Returns an ImageData with an empty data vector if the file cannot be opened
/// or is not a valid P2 PGM file.
inline ImageData ReadFromPgm(const std::string& file_name) {
  std::ifstream file(file_name);
  if (!file.is_open()) { return {}; }

  std::string magic;
  file >> magic;
  if (magic != "P2") { return {}; }

  // Skip comments
  char c;
  while (file.get(c) && c != '\n') {}
  while (file.peek() == '#') {
    std::string comment;
    std::getline(file, comment);
  }

  ImageData img;
  file >> img.cols >> img.rows >> img.max_val;
  img.data.resize(img.rows * img.cols);
  for (int& pixel : img.data) {
    file >> pixel;
  }
  return img;
}

/// Writes greyscale image data to an ASCII PGM file.
/// Returns true on success.
inline bool WriteToPgm(const ImageData& image_data,
                       const std::string& file_name) {
  std::ofstream file(file_name);
  if (!file.is_open()) { return false; }
  file << "P2\n";
  file << image_data.cols << " " << image_data.rows << "\n";
  file << image_data.max_val << "\n";
  for (int row = 0; row < image_data.rows; ++row) {
    for (int col = 0; col < image_data.cols; ++col) {
      file << image_data.data[row * image_data.cols + col];
      if (col < image_data.cols - 1) { file << " "; }
    }
    file << "\n";
  }
  return true;
}

}  // namespace io_tools
}  // namespace igg
