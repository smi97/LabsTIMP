#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void open(ifstream & file, string pass){
    if (file.is_open()) {
        file.close();
    }
    file.open(pass);
}

int CountStrings(istream& is)
{
    string s;
    int nStrings = 0;
    while (getline(is, s))
        ++nStrings;
    return nStrings;
}

int main()
{
    string pass = "f1.txt", pass1 = "f2.txt";
    ifstream file, file1;
    file.open(pass);
    file1.open(pass1);
    if ((!file.is_open()) || (!file1.is_open())){
        if (file.is_open()) file.close();
        if (file1.is_open()) file1.close();
        cout << "Ошибка открытия файла!\n";
        return 1;
    }

    string * str = new string [CountStrings(file)], * str1 = new string [CountStrings(file1)];
    open(file, pass);
    open(file1, pass1);
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
