#ifndef UI_H
#define UI_H

#include <Menu.h>

class UI
{
    public:
        UI();
        virtual ~UI();

        void Start();

    private:
        Menu* m_menu;
};

#endif // UI_H
