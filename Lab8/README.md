# lab8
TIMP
Написать программу, реализующую шаблон проектирования "фабрика классов"
1. Есть базовый класс Base 
class Base {
public:
	virtual void show()=0;
private:
	int value;
};
И классы наследники:
class A: public Base{
public:
	void show(){ cout<<"class A: "<<value<<endl;}
};
class B: public Base{
public:
	void show(){ cout<<"class B: "<<value<<endl;}
};
class C: public Base{
public:
	void show(){ cout<<"class C: "<<value<<endl;}
};

В программе, в зависимости от вводимой пользователем команды реализовать:
create <classname> <value> - функция создания экземпляра класса типа classname со значением value;
showall - функция вызова для всех созданных экземпляров функции show();

2. Входные данные:
N - количество команд;
<команда (create <classname> <value>)|(showall)> - по числу команд N;

3. Выходные данные:
распечатанный вывод функций show() для всех экземпляров классов.

4. Пример:
Входные данные:
4
create A 10
create B 20
create C 1
showall

Выходные данные:
class A: 10
class B: 20
class C: 1
