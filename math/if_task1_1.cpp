#include <iostream>
#include <clocale>

using namespace std;

/*даны четыре числа, на сколько их сумма меньше их произведения*/
int main() 
{
	setlocale(LC_ALL, "rus"); 
	float x1, x2, x3, x4, sum, com;

	cout << "введите первое число" << "\n";
	cin >> x1;
	cout << "введите второе число" << "\n";
	cin >> x2;
	cout << "введите третье число" << "\n";
	cin >> x3;
	cout << "введите четвертое число" << "\n";
	cin >> x4;
	
	sum = x1 + x2 + x3 + x4;
	com = x1 * x2 * x3 * x4;
	if (sum < com) cout << "сумма меньше произведения на " << com - sum << endl; 
	
	cin.get(); //для задержки экрана (библиотека iostream)
	return 0;	
}

