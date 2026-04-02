#pragma once

#include <string>
#include <vector>

namespace igg {

/// Stores the raw data of a colour image.
/// `data` holds three colour channels: data[0] = red, data[1] = green,
/// data[2] = blue. Each channel is a flat vector of rows * cols integers.
struct ImageData {
  int rows = 0;
  int cols = 0;
  int max_val = 255;
  std::vector<std::vector<int>> data;
};

/// Abstract base class for image I/O strategies.
class IoStrategy {
 public:
  virtual bool Write(const std::string& file_name,
                     const ImageData& data) const = 0;
  virtual ImageData Read(const std::string& file_name) const = 0;
  virtual ~IoStrategy() {}
};

}  // namespace igg
