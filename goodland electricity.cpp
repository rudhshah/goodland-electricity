#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr, dist_to_next_tower;
	arr.resize(n);
	for (int j = 0; j < n; j++) {
		cin >> arr[j];
	}// filing the array
	int i = 0, max_range = 0, station = 0;
	int unchecked = 0;
	bool found = false;
	while (i < n) {
		max_range = min(n, i + k - 1);
		found = false;

		for (int r = max_range; r >= unchecked; r--) {
			if (arr[r] == 1) {
				i = r + k;
				found = true;
				unchecked = max_range + 1;
				station++;
				break;
			}
		}
		if (!found) {
			cout << "-1";
			return 0;

		}
	}//while

	cout << station;
	return 0;
}//end of main
