#ifndef MENU_H
#define MENU_H

#include <TreeManager.h>
#include <List.h>
#include <string>

class Menu
{
    public:
        Menu(TreeManager<int>* p_manager);
        virtual ~Menu();

        void Display();

    private:
        TreeManager<int>* m_manager;


        void PrintOptions();
        void AddInput();
        void PrintTree();
        List<int>* GetNumbers(string p_csv_list);
        void TryAdd(List<int>* p_list, string &value);
};

#endif // MENU_H
