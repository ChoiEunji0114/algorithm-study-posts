#include <iostream>
#define MAX 100000
using namespace std;

int cnt[MAX];

int main(void) {
	int n;
	scanf_s("%d", &n);

	int num;
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &num);
		cnt[num]++;
	}

	for (int i = 1; i < MAX; i++) {
		if (cnt[i]) {
			for (int j = 0; j < cnt[i]; j++) {
				printf("%d\n", i);
			}
		}
	}

	return 0;
}