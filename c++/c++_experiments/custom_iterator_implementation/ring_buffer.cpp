//http://www.cplusplus.com/

#include<iostream>
#include"ring_buffer.h"

using namespace std;

int main() {
	ring<string> ring_buffer(3);
	ring_buffer.add("one");
	ring_buffer.add("two");
	ring_buffer.add("three");
	ring_buffer.add("four");
	ring_buffer.add("five");
	ring_buffer.add("six");

	for (int count = 0; count < ring_buffer.size(); count++) {
		cout << ring_buffer.display(count).c_str() << endl;
	}

	cout << endl;
	cout << "Using iterator" << endl;
	for (ring<string>::iterator it = ring_buffer.begin(); it !=  ring_buffer.end(); it++) {
		cout << *it << endl;
	}

	cout << endl;
	cout << "Using range based loop" << endl;
	for(auto str: ring_buffer) {
		cout << str << endl;
	}
	system("pause");
	return 0;
}
