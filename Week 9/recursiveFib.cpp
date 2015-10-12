/************************************************************************************
 *Filename: recursiveFib.cpp
 *Name: John R Toth
 *Date: 6/2/15
 *Description: recursiveFib. implementation file
 ************************************************************************************/


#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Borrowed code for this recursive fibonacci sequence from this site: http://bit.ly/1M8CkzA

int fib(int);

int main()
{
    int fibNum = 40, result = 0;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    result = fib(fibNum);

    cout << "\nThe result of this recursive Fibonacci sequence was: " << result << endl;

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double> >(t2 - t1);

    cout << "\nThis sequence took: " << time_span.count() << " seconds.";
    cout << endl;
    
    return 0;
}
int fib(int num)
{
    if(num == 0)
    {
        
        return 0;
    }
    
    if(num == 1)
    {
       
        return 1;
    }
    
    int result = fib(num - 1) + fib(num - 2);
    
    return result;
}
