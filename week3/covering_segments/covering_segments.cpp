#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool compare (Segment &a1, Segment &a2) { return a1.start < a2.start;}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  std::sort(segments.begin(),segments.end(),compare);
  size_t index = 0;
  int tmp_end = segments[index].end;
  int tmp_start;
  while (index < segments.size())
  {
      tmp_start = segments[index].start;
      if (tmp_start > tmp_end)
      {
           points.push_back(tmp_end);
           tmp_end = segments[index].end;
      }
      else if (segments[index].end < tmp_end)
      {
          tmp_end = segments[index].end;
      }
      ++index;
  }
  points.push_back(tmp_end);
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
