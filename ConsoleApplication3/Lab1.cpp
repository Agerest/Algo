#include "pch.h"
#include <cstdlib>;
#include <windows.h>;
#include <iostream>

using namespace std;

int mains()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char array1[5];
	char * pointer2;
	long array3[5];
	long (*pointer4)[3]; //[������]
	double array5[3][3][3];
	double (* pointer6)[3][3];

	cout << "1.	��������� ���������� ������� �1" << endl;
	for (int i = 0; i < 5; i++) {
		cout << array1[i] << "\t";
	}

	cout << endl << "2.	������ ������ � ������ �1" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> array1[i];
	}

	cout << endl << "3.	��� ��� ��������� ���������� ����� �������" << endl;
	for (int i = 0; i < 5; i++) {
		cout << array1[i] << "\t";
	}
	cout << endl << *(array1 + 2) << endl;

	cout << endl << "4.	��������� ��������� �2 ����� ������� �1, ������� �� ����� ������ ������� � ��������� � ���������� ���������" << endl;
	pointer2 = array1;
	cout << "������ �������: " << &array1 << endl;
	cout << "������ ���������: " << &pointer2 << endl;
	for (int i = 0; i < 5; i++) {
		cout << pointer2[i] << "\t";
	}

	cout << endl << "6.	��������� ������ 1 � 3 ��� ������������ ������� �3" << endl;
	cout << "��������� ���������� ������� �3" << endl;
	for (int i = 0; i < 5; i++) {
		cout << array3[i] << "\t";
	}
	cout << endl << "������ ������ � ������ �3" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> array3[i];
	}
	cout << endl << "��� ��� ��������� ���������� ����� �������" << endl;
	for (int i = 0; i < 5; i++) {
		cout << array3[i] << "\t";
	}

	cout << endl << "7.	��������� ��������� ��������� �2, ������� ������������ ������ � ��������� ��� ���� ������ 1 � 3" << endl;
	int n = 0;
	cout << "������� ������ �������" << endl;
	cin >> n;
	pointer2 = new char[n];
	cout << "��������� ���������� ��������� �2" << endl;
	for (int i = 0; i < n; i++) {
		cout << pointer2[i] << "\t";
	}
	cout << endl << "������ ������ � ��������� �2" << endl;
	for (int i = 0; i < n; i++) {
		cin >> pointer2[i];
	}
	cout << endl << "��� ��� ��������� ���������� ����� ���������" << endl;
	for (int i = 0; i < n; i++) {
		cout << pointer2[i] << "\t";
	}

	cout << endl << "8.	������� ������������ ������. ��������� ��������� �4, ������� ��������� ������������ ������ � ��������� ��� ���� ������ 2, 3. ������� ������. ������� ��������� ������������ ������." << endl;
	delete[] pointer2;
	pointer4 = new long[3][3];
	cout << endl << "������ ������ � ��������� �4" << endl;
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "���� �������� " << "[" << i << "][" << j << "]  " << endl;
			cin >> pointer4[i][j];
		}
	}
	cout << endl << "��������� ���������� ����� ���������" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			cout << pointer4[i][j] << "\t";
		}
		cout << endl;
	}
	/*for (int i = 0; i < 3; i++) {
		delete[] pointer4[i];
	}*/
	delete[] pointer4;

	cout << endl << "9.	������� �� ����� ����� �� ��������� ����������� ������� �5, ��������� �������� ����������" << endl;
	cout << array5[2][1][2] << endl;

	cout << endl << "10.	��������� ����� 9, ��������� ��� ������� ��� ��������� � �������� ������� �� ���������" << endl;
	cout << *(*(*(array5 + 2) + 1) + 2) << endl;

	cout << endl << "11.	��������� ��������� �6 �� ��������� ������ ����� ����������� ������� �5. ��������� ��� ����� ��������� ����� 10" << endl;
	pointer6 = array5;
	cout << *(*(*(pointer6 + 2) + 1) + 2) << endl;

	return 1;
}	