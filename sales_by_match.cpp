#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::set;
using std::unordered_map; 
using std::cout;

int sockMerchant(int n, vector<int> ar);

int main()
{
    vector<int> ar = {1, 2, 1, 2, 1, 3, 2};
    cout << sockMerchant(7, ar);
    return 0;
}

int sockMerchant(int n, vector<int> ar)
{
    // Steps:
    // 1. Create a hashmap; keys will be the colors in ar and values will be their occurence
    unordered_map<int, int> my_map;

    // 2. Count occurence of each number in ar
    for (const auto &key: ar) {
        // create new_key with value 1 if key does not exist in hashmap
        // otherwise increment value at key with 1
        my_map[key]++;
    }

    // 3. Count number of pairs
    int pairs = 0;
    for (const auto &[color, occ]: my_map) {
        pairs += (occ / 2);
    }

    return pairs;
}