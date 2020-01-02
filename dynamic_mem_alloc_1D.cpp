#include <iostream>
using namespace std;

int main() {
	int array_size;
	cout << "Enter size of array : ";
	cin >> array_size;
	
	//dynamically allocate memory
	int *A = new int[array_size];
	
	//assign values to allocated memory
	for(int cnt = 0; cnt < array_size; cnt++){
	    A[cnt] = cnt;
	}
	
	//print 1D array
	for(int cnt = 0; cnt < array_size; cnt++){
	    cout << "A[" << cnt << "] :" << A[cnt] <<"\n" ;
	}
	
	return 0;
}
