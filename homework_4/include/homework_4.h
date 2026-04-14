#ifndef HOMEWORK_4_H
#define HOMEWORK_4_H

#include <algorithm>
#include <string>
#include <vector>

namespace ipb {
template <typename T>

struct named_vector {
  std::string name_;
  std::vector<T> data_;
  // ✅ CONSTRUCTEUR (fonction spéciale)
  named_vector() : name_(""), data_() {}

  // ✅ CONSTRUCTEUR (fonction spéciale)
  named_vector(const std::string &n, const std::vector<T> &d)
      : name_(n), data_(d) {}

  std::string name() const { return name_; }
  std::vector<T> &vector() { return data_; }

  void push_back(const T &value) { data_.push_back(value); }
  void emplace_back(const T &value) { data_.emplace_back(value); }

  T &operator[](size_t i) { return data_[i]; }

  auto begin() { return data_.begin(); }
  auto end() { return data_.end(); }

  bool empty() const { return data_.empty() || name_.empty(); }
  size_t size() const { return data_.size() + name_.size(); }

  void resize(size_t new_size) { data_.resize(new_size); }
  void reserve(size_t new_capacity) { data_.reserve(new_capacity); }
  size_t capacity() const { return data_.capacity(); }
};
}  // namespace ipb

#include "ipb_algorithm.h"

#endif  // HOMEWORK_4_H