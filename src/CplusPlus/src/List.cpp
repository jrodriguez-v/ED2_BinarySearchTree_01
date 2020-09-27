#include "List.h"
#include <Node.h>
#include <ListIterator.h>

template <class T>
List<T>::List()
{
    m_head = m_tail = nullptr;
    m_count = 0;
}

template <class T>
bool List<T>::Append(T p_info)
{
    Node<T>* nuevo = new Node<T>(p_info);

    if(IsEmpty())
    {
        m_head = m_tail = nuevo;
    }
    else
    {
        m_tail->SetNext(nuevo);
        m_tail = m_tail->GetNext();
    }
    m_count++;

    return true;
}

template <class T>
bool List<T>::IsEmpty()
{
    return m_head == nullptr;
}

template <class T>
int List<T>::Count()
{
    return m_count;
}

template <class T>
Node<T>* List<T>::GetHead()
{
    return m_head;
}

template <class T>
ListIterator<T>* List<T>::GetIterator()
{
    return new ListIterator<T>(this, this->GetHead());
}

template <class T>
List<T>::~List()
{
    Node<T>* aux = m_head;
    Node<T>* next = nullptr;

    while(aux != nullptr)
    {
        next = aux->GetNext();
        delete aux;
        aux = next;
    }
}

#include <List.h>
template class List<int>;
