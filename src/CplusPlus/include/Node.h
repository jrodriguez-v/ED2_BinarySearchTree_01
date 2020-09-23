#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
    public:
        Node(T p_info);
        virtual ~Node();

        void SetInfo(T p_info);
        T GetInfo();
        Node<T>* GetNext();
        void SetNext(Node<T>* p_next);

    private:
        T m_info;
        Node<T>* m_next;
};
#endif // NODE_H
