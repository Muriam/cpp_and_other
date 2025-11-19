#include <cmath>
#include <iostream>
#include <conio.h>
#include <iomanip> // для задания кол-ва цифр после запятой при выводе float

using namespace std;

int main()
{
	int t = 1, 
	    z = 3;	
	float y, x;
	
	y = sin(t);
	x = 4 * pow(y,2) / (4 * z - 2 * pow(t,3));
	
	cout <<	"result " << x << endl;	

		//проверка синтаксиса на возведение в степень
		int a = 8, b = 2, c; 
		c = pow(8,2);
		cout << c << endl;
		
		//проверка синтаксиса на вычисление синуса
		cout << fixed << setprecision(2) << "sine 1 = " << y << endl; // fixed и setprecision(2) - для задания кол-ва цифр после запятой
	
	getch();
	return 0;	
}


