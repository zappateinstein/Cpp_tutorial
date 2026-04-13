#pragma once

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "io_tools.h"

namespace igg {

class Image {
 public:
  /// Default constructor – creates an empty (0×0) image.
  Image();

  /// Constructor that creates a zero-initialised image with the given size.
  Image(int rows, int cols);

  /// Returns the number of rows.
  int rows() const;

  /// Returns the number of columns.
  int cols() const;

  /// Returns a reference to the pixel at (row, col) — acts as a setter.
  int& at(int row, int col);

  /// Returns a const reference to the pixel at (row, col) — acts as a getter.
  const int& at(int row, int col) const;

  /// Fills the image from an ASCII PGM file.
  /// Returns true on success, false if the file could not be read.
  bool FillFromPgm(const std::string& file_name);

  /// Writes the image to an ASCII PGM file.
  void WriteToPgm(const std::string& file_name);

  /// Computes a normalised histogram with the given number of bins.
  /// Each bin value is the count of pixels falling in that bin.
  std::vector<float> ComputeHistogram(int bins) const;

  /// Downscales the image by keeping every `scale`-th pixel.
  void DownScale(int scale);

  /// Upscales the image by repeating each pixel `scale` times in both axes.
  void UpScale(int scale);

 private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<int> data_;
};

}  // namespace igg
