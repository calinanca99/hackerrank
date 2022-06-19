#include <algorithm>
#include <iostream>
#include <vector>

void print_vec(const std::vector<int> &vec) {
  std::cout << '[' << ' ';
  for (const auto &elem : vec) {
    std::cout << elem << ' ';
  }
  std::cout << ']' << '\n';
}

std::vector<int> rotate_left(int d, std::vector<int> arr) {
  const int n = arr.size();
  int number_of_rotations = d;

  if (d > n) {
    number_of_rotations = n % d;
  }

  std::vector<int> arr_1(number_of_rotations);
  std::vector<int> arr_2(n - number_of_rotations);

  std::copy_n(arr.begin(), number_of_rotations, arr_1.begin());
  std::copy_n(arr.begin() + number_of_rotations, n - number_of_rotations,
              arr_2.begin());

  arr_2.insert(arr_2.end(), arr_1.begin(), arr_1.end());

  return arr_2;
}

int main() {
  const std::vector<int> input = {1, 2, 3, 4, 5};
  auto output = rotate_left(4, input);
  print_vec(output);
}