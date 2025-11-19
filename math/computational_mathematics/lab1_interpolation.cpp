#include <cmath>
#include <iostream>
#include <conio.h>
#include <iomanip> // для setprecision (сколько знаков после зап¤той в действительном числе)
#define N 5
#define H 0.011

using namespace std;


int main()
{
	double func,result,c;
	int x[30] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};
	int i;
	
	c = N + 1;
	
	
	for (i=0; i<=29; i++)
	{
		if (c <= c+30)
			{	
				c = c+(30*H);
				result = (c + (i * H)) + ((((i%4) + 1) / 5) * H);   //значения функции в точках (с помоцью линейной интерполяции)
				func = (pow(c,3) * 2) * sin(i/c); //значения функции 
				cout << "func = " << setprecision(6) << func << "\t\t" << "x = " << setprecision(6) << result << endl;  
				c++;
			}		
	} 
	

	getch();
	return 0;	
}	
