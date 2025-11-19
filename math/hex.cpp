#include <cmath>
#include <iostream>
#include <conio.h>
#include <locale>

using namespace std; 
 
 
int main()
{
 	setlocale(LC_ALL, "rus");
 
	
 	int a, b;
 	cout << "введите число a  " ; 
        cin >> hex >> a;
  	cout << "введите число b  "; 
	cin >> hex >> b; 
  
  	cout << "\nсумма в шестнадцатеричной = " << hex << a + b << endl;
	cout << "сумма в десятичной = " << dec << a + b << "\n\n";
	
  	cout << "разность в шестнадцатеричной = " << hex << a - b << endl;
	cout << "разность в десятичной = " << dec << a - b << "\n\n";
	
	
	getch();
	return 0;
}
