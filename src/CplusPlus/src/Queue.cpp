#include "Queue.h"

#include <Node.h>
#include <iostream>

using namespace std;

template <class T>
Queue<T>::Queue()
{
    m_head = nullptr;
    m_tail = nullptr;
    m_count = 0;
}

template <class T>
void Queue<T>::Enqueue(T p_info)
{
    Node<T>* nuevo = new Node<T>(p_info);

    if(this->IsEmpty())
    {
        m_head = m_tail = nuevo;
    }
    else
    {
        m_tail->SetNext(nuevo);
        m_tail = nuevo;
    }
    m_count++;
}

template <class T>
T Queue<T>::Dequeue()
{
    if(this->IsEmpty())
         throw std::underflow_error("Empty Queue!");

    Node<T>* aux = m_head;
    m_head = m_head->GetNext();
    T info = aux->GetInfo();

    delete aux;
    m_count--;

    if(this->Count() == 0) m_tail = m_head;

    return info;
}

template <class T>
T Queue<T>::GetLast()
{
    if(this->IsEmpty())
         throw std::underflow_error("Empty Queue!");

    return m_tail->GetInfo();
}

template <class T>
bool Queue<T>::IsEmpty()
{
    return m_head == nullptr && m_tail == nullptr;
}

template <class T>
int Queue<T>::Count()
{
    return m_count;
}

template <class T>
Queue<T>::~Queue()
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

#include <Queue.h>
template class Queue<int>;
