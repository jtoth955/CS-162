/************************************************************************************
 *Filename: Lab10_Factorial.cpp
 *Name: John R Toth
 *Date: 6/1/15
 *Description: Lab10_Factorial implementation file
 ************************************************************************************/

#include <iostream>
#include <ctime> 
#include <time.h>
#include <chrono>

using namespace std; 
using namespace std::chrono;


//not tail recursive
int rFactorial (int n);

//tail recursive
long factorialHelper(int, int);
long factorial(int);
    
//This code was borrowed from the professor and can be found attached to the Lab instructions

int main() {

	long num = 250000, tailResult = 0, ntailResult = 0, result = 0;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();

//not tail-recursive:
	ntailResult = rFactorial(num);

	cout << "\nnon tail recursive result: " << ntailResult << endl;

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double> >(t2 - t1);
    	cout << "The non tail recursive factorial took:" << time_span.count() << " seconds.\n";


 //Tail recursive: 
    high_resolution_clock::time_point t3 = high_resolution_clock::now();
    result = factorial(num);
    tailResult = factorialHelper(num, result);

    cout << "\nTail recursive result: "<< tailResult << endl;

    high_resolution_clock::time_point t4 = high_resolution_clock::now();
	duration<double> time_span2 = duration_cast<duration<double> >(t4 - t3);
    cout << "The tail recursive factorial took:" << time_span.count() << " seconds.";

	return 0; 
}
//not tail-recursive
int rFactorial (int n) {
    
    if(n == 1)
    {
        return 1;
    }
    else
    {    	
        return n* rFactorial(n-1);
	}
	

}
//tail recursive
long factorialHelper(int n, int result) {
    
    if(n == 1)
    {
        return result;
    }
    else
        return factorialHelper(n-1, n*result);
}
long factorial(int n) {
        if(n == 0)
        {
            return 1;
        }
    return factorialHelper(n, 1);
}








