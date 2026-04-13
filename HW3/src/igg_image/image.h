#pragma once

#include <string>
#include <vector>

#include "igg_image/io_strategies/strategy.h"

namespace igg {

class Image {
 public:
  /// A pixel holds three colour channels.
  struct Pixel {
    int red = 0;
    int green = 0;
    int blue = 0;
  };

  /// Constructs an empty image using the given I/O strategy.
  explicit Image(const IoStrategy& io_strategy);

  /// Constructs a zero-filled image with the given dimensions.
  Image(int rows, int cols, const IoStrategy& io_strategy);

  int rows() const;
  int cols() const;

  /// Returns a const reference to the pixel at (row, col).
  const Pixel& at(int row, int col) const;

  /// Returns a reference to the pixel at (row, col).
  Pixel& at(int row, int col);

  /// Reads image data from disk using the configured I/O strategy.
  bool ReadFromDisk(const std::string& file_name);

  /// Writes image data to disk using the configured I/O strategy.
  void WriteToDisk(const std::string& file_name) const;

 private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  const IoStrategy& io_strategy_;
  std::vector<Pixel> data_;
};

}  // namespace igg
