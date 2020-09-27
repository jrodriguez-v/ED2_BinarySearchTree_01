#include "UI.h"
#include <TreeManager.h>
#include <BinarySearchTree.h>

UI::UI()
{
    AbstractBinaryTree<int>* btree = new BinarySearchTree<int>();
    TreeManager<int>* manager = new TreeManager<int>(btree);

    m_menu = new Menu(manager);
}

void UI::Start()
{
    m_menu->Display();
}

UI::~UI()
{
    delete m_menu;
}
