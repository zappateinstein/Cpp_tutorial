#ifndef HOMEWORK_4_H
#define HOMEWORK_4_H

#include <algorithm>
#include <iostream>
#include <vector>
using std::string;
using std::vector;

namespace ipb {
template <typename T> struct named_vector {
  string name_;
  vector<T> data_;
  std::string name() const { return name_; }
  vector<T> data() const { return data_; }
  void emplace_back(const T &value) { data_.emplace_back(value); }
  T &operator[](size_t i) { return data_[i]; }
  T &begin() { return data_.front(); }
  T &end() { return data_.back(); }
  bool empty() const { return data_.empty() || name_.empty(); }
  void resize(size_t new_size) { data_.resize(new_size); }
  size_t size() const { return data_.size() + name_.size(); }
  void reserve(size_t new_capacity) { data_.reserve(new_capacity); }
  size_t capacity() const { return data_.capacity(); }
};
} // namespace ipb

#endif // HOMEWORK_4_H