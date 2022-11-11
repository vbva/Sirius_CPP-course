#include <iostream>
#include <vector>
#include <chrono>
#include "prime_head.h"
using namespace std;

int main ()
{
 vector<int> prime_arr;
 int n, count;

 cout << "Enter the number:" << endl;
 cin >> n;

 auto start = chrono::steady_clock::now();
 for (int i = 0; i <= n; ++i)

     if (prime(i))
     {
         prime_arr.push_back(i);
//         cout << i << endl;

     }

 count = prime_arr.size();

 auto end = chrono::steady_clock::now();    auto elapsed = end - start;
 cout << "Time = " << chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count() / 1e9 << " seconds" << std::endl;
 cout << "Quantity of prime number from 2 to n: " << count << endl;
}

