#pragma once

#include <string>
#include <vector>

namespace hw1 {

/// Split a string into tokens separated by a delimiter character.
/// @param str      The input string to split.
/// @param delimiter The character used as delimiter.
/// @return A vector of substrings (tokens).
std::vector<std::string> Tokenize(const std::string& str, char delimiter);

/// Count the frequency of each word in a string.
/// Words are separated by whitespace.
/// @param str The input string.
/// @return A vector of (word, count) pairs, sorted alphabetically by word.
std::vector<std::pair<std::string, int>> CountWordFrequency(
    const std::string& str);

}  // namespace hw1
