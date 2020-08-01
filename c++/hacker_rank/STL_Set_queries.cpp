/*
  : Add an element  to the set.
  : Delete an element  from the set. (If the number  is not present in the set, then do nothing).
  : If the number  is present in the set, then print "Yes"(without quotes) else print "No"(without quotes).

Input Format

The first line of the input contains  where  is the number of queries. The next  lines contain  query each. 
Each query consists of two integers  and  where  is the type of the query and  is an integer.

Sets are a part of the C++ STL. Sets are containers that store unique elements following a specific order

*/

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int num_queries;
    set<int> s0;

    cin >> num_queries;

    while(num_queries != 0) {
        int query_type;
        int value;
        cin >> query_type;
        cin >> value;

        if(query_type == 1){
            s0.insert(value);
        } else if(query_type == 2) {
            s0.erase(value);
        }else{
            set<int>::iterator itr = s0.find(value);
            if(itr != s0.end()) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
        num_queries--;
    }

    return 0;
}
