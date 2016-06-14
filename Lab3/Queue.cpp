#include <cstring>
#include <string>
#include <iostream>



struct Queue
{
    int el;
    Queue *beg, *next, *end;
};

/**
 \func void push(int iEl, Queue *queue)
*/

void push(int iEl, Queue *queue)
{
    Queue *tmp = new Queue;
    tmp->next = NULL;
    tmp->el = iEl;
    if(queue->end != NULL)
        queue->end->next = tmp;
    else
        queue->beg = tmp;
    queue->end = tmp;
}

/**
 \func int get(Queue *queue){
*/

int get(Queue *queue){
    return queue->beg->el;
}

/**
 \func int pop(int *iEl, Queue *queue)
*/

int pop(int *iEl, Queue *queue)
{
    if(queue->beg == NULL) return 0;
    Queue *tmp;
    tmp = queue->beg;
    *iEl = tmp->el;
    queue->beg = tmp->next;
    free(tmp);
    if(queue->beg == NULL) queue->end = NULL;
    return 1;
}

/**
 \func Queue *CreateQueue()
*/

Queue *CreateQueue()
{
    Queue *queue = new Queue;
    queue->beg = NULL;
    queue->end = NULL;
    return queue;
}

/**
 \func int isQueueEmpty(Queue *queue)
*/

int isQueueEmpty(Queue *queue)
{
    if(queue->beg == NULL) return 1;
    return 0;
}

/**
 \func int recognize(std::string com, int & data)
*/

int recognize(std::string com, int & data)
{
    if ( com.find("add") != std::string::npos ) {data = std::stoi(com.substr(com.find("add") + 4, 1)); return 1;}
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
    Queue *q = CreateQueue();
    std::cin >> c;
    getline(std::cin, command);
    for(i = 0; i < c; i++){
        getline(std::cin, command);
        a = recognize(command, data);
        switch(a)
        {
            case 1:
                push(data, q);
                std::cout << "\nЭлемент добавлен в конец очереди \n";
                break;


            case 2:
                if (isQueueEmpty(q)==1)
                    std::cout << "\nОчередь пустая \n";
                else
                {
                    std::cout << get(q) << std::endl;
                }
                break;

            case 3:
                if (isQueueEmpty(q) == 1)
                    std::cout << "\nОчередь пустая \n";
                else
                {
                    pop(&i, q);
                    std::cout << "\nЭлемент удален из очереди \n";
                }
                break;

            default: std::cout << "\nОшибка! Неправильно введена команда! \n"; break;
        }
    }

    return 0;
}


