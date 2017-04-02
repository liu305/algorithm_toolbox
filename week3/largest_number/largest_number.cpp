#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool compare (string &a1, string &a2)
{
    string concat1 = a1+a2;
    string concat2 = a2+a1;
    for (int i=0; i < concat1.size(); ++i)
    {
        if (concat1.at(i) < concat2.at(i)) {return false;}
        else if (concat1.at(i) > concat2.at(i)) {return true;}
    }
    return true;
}

/*
bool compare (string &a1, string &a2)
{
    size_t min_length = (a1.length() < a2.length()) ? a1.length() : a2.length();
    string common{};
    for (int i = 0; i < min_length; ++i)
    {
        if (a1.at(i) < a2.at(i)) {return false;}
        else if (a1.at(i) > a2.at(i)) {return true;}
        else 
        {
            common += a1.at(i);
            continue;
        }
    }
    string remain {};
    if (a1.length() < a2.length())
    {
        remain = a2.substr(a1.length());
        return compare(common,remain);
    }
    else if (a1.length() > a2.length())
    {
        remain = a1.substr(a2.length());
        return compare(remain,common);
    }
    else {return true;} 
}
*/

string largest_number(vector<string> a) {
  std::sort (a.begin(), a.end(), compare);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
