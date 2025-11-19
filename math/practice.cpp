#include <cmath>
#include <iostream>
#include <conio.h>
#include <locale>

using namespace std; 
 
 
 int main()
{
 	setlocale(LC_ALL, "rus");
 
 	
 	int a, b, tran;
 	cout << "введите число a  " ; 
  	cin >> hex >> a;
  	cout << "введите число b  "; 
	cin >> hex >> b; 
    
	cout << "\nсумма в шестнадцатеричной = " << hex << a + b << endl;
	cout << "разность в шестнадцатеричной = " << hex << a - b << endl;

	cout << "\nвведите число в шестнадцатеричной  "; 
	cin >> hex >> tran;
	cout << "результат перевода в десятичную  "; 
	cout << dec << tran;
	
  
	getch();
	return 0;
}
