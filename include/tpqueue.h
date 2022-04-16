// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue { 
 private:
  T arr[10];
  int head, tail;

 public:
  TPQueue() : head(0), tail(0) {}
  int Dimension() {
    return tail - head;
  }
  void push(T value) {
    if (Dimension() >= size) {
      throw std::string("Full!");
    } else {
      int k = tail - 1;
      while (k >= head && value.prior > arr[k % size].prior) {
        arr[(k + 1) % size] = arr[k % size];
        k--;
      }
    }
    T pop() {
      if (head == tail) {
        throw std::string("Empty!");
      } else {
        return arr[(head++) % size];
      }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
