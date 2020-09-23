#ifndef QUEUE_H
#define QUEUE_H

#include <Node.h>

template <class T>
class Queue
{
    public:
        Queue();
        virtual ~Queue();

        void Enqueue(T p_info);
        T Dequeue();
        T GetLast();

        bool IsEmpty();
        int Count();

    private:
        Node<T>* m_head;
        Node<T>* m_tail;
        int m_count;
};

#endif // QUEUE_H
