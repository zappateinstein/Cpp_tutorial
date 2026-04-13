#pragma once

#include "igg_image/io_strategies/strategy.h"

namespace igg {

/// I/O strategy for plain PPM (P3) colour images.
class PpmIoStrategy : public IoStrategy {
 public:
  bool Write(const std::string& file_name,
             const ImageData& data) const override;
  ImageData Read(const std::string& file_name) const override;
};

}  // namespace igg
