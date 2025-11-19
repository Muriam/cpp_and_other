#include <iostream>

using namespace std; 
 
void func1(char arr1[]); 
 
 
int main()
{
	setlocale(LC_ALL, "rus");
    
    char arr1[] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
 
    func1(arr1);
    
    
    return 0;
}
 
void func1(char arr1[])
{
    for (int i = 0; arr1[i] != '\0'; i++)
    {
        cout << arr1[i];
    }
}
