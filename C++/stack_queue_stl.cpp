#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main() 
{
    stack<int> myStack;
    int ch;
    while(true)
    {
        cout<<"\nEnter 1 to enter value to stack or enter 0 to stop: ";
        cin>>ch;
        if(ch==0)
            break;
        cout<<"Enter number: ";
        cin>>ch;
        myStack.push(ch);
    }
    cout << "\nThe count of stack elements is " << myStack.size() << endl;
    cout << "\nSTACK ELEMENTS(displaying top element and then poping): \n";
    while (!myStack.empty()) 
    {
        cout << myStack.top() << "\n";
        myStack.pop();
    }

    cout << endl;
    cout << "EXITING STACK...UNDERFLOWS!" << endl;
    cout << endl;

    queue<string> myQueue;
    string st;
    while(true)
    {
        cout<<"\nEnter 1 to enter string to queue or enter 0 to stop: ";
        cin>>ch;
        if(ch==0)
            break;
        cout<<"Enter string: ";
        cin>>st;
        myQueue.push(st);
    }
    cout << "\nThe count of queue elements is " << myQueue.size() << endl;
    cout << "\nQUEUE ELEMENTS(displaying front element and then dequeing): \n";
    while (!myQueue.empty()) 
    {
        cout << myQueue.front() << "   ";
        myQueue.pop();
    }
    cout << "\n\nEXITING QUEUE...UNDERFLOWS!" << endl;
    cout << endl;

    return 0;
}
