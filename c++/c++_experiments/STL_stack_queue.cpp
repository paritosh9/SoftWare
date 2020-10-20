//http://www.cplusplus.com/reference/queue/queue/
//http://www.cplusplus.com/reference/stack/stack/

#include<iostream>
#include<stack>
#include<queue>
#include<map>

using namespace std;

class Name {
	string name;

	public:
		//parameterized constructor
		Name(string name) :name(name) {

		}

		//destructor
		~Name() {
			//cout << "Destructor called" << endl;
		}

		void print() {
			cout << name.c_str() << endl;
		}
};

int main() {
	
	//LIFO
	stack<Name> nameStack;
	nameStack.push(Name("tom"));
	nameStack.push(Name("ted"));
	nameStack.push(Name("jeffu"));

	// iterate through stack so to say
	while (nameStack.size() > 0) {
		Name &name = nameStack.top();
		name.print();
		nameStack.pop();
	}

	cout << endl;
	//FIFO
	queue<Name> nameQueue;
	nameQueue.push(Name("tom"));
	nameQueue.push(Name("ted"));
	nameQueue.push(Name("jeffu"));

	//iterate through queue 
	cout << "back of queue : ";
	nameQueue.back().print();
	cout << endl ;
	
	while (nameQueue.size() > 0) {
		Name &name = nameQueue.front();
		name.print();
		nameQueue.pop();
	}

	system("pause");
	return 0;
}
