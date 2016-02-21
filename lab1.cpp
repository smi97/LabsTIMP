#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;



int main(int argc, char * argv[])
{
    FILE * f1;
    FILE * f2;
    f1 = fopen("f1.txt","r");
    f2 = fopen("f2.txt","r");
    char a[100][100], b[100][100];
    int i = 0, j = 0, kol1 = 0, kol2 = 0;
    while(fgets(a[i],1024,f1)){
        if (!strstr(a[i], "\n")) strcat(a[i], "\n");
        i++;
        kol1++;
    }
    i = 0;
    while(fgets(b[i],1024,f2)){
        if (!strstr(b[i], "\n")) strcat(b[i], "\n");

        i++;
        kol2++;
    }
    int * mas;
    int * mas1;
    mas = new int [kol1];
    mas1 = new int [kol2];
    for(i = 0; i < kol1; i++)
        mas[i]=0;
    for(i = 0; i < kol2; i++)
       mas1[i]=0;
    for(i = 0; i < kol1; i++)
        for(j = 0; j < kol2; j++)
    {
        if(!strcmp(a[i],b[j])) {
            mas[i] = 1;
            mas1[j] = 1;
        }


    }
    cout << "file1: ";
    for(i = 0; i < kol1; i++)
        if (!mas[i]) cout << i << " " << a[i];
    cout << "file2: " << endl;
    for(i = 0; i < kol2; i++)
        if (!mas1[i]) cout << i << " " << b[i];
    return 0;
}

