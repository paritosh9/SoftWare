/*
You are provided with a vector of  integers. Then, you are given  queries. For the first query, you are provided with  integer, which denotes a position in the vector. 
The value at this position in the vector needs to be erased. The next query consists of  integers denoting a range of the positions in the vector. 
The elements which fall under that range should be removed. The second query is performed on the updated vector which we get after performing the first query.
*/

//////////////////////////////////////////////
//////////////////////////////////////////////
//////////////////////////////////////////////
//////////////////////////////////////////////
//////////////////////////////////////////////

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int vector_size;
    vector<int> v0;

    cin >> vector_size;

    int tmp;
    for(int count = 0; count<vector_size; count++) {
        cin >> tmp;
        v0.push_back(tmp);
    }

    int index;
    cin >> index;

    v0.erase(v0.begin()+index - 1);

    int range_begin, range_end;
    cin >> range_begin >> range_end;

    v0.erase(v0.begin()+range_begin - 1, v0.begin()+range_end - 1);

    cout << v0.size() <<endl;
    for(auto it = v0.begin(); it != v0.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}
