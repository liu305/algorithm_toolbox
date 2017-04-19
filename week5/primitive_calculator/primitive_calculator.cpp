#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
    vector<int> minimum_opnums;
    vector<int> sequence;
    minimum_opnums.push_back(0);
    int tmp_minimum_opnum;
    int tmp_compare;
    for (int i=1; i<n; ++i) {
	tmp_minimum_opnum = n-1;
	if ((i+1)%2==0) {
	    tmp_compare = minimum_opnums[(i+1)/2-1];
	    tmp_minimum_opnum = (tmp_compare < tmp_minimum_opnum) ? tmp_compare : tmp_minimum_opnum;
	}
	if ((i+1)%3==0) {
	    tmp_compare = minimum_opnums[(i+1)/3-1];
	    tmp_minimum_opnum = (tmp_compare < tmp_minimum_opnum) ? tmp_compare : tmp_minimum_opnum;
	}
	tmp_compare = minimum_opnums[i-1];
	tmp_minimum_opnum = (tmp_compare < tmp_minimum_opnum) ? tmp_compare : tmp_minimum_opnum;
	minimum_opnums.push_back(tmp_minimum_opnum+1);
    }
    int index = n;
    int tmp_minimum_opnum_var;
    sequence.push_back(n);
    while (index > 1){
	tmp_minimum_opnum = index-1;
	if (index % 2 == 0 ) {
	    if (minimum_opnums[index/2-1] < tmp_minimum_opnum){
		tmp_minimum_opnum_var = index/2;
		tmp_minimum_opnum = minimum_opnums[index/2-1];
	    }
	}
	if (index % 3 == 0 ) {
	    if (minimum_opnums[index/3-1] < tmp_minimum_opnum){
	        tmp_minimum_opnum_var = index/3;
		tmp_minimum_opnum = minimum_opnums[index/3-1];
	    }
	}
	if (minimum_opnums[index-2] < tmp_minimum_opnum){
	    tmp_minimum_opnum_var = index-1;
	    tmp_minimum_opnum = minimum_opnums[index-2];
	}
	sequence.push_back(tmp_minimum_opnum_var);
	index = tmp_minimum_opnum_var;
    }
    std::sort(sequence.begin(),sequence.end());
    return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
