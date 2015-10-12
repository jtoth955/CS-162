/************************************************************************************
 *Filename: iterativeFib.cpp
 *Name: John R Toth
 *Date: 6/2/15
 *Description: iterativeFib implementation file
 ************************************************************************************/


#include <cstring>
#include <iostream>
#include <cstdlib>
#include <chrono>
#define ll long long
using namespace std; 
using namespace std::chrono;
 
//Borrowed code for this iterative fibonacci sequence from this site: http://bit.ly/1MqNbWj

/* 
 * Iterative function to find Fibonacci Numbers 
 */
ll fibo_iter(int n)
{
    if (n == 0)
            return 1;

    int previous = 1;
    int current = 1;
    int next = 1;
    for (int i = 3; i <= n; ++i) 
    {
        next = current + previous;
        previous = current;
        current = next;
    }
    return next;
}
int main()
{
    int fibNum = 100000, result = 0;
    
        high_resolution_clock::time_point t1 = high_resolution_clock::now();

        result = fibo_iter(fibNum);

        cout << "\nThe result of this iterative Fibonacci sequence was: " << result << endl;

        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double> >(t2 - t1);

        cout << "\nThis sequence took: " << time_span.count() << " seconds.";
        cout << endl;
    
    return 0;
}








