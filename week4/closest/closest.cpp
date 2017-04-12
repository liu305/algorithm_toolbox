#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <cassert>

using std::vector;
using std::string;
using std::pair;
using std::min;

bool compare (std::pair<int,int> &a, std::pair<int,int> &b)
{
    return (a.first <= b.first);
}

bool compare_second (std::pair<int,int> &a, std::pair<int,int> &b)
{
    return (a.second <= b.second);
}

double recursive_closet_pair(vector<std::pair<int,int>> &points, int left, int right)
{
    if (left >= right) {return std::numeric_limits<double>::infinity();}
    if (left+1 == right)
    {
       return std::pow(std::pow(points[left].first-points[right].first,2) + std::pow(points[left].second-points[right].second,2),0.5);
    }
    int mid = (left+right)/2;
    double mid_x = points[mid].first;
    double dist_l = recursive_closet_pair(points, left, mid-1);
    double dist_r = recursive_closet_pair(points, mid, right);
    vector<std::pair<int,int>> middle_set;
    double min_dist = min(dist_l,dist_r);
    double dist_x = std::numeric_limits<double>::infinity();
    int set_a_index = mid-1;
    int set_b_index = mid;
    while (set_a_index >= left && mid_x-points[set_a_index].first <= min_dist)
    {
        middle_set.push_back(points[set_a_index]);
        set_a_index -= 1;
    }
    while (set_b_index <= right && points[set_b_index].first - mid_x <= min_dist)
    {
        middle_set.push_back(points[set_b_index]);
        set_b_index += 1;
    }
    double tmp_dist_x;
    std::sort(middle_set.begin(),middle_set.end(),compare_second);
    for (int i = 0; i < middle_set.size(); ++i) {
        int j = i-1;
        while (j >=0 && middle_set[i].second - middle_set[j].second <= min_dist)
        {
            tmp_dist_x = std::pow(std::pow((middle_set[i].second-middle_set[j].second),2) +
            std::pow((middle_set[i].first-middle_set[j].first),2), 0.5);
            if (tmp_dist_x < dist_x)
                dist_x = tmp_dist_x;
            --j;
        }
        j = i+1;
        while (j < middle_set.size() && middle_set[j].second - middle_set[i].second <= min_dist)
        {
            tmp_dist_x = std::pow(std::pow((middle_set[i].second-middle_set[j].second),2) +
            std::pow((middle_set[i].first-middle_set[j].first),2), 0.5);
            if (tmp_dist_x < dist_x)
                dist_x = tmp_dist_x;
            ++j;
        }            
    }
    return min(min_dist,dist_x);
}

double minimal_distance(vector<int> &x, vector<int> &y) {
    assert(x.size() == y.size());
    vector<std::pair<int,int>> points;
    for (size_t i=0; i<x.size(); ++i)
    {
        points.push_back(std::make_pair(x[i],y[i]));
    }
    std::sort(points.begin(), points.end(), compare);
    return recursive_closet_pair(points, 0, points.size()-1);
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
