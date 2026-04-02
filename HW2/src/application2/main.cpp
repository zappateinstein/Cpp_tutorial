#include "igg_image/image.h"

#include <iostream>

/// Application 2: reads a PGM file, draws a diagonal, and writes it back.
int main() {
  std::cout << "=== Application 2: read/write PGM ===" << std::endl;
  igg::Image img;
  if (img.FillFromPgm("../data/lena.ascii.pgm")) {
    std::cout << "Image loaded: " << img.rows() << " rows x " << img.cols()
              << " cols" << std::endl;
    // Draw a white diagonal
    int diag = std::min(img.rows(), img.cols());
    for (int i = 0; i < diag; ++i) {
      img.at(i, i) = 255;
    }
    img.WriteToPgm("../data/lena_diagonal.ascii.pgm");
    std::cout << "Written to ../data/lena_diagonal.ascii.pgm" << std::endl;
  } else {
    std::cerr << "Could not open ../data/lena.ascii.pgm" << std::endl;
  }
  return 0;
}
