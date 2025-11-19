/*
https://programmersforum.ru/showthread.php?p=1809254
Есть два файла binaryData1.info и binaryData2.info. Нужно реализовать функцию побитового ИЛИ между их содержимым.
При этом, всё это записать в файл unionbinaryData.info, и чтобы биты были в обратном порядке (младший бит становится старшим и т.д.)
Но при этом нельзя использовать функцию Invert
*/
#include <iostream>
#include <fstream>      //для работы с файлами
#include <conio.h>
#include <locale>
#include <stdio.h>
#include <stdlib.h>
#include <string>


using namespace std;

int main() 
{
	setlocale(LC_ALL, "rus");
 
	string str;	
 	getline(cin, str);	
 	ofstream outf("file1.txt"); 	
 	outf << str;
	
 	
 	getch();
	return 0;
}
