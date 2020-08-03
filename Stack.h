#ifndef _STACK_H
#define _STACK_H
#include <iostream>
#include<string>
using namespace std;
template<class StackElementType>
class Stack
{
    public:
        Stack();
        void push(StackElementType e);
        StackElementType pop();
        bool isempty ();
        StackElementType top();

    private:
        struct Node;
        typedef Node* link ;
        struct Node
        {
            StackElementType data;
            link next;
        };
        link head ;
};
#endif // _STACK_H
