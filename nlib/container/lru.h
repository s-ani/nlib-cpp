#ifndef NLIB_CONTAINER_LRU_H_
#define NLIB_CONTAINER_LRU_H_

#include <cassert>
#include <cstddef>
#include <list>
#include <unordered_map>

namespace nlib {

template <typename T>
class LRU {
 public:
  LRU() = default;

  void Insert(const T& key) {
    assert(!Contains(key));

    lru_.push_front(key);
    pos_[key] = lru_.begin();
  }

  void Remove(const T& key) {
    assert(Contains(key));

    lru_.erase(pos_[key]);
    pos_.erase(key);
  }

  void Use(const T& key) {
    if (Contains(key)) {
      Remove(key);
    }

    Insert(key);
  }

  // Returns the LRU element and removes it from cache.
  T Pop() {
    assert(!IsEmpty());

    T ret = lru_.back();
    lru_.pop_back();
    pos_.erase(ret);
    return ret;
  }

  // Returns the LRU key.
  T Peek() {
    assert(!IsEmpty());
    return lru_.back();
  }

  bool Contains(const T& key) const { return pos_.find(key) != pos_.end(); }

  size_t Size() const { return pos_.size(); }

  bool IsEmpty() const { return lru_.empty(); }

 private:
  std::list<T> lru_;
  std::unordered_map<T, typename std::list<T>::iterator> pos_;

  LRU(const LRU&) = delete;
  LRU& operator=(const LRU&) = delete;
};

}  // namespace nlib

#endif  // NLIB_CONTAINER_LRU_H_