#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
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


long long get_fibonacci_partial_sum_fast(long long from, long long to) 
{
    int tmp = fibonacci_sum_fast(to)-fibonacci_sum_fast(from-1);
    if (tmp < 0)
        tmp = 10+tmp;
    return tmp;
}   

int main() {
    long long from, to;
    std::cin >> from >> to;
//    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
