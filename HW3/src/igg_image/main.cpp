#include "igg_image/image.h"
#include "igg_image/io_strategies/ppm_strategy.h"

#include <iostream>

int main() {
  std::cout << "=== HW3: colour image with strategy pattern ===" << std::endl;

  igg::PpmIoStrategy ppm_strategy;

  igg::Image img(ppm_strategy);
  if (img.ReadFromDisk("../data/sample.ppm")) {
    std::cout << "Loaded " << img.rows() << " x " << img.cols()
              << " colour image" << std::endl;

    // Make the diagonal red.
    int diag = std::min(img.rows(), img.cols());
    for (int i = 0; i < diag; ++i) {
    igg::Image::Pixel red_pixel;
    red_pixel.red = 255;
    red_pixel.green = 0;
    red_pixel.blue = 0;
    img.at(i, i) = red_pixel;
    }

    img.WriteToDisk("../data/output.ppm");
    std::cout << "Written to ../data/output.ppm" << std::endl;
  } else {
    std::cerr << "Could not open ../data/sample.ppm" << std::endl;
  }
  return 0;
}
