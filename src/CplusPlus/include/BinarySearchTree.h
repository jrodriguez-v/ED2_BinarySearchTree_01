#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <BinaryTreeNode.h>
#include <AbstractBinaryTree.h>

template <class T>
class BinarySearchTree: public AbstractBinaryTree<T>
{
    public:
        BinarySearchTree();
        virtual ~BinarySearchTree();

        void Insert(T p_info);

    private:
        bool Exists(T p_info);
};

#endif // BINARYSEARCHTREE_H
