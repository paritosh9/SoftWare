//http://www.cplusplus.com/

#include<iostream>
using namespace std;

class Test {
	private:
		int one{ 1 };
		int two{ 2 };

	public:
		void run() {
			int three{ 3 };
			int four{ 4 };

			//auto plambda = [=, this]() {  // not allowed
			//auto plambda = [&, this]() {  // allowed
			//auto plambda = [three, this four]() { // allowed
			auto plambda = [three, four, this]() {  // this captures private data members by reference, cant change that to capture by value
				one = 111;
				cout << endl << "one : " << one << endl;
				cout << "two : " << two << endl;
				cout << "three : " << three << endl;
				cout << "four : " << four << endl;
			};
			plambda();
		}
};

int main() {
	int one = 1;
	int two = 2;
	int three = 3;

	//capturing local variables by value, cannot change values
	auto func = [=]() { cout << "one : " << one << "  two : " << two <<  "  three : " << three << endl;};
	func();

	//capturing by reference, can edit values of local variables
	auto func_ref = [&]() { cout << "one : " << one << "  two : " << two <<  "  three : " << three << endl; 
							one = 100; two = 200; cout << "one : " << one << "  two : " << two << "  three : " << three << endl;};

	func_ref();

	// mix of capture by value and reference, everything except three is captured by value
	auto func_mix = [= , &three]() {three = 300; cout << "one : " << one << "  two : " << two << "  three : " << three << endl;};
	func_mix();

	// mix of capture by value and reference, everything except two is captured by reference
	auto func_mix2 = [&, two]() {one = 999; cout << "one : " << one << "  two : " << two << "  three : " << three << endl;};
	func_mix2();

	// call Test
	Test test;
	test.run();

	system("pause");
	return 0;
}
