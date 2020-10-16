#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector< vector<int> > grid(4, {1, 2, 3, 4});
	grid[2].push_back(34);
	for (vector< vector<int> >::iterator row = grid.begin(); row != grid.end(); row++) {
		for (vector<int>::iterator col = (*row).begin(); col != (*row).end(); col++) {
			printf("%d ", (*col));
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
