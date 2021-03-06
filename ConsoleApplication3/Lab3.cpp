#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdarg.h>
#include <stdlib.h>

using namespace std;

const int name_length = 30;

struct someStruct {
	char firstName[name_length];
	char * secondName;
	unsigned long number;
	long * someArray;
	double length;
};

void initStruct(someStruct &t) {
	cout << "������������� ���������" << endl;
	t.secondName = new char[name_length];
}

void initSomeArray(someStruct *t) {
	cout << "���������� ������� �����" << endl;
	cout << "������� ���������� ��������� � �������" << endl;
	cin >> t->length;
	t->someArray = new long[t->length];
	for (int i = 0; i < t->length; i++) {
		cout << "������� ������� ����� " << i << endl;
		cin >> t->someArray[i];
	}
}

void initName(someStruct *t) {
	cout << "���� ���������� � ������ ����� � ������� � ������ ����" << endl;
	cout << "������� ���" << endl;
	cin >> t->firstName;
	cout << "������� �������" << endl;
	cin >> t->secondName;
	cout << "������� ID" << endl;
	cin >> t->number;
}

void writeToTextFile(someStruct &s, FILE *file) {
	fprintf(file, "%ul\n%s\n%s\n%lf\n", s.number, s.firstName, s.secondName, s.length);
	for (int i = 0; i < s.length; i ++) {
		fprintf(file, "%ld; ", s.someArray[i]);
	}
}

void writeToBinaryFile(someStruct &s, FILE *file) {
	fwrite((&s.number), sizeof(s.number), 1, file);
	fwrite((s.firstName), sizeof(char), name_length, file);
	fwrite((s.secondName), sizeof(char), name_length, file);
	fwrite((&s.length), sizeof(s.length), 1, file);
	for (int j = 0; j < s.length;j++)
	{
		fwrite(&(s.someArray[j]), sizeof(long), 1, file);
	}
}

void readTextFile(someStruct &s, FILE *file) {
	fscanf(file, "%ul\n%s\n%s\n%lf\n", &s.number, s.firstName, s.secondName, &s.length);
	s.someArray = new long[s.length];
	for (int i = 0; i < s.length; i ++) {
		fscanf(file, "%ld; ", &s.someArray[i]);
	}
}

void readBinaryFile(someStruct &s, FILE *file) {
	fread((&s.number), sizeof(s.number), 1, file);
	fread((s.firstName), sizeof(char), name_length, file);
	fread((s.secondName), sizeof(char), name_length, file);
	fread((&s.length), sizeof(s.length), 1, file);
	s.someArray = new long[s.length];
	for (int j = 0; j < s.length; j++)
	{
		fread(&(s.someArray[j]), sizeof(long), 1, file);
	}
}

void outSomeArray(someStruct &t) {
	cout << "����� �� ����� ������� �����" << endl;
	for (int i = 0; i < t.length; i++) {
		cout << t.someArray[i] << "\t";
	}
	cout << endl;
}

void outName(someStruct &t) {
	cout << "����� �� ����� ���� ����� ���������, ����� ������� �����" << endl;
	cout << t.firstName << " " << t.secondName << " " << t.number << endl;
}

void deleteArrays(someStruct *t) {
	cout << "������������ ������������ ������" << endl;
	delete[] t->someArray;
	delete[] t->secondName;
}

int main3()
{
	setlocale(LC_ALL, "rus");

	FILE* file;
	someStruct *writeStruct = new someStruct[3];
	someStruct *readTextStruct = new someStruct[3];
	someStruct *readBinaryStruct = new someStruct[3];

	cout << "������ ������ � �������� ������� ������������� ������� � ������� �������, ������������� � ������������ ������ �2" << endl;
	for (int i = 0; i < 3; i++) {
		initStruct(writeStruct[i]);
		initSomeArray(&writeStruct[i]);
		initName(&writeStruct[i]);
		initStruct(readBinaryStruct[i]);
		initStruct(readTextStruct[i]);
	}

	cout << "��������� ���������� ��������� ������� �������� � ��������� � �������� ������" << endl;
	for (int i = 0; i < 3; i++) {
		char *fileName = new char[100];
		sprintf(fileName, "text%d", i);
		file = fopen(fileName, "wt");
		writeToTextFile(writeStruct[i], file);
		fclose(file);
		cout << i << " ��������� ���� �������� � ��������� ����" << endl;
		sprintf(fileName, "binary%d", i);
		file = fopen(fileName, "wb");
		writeToBinaryFile(writeStruct[i], file);
		fclose(file);
		cout << i << " ��������� ���� �������� � �������� ����" << endl;
	}

	cout << "������� ���������� ���������� ����� � �������� ������� ������� � ������� �� �����. �������� ���������� ������� � ������� ��������" << endl;
	for (int i = 0; i < 3; i++) {
		char *fileName = new char[100];
		sprintf(fileName, "text%d", i);
		file = fopen(fileName, "rt");
		readTextFile(readTextStruct[i], file);
		fclose(file);
		cout << i << " ��������� ���� ������� �� ���������� �����" << endl;
	}
	cout << "������ ������" << endl;
	for (int i = 0; i < 3; i++) {
		outName(writeStruct[i]);
		outSomeArray(writeStruct[i]);
	}
	cout << "������ ������" << endl;
	for (int i = 0; i < 3; i++) {
		outName(readTextStruct[i]);
		outSomeArray(readTextStruct[i]);
	}

	cout << "������� ���������� ��������� ����� � �������� �������� ������� � ������� �� �����. �������� ���������� ������� � �������� ��������." << endl;
	for (int i = 0; i < 3; i++) {
		char *fileName = new char[100];
		sprintf(fileName, "binary%d", i);
		file = fopen(fileName, "rb");
		readBinaryFile(readBinaryStruct[i], file);
		fclose(file);
		cout << i << " ��������� ���� ������� �� ��������� �����" << endl;
	}
	cout << "������ ������" << endl;
	for (int i = 0; i < 3; i++) {
		outName(writeStruct[i]);
		outSomeArray(writeStruct[i]);
	}
	cout << "������ ������" << endl;
	for (int i = 0; i < 3; i++) {
		outName(readBinaryStruct[i]);
		outSomeArray(readBinaryStruct[i]);
	}

	for (int i = 0; i < 3; i++) {
		deleteArrays(&writeStruct[i]);
		deleteArrays(&readTextStruct[i]);
		deleteArrays(&readBinaryStruct[i]);
	}
	delete[] writeStruct;
	delete[] readBinaryStruct;
	delete[] readTextStruct;

	return 0;
}