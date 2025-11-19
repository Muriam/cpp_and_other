/* Пример порестейшей одномодульной программы в стиле(парадигме) ООП */
#include <iostream>

using namespace std;
 
class Human 
{
private:
    char name[15];
    int age;
    
public:
    Human()
    {
        cout << "Enter name: "; 
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << endl;
    }
    
    void ShowHuman()
    {
        cout << "\t" << "name: " << name << " ";
        cout << "\t" << "age: " << age << endl;
    }
};


int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    Human *mas = new Human[n];
    
    for (int i = 0; i < n; i++)
    {
        cout << "Human " << i+1 << ": ";
        mas[i].ShowHuman();
        cout << endl;
    }
    
    system("pause");
    return 0;
}
