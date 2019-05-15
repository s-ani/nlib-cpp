#ifndef NLIB_CONTAINER_LRU_H_
#define NLIB_CONTAINER_LRU_H_

#include <stddef.h>

#include <list>
#include <unordered_map>

template <typename T>
class LRU {
 public:
  LRU() = default;

 private:
  LRU(const LRU&) = delete;
  LRU& operator=(const LRU&) = delete;
};

#endif  // NLIB_CONTAINER_LRU_H_