#include <iostream>
#include <conio.h>

using namespace std;


int main()
{
	int  aValue = 76;
	int *aPtr = &aValue;
	
	
    	cout << aValue << endl;  //значение переменной
    	cout << *aPtr << endl;	 //указатель на значение переменой
    	cout << &aValue << endl; //адрес ячейки, где находится переменная
	
	
	getch();
	return 0;	
}
