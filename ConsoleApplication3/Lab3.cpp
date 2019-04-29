#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <cstdlib>
#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdarg.h>
#include <stdlib.h>

using namespace std;

struct someStruct {
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

void initName(someStruct *t) {
	cout << "Ввод информации в строки имени и фамилии и другие поля" << endl;
	cout << "Введите имя" << endl;
	cin >> t->firstName;
	cout << "Введите фамилию" << endl;
	cin >> t->secondName;
	cout << "Введите ID" << endl;
	cin >> t->number;
}

void writeToTextFile(someStruct &s, FILE *file) {
	fprintf(file, "%ul\n%s\n%s\n%lf\n", s.number, s.firstName, s.secondName, s.length);
	for (double i = 0; i < s.length; i += 1.0) {
		fprintf(file, "%ld; ", s.someArray[(int)i]);
	}
}

void writeToBinaryFile(someStruct &s, FILE *file) {
	fwrite((&s.number), sizeof(s.number), 1, file);
	fwrite((&s.firstName), sizeof(s.firstName), 1, file);
	fwrite((&s.secondName), sizeof(s.secondName), 1, file);
	fwrite((&s.length), sizeof(s.length), 1, file);
	fwrite((&s.someArray), s.length * sizeof(s.someArray), s.length, file);
}

void readTextFile(someStruct &s, FILE *file) {
	fscanf(file, "%ul\n%s\n%s\n%lf\n", &s.number, s.firstName, s.secondName, &s.length);
	cout << "ffffffffffffffffffffffffff:   " << s.length << endl;
	s.someArray = new long[s.length];
	for (double i = 0; i < s.length; i += 1.0) {
		fscanf(file, "%ld; ", &s.someArray[(int)i]);
	}
}

/*void readTextFile(someStruct &s, FILE *file) {
	fscanf(file, "Number: %d\n", &s.number);
	fscanf(file, "First name: %s\n", s.firstName);
	fscanf(file, "Second name: %s\n", s.secondName);
	fscanf(file, "Length: %f\n", &s.length);
	s.someArray = new long[s.length];
	for (int i = 0; i < s.length; i++) {
		fscanf(file, "%d; ", &s.someArray[i]);
	}
}

void writeToTextFile(someStruct &s, FILE *file) {
	fprintf(file, "Number: %d\nFirst name: %s\nSecond name: %s\nLength: %f\n", s.number, s.firstName, s.secondName, s.length);
	for (int i = 0; i < s.length; i++) {
		fprintf(file, "%d; ", s.someArray[i]);
	}
}*/

void readBinaryFile(someStruct &s, FILE *file) {
	fread((&s.number), sizeof(s.number), 1, file);
	fread((&s.firstName), sizeof(s.firstName), 1, file);
	fread((&s.secondName), sizeof(s.secondName), 1, file);
	fread((&s.length), sizeof(s.length), 1, file);
	fread((&s.someArray), s.length * sizeof(s.someArray), s.length, file);
}

void outSomeArray(someStruct &t) {
	cout << "Вывод на экран массива чисел" << endl;
	for (int i = 0; i < t.length; i++) {
		cout << t.someArray[i] << "\t";
	}
	cout << endl;
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

int main()
{
	setlocale(LC_ALL, "rus");

	FILE* file;
	someStruct *writeStruct = new someStruct[3];
	someStruct *readTextStruct = new someStruct[3];
	someStruct *readBinaryStruct = new someStruct[3];

	cout << "Ввести данные в элементы первого динамического массива с помощью функций, разработанных в лабораторной работе №2" << endl;
	for (int i = 0; i < 3; i++) {
		initStruct(writeStruct[i]);
		initSomeArray(&writeStruct[i]);
		initName(&writeStruct[i]);
	}

	cout << "Сохранить содержимое элементов массива структур в текстовом и двоичном файлах" << endl;
	for (int i = 0; i < 3; i++) {
		char *fileName = new char[100];
		sprintf(fileName, "text%d", i);
		file = fopen(fileName, "wt");
		writeToTextFile(writeStruct[i], file);
		fclose(file);
		cout << i << " структура была записана в текстовый файл" << endl;
		sprintf(fileName, "binary%d", i);
		file = fopen(fileName, "wb");
		writeToBinaryFile(writeStruct[i], file);
		fclose(file);
		cout << i << " структура была записана в двоичный файл" << endl;
	}

	cout << "Считать содержимое текстового файла в элементы второго массива и вывести на экран. Сравнить содержимое первого и второго массивов" << endl;
	for (int i = 0; i < 3; i++) {
		char *fileName = new char[100];
		sprintf(fileName, "text%d", i);
		file = fopen(fileName, "rt");
		initStruct(readTextStruct[i]);
		readTextFile(readTextStruct[i], file);
		fclose(file);
		cout << i << " структура была считана из текстового файла" << endl;
	}
	cout << "Первый массив" << endl;
	for (int i = 0; i < 3; i++) {
		outName(writeStruct[i]);
		outSomeArray(writeStruct[i]);
	}
	cout << "Второй массив" << endl;
	for (int i = 0; i < 3; i++) {
		outName(readTextStruct[i]);
		outSomeArray(readTextStruct[i]);
	}

	cout << "Считать содержимое двоичного файла в элементы третьего массива и вывести на экран. Сравнить содержимое первого и третьего массивов." << endl;
	for (int i = 0; i < 3; i++) {
		char *fileName = new char[100];
		sprintf(fileName, "binary%d", i);
		file = fopen(fileName, "rb");
		readBinaryFile(readBinaryStruct[i], file);
		fclose(file);
		cout << i << " структура была считана из двоичного файла" << endl;
	}
	cout << "Первый массив" << endl;
	for (int i = 0; i < 3; i++) {
		outName(writeStruct[i]);
		outSomeArray(writeStruct[i]);
	}
	cout << "Третий массив" << endl;
	for (int i = 0; i < 3; i++) {
		outName(readBinaryStruct[i]);
		outSomeArray(readBinaryStruct[i]);
	}

	for (int i = 0; i < 3; i++) {
		deleteArrays(&writeStruct[i]);
		deleteArrays(&readTextStruct[i]);
		deleteArrays(&readBinaryStruct[i]);
	}

	return 1;
}