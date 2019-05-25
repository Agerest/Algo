#include "pch.h"
#include <cstdlib>
#include <windows.h>
#include <iostream>

using namespace std;

/*struct List {

	struct Element {
		char data;
		Element *nextElement;
	};

	Element *head = nullptr;
	unsigned int size = 0;

	void add(char data, unsigned int index) {
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

struct LinkedList {

	struct Element {
		char data;
		Element *nextElement;
		Element *prevElement;
	};

	Element *head = nullptr;
	Element *tail = nullptr;
	unsigned int size = 0;

	void add(char data, unsigned int index) {
		if (index > size) {
			cout << "Индекс за пределами списка" << endl;
			return;
		}
		Element *elem = new Element;
		elem->data = data;
		if (index == 0) {
			if (size == 0) {
				head = elem;
				tail = elem;
			}
			else {
				elem->nextElement = head;
				head = elem;
			}
		}
		else if (index == size) {
			tail->nextElement = elem;
			elem->prevElement = tail;
			tail = elem;
		}
		else {
			Element *prevElem = get(index - 1);
			Element *nextElem = prevElem->nextElement;

			elem->nextElement = nextElem;
			elem->prevElement = prevElem;

			nextElem->prevElement = elem;
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
		else if (index == size-1) {
			removeElem = tail;

			if (size > 1) {
				tail = tail->prevElement;
			}
		}
		else {
			removeElem = get(index);

			Element *nextElem = removeElem->nextElement;;
			Element *prevElem = removeElem->prevElement;;

			prevElem->nextElement = nextElem;
			nextElem->prevElement = prevElem;
		}
		delete[] removeElem;
		size--;
	}

	Element* get(unsigned int index) {
		if (index >= size) {
			cout << "Индекс за пределами списка" << endl;
			return nullptr;
		}
		Element *elem;
		if (index < size / 2) {
			elem = head;
			for (int i = 0; i < index; i++) {
				elem = elem->nextElement;
			}
		}
		else {
			elem = tail;
			for (int i = size - 1; i > index; i--) {
				elem = elem->prevElement;
			}
		}
		return elem;
	}
};

struct LoopList {

	struct Element {
		char data;
		Element *nextElement;
		Element *prevElement;
	};

	Element *head = nullptr;
	Element *tail = nullptr;
	unsigned int size = 0;

	void add(char data, unsigned int index) {
		if (index > size) {
			cout << "Индекс за пределами списка" << endl;
			return;
		}
		Element *elem = new Element;
		elem->data = data;
		if (index == 0) {
			if (size == 0) {
				head = elem;
				tail = elem;
			}
			else {
				elem->nextElement = head;
				head = elem;
			}
			tail->nextElement = head;
			head->prevElement = tail;
		}
		else if (index == size) {
			tail->nextElement = elem;
			elem->nextElement = head;
			elem->prevElement = tail;
			tail = elem;
		}
		else {
			Element *prevElem = get(index - 1);
			Element *nextElem = prevElem->nextElement;
			elem->nextElement = nextElem;
			elem->prevElement = prevElem;
			nextElem->prevElement = elem;
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
				head->prevElement = tail;
			}
		}
		else if (index == size-1) {
			removeElem = tail;
			if (size > 1) {
				tail = tail->prevElement;
				tail->nextElement = head;
			}
		}
		else {
			removeElem = get(index);
			Element *nextElem = removeElem->nextElement;
			Element *prevElem = removeElem->prevElement;
			prevElem->nextElement = nextElem;
			nextElem->prevElement = prevElem;
		}
		delete[] removeElem;
		size--;
	}

	Element* get(unsigned int index) {
		if (index >= size) {
			cout << "Индекс за пределами списка" << endl;
			return nullptr;
		}
		Element *elem;
		if (index < size / 2) {
			elem = head;
			for (int i = 0; i < index; i++) {
				elem = elem->nextElement;
			}
		}
		else {
			elem = tail;
			for (int i = size - 1; i > index; i--) {
				elem = elem->prevElement;
			}
		}
		return elem;
	}
};

int main5() {

	setlocale(LC_ALL, "rus");

	List list;
	LinkedList linkedList;
	LoopList loopList;

	char data;
	unsigned int index;

	int i = 0;
	do {
		cout << "1 - add to list" << endl;
		cout << "2 - delete from list" << endl;
		cout << "3 - get from list" << endl;
		cout << "4 - add to linked list" << endl;
		cout << "5 - delete from linked list" << endl;
		cout << "6 - get from linked list" << endl;
		cout << "7 - add to loop list" << endl;
		cout << "8 - delete from loop list" << endl;
		cout << "9 - get from loop list" << endl;
		cout << "0 - exit" << endl;
		cin >> i;
		switch (i)
		{
		case 1: {
			cout << "Введите элемент: " << endl;
			cin >> data;
			cout << "Введите индекс: " << endl;
			cin >> index;
			list.add(data, index);
			break;
		}
		case 4: {
			cout << "Введите элемент: " << endl;
			cin >> data;
			cout << "Введите индекс: " << endl;
			cin >> index;
			linkedList.add(data, index);
			break;
		}
		case 7: {
			cout << "Введите элемент: " << endl;
			cin >> data;
			cout << "Введите индекс: " << endl;
			cin >> index;
			loopList.add(data, index);
			break;
		}
		case 2: {
			cout << "Введите индекс: " << endl;
			cin >> index;
			list.remove(index);
			break;
		}
		case 5: {
			cout << "Введите индекс: " << endl;
			cin >> index;
			linkedList.remove(index);
			break;
		}
		case 8: {
			cout << "Введите индекс: " << endl;
			cin >> index;
			loopList.remove(index);
			break;
		}
		case 3: {
			cout << "Введите индекс: " << endl;
			cin >> index;
			if (list.get(index) == nullptr) {
				break;
			}
			data = list.get(index)->data;
			cout << "Элемент: " << data << endl;
			break;
		}
		case 6: {
			cout << "Введите индекс: " << endl;
			cin >> index;
			if (linkedList.get(index) == nullptr) {
				break;
			}
			data = linkedList.get(index)->data;
			cout << "Элемент: " << data << endl;
			break;
		}
		case 9: {
			cout << "Введите индекс: " << endl;
			cin >> index;
			if (loopList.get(index) == nullptr) {
				break;
			}
			data = loopList.get(index)->data;
			cout << "Элемент: " << data << endl;
			break;
		}
		default:
			break;
		}
	} while (i != 0);


	return 0;
}*/