#include <cmath>
#include <iostream>
#include <conio.h>
#include <iomanip> // для setprecision (сколько знаков после запятой в действительном числе)
#include <locale>
#define N 5
#define H 0.011

using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	
	double func, result, c, interpol;
//	int array_1[30]; лишнее
//	int array_2[31]; лишнее
	int j,i;
	double x[31];
	double y[31];
		
	c = N + 1;
	
	for (j=0; j<=30; j++)
	{		
		x[j] = c+(double)j*H;  	// значения ф-ции по оси Х
		y[j] = (pow(c,3) * 2) * sin(x[j]/c); 	// значения ф-ции по оси Y  (  f(x)  )
		
		cout << " x = " << fixed << setprecision(4) << x[j] << "\t" 
		<< "f(x) = " << fixed << setprecision(4) << y[j] << endl;	 		
	}
	
	cout << endl;
	
	for (i=0; i<=29; i++)
	{		
		result = (c + (double)i * H) + ((((double)(i%4) + double(1)) / 5) * H);   //x промежуточное
		func = (pow(c,3) * 2) * sin(result/c);                                   //точное значение функции 
		interpol = (y[i] + ((result - x[i]) / H) * (y[i+1] - y[i]) );		 //интерполяция
		
		cout << "x промежут. " << fixed << setprecision(4) << result << "\t" 
		<< "интерп " << fixed << setprecision(4) << interpol << "\t\t" 
		<< "точн. " << fixed << setprecision(4) << func << endl;
	}

	getch();
	return 0;	
}
