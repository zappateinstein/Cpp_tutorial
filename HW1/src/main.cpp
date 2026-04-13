#include "string_tools.h"

#include <iostream>

int main() {
  // Demonstrate string tokenization
  const std::string csv_line = "hello,world,modern,cpp,course";
  std::cout << "Tokenizing: \"" << csv_line << "\" by ','" << std::endl;
  auto tokens = hw1::Tokenize(csv_line, ',');
  for (const auto& token : tokens) {
    std::cout << "  Token: " << token << std::endl;
  }

  // Demonstrate word frequency counting
  const std::string text =
      "the quick brown fox jumps over the lazy dog the fox";
  std::cout << "\nWord frequencies in: \"" << text << "\"" << std::endl;
  auto frequencies = hw1::CountWordFrequency(text);
  for (const auto& pair : frequencies) {
    std::cout << "  \"" << pair.first << "\": " << pair.second << std::endl;
  }

  return 0;
}
