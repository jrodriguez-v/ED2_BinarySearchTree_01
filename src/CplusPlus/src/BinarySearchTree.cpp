#include "BinarySearchTree.h"

using namespace std;

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    m_root = nullptr;
}

template <class T>
void BinarySearchTree<T>::Insert(T p_info)
{
    if(IsEmpty(m_root))
    {
        m_root = new BinaryTreeNode<T>(p_info);
    }
    else
    {
        BinaryTreeNode<T>* current = m_root;

        while(!IsEmpty(current))
        {
            //Si el valor ingresado es menor a la raíz, va por la izquierda
            if(p_info < current->GetInfo())
            {
                if(IsEmpty(current->GetLeft()))
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
                if(IsEmpty(current->GetRight()))
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
Queue<T>* BinarySearchTree<T>::TraversePreOrder()
{
    Queue<T>* result = new Queue<T>();

    PreOrder(m_root, result);

    return result;
}

template <class T>
Queue<T>* BinarySearchTree<T>::TraverseInOrder()
{
    Queue<T>* result = new Queue<T>();

    InOrder(m_root, result);

    return result;
}

template <class T>
Queue<T>* BinarySearchTree<T>::TraversePostOrder()
{
    Queue<T>* result = new Queue<T>();

    PostOrder(m_root, result);

    return result;
}

template <class T>
bool BinarySearchTree<T>::IsEmpty(BinaryTreeNode<T>* p_node)
{
    return p_node == nullptr;
}

template <class T>
void BinarySearchTree<T>::PreOrder(BinaryTreeNode<T>* p_node, Queue<T>* p_result)
{
    //Root-Left-Right
    if(IsEmpty(p_node))
        return;

    p_result->Enqueue(p_node->GetInfo());

    PreOrder(p_node->GetLeft(), p_result);
    PreOrder(p_node->GetRight(), p_result);
}

template <class T>
void BinarySearchTree<T>::InOrder(BinaryTreeNode<T>* p_node, Queue<T>* p_result)
{
    //Left-Root-Right
    if(IsEmpty(p_node))
        return;

    InOrder(p_node->GetLeft(), p_result);

    p_result->Enqueue(p_node->GetInfo());

    InOrder(p_node->GetRight(), p_result);
}

template <class T>
void BinarySearchTree<T>::PostOrder(BinaryTreeNode<T>* p_node, Queue<T>* p_result)
{
    //Left-Right-Root
    if(IsEmpty(p_node))
        return;

    PostOrder(p_node->GetLeft(), p_result);

    PostOrder(p_node->GetRight(), p_result);

    p_result->Enqueue(p_node->GetInfo());
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    delete m_root;
}

#include <BinarySearchTree.h>
template class BinarySearchTree<int>;
