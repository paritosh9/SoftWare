#include<iostream>
#include<iomanip>
#include<map>

using namespace std;

class Person {
private:
	string name;
	int age;
public:
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

	// operator overloading since map needs to compare keys using < bool operator
	bool operator< (const Person &other_person) const{
		if (name == other_person.name) {
			return (age < other_person.age);
		}
		return (name < other_person.name) ;
	}

	void print() const{
		cout << setw(10) << "Name : " << name.c_str() << setw(10) << "Age : " << age << endl;
	}
};

int main() {
	// declare and initialize custom_map using Person as keys
	map<Person, int> custom_map;

	custom_map[Person("tom", 27)] = 27;
	custom_map[Person("teddy", 23)] = 23;
	custom_map[Person("tom", 37)] = 37;

	// print out custom_map
	for (map<Person, int>::iterator it = custom_map.begin(); it != custom_map.end(); it++) {
		it->first.print();
		cout << setw(10) << it->second << endl;
	}

	// use find() method of map STL class
	map<Person, int>::iterator it = custom_map.find(Person("tom", 27));
	if (it != custom_map.end()) {
		cout << "key found ";
		it->first.print();
	} else {
		cout << "key not found" << endl;
	}

	// use erase() method of map STL class
	custom_map.erase(it);
	cout << endl;
	// print out custom_map
	for (map<Person, int>::iterator it = custom_map.begin(); it != custom_map.end(); it++) {
		it->first.print();
		cout << setw(10) << it->second << endl;
	}

	// use insert() method of map STL class
	map<Person, int>::iterator it_insert = custom_map.find(Person("tom", 37));
	custom_map.insert(it_insert,pair<Person, int>(Person("jeffu", 15), 15));
	cout << endl;
	// print out custom_map
	for (map<Person, int>::iterator it = custom_map.begin(); it != custom_map.end(); it++) {
		it->first.print();
		cout << setw(10) << it->second << endl;
	}
	system("pause");
	return 0;
}
