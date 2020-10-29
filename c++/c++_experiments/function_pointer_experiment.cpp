//http://www.cplusplus.com/

#include<iostream>
#include<vector>
#include <string>
using namespace std;

// will use this function as function pointer to be passed to match_count
bool match(string str) {
	return str.size() == 4;
	//return str == one;
}

//consumes vector os srings and function pointer 
int match_count(vector<string> &strings, bool(*match)(string)) {
	int count = 0;
	for (auto text : strings) {
		if (match(text)) count++;
	}

	return count;
}

// Just a simple function to test function pointers
void test(int number, string str) {
	cout << "hello : " << number << " " << str << endl;
}

int main() {
	test(2, "tom");

	//Simple function pointer test
	void(*pfunc)(int, string) = test;
	pfunc(1,"jeffu");

	// Using vector string , function pointer, passing both to match_count function to count matches
	vector<string> strings{ "one", "two","three", "four", "five" };
	bool(*pMatch)(string) = match;

	cout << "match counts : " << match_count(strings, pMatch) << endl;

	// can just use function name as well it seems
	cout << "match counts : " << match_count(strings, match) << endl;

	system("pause");
	return 0;
}
