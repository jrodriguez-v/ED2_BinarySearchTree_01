#include "TreeManager.h"
#include <ListIterator.h>

#include <string>
#include <iostream>

using namespace std;

template <class T>
TreeManager<T>::TreeManager(AbstractBinaryTree<T>* p_tree)
{
    if(p_tree == nullptr)
        throw std::invalid_argument("p_tree no puede ser nulo.");

    m_tree = p_tree;
    m_log = new List<T>();
}

template <class T>
void TreeManager<T>::Add(int p_info)
{
    m_tree->Insert(p_info);
    m_log->Append(p_info);
}

template <class T>
void TreeManager<T>::PrintTreeTraversals()
{
    if(m_tree->IsEmpty())
    {
        cout << "Arbol vacio" << endl;
        return;
    }

    List<T>* list_preorder = m_tree->TraversePreOrder();
    List<T>* list_inorder = m_tree->TraverseInOrder();
    List<T>* list_postorder = m_tree->TraversePostOrder();

    Print(m_log, "LISTA DE INGRESADOS");

    Print(list_preorder, "PREORDER");
    Print(list_inorder, "INORDER");
    Print(list_postorder, "POSTORDER");
}

template <class T>
void TreeManager<T>::Print(List<T>* p_list, string p_title)
{
    cout << p_title << endl;

    ListIterator<T>* iterador = p_list->GetIterator();
    for(iterador->Start(); iterador->HasNext(); iterador->Next())
    {
        cout << " " << iterador->GetItem() << " | ";
    }

    cout << endl << endl;

}

template <class T>
TreeManager<T>::~TreeManager()
{
    delete m_tree;
    delete m_log;
}

#include <TreeManager.h>
template class TreeManager<int>;
