#include "pch.h"
#include <cstdlib>
#include <windows.h>
#include <iostream>
#include <ctime>

using namespace std;

/*void partition(int *arr, int begin, int end) {
	int middle = arr[(begin + end) / 2];
	int left = begin, rigth = end;
	int temp;

	do {

		while (arr[left] < middle) {
			left++;
		}

		while (arr[rigth] > middle) {
			rigth--;
		}

		if (left <= rigth) {
			temp = arr[left];
			arr[left] = arr[rigth];
			arr[rigth] = temp;
			left++;
			rigth--;
		}

	} while (left <= rigth);

	if (begin < rigth) {
		partition(arr, begin, rigth);
	}

	if (end > left) {
		partition(arr, left, end);
	}
}

void quickSort(int *arr, int length) {
	partition(arr, 0, length - 1);
}

void insertSort(int a[], int length) {
	int x;
	int j = 0;

	for (int i = 0; i < length; i++) {
		x = a[i];

		for (j = i - 1; j >= 0 && a[j] > x; j--)
			a[j + 1] = a[j];

		a[j + 1] = x;
	}
}

void main() {
	const int LENGTH = 15;

	setlocale(LC_ALL, "rus");

	srand(time(NULL));
	int* array = new int[LENGTH];
	cout << "Заполнение массива случайными элементами" << endl;
	for (int i = 0; i < LENGTH; i++) {
		array[i] = rand();
		cout << array[i] << "\t";
	}
	cout << endl << "quick sort" << endl;
	quickSort(array, LENGTH);
	for (int i = 0; i < LENGTH; i++) {
		cout << array[i] << "\t";
	}
	cout << endl << "Заполнение массива случайными элементами" << endl;
	for (int i = 0; i < LENGTH; i++) {
		array[i] = rand();
		cout << array[i] << "\t";
	}
	cout << endl << "insert sort" << endl;
	insertSort(array, LENGTH);
	for (int i = 0; i < LENGTH; i++) {
		cout << array[i] << "\t";
	}
}*/