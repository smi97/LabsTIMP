#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PriorityTree
{
private:
    vector<int> tree;
public:
    void add(int value)
    {
        tree.push_back(value);
        std::sort(tree.begin(), tree.end());
    }

    void del()
    {
        tree.erase(tree.begin());
    }

    int get() const
    {
        return tree[0];
    }
};

int recognize(std::string com, int & data)
{
    if ( com.find("add") != std::string::npos )
    {
        data = std::stoi(com.substr(com.find("add") + 4, 1));
        return 1;
    }
    if ( com.find("get") != std::string::npos )
        return 2;
    if ( com.find("del") != std::string::npos )
        return 3;
    return 0;
}


int main() {
    std::string command;
    PriorityTree pq;
    int c, a, data;
    std::cin >> c;
    getline(std::cin, command);
    for (int i = 0; i < c; ++i)
    {
        getline(std::cin, command);
        a = recognize(command, data);
        switch(a)
        {
            case 1:
                pq.add(data);
                break;
            case 2:
                std::cout << pq.get() << std::endl;
                break;

            case 3:
                pq.del();
                break;

            default:
                std::cout << "\nОшибка! Неправильно введена команда! \n";
                i--;
                break;

        }


    }
    return 0;
}