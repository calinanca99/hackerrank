#include <iostream>
#include <unordered_map>
#include <vector>

int sock_merchant(int n, std::vector<int> ar);

int main() {
  std::vector<int> ar = {1, 2, 1, 2, 1, 3, 2};
  std::cout << sock_merchant(7, ar);
  return 0;
}

int sock_merchant(int n, std::vector<int> ar) {
  // Steps:
  // 1. Create a hashmap; keys will be the colors in ar and values will be their
  // occurence
  std::unordered_map<int, int> my_map;

  // 2. Count occurence of each number in ar
  for (const auto &key : ar) {
    // create new_key with value 1 if key does not exist in hashmap
    // otherwise increment value at key with 1
    my_map[key]++;
  }

  // 3. Count number of pairs
  int pairs = 0;
  for (const auto &[color, occ] : my_map) {
    pairs += (occ / 2);
  }

  return pairs;
}