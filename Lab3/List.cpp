#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


struct List
{
    int index;
    int data;
    List *pNext;
};

/**
 \func void add(List **pF, int _index, int _data)
*/

void add(List **pF, int _index, int _data)
{
    List *_add;
    _add = new List;
    _add->index = _index;
    _add->data = _data;
    if (_index == 0)
    {
        _add->pNext = *pF;
        *pF = _add;
    }
    else
    {
        List *pInd = *pF;
        while ((pInd->index != _index - 1) && (pInd->pNext))
            pInd = pInd->pNext;
        _add->pNext = pInd->pNext;
        pInd->pNext = _add;
    }
    for (List *pi = _add->pNext; pi; pi = pi->pNext)
        pi->index++;
}

/**
 \func int get(List **pF, int _index)
*/

int get(List **pF, int _index)
{
    int i = 0;
    List *pInd = *pF;
    while ((pInd->index != _index) && (pInd->pNext))
        pInd = pInd->pNext;
    return pInd->data;
}

/**
 \func void del(List **pF, int _index)
*/

void del(List **pF, int _index)
{
    List *pInd = *pF;
    while ((pInd->index != _index - 1) && (pInd->pNext))
        pInd = pInd->pNext;
    pInd->pNext = pInd->pNext->pNext;
    for (List *pi = pInd->pNext; pi; pi = pi->pNext)
        pi->index--;
}

/**
 \func bool isListEmpty( List **pF) 
*/

bool isListEmpty( List **pF)
{
    if(*pF == nullptr) return true;
    return false;
}

/**
 \func int recognize(std::string com, int & index, int & data)
*/

int recognize(std::string com, int & index, int & data)
{
    if ( com.find("add") != std::string::npos ) {index = std::stoi(com.substr(com.find("add") + 4, 2)); data = std::stoi(com.substr(com.find("add") + 6, 2)); return 1;}
    if ( com.find("get") != std::string::npos )  {index = std::stoi(com.substr(com.find("get") + 4, 2)); return 2;}
    if ( com.find("del") != std::string::npos )  {index = std::stoi(com.substr(com.find("del") + 4, 2)); return 3;}
    if ( com.find("show") != std::string::npos )  return 4;return 0;

}

/**
 \func int main(int argc, char* argv[])
*/

int main(int argc, char* argv[])
{
    List *pF = nullptr;
    List *p;
    char Ch, s;
    bool first = true;
    int n, d, c, ind, dat, a;
    std::string command;
    std::cin >> c;
    getline(std::cin, command);
    for(int i = 0; i < 100; i++){
        getline(std::cin, command);
        a = recognize(command, ind, dat);
        switch(a)
        {
            case 1:
                add(&pF, ind, dat);
                std::cout << "\nЭлемент добавлен в список \n";
                break;
            case 2:
                if (isListEmpty(&pF)==1)
                    std::cout << "Список пуст \n";
                else
                {
                    std::cout << get(&pF, ind) << std::endl;
                }
                break;
            case 3:
                if (isListEmpty(&pF) == 1)
                    std::cout << "Список пуст \n";
                else
                {
                    del(&pF, ind);
                    std::cout << "\nЭлемент удален из списка \n";
                }
                break;
            case 4:
                for (List *pi = pF; pi; pi = pi->pNext)
                    std::cout << pi->index << ". " << pi->data << std::endl;
                break;

            default: std::cout << "\nОшибка! Неправильно введена команда! \n"; break;
        }
    }

    return 0;
}
 
