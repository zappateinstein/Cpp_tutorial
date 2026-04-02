#include "igg_image/image.h"
#include "igg_image/io_strategies/dummy_strategy.h"
#include "igg_image/io_strategies/ppm_strategy.h"

#include <cassert>
#include <iostream>
#include <string>

static const char* kSamplePpm = CMAKE_SOURCE_DIR "/data/sample.ppm";

void TestDefaultConstructor() {
  igg::DummyIoStrategy dummy;
  igg::Image img(dummy);
  assert(img.rows() == 0);
  assert(img.cols() == 0);
  std::cout << "TestDefaultConstructor: PASSED" << std::endl;
}

void TestSizedConstructor() {
  igg::DummyIoStrategy dummy;
  igg::Image img(3, 4, dummy);
  assert(img.rows() == 3);
  assert(img.cols() == 4);
  // All pixels should be zero.
  for (int r = 0; r < 3; ++r)
    for (int c = 0; c < 4; ++c) {
      assert(img.at(r, c).red == 0);
      assert(img.at(r, c).green == 0);
      assert(img.at(r, c).blue == 0);
    }
  std::cout << "TestSizedConstructor: PASSED" << std::endl;
}

void TestAtSetterGetter() {
  igg::DummyIoStrategy dummy;
  igg::Image img(2, 2, dummy);
  igg::Image::Pixel px;
  px.red = 10; px.green = 20; px.blue = 30;
  img.at(0, 1) = px;
  const igg::Image& cimg = img;
  assert(cimg.at(0, 1).red == 10);
  assert(cimg.at(0, 1).green == 20);
  assert(cimg.at(0, 1).blue == 30);
  assert(cimg.at(0, 0).red == 0);
  std::cout << "TestAtSetterGetter: PASSED" << std::endl;
}

void TestReadFromDisk() {
  igg::PpmIoStrategy ppm;
  igg::Image img(ppm);
  bool ok = img.ReadFromDisk(kSamplePpm);
  assert(ok);
  assert(img.rows() == 4);
  assert(img.cols() == 4);
  // Top-left pixel: red=0, green=0, blue=128
  assert(img.at(0, 0).red == 0);
  assert(img.at(0, 0).green == 0);
  assert(img.at(0, 0).blue == 128);
  std::cout << "TestReadFromDisk: PASSED" << std::endl;
}

void TestReadFromDiskMissing() {
  igg::PpmIoStrategy ppm;
  igg::Image img(ppm);
  bool ok = img.ReadFromDisk("/nonexistent/path.ppm");
  assert(!ok);
  assert(img.rows() == 0);
  std::cout << "TestReadFromDiskMissing: PASSED" << std::endl;
}

void TestWriteToDisk() {
  igg::PpmIoStrategy ppm;
  igg::Image img(2, 2, ppm);
  igg::Image::Pixel px00; px00.red = 100; px00.green = 150; px00.blue = 200;
  img.at(0, 0) = px00;
  igg::Image::Pixel px11; px11.red = 50; px11.green = 75; px11.blue = 25;
  img.at(1, 1) = px11;

  const std::string tmp = "/tmp/hw3_test_write.ppm";
  img.WriteToDisk(tmp);

  igg::Image img2(ppm);
  bool ok = img2.ReadFromDisk(tmp);
  assert(ok);
  assert(img2.rows() == 2);
  assert(img2.cols() == 2);
  assert(img2.at(0, 0).red == 100);
  assert(img2.at(0, 0).green == 150);
  assert(img2.at(0, 0).blue == 200);
  assert(img2.at(1, 1).red == 50);
  assert(img2.at(1, 1).green == 75);
  assert(img2.at(1, 1).blue == 25);
  std::cout << "TestWriteToDisk: PASSED" << std::endl;
}

void TestDummyStrategy() {
  igg::DummyIoStrategy dummy;
  igg::Image img(dummy);
  bool ok = img.ReadFromDisk("any_file.ppm");
  assert(!ok);  // DummyIoStrategy returns empty data
  assert(dummy.Write("any_file.ppm", {}) == true);
  std::cout << "TestDummyStrategy: PASSED" << std::endl;
}

int main() {
  TestDefaultConstructor();
  TestSizedConstructor();
  TestAtSetterGetter();
  TestReadFromDisk();
  TestReadFromDiskMissing();
  TestWriteToDisk();
  TestDummyStrategy();
  std::cout << "All HW3 tests passed!" << std::endl;
  return 0;
}
