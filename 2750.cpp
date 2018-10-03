#include <iostream>
using namespace std;

int main(void) {
	int n;
	int arr[1000];

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = n; i >= 2; i--) {
		int max = arr[i];
		int maxLoc = i;
		for (int j = 1; j <= i; j++) {
			if (arr[j] > max) {
				max = arr[j];
				maxLoc = j;
			}
		}
		swap(arr[i], arr[maxLoc]);
	}
	
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}