#include<iostream>
#include<iomanip>
#include<map>

using namespace std;

class Person {
	private :
		string name;
		int age;
	public :
		// default constructor 
		Person() {
		
		}

		// Parameterized constrcutor
		Person(string name, int age) : name(name), age(age) {

		}

		// copy constructor 
		Person(const Person &original_person) {
			name = original_person.name;
			age = original_person.age;
		}

		void print() {
			cout  << setw(10) << "Name : " << name.c_str() << setw(10) << "Age : " << age << endl;
		}
};

int main() {

	map<int, Person> custom_map;

	custom_map[12] = Person("tom", 27);
	custom_map[2] = Person("teddy", 23);

	//experiment with inserting in map
	for (map<int, Person>::iterator it = custom_map.begin(); it != custom_map.end(); it++) {
		cout << setw(10) << "Key : " << it->first;
		it->second.print();
	}

	custom_map.insert(make_pair(55, Person("jeffu", 15)));
	cout << endl;

	// print key values of custom_map
	for (map<int, Person>::iterator it = custom_map.begin(); it != custom_map.end(); it++) {
		cout << setw(10) << "Key : " << it->first;
		it->second.print();
	}

	pair<int, Person> new_elem(66, Person("tigu", 16));
	custom_map.insert(new_elem);
	cout << endl;

	// print key values of custom_map
	for (map<int, Person>::iterator it = custom_map.begin(); it != custom_map.end(); it++) {
		cout << setw(10) << "Key : " << it->first;
		it->second.print();
	}

	// experiment with finding and erasing from map
	map<int,Person>::iterator it = custom_map.find(2);
	custom_map.erase(it);
	cout << endl;

	// print key values of custom_map
	for (map<int, Person>::iterator it = custom_map.begin(); it != custom_map.end(); it++) {
		cout << setw(10) << "Key : " << it->first;
		it->second.print();
	}

	system("pause");
	return 0;
}
