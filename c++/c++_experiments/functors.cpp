//http://www.cplusplus.com/

#include<iostream>
#include<vector>
using namespace std;

//super-class Test
class Test {
	public:
		virtual bool operator()(string &str) = 0;
		virtual ~Test() {};
};

//derived class from super-class Test with specific test method
class Match_Test_1 : public Test {
	public:
		//overriding operator () is functor
		bool operator()(string &str) {
			return str == "one";
		}
};

//derived class from super-class Test with specific test method
class Match_Test_2 : public Test {
	public:
		//overriding operator () is functor
		bool operator()(string &str) {
			return str == "two";
		}
};

//check function which uses functor
// use super-class Test reference and can use various derived match_test class objects to use various functor methods
//using polymorphism 
int check(vector<string> strings, Test &match) {
	int count = 0;
	for (auto text : strings) {
		//match(text) is not function but match object (Match_Test_1 or Match_Test_2 class) using overrided ()(string &str) operator
		if (match(text)) count++;
	}
	return count;
}

int main(){
	vector<string> numbers{ "one", "one", "two", "three" };
	Match_Test_1 match1;
	Match_Test_2 match2;

	cout << endl;
	int match_count1 = check(numbers, match1);
	cout << "match1 count : " << match_count1 << endl;

	cout << endl;
	int match_count2 = check(numbers, match2);
	cout << "match2 count : " << match_count2 << endl;

	system("pause");
	return 0;
}
