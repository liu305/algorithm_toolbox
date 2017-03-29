#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
#include <algorithm>

using std::vector;

bool pairCompare(const std::pair<size_t,double> &a, const std::pair<size_t,double> &b)
{
    return a.second < b.second;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  assert (weights.size() == values.size());
  vector<std::pair<size_t,double>> index_density(weights.size());
  for (int i = 0; i < weights.size(); ++i)
  {
      index_density.push_back(std::make_pair(i,static_cast<double>(values[i])/static_cast<double>(weights[i])));
  }
  std::sort(index_density.begin(),index_density.end(),pairCompare);
  while (capacity > 0)
  {
      auto &tmp = index_density.back();
      if (weights[tmp.first] <= capacity)
      {
          capacity -= weights[tmp.first];
          value += values[tmp.first];
      }
      else
      {
          value += capacity * tmp.second;
          capacity = 0;          
      }
      index_density.pop_back();
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
