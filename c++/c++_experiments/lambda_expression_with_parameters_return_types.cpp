//http://www.cplusplus.com/

#include<iostream>
#include<string>
using namespace std;

// function accepting lambda with no parameters and return value
void test(void(*pfunc)()) {
	cout << endl;
	cout << "inside test function" << endl;
	pfunc();
}

// function accepting lambda with parameters and return value
void division(double(*pdivide)(double, double)) {
	double result1 = pdivide(10, 2);
	auto result2 = pdivide(10, 0);

	cout << "dividing 10 by 2 : " << result1 << endl;
	cout << "dividing 10 by 0 : " << result2 << endl;
}

int main() {
	
	// lambda expression with no variables, no return type
	auto func = []() { cout << "hello" << endl;};
	
	func();
	[]() { cout << "hello again" << endl;}();

	test(func);

	test([]() { cout << "hello again again" << endl;});

	//lambda expression with variables
	cout << endl << "lambda expression with variables" << endl;
	auto greet = [](string name) {cout << "hello " << name << endl;};
	greet("tom");

	//lambda expression with variables and trailing return type
	cout << endl << "lambda expression with variables and trailing return type" << endl;
	auto divide = [](double num, double den) -> double{
		if (den == 0) { 
			return 0; 
		}

		return num / den;
	};
	cout << "dividing 10.0 by 5.0 : " << divide(10.0, 5.0) << endl;
	cout << "dividing 10.0 by 0 : " << divide(10.0, 0) << endl;

	cout << endl;
	division(divide);

	system("pause");
	return 0;
}
