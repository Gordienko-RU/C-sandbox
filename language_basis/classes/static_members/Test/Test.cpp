#include "./Test.h"

int sandbox::Test::instanceCount = 0;

int sandbox::Test::getInstanceCount() {
  return instanceCount;
};

sandbox::Test::Test() {
  this->id = ++instanceCount;
}

int sandbox::Test::getId() const {
  return this->id;
}
