#include <cstring>
#include <string>
#include <iostream>


struct Stack
{
    int el;
    Stack *head, *next;
};

/**
 \func void push(int iEl, Stack *stack)
*/

void push(int iEl, Stack *stack)
{
    Stack *tmp = new Stack;
    tmp->el = iEl;
    tmp->next=stack->head;
    stack->head=tmp;
}

/**
 \func int get(Stack *stack)
*/

int get(Stack *stack)
{
    return stack->head->el;
}

/**
 \func int pop(int *iEl, Stack *stack)
*/

int pop(int *iEl, Stack *stack)
{
    if(stack->head == nullptr) return 0;
    Stack *tmp;
    tmp = stack->head;
    *iEl = tmp->el;
    stack->head = tmp->next;
    free(tmp);
    return 1;
}

/**
 \func Stack * CreateStack()
*/

Stack * CreateStack()
{
    Stack *stack = new Stack;
    stack->head = nullptr;
    stack->next = nullptr;
    return stack;
}

/**
 \func int isStackEmpty(Stack *stack)
*/

int isStackEmpty(Stack *stack)
{
    if(stack->head == nullptr) return 1;
    return 0;
}

/**
 \func int recognize(std::string com, int & data)
*/

int recognize(std::string com, int & data)
{
    if ( com.find("add") != std::string::npos ) {data = std::stoi(com.substr(com.find("add") + 4, 100)); return 1;}
    if ( com.find("get") != std::string::npos )  return 2;
    if ( com.find("del") != std::string::npos )  return 3;   return 0;
}

/**
 \func int main()
*/

int main()
{
    int i, n = 0, c, d, a, data;
    std::string command;
    Stack *q = CreateStack();
    std::cin >> c;
    getline(std::cin, command);
    for(i = 0; i < c; i++){
        getline(std::cin, command);
        a = recognize(command, data);
        switch(a)
        {
            case 1:
                push(data, q);
                std::cout << "\nЭлемент добавлен в стек \n";
                break;


            case 2:
                if (isStackEmpty(q)==1)
                    std::cout << "\nСтек пуст \n";
                else
                {
                    std::cout << get(q) << std::endl;
                }
                break;

            case 3:
                if (isStackEmpty(q) == 1)
                    std::cout << "\nСтек пуст \n";
                else
                {
                    pop(&i, q);
                    std::cout << "\nЭлемент удален из стека \n";
                }
                break;

            default: std::cout << "\nОшибка! Неправильно введена команда! \n"; break;
        }
    }

    return 0;
}


