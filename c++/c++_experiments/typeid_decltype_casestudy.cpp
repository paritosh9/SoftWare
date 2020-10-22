//http://www.cplusplus.com/

#include<iostream>

using namespace std;

template<class T>
auto counter(T count) -> decltype(count) {
	return count;
}

int main() {
	
	int value = 7;
	cout << typeid(value).name() << endl;

	decltype(value) count = 10;
	cout << "count : " << count << endl;

	cout << "counter value : " << counter(33) << endl;;
	cout << "counter value : "  << counter("hello") << endl;


	system("pause");
	return 0;
}
