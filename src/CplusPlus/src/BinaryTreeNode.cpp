#include "BinaryTreeNode.h"

using namespace std;

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(T p_info)
{
    this->SetInfo(p_info);
    m_left = nullptr;
    m_right = nullptr;
}

template <class T>
void BinaryTreeNode<T>::SetInfo(T p_info)
{
    m_info = p_info;
}

template <class T>
T BinaryTreeNode<T>::GetInfo()
{
    return m_info;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::GetLeft()
{
    return m_left;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::GetRight()
{
    return m_right;
}

template <class T>
void BinaryTreeNode<T>::SetLeft(BinaryTreeNode<T>* p_left)
{
    m_left = p_left;
}

template <class T>
void BinaryTreeNode<T>::SetRight(BinaryTreeNode<T>* p_right)
{
    m_right = p_right;
}

template <class T>
BinaryTreeNode<T>::~BinaryTreeNode()
{
    delete m_left;
    delete m_right;
}

#include <BinaryTreeNode.h>
template class BinaryTreeNode<int>;
