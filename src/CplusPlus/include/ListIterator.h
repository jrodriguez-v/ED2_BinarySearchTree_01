#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include <List.h>
#include <Node.h>

template <class T>
class ListIterator
{
    public:
        ListIterator(List<T>* p_list, Node<T>* p_node);
        virtual ~ListIterator();

        void Start();
        bool HasNext();
        void Next();
        T GetItem();

    protected:

    private:
        List<T>* m_list;
        Node<T>* m_node;
};

#endif // LISTITERATOR_H
