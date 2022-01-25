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

    class iterator;

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

    ring::iterator begin() {
      ring::iterator it(this->buffer, 0);

      return it;
    }

    ring::iterator end() {
      ring::iterator it(this->buffer, this->bufferMaxSize);

      return it;
    }
};

template<class A>
class ring<A>::iterator {
  public:
    int currentIndex;
    deque<A> &buffer;

    iterator(deque<A> &buffer, int startIndex): currentIndex(startIndex), buffer(buffer) {};

    iterator & operator++() {
      ++this->currentIndex;

      return *this;
    }

    A & operator*() {
      return this->buffer[this->currentIndex];
    }
};

#endif // !RING_H_