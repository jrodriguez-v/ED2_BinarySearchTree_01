#ifndef LIST_H
#define LIST_H

#include <Node.h>

//forward declaration: para evitar el error "Class name does not name a type" debido a la referencia circular
template <class T>
class ListIterator;

template <class T>
class List
{
    public:
        List();
        virtual ~List();

        bool Append(T p_info);

        bool IsEmpty();
        int Count();

        Node<T>* GetHead();
        ListIterator<T>* GetIterator();

    protected:
        Node<T>* m_head;
        Node<T>* m_tail;
        int m_count;
};

#endif // LIST_H
