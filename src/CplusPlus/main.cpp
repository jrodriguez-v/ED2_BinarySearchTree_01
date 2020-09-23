#include <iostream>
#include <string>

#include <BinarySearchTree.h>
#include <Queue.h>

using namespace std;

void PrintQueue(Queue<int>* p_queue, string p_title);

int main()
{

    BinarySearchTree<int>* tree = new BinarySearchTree<int>();
    tree->Insert(32);
    tree->Insert(68);
    tree->Insert(12);
    tree->Insert(75);
    tree->Insert(6);
    tree->Insert(42);
    tree->Insert(84);
    tree->Insert(99);
    tree->Insert(69);
    tree->Insert(7);
    tree->Insert(27);
    tree->Insert(73);

    Queue<int>* queue_preorder = tree->TraversePreOrder();
    Queue<int>* queue_inorder = tree->TraverseInOrder();
    Queue<int>* queue_postorder = tree->TraversePostOrder();

    PrintQueue(queue_preorder, "PREORDER");
    PrintQueue(queue_inorder, "INORDER");
    PrintQueue(queue_postorder, "POSTORDER");

    return 0;
}

void PrintQueue(Queue<int>* p_queue, string p_title)
{
    cout << p_title << endl;

    while(!p_queue->IsEmpty())
    {
        cout << p_queue->Dequeue() << " | ";
    }

    cout << endl << endl;
}
