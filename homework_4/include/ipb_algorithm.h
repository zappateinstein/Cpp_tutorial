#ifndef IPB_ALGORITHM_H
#define IPB_ALGORITHM_H

#include "homework_4.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <numeric>
#include <vector>

namespace ipb {

// accumulate: returns the sum over all the elements in the data container
template <typename T> T accumulate(const named_vector<T> &nv) {
  return std::accumulate(nv.vector().begin(), nv.vector().end(), T(0));
}

// count: return how many elements are stored with given value
template <typename T> int count(const named_vector<T> &nv, const T &value) {
  return std::count(nv.vector().begin(), nv.vector().end(), value);
}

// all_even: returns true if all values in the container are even
template <typename T> bool all_even(const named_vector<T> &nv) {
  return std::all_of(nv.vector().begin(), nv.vector().end(),
                     [](const T &val) { return val % 2 == 0; });
}

// clamp: clamp all the values in the container to a given range [min, max]
template <typename T>
void clamp(named_vector<T> &nv, const T &min_val, const T &max_val) {
  for (auto &elem : nv.vector()) {
    if (elem < min_val) {
      elem = min_val;
    } else if (elem > max_val) {
      elem = max_val;
    }
  }
}

// fill: Fill all the elements in the container with a given value
template <typename T> void fill(named_vector<T> &nv, const T &value) {
  std::fill(nv.vector().begin(), nv.vector().end(), value);
}

// find: returns true if a given value is in the container
template <typename T> bool find(const named_vector<T> &nv, const T &value) {
  return std::find(nv.vector().begin(), nv.vector().end(), value) !=
         nv.vector().end();
}

// print: print everything inside the container to the standard output
template <typename T> void print(const named_vector<T> &nv) {
  std::cout << nv.name() << " : ";
  for (size_t i = 0; i < nv.vector().size(); ++i) {
    std::cout << nv.vector()[i];
    if (i < nv.vector().size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << std::endl;
}

// toupper: converts the name(if any) of the container to upper case
template <typename T> void toupper(named_vector<T> &nv) {
  std::string new_name = nv.name();
  for (auto &c : new_name) {
    c = std::toupper(static_cast<unsigned char>(c));
  }
  nv.name_ = new_name;
}

// sort: Sort the values in the container
template <typename T> void sort(named_vector<T> &nv) {
  std::sort(nv.begin(), nv.end());
}

// rotate: shift rotate the values in the container a given number of positions
template <typename T> void rotate(named_vector<T> &nv, size_t positions) {
  auto &vec = nv.vector();
  if (vec.empty())
    return;
  positions = positions % vec.size();
  std::rotate(vec.begin(), vec.end() - positions, vec.end());
}

// reverse: reverse(mirror) the values in the container
template <typename T> void reverse(named_vector<T> &nv) {
  std::reverse(nv.vector().begin(), nv.vector().end());
}

} // namespace ipb

#endif // IPB_ALGORITHM_H