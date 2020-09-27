#include "BinarySearchTree.h"
#include <AbstractBinaryTree.h>
#include <BinaryTreeNode.h>

using namespace std;

template <class T>
BinarySearchTree<T>::BinarySearchTree(): AbstractBinaryTree<T>()
{
}

template <class T>
void BinarySearchTree<T>::Insert(T p_info)
{
    if(this->IsEmptyNode(this->m_root))
    {
        this->m_root = new BinaryTreeNode<T>(p_info);
    }
    else if(Exists(p_info))
    {
        return;
    }
    else
    {
        BinaryTreeNode<T>* current = this->m_root;

        while(!this->IsEmptyNode(current))
        {
            //Si el valor ingresado es menor a la raíz, va por la izquierda
            if(p_info < current->GetInfo())
            {
                if(this->IsEmptyNode(current->GetLeft()))
                {
                    BinaryTreeNode<T>* left = new BinaryTreeNode<T>(p_info);
                    current->SetLeft(left);
                    current = nullptr;//detiene el ciclo
                }
                else
                {
                    current = current->GetLeft();
                }
            }
            else //Si el valor ingresado es mayor a la raíz, va por la derecha
            {
                if(this->IsEmptyNode(current->GetRight()))
                {
                    BinaryTreeNode<T>* right = new BinaryTreeNode<T>(p_info);
                    current->SetRight(right);
                    current = nullptr;//detiene el ciclo
                }
                else
                {
                    current = current->GetRight();
                }
            }
        }
    }
}

template <class T>
bool BinarySearchTree<T>::Exists(T p_info)
{
    auto found = this->Find(p_info);
    return !this->IsEmptyNode(found);
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
}

#include <BinarySearchTree.h>
template class BinarySearchTree<int>;
