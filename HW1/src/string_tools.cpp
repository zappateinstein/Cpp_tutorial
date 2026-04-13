#include "string_tools.h"

#include <algorithm>
#include <map>
#include <sstream>

namespace hw1 {

std::vector<std::string> Tokenize(const std::string& str, char delimiter) {
  std::vector<std::string> tokens;
  std::istringstream stream(str);
  std::string token;
  while (std::getline(stream, token, delimiter)) {
    if (!token.empty()) {
      tokens.push_back(token);
    }
  }
  return tokens;
}

std::vector<std::pair<std::string, int>> CountWordFrequency(
    const std::string& str) {
  std::map<std::string, int> freq_map;
  std::istringstream stream(str);
  std::string word;
  while (stream >> word) {
    ++freq_map[word];
  }
  std::vector<std::pair<std::string, int>> result(freq_map.begin(),
                                                   freq_map.end());
  return result;
}

}  // namespace hw1
