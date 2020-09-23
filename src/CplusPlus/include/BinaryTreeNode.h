#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H



template <class T>
class BinaryTreeNode
{
    public:
        BinaryTreeNode(T p_info);
        virtual ~BinaryTreeNode();

        void SetInfo(T p_info);
        T GetInfo();

        BinaryTreeNode<T>* GetLeft();
        BinaryTreeNode<T>* GetRight();

        void SetLeft(BinaryTreeNode<T>* p_left);
        void SetRight(BinaryTreeNode<T>* p_right);

    private:
        T m_info;
        BinaryTreeNode<T>* m_left;
        BinaryTreeNode<T>* m_right;
};

#endif // BINARYTREENODE_H
