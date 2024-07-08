#include<iostream>
#include<string>
#include<list>
using namespace std;

class sparepart
{
public:
string name,size,pid;
int quantity;
float price;
sparepart(string n,string s,string id,int q,float p)
	{
	name=n;
	size=s;
	pid=id;
	quantity=q;
	price=p;
	}
void display()
	{
	cout<<"Name:"<<name<<endl;
	cout<<"ID:"<<pid<<endl;
	cout<<"Quantity:"<<quantity<<endl;
	cout<<"Size:"<<size<<endl;
	cout<<"Price:"<<price<<endl;
	}
}; 

void print_list(list<sparepart>& ll)
{
    for(list<sparepart>::iterator it=ll.begin();it!=ll.end();it++)
    {
        it->display();
        cout<< endl;
    }
    cout<<"Size of list:"<<ll.size()<<endl;
}

int main()
{
    sparepart a("Nut","25mm","n101",105,5.5);
    sparepart b("Bolt","3cm","s103",250,6.5);
    sparepart c("Engine","5kg","eng120",10,15000);
    list<sparepart> lt={a,b,c};
    print_list(lt);
    cout<<endl;
    sparepart d("Handle","1m","hn123",25,2500);
    lt.push_back(d);
    print_list(lt);
    return 0;
}