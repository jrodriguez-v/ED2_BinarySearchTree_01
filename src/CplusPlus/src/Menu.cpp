#include "Menu.h"
#include<List.h>
#include<ListIterator.h>

#include <regex>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Menu::Menu(TreeManager<int>* p_manager)
{
    if(p_manager == nullptr)
        throw std::invalid_argument("p_manager no puede ser nulo.");

    m_manager = p_manager;
}

void Menu::Display()
{
    string input;
    char exit ='x';
    char option;
    do
    {
        PrintOptions();
        getline(std::cin >> std::ws, input);
        option = input[0];
        switch(option)
        {
            case 'a':
                AddInput();
                break;
            case 'b':
                PrintTree();
                break;
            default:
                if(option != exit) cout << "Escriba la opcion correcta"<< endl;
            break;
        }
    }while(option != exit);
}

void Menu::PrintOptions()
{
    cout << "\n";
    cout << " Escriba la opción: " << endl;
    cout << "  a) Agregar item al árbol" << endl;
    cout << "  b) Imprimir árbol" << endl;
    cout << "  x) Salir" << endl;
}

void Menu::AddInput()
{
    string input;
    regex regexp("(\\s*\\d+\\s*)(,*\\s*\\d+\\s*)*(,)*");

    do
    {
        cout <<"   Un nro o una lista de nros separados por coma (,):  ";
        getline(std::cin >> std::ws, input);

        List<int>* numbers = GetNumbers(input);
        ListIterator<int>* iterador = numbers->GetIterator();
        for(iterador->Start(); iterador->HasNext(); iterador->Next())
        {
            m_manager->Add(iterador->GetItem());
        }

    }
    while(!regex_match(input,regexp));
}

void Menu::PrintTree()
{
    m_manager->PrintTreeTraversals();
}

List<int>* Menu::GetNumbers(string p_csv_list)
{
    List<int>* numbers = new List<int>();


    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;
    while ((pos = p_csv_list.find(delimiter)) != std::string::npos)
    {
        token = p_csv_list.substr(0, pos);
        TryAdd(numbers, token);

        p_csv_list.erase(0, pos + delimiter.length());
    }
    TryAdd(numbers, p_csv_list);

    return numbers;
}

void Menu::TryAdd(List<int>* p_list, string &value)
{
    regex regexp("\\s*\\d+\\s*");

    if(regex_match(value,regexp))
    {
         int number = std::stoi(value);
         p_list->Append(number);
    }
}

Menu::~Menu()
{
    delete m_manager;
}
