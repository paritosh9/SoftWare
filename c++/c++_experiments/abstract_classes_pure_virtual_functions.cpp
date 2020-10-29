//http://www.cplusplus.com/

#include<iostream>
using namespace std;

// base , super-class, which is abstract class since it has pure virtual functions
class Animal {
public:
	virtual void run() = 0;
	virtual void speak() = 0;
};

//derived class Dog, it is abstract as well since it did provide implementation for pur virtual method speak()
class Dog : public Animal {
	public:
		void run() {
			cout << "Dog running" << endl;
		}
};

//concrete class, derived from Dog
class Labrador : public Dog {
	public:
		void speak() {
			cout << "Labrador barking" << endl;
		}
};

// test function which takes reference to animal object as parameter, super class can point or refer to dereived classes, in this case Dog, Labrador
void test(Animal &animal) {
	animal.run();
	animal.speak();
}

int main() {
	//cannot insantiate abstract classes
	// Animal animal;
	//Dog dog;

	//Instantiate concrete classes
	Labrador labrador;
	labrador.run();
	labrador.speak();

	//array of pointers to Animal class, it can point to concrete derived class objects (Labrador)
	Animal *animals[4];
	animals[0] = &labrador;
	
	cout << endl << endl;
	animals[0]->run();
	animals[0]->speak();

	cout << endl << endl;

	// super-class Animal can refer to derived class object and can be used as parameter passed as reference to a function
	test(labrador);

	system("pause");
	return 0;
}
