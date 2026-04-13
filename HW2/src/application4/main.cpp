#include "igg_image/image.h"

#include <iostream>

/// Application 4: demonstrates downscaling and upscaling.
int main() {
  std::cout << "=== Application 4: scaling ===" << std::endl;
  igg::Image img;
  if (img.FillFromPgm("../data/lena.ascii.pgm")) {
    std::cout << "Original size: " << img.rows() << " x " << img.cols()
              << std::endl;
    img.DownScale(2);
    std::cout << "After DownScale(2): " << img.rows() << " x " << img.cols()
              << std::endl;
    img.WriteToPgm("../data/lena_downscaled.ascii.pgm");

    img.UpScale(2);
    std::cout << "After UpScale(2): " << img.rows() << " x " << img.cols()
              << std::endl;
    img.WriteToPgm("../data/lena_upscaled.ascii.pgm");
  } else {
    std::cerr << "Could not open ../data/lena.ascii.pgm" << std::endl;
  }
  return 0;
}
