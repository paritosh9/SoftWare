#include<iostream>
#include<iomanip>
#include<map>

using namespace std;


int main() {
	
	// define and initialize muti-map
	multimap<int, string> mmap;
	mmap.insert(make_pair(15, "jeffu"));
	mmap.insert(make_pair(25, "tigu"));
	mmap.insert(make_pair(25, "tigs"));
	mmap.insert(make_pair(25, "zebra"));
	mmap.insert(make_pair(35, "tom"));
	
	// print mmap 
	for (multimap<int, string>::iterator it = mmap.begin(); it != mmap.end(); it++) {
		cout << "age : " << it->first << ", name : " << it->second.c_str() << endl;
	}
	cout << endl;

	// equal_range() method to return the bounds of a range that includes all the elements in the container which have a key equivalent to k
	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> it = mmap.equal_range(25);
	cout << "All keys 25" << endl;
	// print mmap for the range 
	for (multimap<int, string>::iterator its = it.first; its != it.second; its++) {
		cout << "age : " << its->first << ", name : " << its->second.c_str() << endl;
	}

	system("pause");
	return 0;
}
