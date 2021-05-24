#ifndef TEST
#define TEST

namespace sandbox
{
  class Test {
    public:
      static const int TEST_CONSTANT = 99;
      static int getInstanceCount();
    private:
      static int instanceCount;
      int id;
    public:
      Test();
      int getId() const;
  };
};

#endif

