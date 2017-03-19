#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) 
{
    int *array = new int [n+1];
    array[0] = 0;
    array[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        array[i]=(array[i-1]+array[i-2]) % 10;
    }
    return array[n];
}

void test()
{
    int tmp_fast;
    int tmp_naive;
    for (int i = 0; i <= 30; ++i)
    {        
        tmp_fast = get_fibonacci_last_digit_fast(i);
        tmp_naive = get_fibonacci_last_digit_naive(i);
        if (tmp_fast != tmp_naive)
        {
            std::cout << tmp_fast << "!=" << tmp_naive << "\n";
            return;
        }
        std::cout << tmp_fast << "=" <<tmp_naive << "\n";
    }
    return;
}

int main() 
{   
    //test();
    int n;
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);
    //std::cout << c << '\n';
    int b = get_fibonacci_last_digit_fast(n);
    std::cout << b << '\n';
}
