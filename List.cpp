#include <iostream>
#include <string>

using namespace std;

struct element
{
        element * next;
        int number;
};
class spisok
{
private:
        element * first;
        element * last;

public:
        spisok():first(NULL), last(NULL)
{
        ;
}
void add(int new_element)
{
        if(first==NULL)
                {
                        first=new element;
                        first->number=new_element;
                        first->next=NULL;
                        last=first;
            } 
        else
        {
                element * new_element_=new element;
                new_element_->number=new_element;
                last->next=new_element_;
                last=new_element_;
                last->next=NULL;
        }
}
int ket(int i)
{
        if (i<0) return 0;
        element * currect=first;
        int k=1;
        while(currect)
        {
                if(k==i)
                        return currect->number;
                k++;
                currect=currect->next;
        }
        return 0;
}
~spisok()
{
        element * currect=first;
        while(currect)
        {
                element * next=currect->next;
                delete currect;
                currect=next;
        }
}
};



void main()
{
        setlocale(LC_ALL, "Russian");
        system("title Список");
        spisok spisok1;
        while(true)
        {
                cout<<"\nДобавить элемент?(y/n)"<<endl;
                string input;
                cin>>input;
                if (input=="y")
                {
                        int input_number;
                        cout<<"\nВведите число: ";
                        cin>>input_number;
                        spisok1.add(input_number);
                }
                else 
                        if (input=="n")
                                break;
                        else
                        {
                                cout<<"\nОшибка ввода. The end."<<endl;
                                system("pause");
                                return;
                        }
        }
        cout<<"\nВведите номер получаемого элемента: "<<endl;
        int numberber;
        cin>>numberber;
        cout<<endl<<spisok1.ket(numberber)<<endl;
        system("pause");
}