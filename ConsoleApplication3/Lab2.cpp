#include "pch.h"
#include <cstdlib>;
#include <windows.h>;
#include <iostream>

using namespace std;

/*struct someStruct {
	char firstName[10];
	char * secondName;
	unsigned long number;
	long * someArray;
	double length;
};

void initStruct(someStruct &t) {
	cout << "Инициализации структуры" << endl;
	t.secondName = new char[10];
}

void initSomeArray(someStruct *t) {
	cout << "Заполнение массива чисел" << endl;
	cout << "Введите количество элементов в массиве" << endl;
	cin >> t->length;
	t->someArray = new long[t->length];
	for (int i = 0; i < t->length; i++) {
		cout << "Введите элемент номер " << i << endl;
		cin >> t->someArray[i];
	}
}

void outSomeArray(someStruct &t) {
	cout << "Вывод на экран массива чисел" << endl;
	for (int i = 0; i < t.length; i++) {
		cout << t.someArray[i] << "\t";
	}
	cout << endl;
}

void initName(someStruct *t) {
	cout << "Ввод информации в строки имени и фамилии и другие поля" << endl;
	cout << "Введите имя" << endl;
	cin >> t->firstName;
	cout << "Введите фамилию" << endl;
	cin >> t->secondName;
	cout << "Введите ID" << endl;
	cin >> t->number;
}

void outName(someStruct &t) {
	cout << "Вывод на экран всех полей структуры, кроме массива чисел" << endl;
	cout << t.firstName << " " << t.secondName << " " << t.number << endl;
}

void deleteArrays(someStruct *t) {
	cout << "Освобождение динамической памяти" << endl;
	delete[] t->someArray;
	delete[] t->secondName;
}

int main2()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	someStruct objectStruct;
	someStruct *pointerStruct;

	pointerStruct = new someStruct[3];

	initStruct(objectStruct);
	initSomeArray(&objectStruct);
	initName(&objectStruct);
	outName(objectStruct);
	outSomeArray(objectStruct);

	for (int i = 0; i < 3; i++) {
		initStruct(pointerStruct[i]);
		initSomeArray(&pointerStruct[i]);
		initName(&pointerStruct[i]);
	}

	for (int i = 0; i < 3; i++) {
		outName(pointerStruct[i]);
		outSomeArray(pointerStruct[i]);
	}

	deleteArrays(&objectStruct);
	for (int i = 0; i < 3; i++) {
		deleteArrays(&pointerStruct[i]);
	}

	return 1;
}*/