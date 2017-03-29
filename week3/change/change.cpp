#include <iostream>

int get_change(int m) {
  int num_coins = 0;
  while (m > 0) {
      if ( m >= 10)
      {
        num_coins = num_coins + m / 10;
        m = m - m / 10 * 10;
      }
      else if (m >= 5)
      {
          num_coins = num_coins + m / 5;
          m = m - m / 5 * 5;
      }
      else
      {
          num_coins = num_coins + m;
          m = 0;
      }
  } 

  return num_coins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
