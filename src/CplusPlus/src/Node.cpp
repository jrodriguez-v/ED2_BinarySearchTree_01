#include "Node.h"

using namespace std;

template <class T>
Node<T>::Node(T p_info)
{
    SetInfo(p_info);
    SetNext(nullptr);
}

template <class T>
T Node<T>::GetInfo()
{
    return this->m_info;
}

template <class T>
void Node<T>::SetInfo(T p_info)
{
    this->m_info = p_info;
}

template <class T>
Node<T>* Node<T>::GetNext()
{
    return this->m_next;
}

template <class T>
void Node<T>::SetNext(Node<T>* p_next)
{
    this->m_next = p_next;
}

template <class T>
Node<T>::~Node()
{
    //dtor
}

#include <Node.h>
template class Node<int>;
