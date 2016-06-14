#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Base
{
protected:
    int data;
public:
    Base(int _data) :data(_data) { }

    virtual void show() = 0;
};

class A : public Base
{
public:
    A(int _data) : Base (_data) { }

    void show()
    {
        cout << "class A: " << data << endl;
    }
};

class B : public Base
{
public:
    B(int _data) : Base(_data) { }

    void show()
    {
        cout << "class B: " << data << endl;
    }
};

class C : public Base
{
public:
    C(int _data) : Base(_data) { }
    void show()
    {
        cout << "class C: " << data << endl;
    }
};

vector<Base*> objects;

class Functor
{
public:
    virtual void operator()() { };
    virtual void operator()(string, int) { };
};

class FunctorShow : public Functor
{
public:
    FunctorShow() { };
    void operator()()
    {
        for (auto it = objects.begin(); it != objects.end(); ++it)
            (*it)->show();
    }
};

class FunctorCreate : public Functor
{
public:
    FunctorCreate() { }

    void operator()(string classname, int _data)
    {
        map<string, Base*> classes;
        classes["A"] = new A(_data);
        classes["B"] = new B(_data);
        classes["C"] = new C(_data);
        Base * base;
        base = classes[classname];
        objects.push_back(base);
    }
};

vector<string> recognize(string s)
{
    string temp;
    vector<string> rec;
    istringstream str(s);
    while (str >> temp)
        rec.push_back(temp);
    return rec;
}

int main()
{
    Functor * show = new FunctorShow;
    Functor * create = new FunctorCreate;
    Functor * functor;
    map<string, Functor *> mfunc = {{ "showall", show },
        { "create", create }};
    map<string, int> coms = {{ "showall", 0 },
        { "create", 1 }};
    string command;
    vector<string> recognized;
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i != n; ++i)
    {
        getline(cin, command);
        recognized = recognize(command);
        functor = mfunc[recognized[0]];
        switch(coms[recognized[0]])
        {
            case 0:
                functor->operator()();
                break;
            case 1:
                functor->operator()(recognized[1], stoi(recognized[2]));
                break;
            default:
                cout << "\nОшибка! Неправильно введена команда! \n";
                --i;
                break;
        }
    }
    return 0;
}