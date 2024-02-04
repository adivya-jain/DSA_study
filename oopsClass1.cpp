#include<iostream>
using namespace std;

class Hero{
    public:
    int health;
    int level;
    Hero()
    {
        cout<<"address of this ->"<<this<<endl;
        cout<<"this keyword stores the address the current object"<<endl;
        cout<<"hello default constructor"<<endl;
    }
    Hero(int health)
    {
        this->health=health;
        cout<<"this is parameterized constructor"<<endl;
    }
    Hero(int health,int level)
    {
        this->level=level;
        this->health=health;
    }
};


int main()
{
    Hero adi(68);
    cout<<"size of adi is"<<sizeof(adi)<<endl;

//copy constructor 
//shallow copy and deep copy
    
return 0;
}