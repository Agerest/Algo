#include "pch.h"
#include <cstdlib>;
#include <windows.h>;
#include <iostream>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double array1[3];
	double *pointer2;
	unsigned int array3[3];
	unsigned int (*pointer4)[3];
	char array5[3][3][3];
	char (*pointer6)[3][3];

	cout << "1.	Значения в массиве №1" << endl;
	for (int i = 0; i < 3; i++) {
		cout << array1[i] << "\t";
	}

	cout << endl << "2.	Введите значения в массив №1" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> array1[i];
	}

	cout << endl << "3.	Новые значения в массиве №1" << endl;
	for (int i = 0; i < 3; i++) {
		cout << array1[i] << "\t";
	}
	cout << endl << *(array1 + 2) << endl;

	cout << endl << "4.	Присвоить указателю №2 адрес массива №1, вывести на экран адреса массива и указателя и содержимое указателя" << endl;
	pointer2 = array1;
	cout << "Адреса массива: " << &array1 << endl;
	cout << "Адреса указателя: " << pointer2 << endl;
	cout << "Содержимое указателя № 2" << endl;
	for (int i = 0; i < 3; i++) {
		cout << pointer2[i] << "\t";
	}

	cout << endl << "6.	Повторить пункты 1 – 3 для статического массива №3" << endl;
	cout << "Проверить содержимое массива №3" << endl;
	for (int i = 0; i < 3; i++) {
		cout << array3[i] << "\t";
	}
	cout << endl << "Ввести данные в массив №3" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> array3[i];
	}
	cout << endl << "Еще раз проверить содержимое этого массива" << endl;
	for (int i = 0; i < 3; i++) {
		cout << array3[i] << "\t";
	}

	cout << endl << "7.	Используя имеющийся указатель №2, создать динамический массив и повторить для него пункты 1 – 3" << endl;
	int n = 0;
	cout << "Введите размер массива" << endl;
	cin >> n;
	pointer2 = new double[n];
	cout << "Проверить содержимое указателя №2" << endl;
	for (int i = 0; i < n; i++) {
		cout << pointer2[i] << "\t";
	}
	cout << endl << "Ввести данные в указатель №2" << endl;
	for (int i = 0; i < n; i++) {
		cin >> pointer2[i];
	}
	cout << endl << "Еще раз проверить содержимое этого указателя" << endl;
	for (int i = 0; i < n; i++) {
		cout << pointer2[i] << "\t";
	}

	cout << endl << "8.	Удалить динамический массив. Используя указатель №4, создать двумерный динамический массив и повторить для него пункты 2, 3. Сделать выводы. Удалить двумерный динамический массив." << endl;
	delete[] pointer2;
	pointer4 = new unsigned int[3][3];
	cout << endl << "Ввести данные в указатель №4" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Ввод элемента " << "[" << i << "][" << j << "]  " << endl;
			cin >> pointer4[i][j];
		}
	}
	cout << endl << "Проверить содержимое этого указателя" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			cout << pointer4[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < 3; i++) {
		//delete[] pointer4[i];
	}
	delete[] pointer4;

	cout << endl << "9.	Вывести на экран любой из элементов трехмерного массива №5, используя операцию индексации" << endl;
	cout << endl << "Элемент номер 2, 1, 2 в массиве № 5" << endl;
	cout << array5[2][1][2] << endl;

	cout << endl << "10.	Повторить пункт 9, используя имя массива как указатель и операцию доступа по указателю" << endl;
	cout << endl << "Элемент номер 2, 1, 2 в массиве № 5" << endl;
	cout << *(*(*(array5 + 2) + 1) + 2) << endl;

	cout << endl << "11.	Присвоить указателю №6 на двумерный массив адрес трехмерного массива №5. Повторить для этого указателя пункт 10" << endl;
	pointer6 = array5;
	cout << endl << "Элемент номер 2, 1, 2 в указателе № 6" << endl;
	cout << *(*(*(pointer6 + 2) + 1) + 2) << endl;

	return 1;
}