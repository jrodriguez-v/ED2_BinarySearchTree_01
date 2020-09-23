#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <BinaryTreeNode.h>
#include <Queue.h>

template <class T>
class BinarySearchTree
{
    public:
        BinarySearchTree();
        virtual ~BinarySearchTree();

        void Insert(T p_info);

        Queue<T>* TraversePreOrder();
        Queue<T>* TraverseInOrder();
        Queue<T>* TraversePostOrder();

    protected:
        bool IsEmpty(BinaryTreeNode<T>* p_node);
        void PreOrder(BinaryTreeNode<T>* p_node, Queue<T>* p_result);
        void InOrder(BinaryTreeNode<T>* p_node, Queue<T>* p_result);
        void PostOrder(BinaryTreeNode<T>* p_node, Queue<T>* p_result);

    private:
        BinaryTreeNode<T>* m_root;
};

#endif // BINARYSEARCHTREE_H
