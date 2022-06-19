#include <string>

std::string kangaroo(int x1, int v1, int x2, int v2) {
  if ((x1 < x2 && v1 < v2) || (x2 < x1 && v2 < v1)) {
    return std::string("NO");
  }

  if (v1 == v2 && x1 != x2) {
    return std::string("NO");
  }

  // This result is always positive since x2 > x1 and it has been already
  // checked that v1 > v2.
  return (x2 - x1) % (v1 - v2) == 0 ? std::string("YES") : std::string("NO");
}