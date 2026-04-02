#include "igg_image/image.h"

#include <iostream>
#include <vector>

/// Application 3: loads a PGM image and prints its histogram.
int main() {
  std::cout << "=== Application 3: histogram ===" << std::endl;
  igg::Image img;
  if (img.FillFromPgm("../data/lena.ascii.pgm")) {
    std::cout << "Image loaded: " << img.rows() << " rows x " << img.cols()
              << " cols" << std::endl;
    const int kBins = 10;
    std::vector<float> hist = img.ComputeHistogram(kBins);
    std::cout << "Histogram (" << kBins << " bins):" << std::endl;
    for (int i = 0; i < kBins; ++i) {
      std::cout << "  bin[" << i << "] = " << hist[i] << std::endl;
    }
  } else {
    std::cerr << "Could not open ../data/lena.ascii.pgm" << std::endl;
  }
  return 0;
}
