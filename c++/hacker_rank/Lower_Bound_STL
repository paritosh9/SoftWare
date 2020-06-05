#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int vector_length;
    int input;
    
    cin >> vector_length;
    
    std::vector<int> v;
    for(int count = 0; count < vector_length; count++) {
        cin >> input;
        v.push_back(input);
    } 

    //for(std::vector<int>::const_iterator i = v.begin(); i != v.end(); i++){
        //cout << *i <<endl;
    //}

    std::vector<int>::iterator it;

    int query_len;
    cin >> query_len;
    for(int count = 0; count < query_len; count++) {
        cin >> input;
        it = std::lower_bound(v.begin(), v.end(), input);
        if(*it == input){
            cout << "Yes " << (it - v.begin()+1) << endl;
        }
        else {
            cout << "No " << (it - v.begin()+1) << endl;
        }
    }

    return 0;
}
