#include "ListIterator.h"

#include <List.h>
#include <Node.h>

template <class T>
ListIterator<T>::ListIterator(List<T>* p_lista, Node<T>* p_nodo)
{
    m_list = p_lista;
    m_node = p_nodo;
}

template <class T>
void ListIterator<T>::Start()
{
    if(m_list != nullptr)
        m_node = m_list->GetHead();
}

template <class T>
bool ListIterator<T>::HasNext()
{
    return m_node != nullptr;
}

template <class T>
void ListIterator<T>::Next()
{
    if(m_node != nullptr)
        m_node = m_node->GetNext();
}

template <class T>
T ListIterator<T>::GetItem()
{
    return m_node->GetInfo();
}

template <class T>
ListIterator<T>::~ListIterator()
{
    delete m_list;
    delete m_node;
}

#include <ListIterator.h>
template class ListIterator<int>;
