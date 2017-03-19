#include <iostream>
#include <vector>
/*
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
*/
long long get_fibonacci_huge_fast(long long n, long long m)
{
    std::vector<int> mod_vec;
    mod_vec.reserve(100);
    mod_vec.push_back(0);
    mod_vec.push_back(1);
    size_t index = 2;
    while (true)
    {
        mod_vec.push_back((mod_vec[index-2]+mod_vec[index-1])%m);
        if (mod_vec[index] == 1 and mod_vec[index-1] == 0)
            break;
        ++index;        
    }
    mod_vec.pop_back();
    mod_vec.pop_back();
    int periodicity = mod_vec.size();
    size_t periodic_index = n % periodicity;
    return mod_vec[periodic_index];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
