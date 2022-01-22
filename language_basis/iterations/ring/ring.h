#ifndef RING_H_
#define RING_H_

#include <deque>

using namespace std;

template<class A>
class ring {
  private:
    deque<A> buffer;
    const int bufferMaxSize;

  public:
    ring(int bufferMaxSize): bufferMaxSize(bufferMaxSize) {};

    void add(A item) {
      const bool bufferFull = this->buffer.size() == this->bufferMaxSize;

      if (bufferFull) {
        buffer.pop_back();
        buffer.push_front(item);
      } else {
        buffer.push_back(item);
      }
    }

    A get(int index) const {
      return this->buffer[index];
    }

    int size() const {
      return this->buffer.size();
    }
};

#endif // !RING_H_