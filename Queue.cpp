#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Queue
{
private:
        int * ptr;
        int proportions;
        int lgth;
        int first;
        int last;
public:
        Queue():lgth(0), first(0), last(-1)
{
        cout<<"Введите размер очереди:";
        cin>>proportions;
        while (proportions<=0)
        {
                cout<<"\nНеверный размер очереди\n"<<endl;
                cout<<"Введите размер очереди:";
                cin>>proportions;
        }
        ptr=new int [proportions];
}
bool not_full()
{
        if (lgth<proportions) 
                return true;
        else
                return false;
}
bool not_empty()
{
        if (lgth>0)
                return true;
        else
                return false;
}
void input()
{
        if(not_full())
        {
                int number;
                cout<<"\nВведите число: ";
                cin>>number;
                last=(last+1)%proportions;
                ptr[last]=number;
                lgth++;
                cout<<endl;
        }
        else
                cout<<"\nОчередь полна\n"<<endl;
}
void Take()
{
        if (not_empty())
        {
                cout<<"\nУдаленный элемент: "<<ptr[first]<<endl<<endl;
                first=(first+1)%proportions;
                lgth--;
        }
        else
                cout<<"\nОчередь пуста\n"<<endl;
}
void out()
{
        if (not_empty())
        {
                int numberber=0;
                cout<<"\nВведите номер элемента:";
                cin>>numberber;
                while (!((0<numberber)&&(numberber<=lgth)))
                {
                        cout<<
                                "\nНомер элемента должен быть больше нуля"
                                "и не выходить за пределы очереди\n"
                                    <<endl;
                        cout<<"Введите номер элемента:";
                        cin>>numberber;
                }
                cout<<endl<<ptr[(first+numberber-1)%proportions]<<endl<<endl;
        }
        else
                cout<<"\nОчередь пуста\n"<<endl;
}
~Queue()
{
        delete [] ptr;
}
};


char message()
{
        char * mes="Выребите действие:\n"
                "1)Добавить элемент\n"
                "2)Удалить элемент\n"
                "3)Вывести i-й элемент\n"
                "4)Выйти\n";
        cout<<mes;
        char message;
        cin.clear();
        message=getch();
        system("CLS");
        return message;
}
void main()
{
        setlocale(LC_ALL, "Russian");
        system("title Очередь");
        Queue First;
        char off=1;
        while(off)
        {
                switch(message())
                {
                case '1':
                        {
                                First.input();
                                break;
                        }
                case '2':
                        {
                                First.Take();
                                break;
                        }
                case '3':
                        {
                                First.out();
                        }
                        break;
                case '4':
                        off=0;
                        break;
                default:
                        cout<<"\nНеверный ввод. Повторите ввод.\n\n";
                        break;
                }
        }
        system("pause");
}
