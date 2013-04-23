#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Stack
{
private:
        int * ptr;
        int lgth;
public:
        Stack():ptr(NULL), lgth(0)
{
        ;
}
bool blank()
{
        if (lgth==0)
                return true;
        return false;
}
void input()
{
        int number;
        cout<<"Введите число: ";
        cin>>number;
        cout<<endl;
        if(blank())
        {
                ptr=new int[1];
                ptr[0]=number;
                lgth++;
        }
        else
        {
                int * temp=new int [lgth+1];
                for(int g=0;g<lgth;g++)
                {
                        temp[g]=ptr[g];
                }
                delete [] ptr;
                temp[lgth]=number;
                ptr=temp;
                lgth++;
        }
}
void Take()
{
        if(blank())
        {
                cout<<"\nСтек пуст\n"<<endl;
        }
        else
        {
                int el;
                int * temp=new int [lgth-1];
                for(int g=0;g<lgth-1;g++)
                {
                        temp[g]=ptr[g];
                }
                el=ptr[lgth-1];
                delete [] ptr;
                ptr=temp;
                cout<<"\nУдаленный элемент: "<<el<<endl<<endl;
                lgth--;
        }
}
void out()
{
        if(blank())
        {
                cout<<"\nСтек пуст\n"<<endl;
        }
        else
        {
                cout<<endl;
                for(int g=lgth-1;g>=0;g--)
                {
                        cout<<ptr[g]<<endl;
                }
                cout<<endl;
        }
}
~Stack()
{
        delete [] ptr;
}
};


char message()
{
        char * mes="Выребите действие:\n"
                "1)Добавить элемент\n"
                "2)Проверить стек на пустоту\n"
                "3)Удалить элемент\n"
                "4)Вывести стек на экран\n"
                "5)Выйти\n";
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
        system("title Стэк");
        Stack First;
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
                                if(First.blank())
                                        cout<<"Стек пустой"<<endl<<endl;
                                else
                                        cout<<"Стек не пустой"<<endl<<endl;
                                break;
                        }
                case '3':
                        {
                                First.Take();
                                break;
                        }
                case '4':
                        First.out();
                        break;
                case '5':
                        off=0;
                        break;
                default:
                        cout<<"\nНеверный ввод. Повторите ввод.\n\n";
                        break;
                }
        }
        system("pause");
}