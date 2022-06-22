#include <algorithm>
#include <iostream>
#include <vector>

int hackerland_radio_transmitters(std::vector<int> x, int k) {
  std::sort(x.begin(), x.end());

  int n = x.size();

  int i = 0;
  int transmitters = 0;

  while (i < n) {
    int mid = x[i] + k; // Find the furthest point to the right where to place
                        // the transmitter.

    while (i < n && x[i] <= mid) {
      ++i;
    }

    --i; // We walked one past the point where to place the transmitter
         // so let's go back.
    ++transmitters;
    std::cout << "Place transmitter at: " << x[i] << '\n';

    int end = x[i] + k; // Find the end of range for the transmitter
    while (i < n && x[i] <= end) {
      ++i;
    }
  }

  return transmitters;
}

int main() {
  std::vector<int> input = {2, 4, 5, 6, 7, 9, 11, 12};
  auto output = hackerland_radio_transmitters(input, 2);

  std::cout << "Minimum number of transmitters: " << output << '\n';
}