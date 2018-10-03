#include <stdio.h>
#include <malloc.h>

int n;
int *arr;
int *tmp;

void merge(int *arr, int left, int right, int mid) {
	int i = left; 
	int j = mid + 1; 
	int k = left; 

	while (i <= mid && j <= right) {
		if (arr[i] < arr[j]) {
			tmp[k] = arr[i];
			k++;
			i++;
		}
		else {
			tmp[k] = arr[j];
			k++;
			j++;
		}
	}

	while (i <= mid) {
		tmp[k] = arr[i];
		k++;
		i++;
	}

	while (j <= right) {
		tmp[k] = arr[j];
		k++;
		j++;
	}

	for (int l = left; l <= right; l++) {
		arr[l] = tmp[l];
	}
}

void mergeSort(int *arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid); 
		mergeSort(arr, mid + 1, right); 
		merge(arr, left, right, mid);
	}
}

int main(void) {
	
	scanf_s("%d", &n);

	arr = (int*)malloc(sizeof(int)*n);
	tmp = (int*)malloc(sizeof(int)*n);

	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &arr[i]);
	}

	mergeSort(arr, 1, n);

	for (int i = 1; i <= n; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}
