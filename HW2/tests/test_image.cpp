#include "igg_image/image.h"

#include <cassert>
#include <cmath>
#include <iostream>

// Path to the sample PGM file relative to the build directory.
// CMake copies (or we rely on) the data directory.
static const char* kSamplePgm =
    CMAKE_SOURCE_DIR "/data/sample.pgm";

void TestDefaultConstructor() {
  igg::Image img;
  assert(img.rows() == 0);
  assert(img.cols() == 0);
  std::cout << "TestDefaultConstructor: PASSED" << std::endl;
}

void TestSizedConstructor() {
  igg::Image img(4, 6);
  assert(img.rows() == 4);
  assert(img.cols() == 6);
  // All pixels should be zero-initialised.
  for (int r = 0; r < 4; ++r)
    for (int c = 0; c < 6; ++c)
      assert(img.at(r, c) == 0);
  std::cout << "TestSizedConstructor: PASSED" << std::endl;
}

void TestAtSetterGetter() {
  igg::Image img(3, 3);
  img.at(1, 2) = 128;
  const igg::Image& cimg = img;
  assert(cimg.at(1, 2) == 128);
  assert(cimg.at(0, 0) == 0);
  std::cout << "TestAtSetterGetter: PASSED" << std::endl;
}

void TestFillFromPgm() {
  igg::Image img;
  bool ok = img.FillFromPgm(kSamplePgm);
  assert(ok);
  assert(img.rows() == 8);
  assert(img.cols() == 8);
  // Top-left pixel should be 0.
  assert(img.at(0, 0) == 0);
  // Bottom-right pixel should be 255.
  assert(img.at(7, 7) == 255);
  std::cout << "TestFillFromPgm: PASSED" << std::endl;
}

void TestFillFromPgmMissing() {
  igg::Image img;
  bool ok = img.FillFromPgm("/nonexistent/path.pgm");
  assert(!ok);
  assert(img.rows() == 0);
  std::cout << "TestFillFromPgmMissing: PASSED" << std::endl;
}

void TestWriteToPgm() {
  igg::Image img(4, 4);
  img.at(0, 0) = 10;
  img.at(3, 3) = 200;

  const std::string tmp = "/tmp/hw2_test_write.pgm";
  img.WriteToPgm(tmp);

  igg::Image img2;
  bool ok = img2.FillFromPgm(tmp);
  assert(ok);
  assert(img2.rows() == 4);
  assert(img2.cols() == 4);
  assert(img2.at(0, 0) == 10);
  assert(img2.at(3, 3) == 200);
  std::cout << "TestWriteToPgm: PASSED" << std::endl;
}

void TestComputeHistogram() {
  // Create a 2x2 image with known values: 0, 64, 192, 255
  igg::Image img(2, 2);
  img.at(0, 0) = 0;
  img.at(0, 1) = 64;
  img.at(1, 0) = 192;
  img.at(1, 1) = 255;

  const int bins = 4;
  auto hist = img.ComputeHistogram(bins);
  assert(static_cast<int>(hist.size()) == bins);
  // Total pixel count must equal image size.
  float total = 0.0f;
  for (float v : hist) total += v;
  assert(static_cast<int>(total) == img.rows() * img.cols());
  std::cout << "TestComputeHistogram: PASSED" << std::endl;
}

void TestDownScale() {
  igg::Image img(6, 6);
  for (int r = 0; r < 6; ++r)
    for (int c = 0; c < 6; ++c)
      img.at(r, c) = r * 6 + c;

  img.DownScale(2);
  assert(img.rows() == 3);
  assert(img.cols() == 3);
  // Top-left 2x2 block had values 0,1,6,7 – we keep (0,0) = 0.
  assert(img.at(0, 0) == 0);
  std::cout << "TestDownScale: PASSED" << std::endl;
}

void TestUpScale() {
  igg::Image img(2, 2);
  img.at(0, 0) = 10;
  img.at(0, 1) = 20;
  img.at(1, 0) = 30;
  img.at(1, 1) = 40;

  img.UpScale(2);
  assert(img.rows() == 4);
  assert(img.cols() == 4);
  // Each original pixel should map to a 2x2 block.
  assert(img.at(0, 0) == 10);
  assert(img.at(0, 1) == 10);
  assert(img.at(1, 0) == 10);
  assert(img.at(1, 1) == 10);
  assert(img.at(0, 2) == 20);
  assert(img.at(2, 0) == 30);
  assert(img.at(2, 2) == 40);
  assert(img.at(3, 3) == 40);
  std::cout << "TestUpScale: PASSED" << std::endl;
}

int main() {
  TestDefaultConstructor();
  TestSizedConstructor();
  TestAtSetterGetter();
  TestFillFromPgm();
  TestFillFromPgmMissing();
  TestWriteToPgm();
  TestComputeHistogram();
  TestDownScale();
  TestUpScale();
  std::cout << "All HW2 tests passed!" << std::endl;
  return 0;
}
