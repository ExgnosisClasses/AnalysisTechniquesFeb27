// Sufficient Initial Capacity
// This compliant solution initializes v to 10 elements whose values are all 0x42.

#include <algorithm>
#include <vector>
 
void f() {
  std::vector<int> v(10);
  std::fill_n(v.begin(), 10, 0x42);
}