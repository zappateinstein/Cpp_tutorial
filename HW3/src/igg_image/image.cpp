#include "igg_image/image.h"

namespace igg {

Image::Image(const IoStrategy& io_strategy) : io_strategy_(io_strategy) {}

Image::Image(int rows, int cols, const IoStrategy& io_strategy)
    : rows_(rows), cols_(cols), io_strategy_(io_strategy),
      data_(rows * cols, Pixel{}) {}

int Image::rows() const { return rows_; }
int Image::cols() const { return cols_; }

const Image::Pixel& Image::at(int row, int col) const {
  return data_[row * cols_ + col];
}

Image::Pixel& Image::at(int row, int col) {
  return data_[row * cols_ + col];
}

bool Image::ReadFromDisk(const std::string& file_name) {
  ImageData img_data = io_strategy_.Read(file_name);
  if (img_data.data.empty() || img_data.rows == 0 || img_data.cols == 0) {
    return false;
  }
  rows_ = img_data.rows;
  cols_ = img_data.cols;
  max_val_ = img_data.max_val;

  const auto& red = img_data.data.at(0);
  const auto& green = img_data.data.at(1);
  const auto& blue = img_data.data.at(2);

  int pixel_count = rows_ * cols_;
  data_.resize(pixel_count);
  for (int i = 0; i < pixel_count; ++i) {
    data_[i].red = red[i];
    data_[i].green = green[i];
    data_[i].blue = blue[i];
  }
  return true;
}

void Image::WriteToDisk(const std::string& file_name) const {
  ImageData img_data;
  img_data.rows = rows_;
  img_data.cols = cols_;
  img_data.max_val = max_val_;

  int pixel_count = rows_ * cols_;
  std::vector<int> red(pixel_count), green(pixel_count), blue(pixel_count);
  for (int i = 0; i < pixel_count; ++i) {
    red[i] = data_[i].red;
    green[i] = data_[i].green;
    blue[i] = data_[i].blue;
  }
  img_data.data = {red, green, blue};
  io_strategy_.Write(file_name, img_data);
}

}  // namespace igg
