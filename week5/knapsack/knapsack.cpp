#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &ws) {
    int tmp_compare;
    int n = ws.size();
    std::vector<std::vector<int>> dpw(W+1,std::vector<int>(n,0));
    for (int w = 0; w <= W; ++w) dpw[w][0] = 0;
    for (int ws_index = 0; ws_index <= n; ++ws_index) dpw[0][ws_index] = 0;
    for (int w = 1; w <=W; ++w)
        for (int ws_index = 1; ws_index <= n; ++ws_index){
	    dpw[w][ws_index] = dpw[w][ws_index-1];		
	    if (ws[ws_index-1] <= w){
		tmp_compare =  dpw[w-ws[ws_index-1]][ws_index-1] + ws[ws_index-1];
		dpw[w][ws_index] = (tmp_compare > dpw[w][ws_index]) ? tmp_compare : dpw[w][ws_index] ;
	    }
	}
    tmp_compare = dpw[W][n];
    return tmp_compare;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
