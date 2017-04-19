#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c){
    std::vector<std::vector<std::vector<int>>> dp_matrix (a.size()+1, std::vector<std::vector<int>>(b.size()+1,std::vector<int>(c.size(),0)));
    std::vector<int> tmp_vec(7);
    for (int i = 1; i <= a.size(); ++i)
        for (int j = 1; j <= b.size(); ++j)
	    for (int k = 1; k <= c.size(); ++k) {
	    	tmp_vec[0] = dp_matrix[i-1][j][k];
	    	tmp_vec[1] = dp_matrix[i][j-1][k];
		tmp_vec[2] = dp_matrix[i][j][k-1];
		tmp_vec[3] = dp_matrix[i-1][j-1][k];
		tmp_vec[4] = dp_matrix[i-1][j][k-1];
		tmp_vec[5] = dp_matrix[i][j-1][k-1];
	    	tmp_vec[6] = ( (a[i-1] == b[j-1]) && (b[j-1] == c[k-1]) && ( a[i-1] == c[k-1])) ? dp_matrix[i-1][j-1][k-1] + 1 : dp_matrix[i-1][j-1][k-1];
	    	dp_matrix[i][j][k] = *std::max_element(tmp_vec.begin(),tmp_vec.end());
	}
    return dp_matrix[a.size()][b.size()][c.size()];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
  }
