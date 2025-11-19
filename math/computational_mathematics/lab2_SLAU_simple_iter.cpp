#include <cmath>
#include <iostream>
#include <conio.h>
#include <iomanip> // для setprecision (сколько знаков после запятой в действительном числе) ;  setw (отступы)
#include <locale>
#define SIZE 4
 
 
using namespace std;
 
 
float Var(int n); //для рассчета с
void Multip(float C[SIZE][SIZE], float B[SIZE], float CB[SIZE]); // умножение матрицы на вектор 
void Subtr(float B[SIZE], float CB[SIZE], float X1[SIZE]); // вычитание двух векторов 
void Multip_2(float C[SIZE][SIZE], float X1[SIZE], float CB[SIZE]); // умножение для X2
void Subtr_2(float B[SIZE], float CX1[SIZE], float X2[SIZE]); // вычитание для X2 
void Multip_3(float C[SIZE][SIZE], float X2[SIZE], float CX2[SIZE]); // умножение для X3
void Subtr_3(float B[SIZE], float CX2[SIZE], float X3[SIZE]); // вычитание для X3  
void inaccuracy(float X3[SIZE], float X2[SIZE], float result[SIZE]); //вычитание для погрешности 
 
 
 
 
int main()
{
    setlocale(LC_ALL, "rus");
     
    
    float c;
    int i,j;
    float C[SIZE][SIZE];
    float normC, max1=0;
    float normB, max2=0;
    int steps; 
    float CB[SIZE];  
    float X1[SIZE];
    float CX1[SIZE];
    float X2[SIZE];
    float CX2[SIZE];
    float X3[SIZE];
    float result[SIZE];
    float normR, max3=0;
        
        
    c = Var(5);
    
    
    float arr1[SIZE][SIZE] = {{ 0.95+c, 0.26+c, -0.17+c, 0.27+c },
                              { -0.15+c, 1.26+c, 0.36+c, 0.42+c },
                              { 0.26+c, -0.54+c, -1.76+c, 0.31+c },
                              { -0.44+c, 0.29+c, -0.78+c, -1.78+c }};
                              
                              
                              
                                
    //вывод матрицы изначальной arr1    
    cout << "изначальная матрица arr1 \n" << endl; 
        for (i = 0; i<SIZE; i++)          //цикл по строкам
        {
            for (j = 0; j<SIZE; j++)      //цикл по столбцам
            {
                    cout << setw(12) << fixed << setprecision(3) << arr1[i][j]; 
            }
            cout << endl;
        }
        cout << endl;
    
//////////////////////////////////////////////////////////////////////////////////////////////////////
 
    //вывод матрицы — (она же det arr1)
    cout << "матрица С \n" << endl; 
    for (i = 0; i<SIZE; i++)          //цикл по строкам
        {
            for (j = 0; j<SIZE; j++)  //цикл по столбцам
            {           
                C[i][j] = arr1[i][j] / arr1[i][i];   //вычисление матрицы — из матрицы arr1  //???????? КАК ЭТО?
                if (i == j) C[i][j] = 0;            //присваивание 0 диагонали
                
                cout << setw(12) << fixed << setprecision(3) << C[i][j]; 
            }
            cout << endl; 
        }
        cout << endl;
 
//////////////////////////////////////////////////////////////////////////////////////////////////////
    
    float B[SIZE] = { 2.480, -3.160, 1.520, -1.290 };   
    
    cout << "изначальный вектор В \n" << endl;
    for (i = 0; i<SIZE; i++)  
    {   
        cout << setw(12) << fixed << setprecision(3) << B[i]; 
        cout << endl;   
    }
    cout << endl;
                                        
    
    cout << "вектор неВ \n" << endl;
    for (i = 0; i<SIZE; i++)  
    {
        B[i] = B[i] / arr1[i][i];   
        cout << setw(12) << fixed << setprecision(3) << B[i]; 
        cout << endl;   
    }
    cout << endl;
    
//////////////////////////////////////////////////////////////////////////////////////////////////////
    
    cout << "норма матрицы С = " ;  
    for (int i=0; i<SIZE; i++)
    {
        normC = fabs(C[i][0]) + fabs(C[i][1]) + fabs(C[i][2]) + fabs(C[i][3]); //за одну итерацию суммируются значения в одной строке (fabs - взятие модуля для float)
        if (normC > max1)   //если сумма значений строки > 0      //???????? ЗАЧЕМ ЭТО?
        max1 = normC;       
    }
    cout << fixed << setprecision(3) << max1 << endl;           
 
///////////////////////////////////////////////////////////////////////////////////////////////////////
    
    cout << "норма вектора неВ = " ;    
    for (int i=0; i<SIZE; i++)
    {
        normB = fabs(B[i]);  //за одну итерацию взятие модуля одного элемента
        if (normB > max2)    //если значение элемента > 0         //???????? ЗАЧЕМ ЭТО?
        max2 = normB;   
    }
    cout << fixed << setprecision(3) << max2 << endl;           
    cout << "\n\n";
    
///////////////////////////////////////////////////////////////////////////////////////////////////////
 	
 	cout << "----------------------------------------------\n" ;
    cout << "результат умножения матрицы С на вектор неВ \n\n" ; 

    Multip(C, B, CB);
    
    for (i = 0; i<SIZE; i++)  
    {
		cout << setw(12) << fixed << CB[i] << endl;
	}
    cout << endl;
    
//////////////////////////////////////// 

	cout << "результат вычитания вектора CнеB из вектора неB \n" ;
	cout << "то есть это вектор X1 \n" ;
	
	Subtr(B, CB, X1);
		  
        for (i = 0; i<SIZE; i++)  
    {
		cout << setw(12) << fixed << X1[i] << endl;
	}
    cout << endl;
    
///////////////////////////////////////////////////////////////////////////////////////////////////////
	
	cout << "----------------------------------------------\n" ;
	cout << "результат умножения матрицы С на вектор X1 \n\n" ; 
	
    Multip_2(C, X1, CX1);
    
    for (i = 0; i<SIZE; i++)  
    {	
		cout << setw(12) << fixed << CX1[i] << endl;
	}
    cout << endl;
	
////////////////////////////////////////

	cout << "результат вычитания вектора CX1 из вектора неB \n" ;
	cout << "то есть это вектор X2 \n" ;
	
	Subtr_2(B, CX1, X2);
		  
        for (i = 0; i<SIZE; i++)  
    {
		cout << setw(12) << fixed << X2[i] << endl;
	}
    cout << endl;
	
///////////////////////////////////////////////////////////////////////////////////////////////////////	
	
	cout << "----------------------------------------------\n" ;
	cout << "результат умножения матрицы С на вектор X2 \n\n" ; 
	
    Multip_3(C, X2, CX2);
    
    for (i = 0; i<SIZE; i++)  
    {	
		cout << setw(12) << fixed << CX2[i] << endl;
	}
    cout << endl;
	
////////////////////////////////////////

	cout << "результат вычитания вектора CX2 из вектора неB \n" ;
	cout << "то есть это вектор X3 \n" ;
	
	Subtr_3(B, CX2, X3);
		  
        for (i = 0; i<SIZE; i++)  
    {
		cout << setw(12) << fixed << X3[i] << endl;
	}  
    cout << "----------------------------------------------\n" << endl;
	
///////////////////////////////////////////////////////////////////////////////////////////////////////		
	
	cout << "результат вычитания вектора X2 из вектора X3 (для погрешности) \n" ;
	cout << "то есть это вектор result \n" ;

	inaccuracy(X3, X2, result);
		  
        for (i = 0; i<SIZE; i++)  
    {
		cout << setw(12) << fixed << result[i] << endl;
	}  
	cout << endl; 
	
	
	
    cout << "норма вектора result = " ;    
    for (int i=0; i<SIZE; i++)
    {
        normR = fabs(result[i]);  //за одну итерацию взятие модуля одного элемента
        if (normR > max3)    //если значение элемента > 0         //???????? ЗАЧЕМ ЭТО?
        max3 = normR;   
    }
    cout << fixed << setprecision(3) << max3 << endl;           
    cout << endl;  
	
	
	
    cout << "----------------------------------------------\n" << endl;

///////////////////////////////////////////////////////////////////////////////////////////////////////	
		
    
    getch();
    return 0;
}
 
