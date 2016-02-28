#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream file, file1;
    file.open("f1.txt");
    file1.open("f2.txt");
    if ((!file.is_open()) || (!file1.is_open())){
        cout << "Ошибка открытия файла!\n";
        return 0;
    }

    string * str = new string [1024], * str1 = new string [1024];
    int i = 0, j = 0, kol = 0, kol1 = 0;

    while (getline(file, str[i])){
        if (!(str[i].find("\n"))) str[i] += "\n";
        i++;
        kol++;
    }
    i = 0;
    while(getline(file1, str1[i])){
        if (!(str1[i].find("\n"))) str1[i] += "\n";
        i++;
        kol1++;
    }

    int * mas = new int [kol];
    int * mas1 = new int [kol1];
    memset(mas, 0, kol);
    memset(mas1, 0, kol1);

    for(i = 0; i < kol; i++)
        for(j = 0; j < kol1; j++)
            if(str[i] == str1[j]) {
            mas[i] = 1;
            mas1[j] = 1;
        }

    cout << "file1: " << endl;
    for(i = 0; i < kol; i++)
        if (!mas[i]) cout << i << " " << str[i] << endl;
    cout << "file2: " << endl;
    for(i = 0; i < kol1; i++)
        if (!mas1[i]) cout << i << " " << str1[i] << endl;

    file.close();
    file1.close();

    delete [] str;
    delete [] str1;
    return 0;
}
