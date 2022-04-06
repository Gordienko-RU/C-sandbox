#include "utils.h"

using namespace std;

int main() {
  const int tableSize = getTableSize();

  renderHeader();

  renderTable(tableSize);

  return 0;
}
