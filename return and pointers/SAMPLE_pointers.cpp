//ОБРАЗЕЦ
//https://purecodecpp.com/archives/1188
#include <iostream>
#include <clocale>
#include <conio.h>

using namespace std;
 
void changeData(int *varForCh1, int *varForCh2);
 
int main()
{
	setlocale(LC_ALL, "rus");
 
	int variableForChange_1 = 0;
	int variableForChange_2 = 0;
 
	cout << "variableForChange_1 = " << variableForChange_1 << endl;
	cout << "variableForChange_2 = " << variableForChange_2 << endl;
	cout << endl;
 
	changeData(&variableForChange_1, &variableForChange_2);
	//ЭТО ПРАВИЛЬНО, НО ПОЧЕМУ ПЕРЕМЕННЫЕ, В ЭТИХ ПАРАМЕТРАХ, НАЗЫВАЮТСЯ variableForChange... А НЕ varForCh... ????  
 
	cout << endl;
	cout << "variableForChange_1 = " << variableForChange_1 << endl;
	cout << "variableForChange_2 = " << variableForChange_2 << endl;
 
	getch();
	return 0;
}
 
void changeData(int *varForCh1, int *varForCh2)
{
	cout << "Введите новое значение первой переменной: ";
	cin >> *varForCh1;
	cout << "Введите новое значение второй переменной: ";
	cin >> *varForCh2;
}
