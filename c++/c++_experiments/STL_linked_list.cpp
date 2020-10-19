#include<iostream>
#include<list>

using namespace std;

int main() {

	list<int> numbers;

	//initialize list (doubly linked list)
	for (int index = 0; index != 5; index++) {
		numbers.push_back(index * 40);
	}

	//insert element in between the list, not at back or front
	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		if (*it == 40) {
			numbers.insert(++it, 314);
		}
	}

	//print list
	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		cout << *it << endl;
	}

	//erase an element from middle of list
	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		if (*it == 80) {
			it = numbers.erase(it);
		}
	}

	//print list
	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		cout << *it << endl;
	}

	system("pause");
	return 0;
}
