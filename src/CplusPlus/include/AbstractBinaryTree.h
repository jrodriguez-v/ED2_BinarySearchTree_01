#ifndef ABSTRACTBINARYTREE_H
#define ABSTRACTBINARYTREE_H

#include <List.h>
#include <BinaryTreeNode.h>

template <class T>
class AbstractBinaryTree
{
    public:
        AbstractBinaryTree();
        virtual ~AbstractBinaryTree();

        virtual void Insert(T p_info) = 0; //abstract method

        bool IsEmpty();

        List<T>* TraversePreOrder();
        List<T>* TraverseInOrder();
        List<T>* TraversePostOrder();

    protected:

        BinaryTreeNode<T>* m_root;

        BinaryTreeNode<T>* Find(T p_info);
        bool IsEmptyNode(BinaryTreeNode<T>* p_node);
        void PreOrder(BinaryTreeNode<T>* p_node, List<T>* p_result);
        void InOrder(BinaryTreeNode<T>* p_node, List<T>* p_result);
        void PostOrder(BinaryTreeNode<T>* p_node, List<T>* p_result);
};

#endif // ABSTRACTBINARYTREE_H