/* ф-ция для рассчета с */
float Var(int n)
{
    return (float)n*0.01;
}
 
 
/* ф-ция умножения матрицы С на вектор неB */
void Multip(float C[SIZE][SIZE], float B[SIZE], float CB[SIZE])
{
    for (int i=0; i < SIZE; i++)
    {
        CB[i] = 0;
        for (int j=0; j < SIZE; j++)
        {
            CB[i] += C[i][j] * B[i];
        }
    }  
}
/* ф-ция вычитания вектора CнеB из вектора неB */
void Subtr(float B[SIZE], float CB[SIZE], float X1[SIZE])
{
    for (int i=0; i < SIZE; i++)
    {
        X1[i] = 0;
        for (int j=0; j < SIZE; j++)
        {
            X1[i] = B[i] - CB[i];
        }
    } 
	cout << endl; 
}


/* ф-ция умножения матрицы С на вектор X1 */
void Multip_2(float C[SIZE][SIZE], float X1[SIZE], float CX1[SIZE])
{
    for (int i=0; i < SIZE; i++)
    {	
        CX1[i] = 0;
        for (int j=0; j < SIZE; j++)
        {
            CX1[i] += C[i][j] * X1[i];
        }
    }  
}
/* ф-ция вычитания вектора CX1 из вектора неB */
void Subtr_2(float B[SIZE], float CX1[SIZE], float X2[SIZE])
{
    for (int i=0; i < SIZE; i++)
    {
        X2[i] = 0;
        for (int j=0; j < SIZE; j++)
        {
            X2[i] = B[i] - CX1[i];
        }
    } 
	cout << endl; 
}


/* ф-ция умножения матрицы С на вектор X2 */
void Multip_3(float C[SIZE][SIZE], float X2[SIZE], float CX2[SIZE])
{
    for (int i=0; i < SIZE; i++)
    {	
        CX2[i] = 0;
        for (int j=0; j < SIZE; j++)
        {
            CX2[i] += C[i][j] * X2[i];
        }
    }  
}
/* ф-ция вычитания вектора CX2 из вектора неB */
void Subtr_3(float B[SIZE], float CX2[SIZE], float X3[SIZE])
{
    for (int i=0; i < SIZE; i++)
    {
        X3[i] = 0;
        for (int j=0; j < SIZE; j++)
        {
            X3[i] = B[i] - CX2[i];
        }
    } 
	cout << endl; 
}


/* ф-ция вычитания для погрешности вектора X2 из вектора X3 */
void inaccuracy(float X3[SIZE], float X2[SIZE], float result[SIZE])
{
	
	for (int i=0; i < SIZE; i++)
    {
        result[i] = 0;
        for (int j=0; j < SIZE; j++)
        {
            result[i] = X3[i] - X2[i];
        }
    } 
	cout << endl; 
			
}
