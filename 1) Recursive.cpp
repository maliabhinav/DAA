#include<iostream>
using namespace std;

int fibonacciRecursive(int n)  {
	if (n<=1)
	    return n;
	return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

int main() {
	int n;
	cout<<"Enter the value of n for the nth Fibonacci number: ";
	cin>>n;
	
	if (n<0) {
		std::cout<<"Invalid input. Please enter a non-negative integer." << endl;
		return 1;
	}
	
	int result = fibonacciRecursive(n);
	cout<<"The" <<n<< "th Fibonacci number is: " <<result<< endl;
	
	return 0;
}
