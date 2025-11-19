#include <iostream>
#include <clocale>

using namespace std;

/* вводится число программ N <= 20. Напечатать фразу 
"Я разработал N программ", согласовав слово "программа" с числом N. */
int main() 
{
	setlocale(LC_ALL, "rus"); 
	
	int N;
	cout << "введите номер программы" << "\n";
	cin >> N;
		
	switch(N)
		{
		case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
		case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20:	
		cout << "я разработал программ " << N << "\n"; break;	
		default: cout << "программ создано меньше, чем " << N << "\n"; 
    	}

	cin.get(); 
	return 0;		
}
