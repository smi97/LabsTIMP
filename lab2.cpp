#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Doxygen(ifstream& file)
{
    int i = 0, j = 0, k = 0;
    string str;
    size_t n;
    bool f = false;

    while (!file.eof()) {
        getline(file, str);
        n = str.find("/**");
        if(n != string::npos){
            n = str.find("\\func");
            k = n + 6;
            if (n != string::npos) {
                j++;
                cout << j << ". ";
                while (str[str.find("*/")] != str[k]){
                    cout<< str[k];
                    k++;
                }
                cout << endl;
            }
            else {
                do {
                    getline(file, str);
                    n = str.find("\\func");
                    k = n + 6;
                    if(n != string::npos)
                    {
                        f = true;
                        j++;
                        cout << j << ". ";
                        while (str[str.find("*/")] != str[k]){
                            cout<< str[k];
                            k++;
                        }
                        cout << endl;

                    }
                    if(file.eof()) break;
                }
                while (!f);
            }
            f = false;
        }
    }


}

int main()
{
    string pass = "main.cpp";
    ifstream file;
    file.open(pass);
    if (!file.is_open()){
        cout << "Ошибка открытия файла!\n";
        return 1;
    }

    Doxygen(file);

    file.close();

    return 0;
}

