#include"Stack.h"
template<class StackElementType>

Stack<StackElementType>::Stack()
{
    head = NULL;
}

template<class StackElementType>
void Stack<StackElementType>::push(StackElementType e)
{
    link addedNode;
    addedNode = new Node ;
    addedNode->data= e;
    addedNode->next = head ;
    head = addedNode ;
}

template<class StackElementType>
bool Stack<StackElementType>::isempty()
{
    if(head == NULL)
        return true ;
    else
        return false;
}

template<class StackElementType>
StackElementType Stack<StackElementType>::pop()
{
    StackElementType data = head->data ;
//    cout<<data<<" will be popped"<<endl;
    link newhead = head->next;
    delete head;
    head = newhead ;
    return data;

}

template<class StackElementType>
StackElementType Stack<StackElementType>::top()
{
    StackElementType data = head->data ;
    return data;
}
