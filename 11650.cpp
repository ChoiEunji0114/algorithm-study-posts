/*
백준 11650
좌표 정렬하기 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
	if (b.first > a.first) {
		return true;
	}
	else if (b.first == a.first) {
		if (b.second > a.second) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main(void) {
	int n;
	vector <pair<int, int>> v;

	scanf_s("%d", &n);
	v.resize(n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &v[i].first, &v[i].second);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}

	return 0;
}
