#include <stack>
#include <map>
class Solution {
public:
    map<char, char> validity_map = {
        {'(',')'},
        {'{','}'},
        {'[',']'}
    };
    
    stack<char> parentheses;
    
    bool isValid(string s) {
        //cout << "string length : " << s.length() << endl;
        for(auto i:s) {
           //cout << i << endl; 
           if(validity_map[i]) {
               //cout << "exists" << endl;
               parentheses.push(i);
           }else if(parentheses.size() == 0){
               return 0;   
           }else if(i == validity_map[parentheses.top()]) {
               parentheses.pop();
           }else {
               return 0;
           }
        }
        return !parentheses.size();
    }
};
