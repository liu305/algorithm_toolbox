#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n)
{
    if (n <= 1)
        return n;
    int index = 2;
    int last_digit_sum = 1;
    int previous1 = 0;
    int previous2 = 1;
    int current;
    while (index <= n)
    {
        current = (previous1 + previous2) % 10;
        last_digit_sum = (last_digit_sum + current) % 10;
        previous1 = previous2;
        previous2 = current;
        ++index;
    }
    return last_digit_sum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n);
    std::cout << fibonacci_sum_fast(n);
}
