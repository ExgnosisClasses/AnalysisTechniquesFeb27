// Sufficient Initial Capacity
// This compliant solution ensures the capacity of the vector is sufficient before attempting to fill the container.
// However, this compliant solution is inefficient. The constructor will default-construct 10 elements of type int, 
// which are subsequently replaced by the call to std::fill_n(), meaning that each element in the container is initialized twice.

#include <algorithm>
#include <vector>
 
void f() {
  std::vector<int> v(10);
  std::fill_n(v.begin(), 10, 0x42);
}