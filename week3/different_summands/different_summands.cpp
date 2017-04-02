#include <iostream>
#include <vector>

using std::vector;


vector<int> optimal_summands(int n) {
  vector<int> summands;
  int leftover = n;
  int current_num = 1;
  while (leftover > 2*current_num)
  {
      summands.push_back(current_num);
      leftover -= current_num;
      current_num += 1;

  }
  summands.push_back(leftover);
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
