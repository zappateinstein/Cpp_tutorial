#pragma once

#include "igg_image/io_strategies/strategy.h"

namespace igg {

/// A dummy I/O strategy used for testing.
/// Write() always succeeds; Read() always returns an empty ImageData.
class DummyIoStrategy : public IoStrategy {
 public:
  bool Write(const std::string& /*file_name*/,
             const ImageData& /*data*/) const override {
    return true;
  }
  ImageData Read(const std::string& /*file_name*/) const override {
    return {};
  }
};

}  // namespace igg
