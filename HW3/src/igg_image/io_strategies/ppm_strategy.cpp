#include "igg_image/io_strategies/ppm_strategy.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace igg {

bool PpmIoStrategy::Write(const std::string& file_name,
                          const ImageData& data) const {
  std::ofstream ofs(file_name);
  if (!ofs.is_open()) { return false; }

  ofs << "P3\n";
  ofs << data.cols << " " << data.rows << "\n";
  ofs << data.max_val << "\n";

  const auto& red = data.data.at(0);
  const auto& green = data.data.at(1);
  const auto& blue = data.data.at(2);

  int pixel_count = data.rows * data.cols;
  for (int i = 0; i < pixel_count; ++i) {
    ofs << red[i] << " " << green[i] << " " << blue[i];
    // PPM recommends at most 70 characters per line; add a newline per pixel
    // for clarity.
    ofs << "\n";
  }
  return true;
}

ImageData PpmIoStrategy::Read(const std::string& file_name) const {
  std::ifstream ifs(file_name);
  if (!ifs.is_open()) { return {}; }

  std::string magic;
  ifs >> magic;
  if (magic != "P3") { return {}; }

  ImageData img;
  // Skip optional comment lines.
  std::string line;
  std::getline(ifs, line);  // consume rest of magic line
  while (ifs.peek() == '#') { std::getline(ifs, line); }

  ifs >> img.cols >> img.rows >> img.max_val;

  int pixel_count = img.rows * img.cols;
  std::vector<int> red(pixel_count), green(pixel_count), blue(pixel_count);
  for (int i = 0; i < pixel_count; ++i) {
    ifs >> red[i] >> green[i] >> blue[i];
  }
  img.data = {red, green, blue};
  return img;
}

}  // namespace igg
