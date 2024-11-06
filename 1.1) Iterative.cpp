#include<iostream>
using namespace std;

int fibonacciIterative(int n){
	if (n<=1)
	    return n;
	    
	int prev = 0, curr = 1;
	for (int i=2; i<=n; i++){
		int next = prev + curr;
		prev = curr;
		curr = next;
		cout<<next<<" ";
	}
	return curr;
}

int main() {
	int n;
	cout << "Enter the value of n for the nth Fibnoacci number: ";
	cin >> n;
	
	if (n<0){
		cout << "Invalid input. Please enter a non-negative integer." << endl;
		return 1;
	}
	
	cout<<"Fibonacci Sequence: ";
	int result = fibonacciIterative(n);
	cout<< "\nThe " <<n<<" th Fibonacci number is: " << result << endl;
	
	return 0; 
}
