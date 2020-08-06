/// WIP


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int number_of_lines, number_of_queries;
    string test;
    string key, value_name, value, tmp;
    map<string,string> hrml_map;
    cin >> number_of_lines;
    cin >> number_of_queries;

    cin >> test;
    string key_root = test.substr(1,sizeof(test)-1);
    cout << "key root - " << key_root << endl;
    cin >> value_name;
    key = key_root + "~" + value_name;
    cin >> tmp; cin >> value;
    int pos = value.find(">");
    int len_value = sizeof(value) ;
    cout << len_value << endl;
    string value2 = value.substr(1,pos-2);
    hrml_map[key] = value2;
    cout << key << " " << value << " " << hrml_map[key] << endl;


    cout << number_of_lines << " " << number_of_queries << " " << test << endl;

    return 0;
}
