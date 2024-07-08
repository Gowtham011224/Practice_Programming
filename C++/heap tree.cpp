#include<iostream>
using namespace std;
#include<cmath>
#include<vector>
vector<int> heap;


template<typename T>
void heapify(T p,T lc,T rc)
{
    if(heap[p]<heap[lc] && heap[p]<heap[rc])
        return;
    if(heap[lc] <= heap[rc] && heap[lc]<heap[p])
    {
        T t=heap[lc];
        heap[lc]=heap[p];
        heap[p]=t;
    }
    else if(heap[rc] <= heap[lc] && heap[rc]<heap[p])
    {
        T t=heap[rc];
        heap[rc]=heap[p];
        heap[p]=t;
    }
    return;
}

int menu()
{    
    int ch;
    cout<<endl<<"Menu:\n1.Insert\n2.Delete\n3.Display min heap\n4.END\n";
    cout<<"Choice:";
    cin>>ch;
    return ch;
}

void displayh()
{
    int s=heap.size();
    int j=1,k=1;
    
    for(int i=0;i<s;i++)
    {
        cout<<heap[i]<<" ";
        j++;
        if(j>(int)pow(2,k)-1)
        {
            cout<<endl;
            k++;
        }
    }
    return;
}

void minheap()
{
    int s=heap.size();
    int p=s/2 -1;
    if(p>=0)
    {
    int lc=2*p+1;
    int rc=2*p+2;
    if(!(rc<s))
    {
        if(heap[lc]<heap[p])
        {
        int t=heap[lc];
        heap[lc]=heap[p];
        heap[p]=t;
        }
        p--;
        lc=2*p+1;
        rc=2*p+2;
    }
       
    while(p>=0)
    {
        heapify<int>(p,lc,rc);
        p--;
        lc=2*p+1;
        rc=2*p+2;
    }
    }
    return;
}

int main()
{
    int ch,e;
    while(true)
    {
        ch=menu();
   	    switch(ch)
   	    {
   	        case 1:
   		        cout<<"\nEnter element:";
   		        cin>>e;
                heap.push_back(e);
                minheap();
                cout<<"Element added successfully\n";
		        break;
            case 2:
                if(heap.empty())
                {
                    cout<<"\nNo elements present to delete"<<endl;
                    break;
                }
                cout<<"\nRemoved "<<heap[0]<<endl;
                heap[0]=heap.back();
                heap.pop_back();
                minheap();
                break;
   	        case 3:

                if(heap.empty())
                {
                    cout<<"\tEmpty"<<endl;
                    break;
                }
                cout<<endl<<"Heap array:"<<endl;
                for(int i=0;i<heap.size();i++)
                {
                    cout<<heap[i]<<" ";
                }
                cout<<endl<<"Heap graph:"<<endl;
                displayh();
                cout<<endl;
                break;
   	        case 4:
   		        return 0;
   	        default:
   		        cout<<"Invalid Input";
   	    }
    }
    return 0;
}