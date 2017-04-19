#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::string;

int edit_distance(const string &str1, const string &str2) {
	std::vector<std::vector<int>> ed_matrix(str1.length()+1,std::vector<int>(str2.length()+1,0));
	int tmp1, tmp2, tmp3;
	for (int i = 0; i <= str1.length(); ++i) {ed_matrix[i][0] = i;}
	for (int j = 0; j <= str2.length(); ++j) {ed_matrix[0][j] = j;}
	for (int i = 1; i <= str1.length(); ++i)
	    for (int j = 1; j<= str2.length(); ++j){
		tmp1 = ed_matrix[i][j-1]+1;
		tmp2 = ed_matrix[i-1][j]+1;
		tmp3 = (str1[i-1] == str2[j-1]) ? ed_matrix[i-1][j-1] : ed_matrix[i-1][j-1]+1;
		ed_matrix[i][j] = std::min(std::min(tmp1,tmp2),tmp3);
	    }
	return ed_matrix[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
