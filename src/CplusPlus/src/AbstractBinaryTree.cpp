#include "AbstractBinaryTree.h"

#include <List.h>
using namespace std;

template <class T>
AbstractBinaryTree<T>::AbstractBinaryTree()
{
    m_root = nullptr;
}

template <class T>
bool AbstractBinaryTree<T>::IsEmpty()
{
    return IsEmptyNode(m_root);
}

template <class T>
BinaryTreeNode<T>* AbstractBinaryTree<T>::Find(T p_info)
{
    BinaryTreeNode<T>* current = m_root;

    while(!IsEmptyNode(current))
    {
        if(p_info == current->GetInfo())
            return current;

        //Si p_info es menor que el valor del actual nodo, sigue buscando por la izquierda
        //Si p_info es mayor que el valor del actual nodo, sigue buscando por la derecha
        current = p_info < current->GetInfo() ? current->GetLeft() : current->GetRight();
    }

    return nullptr;
}

template <class T>
bool AbstractBinaryTree<T>::IsEmptyNode(BinaryTreeNode<T>* p_node)
{
    return p_node == nullptr;
}

template <class T>
List<T>* AbstractBinaryTree<T>::TraversePreOrder()
{
    List<T>* result = new List<T>();

    PreOrder(m_root, result);

    return result;
}

template <class T>
List<T>* AbstractBinaryTree<T>::TraverseInOrder()
{
    List<T>* result = new List<T>();

    InOrder(m_root, result);

    return result;
}

template <class T>
List<T>* AbstractBinaryTree<T>::TraversePostOrder()
{
    List<T>* result = new List<T>();

    PostOrder(m_root, result);

    return result;
}

template <class T>
void AbstractBinaryTree<T>::PreOrder(BinaryTreeNode<T>* p_node, List<T>* p_result)
{
    //Root-Left-Right
    if(IsEmptyNode(p_node))
        return;

    p_result->Append(p_node->GetInfo());

    PreOrder(p_node->GetLeft(), p_result);
    PreOrder(p_node->GetRight(), p_result);
}

template <class T>
void AbstractBinaryTree<T>::InOrder(BinaryTreeNode<T>* p_node, List<T>* p_result)
{
    //Left-Root-Right
    if(IsEmptyNode(p_node))
        return;

    InOrder(p_node->GetLeft(), p_result);

    p_result->Append(p_node->GetInfo());

    InOrder(p_node->GetRight(), p_result);
}

template <class T>
void AbstractBinaryTree<T>::PostOrder(BinaryTreeNode<T>* p_node, List<T>* p_result)
{
    //Left-Right-Root
    if(IsEmptyNode(p_node))
        return;

    PostOrder(p_node->GetLeft(), p_result);

    PostOrder(p_node->GetRight(), p_result);

    p_result->Append(p_node->GetInfo());
}

template <class T>
AbstractBinaryTree<T>::~AbstractBinaryTree()
{
    delete m_root;
}

#include <AbstractBinaryTree.h>
template class AbstractBinaryTree<int>;
