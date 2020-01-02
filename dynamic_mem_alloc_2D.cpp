#include <iostream>
using namespace std;

int main() {
	int row_length, colomn_length;
	cout << "Enter row_length : ";
	cin >> row_length;
	
	cout << "Enter colomn_length : ";
	cin >> colomn_length;	
	
	
	// dynamically create array of pointers of size row_length
	int **array_2D = new int*[row_length];
	
	// dynamically allocate memory of size colomn_length for each row
	for(int row_cnt = 0; row_cnt < row_length; row_cnt++ ) {
	    array_2D[row_cnt] = new int[colomn_length];
	}
	
	//assign values to allocated memory
	for(int row_cnt = 0; row_cnt < row_length; row_cnt++) {
	   for(int col_cnt = 0; col_cnt < colomn_length; col_cnt++) {
	      array_2D[row_cnt][col_cnt] = row_cnt + col_cnt; 
	   }
	    
	}
	
	//print 2D array
	for(int row_cnt = 0; row_cnt < row_length; row_cnt++) {
	   for(int col_cnt = 0; col_cnt < colomn_length; col_cnt++) {
	      cout << "A[" << row_cnt << "]" << "[" << col_cnt << "] :" << array_2D[row_cnt][col_cnt] <<"\n" ;
	   } 
	}
	
	// deallocating memory
	for(int row_cnt = 0; row_cnt < row_length; row_cnt++) {
	    cout << "deallocating array_2D[" << row_cnt << "]\n";
	    delete [] array_2D[row_cnt];
	}
	return 0;
}
