//http://www.cplusplus.com/

#include<iostream>
using namespace std;

class Parent {
	private :
		int parent_id;
	public:
		//default constructor
		Parent() : parent_id(0) {
			cout << "Parent non parameterized constructor" << endl;
		}

		Parent(int num) : parent_id(num) {
			cout << "Parent parameterized constructor with num : " << num << endl;
		}

		//Copy constructor
		Parent(const Parent &other_parent) : parent_id(0) {
			parent_id = other_parent.parent_id;
			cout << "Copy constructor Parent" << endl;
		}

		//void print() {
		virtual void print() {
			cout << "Parent print method : " << parent_id << endl;
		}
		
		//virtual destructor
		virtual ~Parent() {}
};

class Child : public Parent {
	private :
		int child_id;
	public :
		//default child constructor
		Child() : child_id(1){
			cout << "Child non parameterized constructor" << endl;
		}

		Child(int num) : child_id(num) {
			cout << "Child parameterized constructor with num : " << num << endl;
		}

		void print() {
			cout << "Child print method : " << child_id << endl;
		}
};

int main() {
	Parent p1;
	Child c1;

	cout << endl;

	p1.print();
	c1.print();

	cout << endl;

	// parent pointer pointing to child 
	cout << "parent pointer pointing to child" << endl;
	Parent *p2 = &c1;
	p2->print();
	c1.print();
	
	cout << endl;

	//experimenting with copy constructor
	Parent p3 = Child();
	p3.print();

	cout << endl;
	Parent p_4(3);
	p_4.print();
	cout << "after copy " <<  endl;
	p_4 = Child(5);
	p_4.print();

	//parent reference to child object
	cout << endl;
	cout << "parent reference to child object" << endl;
	Child c_obj;
	Parent &p_ref = c_obj;
	p_ref.print();

	system("pause");
	return 0;
}
