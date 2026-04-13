// @file      homework_4.h
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2020 Ignacio Vizzo, all rights reserved
#pragma once

#include <algorithm>
#include <cctype>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

namespace ipb {

template <typename T>
class named_vector {
 public:
  named_vector() = default;
  named_vector(const std::string& name, const std::vector<T>& vec)
      : name_(name), vec_(vec) {}

  // Accessors
  const std::string& name() const { return name_; }
  std::string& name() { return name_; }
  const std::vector<T>& vector() const { return vec_; }
  std::vector<T>& vector() { return vec_; }

  /// Returns true only when BOTH name and vector are non-empty.
  bool empty() const { return name_.empty() || vec_.empty(); }

  /// Returns the combined size of the name and the underlying vector.
  std::size_t size() const { return name_.size() + vec_.size(); }

  std::size_t capacity() const { return vec_.capacity(); }
  void resize(std::size_t n) { vec_.resize(n); }
  void reserve(std::size_t n) { vec_.reserve(n); }

 private:
  std::string name_;
  std::vector<T> vec_;
};

// ---------------------------------------------------------------------------
// Algorithms
// ---------------------------------------------------------------------------

template <typename T>
T accumulate(const named_vector<T>& v) {
  return std::accumulate(v.vector().begin(), v.vector().end(), T{});
}

template <typename T>
int count(const named_vector<T>& v, const T& value) {
  return static_cast<int>(
      std::count(v.vector().begin(), v.vector().end(), value));
}

template <typename T>
bool all_even(const named_vector<T>& v) {
  return std::all_of(v.vector().begin(), v.vector().end(),
                     [](const T& x) { return x % 2 == 0; });
}

template <typename T>
void clamp(named_vector<T>& v, const T& lo, const T& hi) {
  for (auto& x : v.vector()) {
    if (x < lo) {
      x = lo;
    } else if (x > hi) {
      x = hi;
    }
  }
}

template <typename T>
void fill(named_vector<T>& v, const T& value) {
  std::fill(v.vector().begin(), v.vector().end(), value);
}

template <typename T>
bool find(const named_vector<T>& v, const T& value) {
  return std::find(v.vector().begin(), v.vector().end(), value) !=
         v.vector().end();
}

template <typename T>
void print(const named_vector<T>& v) {
  std::cout << v.name() << ": ";
  for (const auto& x : v.vector()) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}

template <typename T>
void toupper(named_vector<T>& v) {
  std::string& name = v.name();
  std::transform(name.begin(), name.end(), name.begin(),
                 [](unsigned char c) { return std::toupper(c); });
}

template <typename T>
void sort(named_vector<T>& v) {
  std::sort(v.vector().begin(), v.vector().end());
}

template <typename T>
void rotate(named_vector<T>& v, int n) {
  const auto sz = static_cast<int>(v.vector().size());
  if (sz == 0) return;
  n = ((n % sz) + sz) % sz;  // normalise to [0, sz)
  std::rotate(v.vector().begin(), v.vector().begin() + n, v.vector().end());
}

template <typename T>
void reverse(named_vector<T>& v) {
  std::reverse(v.vector().begin(), v.vector().end());
}

}  // namespace ipb
