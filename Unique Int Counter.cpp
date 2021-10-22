// Unique Int Counter
// 10.21.2021
// Amir Afunian

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Outputs each unique integer on the left side, with the amount of repeats on the right side.
//		If an int was not repeated, it has no count (per exercise instructions)
int main() {
	ifstream ifs{ "mydata.txt" };
	int temp;
	vector<int> store;
	while (true) {
		if (ifs.bad()) {
			cout << "Error! (1)\n";
			return -1;
		}
		if (ifs >> temp) {
			store.push_back(temp);
		}
		if (ifs.eof()) break;
	}
	sort(store.begin(), store.end());

	cout << "Sorted integers: ";
	for (int i = 0; i < store.size(); ++i) {
		cout << store[i] << ' ';
	}
	cout << '\n' << '\n';
	vector<int> cpy = store;

	int counter = 0;
	for (int i = 0; i < store.size(); ++i) {
		if (i != 0 && store[i] != store[i - 1]) {
			cout << store[i - 1] << '\t';
			for (int x : cpy) {
				if (store[i - 1] == x) ++counter;
			}
			if (counter > 1) cout << counter;
			cout << '\n';
			counter = 0;
		}
		if (i + 1 == store.size()) {
			cout << store[i] << '\t';
			for (int x : cpy) {
				if (store[i] == x) ++counter;
			}
			if (counter > 1) cout << counter;
			cout << '\n';
		}
	}

	return 0;
}