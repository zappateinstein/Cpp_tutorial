#include "string_tools.h"

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

void TestTokenize() {
  auto tokens = hw1::Tokenize("a,b,c", ',');
  assert(tokens.size() == 3);
  assert(tokens[0] == "a");
  assert(tokens[1] == "b");
  assert(tokens[2] == "c");

  // Test with empty parts (consecutive delimiters skipped)
  auto tokens2 = hw1::Tokenize("hello world", ' ');
  assert(tokens2.size() == 2);
  assert(tokens2[0] == "hello");
  assert(tokens2[1] == "world");

  // Test empty string
  auto tokens3 = hw1::Tokenize("", ',');
  assert(tokens3.empty());

  std::cout << "TestTokenize: PASSED" << std::endl;
}

void TestCountWordFrequency() {
  auto freq = hw1::CountWordFrequency("the cat sat on the mat the cat");
  // Expect: cat=2, mat=1, on=1, sat=1, the=3
  assert(freq.size() == 5);
  for (const auto& wc : freq) {
    if (wc.first == "the") assert(wc.second == 3);
    if (wc.first == "cat") assert(wc.second == 2);
    if (wc.first == "sat") assert(wc.second == 1);
    if (wc.first == "on")  assert(wc.second == 1);
    if (wc.first == "mat") assert(wc.second == 1);
  }

  // Test empty string
  auto freq2 = hw1::CountWordFrequency("");
  assert(freq2.empty());

  std::cout << "TestCountWordFrequency: PASSED" << std::endl;
}

int main() {
  TestTokenize();
  TestCountWordFrequency();
  std::cout << "All HW1 tests passed!" << std::endl;
  return 0;
}
