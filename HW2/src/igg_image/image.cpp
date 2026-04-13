#include "image.h"

namespace igg {

Image::Image() {}

Image::Image(int rows, int cols)
    : rows_(rows), cols_(cols), data_(rows * cols, 0) {}

int Image::rows() const { return rows_; }

int Image::cols() const { return cols_; }

int& Image::at(int row, int col) {
  return data_[row * cols_ + col];
}

const int& Image::at(int row, int col) const {
  return data_[row * cols_ + col];
}

bool Image::FillFromPgm(const std::string& file_name) {
  io_tools::ImageData img = io_tools::ReadFromPgm(file_name);
  if (img.data.empty()) { return false; }
  rows_ = img.rows;
  cols_ = img.cols;
  max_val_ = img.max_val;
  data_.swap(img.data);
  return true;
}

void Image::WriteToPgm(const std::string& file_name) {
  io_tools::ImageData img;
  img.rows = rows_;
  img.cols = cols_;
  img.max_val = max_val_;
  img.data = data_;
  io_tools::WriteToPgm(img, file_name);
}

std::vector<float> Image::ComputeHistogram(int bins) const {
  std::vector<float> hist(bins, 0.0f);
  for (const int& pixel : data_) {
    // Map pixel in [0, max_val_] to a bin index in [0, bins-1].
    int bin = static_cast<int>(
        std::ceil(static_cast<float>(pixel) / static_cast<float>(max_val_) *
                  static_cast<float>(bins))) -
              1;
    if (bin < 0) { bin = 0; }
    if (bin >= bins) { bin = bins - 1; }
    hist[bin]++;
  }
  return hist;
}

void Image::DownScale(int scale) {
  int new_rows = rows_ / scale;
  int new_cols = cols_ / scale;
  std::vector<int> new_data(new_rows * new_cols, 0);
  for (int row = 0; row < new_rows; ++row) {
    for (int col = 0; col < new_cols; ++col) {
      new_data[row * new_cols + col] = data_[row * scale * cols_ + col * scale];
    }
  }
  rows_ = new_rows;
  cols_ = new_cols;
  data_.swap(new_data);
}

void Image::UpScale(int scale) {
  int new_rows = rows_ * scale;
  int new_cols = cols_ * scale;
  std::vector<int> new_data(new_rows * new_cols, 0);
  for (int row = 0; row < rows_; ++row) {
    for (int col = 0; col < cols_; ++col) {
      int val = data_[row * cols_ + col];
      for (int dr = 0; dr < scale; ++dr) {
        for (int dc = 0; dc < scale; ++dc) {
          new_data[(row * scale + dr) * new_cols + (col * scale + dc)] = val;
        }
      }
    }
  }
  rows_ = new_rows;
  cols_ = new_cols;
  data_.swap(new_data);
}

}  // namespace igg
