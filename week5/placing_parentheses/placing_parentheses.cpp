#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const std::string &exp) {
    int n = (exp.length()-1)/2;
    std::vector<std::vector<int>> max_matrix(n+1,std::vector<int>(n+1,0));
    std::vector<std::vector<int>> min_matrix(n+1,std::vector<int>(n+1,0));
    for (int i = 0; i <= n; i++) {
	max_matrix[i][i] = static_cast<int>(exp[2*i]) - 48;
	min_matrix[i][i] = static_cast<int>(exp[2*i]) - 48;
    }
    int tmp_min;
    int tmp_max;
    std::vector<int> tmp_vec(4);
    for (int slope_index = 1; slope_index <=n; ++slope_index)
	for (int i = 0; i <= n - slope_index; ++i){
	    tmp_min = std::numeric_limits<int>::max();
	    tmp_max = std::numeric_limits<int>::min();
	    for (int k = i; k <= i+slope_index-1; ++k) {
	    	tmp_vec[0] = eval(max_matrix[i][k],max_matrix[k+1][i+slope_index],exp[2*k+1]);
	    	tmp_vec[1] = eval(min_matrix[i][k],max_matrix[k+1][i+slope_index],exp[2*k+1]);
	    	tmp_vec[2] = eval(max_matrix[i][k],min_matrix[k+1][i+slope_index],exp[2*k+1]);
	    	tmp_vec[3] = eval(min_matrix[i][k],min_matrix[k+1][i+slope_index],exp[2*k+1]);
	    	for (auto &x : tmp_vec) {
		    if (x < tmp_min) tmp_min = x;
	    	    if (x > tmp_max) tmp_max = x;
		}
	    }
	    min_matrix[i][i+slope_index] = tmp_min;
	    max_matrix[i][i+slope_index] = tmp_max;
	}
    return max_matrix[0][n];
}

int main() {
  std::string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
