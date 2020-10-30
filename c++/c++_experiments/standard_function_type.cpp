//http://www.cplusplus.com/

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

//functor
class check_class {
	public:
		bool operator()(string str) {
			return str.size() == 2;
		}
} check_class_obj;

//function object
bool check(string str) {
	return str.size() == 5;
}

// using functional library ,function keyword
// run() function can be passed any function of type , return type bool and parameter string&
// it can be lambda expression, function pointer , functor
void run(function<bool(string&)> func) {
	string test = "dog";
	cout << endl << "in run function :" << func(test) << endl;
}

int main() {
	
	int size = 3;
	vector<string> strings{ "one", "two", "three" };

	auto lambda = [size](string test) { return test.size() == size;};

	// passing lambda expression to count_if from algorithm library
	int count = count_if(strings.begin(), strings.end(), lambda);
	cout << count << endl;

	// passing function pointer to count_if from algorithm library
	count = count_if(strings.begin(), strings.end(), check);
	cout << count << endl;

	// passing functor to count_if from algorithm library
	count = count_if(strings.begin(), strings.end(), check_class_obj);
	cout << count << endl;

	run(lambda);
	run(check);
	run(check_class_obj);


	system("pause");
	return 0;
}
