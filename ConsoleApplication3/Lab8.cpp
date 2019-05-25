#include "pch.h"
#include <cstdlib>
#include <windows.h>
#include <iostream>

using namespace std;

struct List {

	struct Element {
		int data;
		Element *nextElement;
	};

	Element *head = nullptr;
	unsigned int size = 0;

	void add(int data, unsigned int index) {
		if (index > size) {
			cout << "Индекс за пределами списка" << endl;
			return;
		}
		Element *elem = new Element;
		elem->data = data;
		if (index == 0) {
			if (size == 0) {
				head = elem;
			}
			else {
				elem->nextElement = head;
				head = elem;
			}
		}
		else {
			Element *prevElem = get(index - 1);

			elem->nextElement = prevElem->nextElement;
			prevElem->nextElement = elem;
		}
		size++;
	}

	void remove(unsigned int index) {
		if (index >= size) {
			cout << "Индекс за пределами списка" << endl;
			return;
		}
		Element *removeElem;
		if (index == 0) {
			removeElem = head;

			if (size > 1) {
				head = head->nextElement;
			}
		}
		else {
			Element *prevElem = get(index - 1);
			removeElem = prevElem->nextElement;
			prevElem->nextElement = removeElem->nextElement;
		}
		delete[] removeElem;
		size--;
	}

	Element* get(unsigned int index) {
		if (index >= size) {
			cout << "Индекс за пределами списка" << endl;
			return nullptr;
		}
		Element *elem = head;
		for (int i = 0; i < index; i++) {
			elem = elem->nextElement;
		}
		return elem;
	}
};

int lineSearch(int *arr, int length, int key) {

	for (int i = 0; i < length; i++) {

		if (arr[i] == key) {
			return i;
		}

	}

	return -1;
}

int lineSearch(List *list, int key) {

	for (int i = 0; i < list->size; i++) {

		if (list->get(i)->data == key) {
			return i;
		}

	}

	return -1;
}

int binarySearch(int *arr, int length, int key) {
	int mid, left = 0, rigth = length - 1;

	while (left != rigth) {
		mid = left + (rigth - left) / 2;

		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] < key) {
			left = mid;
		}
		else if (arr[mid] > key) {
			rigth = mid;
		}
	}

	return -1;
}

int binarySearch(List *list, int key) {
	int mid, left = 0, rigth = list->size - 1;

	while (left != rigth) {
		mid = left + (rigth - left) / 2;

		if (list->get(mid)->data == key) {
			return mid;
		}
		else if (list->get(mid)->data < key) {
			left = mid;
		}
		else if (list->get(mid)->data > key) {
			rigth = mid;
		}
	}

	return -1;
}

void partition(int *arr, int begin, int end) {
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

void main() {
	const int LENGTH = 15;

	setlocale(LC_ALL, "rus");

	List list;
	int arr[LENGTH];
	int result;
	int key;
	cout << "Заполнение массива случайными элементами" << endl;
	for (int i = 0; i < LENGTH; i++) {
		arr[i] = rand();
		cout << arr[i] << "\t";
	}
	cout << endl << "Элемент, который нужно найти в массиве:" << endl;
	cin >> key;
	result = lineSearch(arr, LENGTH, key);
	cout << "Линейный поиск: " << result << endl;
	quickSort(arr, LENGTH);
	result = binarySearch(arr, LENGTH, key);
	cout << "Бинарный поиск: " << result << endl;
	cout << endl << "Заполнение списка случайными элементами" << endl;
	for (int i = 0; i < LENGTH; i++) {
		int data = rand();
		list.add(data, i);
		cout << data << "\t";
	}
	cout << endl << "Элемент, который нужно найти в списке:" << endl;
	cin >> key;
	result = lineSearch(&list, key);
	cout << "Линейный поиск: " << result << endl;
}