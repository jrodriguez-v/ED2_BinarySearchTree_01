#ifndef TREEMANAGER_H
#define TREEMANAGER_H

#include <AbstractBinaryTree.h>
#include <List.h>
#include <string>
using namespace std;

template <class T>
class TreeManager
{
    public:
        TreeManager(AbstractBinaryTree<T>* p_tree);
        virtual ~TreeManager();

        void Add(int p_info);
        void PrintTreeTraversals();

    protected:
        AbstractBinaryTree<T>* m_tree;
        List<T>* m_log;

    private:
        void Print(List<T>* p_list, string p_title);
};

#endif // TREEMANAGER_H
