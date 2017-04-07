#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

//int get_majority_element(vector<int> &a, int left, int right) {
int get_majority_element(vector<int> &a) {
    std::unordered_map<int,int> dict;
    for (auto &x : a)
    {
        if (dict.count(x) == 0){dict[x] = 1;}
        else {dict[x] = dict[x]+1;}
    }
    for (auto &x : dict)
    {
        if (x.second > a.size()/2)
            return 1;
    }
    return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a)) << '\n';
  //std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
