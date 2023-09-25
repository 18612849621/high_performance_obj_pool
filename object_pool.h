#pragma once

#include <atomic>
#include <iostream>
#include <queue>
#include <thread>
#include <unordered_set>
#include <utility>
#include <vector>

namespace ks {
namespace photo_store {

template<class T>
class GlobalPool;

template <class T> class ObjectPool {
public:
  ObjectPool() = default;
  virtual ~ObjectPool() = default;

protected:
  union Slot {
    Slot *next_ = NULL;
    T val_;
  };

  struct Block {
    Slot *slots_;
    size_t idx_ = 0;
  };
};

} // namespace photo_store
} // namespace ks