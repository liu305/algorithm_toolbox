#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <algorithm>

using std::vector;

bool larger(const int &a, const int &b) {return a>b;}

int binary_search_start(vector<int> &src, int target)
{
    int left = 0;
    int right = src.size()-1;
    int target_index;
    if (src[left] > target) {return 0;}
    if (src[right] <= target) {return src.size();}
    while (left <= right)
    {
        int mid = (left+right)/2;
        if (src[mid] <= target &&  src[mid+1] > target) {return mid+1;}
        else if (src[mid] <= target) {left = mid+1;}
        else {right = mid-1;}
    }
    return -1;
}

int binary_search_end(vector<int> &src, int target)
{
    int left = 0;
    int right = src.size()-1;
    int target_index;
    if (src[right] >= target) {return src.size();}
    if (src[left] < target) {return 0;}
    while (left <= right)
    {
        int mid = (left+right)/2;
        if (src[mid] >= target && src[mid+1] < target) {return mid+1;}
        else if (src[mid] >= target) {left = mid+1;}
        else {right = mid-1;}
    }
    return -1;
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt;
  cnt.reserve(points.size());
  assert(starts.size() == ends.size());
  std::sort(starts.begin(), starts.end());
  std::sort(ends.begin(), ends.end(), larger);
  for (auto &x : points)
  {
      cnt.push_back(binary_search_start(starts,x)+binary_search_end(ends,x)-starts.size());
  }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
