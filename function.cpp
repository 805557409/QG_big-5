#include "BST.h"

template <class T>
void BinarySortTree<T>::show_Menu()
{
    cout << "****************************************************************************" << endl;
    cout << "*****************0.退出系统*************************************************" << endl;
    cout << "*****************1.插入数据*************************************************" << endl;
    cout << "*****************2.查找数据*************************************************" << endl;
    cout << "*****************3.删除数据*************************************************" << endl;
    cout << "*****************4.递归前序遍历*********************************************" << endl;
    cout << "*****************5.递归中序遍历*********************************************" << endl;
    cout << "*****************6.递归后序遍历*********************************************" << endl;
    cout << "*****************7.迭代前序遍历*********************************************" << endl;
    cout << "*****************8.迭代中序遍历*********************************************" << endl;
    cout << "*****************9.迭代后序遍历*********************************************" << endl;
    cout << "*****************10.层序遍历************************************************" << endl;
    cout << "****************************************************************************" << endl;
    cout << endl;
}

template <class T>
void BinarySortTree<T>::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

//创建排序二叉树
template <class T>
BinarySortTree<T>::BinarySortTree()
{
    this->root = nullptr;
}

//销毁排序二叉树
template <class T>
BinarySortTree<T>::~BinarySortTree()
{
    destroy(root);

}

template <class T>
void BinarySortTree<T>::destroy(Node<T>* p)
{
    if (p != nullptr)
    {
        if (p->left != nullptr)
            destroy(p->left);
        if (p->right != nullptr)
            destroy(p->right);
        delete p;
        p = nullptr;
    }

}

//插入元素
template <class T>
bool BinarySortTree<T>::BST_insert(const T value)
{

    Node<T>* ptr = new Node<T>;
    ptr->value = value;
    ptr->left = nullptr;
    ptr->right = nullptr;
    if (ptr == nullptr)
    {
        return false;
    }

    if (root == nullptr)
    {
        root = ptr;
        root->left = nullptr;
        root->right = nullptr;
        return true;
    }

    Node<T>* p = root;
    Node<T>* pParent = root;
    while (p != nullptr)
    {

        pParent = p;
        if (value > p->value)
        {
            p = p->right;
        }
        else if (value < p->value)
        {
            p = p->left;
        }
        else
        {

            delete ptr;
            ptr = nullptr;
            return false;
        }
    }

    if (value < pParent->value)
    {
        pParent->left = ptr;
    }
    if (value > pParent->value)
    {
        pParent->right = ptr;
    }
    return true;

}

//删除元素
template <class T>
bool BinarySortTree<T>::BST_delete(T value)
{
    Node<T>* p = this->BST_search(value);
    if (p == nullptr)
    {
        return false;
    }

    if (p->left == nullptr)
    {

        Node<T>* pParent = getParent(p);
        if (pParent->left == p)
            pParent->left = p->right;
        else
            pParent->right = p->right;
        delete p;
        p = nullptr;
        return true;
    }
    else   if (p->right == nullptr)
    {

        Node<T>* pParent = getParent(p);
        if (pParent->left == p)
            pParent->left = p->left;
        else
            pParent->right = p->left;
        delete p;
        p = nullptr;
        return true;
    }
}

//查找元素
template <typename T>
Node<T>* BinarySortTree<T>::BST_search(T value)
{

    Node<T>* ptr = root;

    while (ptr != nullptr)
    {
        if (ptr->value == value)
            return ptr;
        else  if (ptr->value > value)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return nullptr;
}

//递归前序遍历
template <typename T>
void  BinarySortTree<T>::BST_preorderR()
{
    BST_preorderR(root);
}

template <typename T>
void  BinarySortTree<T>::BST_preorderR(Node<T>* p)
{
    if (p != nullptr)
    {
        cout << p->value << endl;
        BST_preorderR(p->left);
        BST_preorderR(p->right);
    }

}

//迭代前序遍历
template <typename T>
void BinarySortTree<T>::BST_preorderI()
{
    stack<Node<T>*>s;
    Node<T>* p = root;
    while (p != nullptr || !s.empty())
    {
        while (p != nullptr)
        {
            cout << p->value << endl;
            s.push(p);
            p = p->left;
        }
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }

}

//递归中序遍历
template<typename T>
void BinarySortTree<T>::BST_inorderR()
{
    BST_inorderR(root);
}

template<typename T>
void BinarySortTree<T>::BST_inorderR(Node<T>* p)
{
    if (p != nullptr)
    {
        BST_inorderR(p->left);
        cout << p->value << endl;
        BST_inorderR(p->right);
    }

}

//迭代中序遍历
template<typename T>
void BinarySortTree<T>::BST_inorderI()
{
    stack<Node<T>*> s;
    Node<T>* p = root;
    while (p != nullptr || !s.empty())
    {
        while (p != NULL)
        {
            s.push(p);
            p = p->left;
        }
        if (!s.empty())
        {
            p = s.top();
            cout << p->value << endl;
            s.pop();
            p = p->right;
        }
    }

}

//递归后序遍历
template<typename T>
void BinarySortTree<T>::BST_postorderR()
{
    BST_postorderR(root);
}

template<typename T>
void BinarySortTree<T>::BST_postorderR(Node<T>* p)
{
    if (p != nullptr)
    {
        BST_postorderR(p->left);
        BST_postorderR(p->right);
        cout << p->value << endl;
    }

}

//迭代后序遍历
template<typename T>
void BinarySortTree<T>::BST_postorderI()
{

    stack<Node<T>*> t;
    stack<Node<T>*> t1;
    t.push(root);
    while (!t.empty())
    {
        root = t.top();
        t1.push(t.top());
        t.pop();
        if (root->left != nullptr)
        {
            t.push(root->left);
        }
        if (root->right != nullptr)
        {
            t.push(root->right);
        }
    }
    //出栈
    while (!t1.empty())
    {
        cout << t1.top()->value << endl;
        t1.pop();
    }
}

//找到对应的父节点
template<class T>
Node<T>* BinarySortTree<T>::getParent(Node<T>* p)
{
    if (p == root)
        return NULL;
    Node<T>* ptr = root;
    Node<T>* ptf = ptr;
    while (ptr != NULL)
    {
        if (ptr->value == p->value)
            return ptf;
        if (ptr->value > p->value)
        {
            ptf = ptr;
            ptr = ptr->left;
        }
        else
        {
            ptf = ptr;
            ptr = ptr->right;
        }
    }
    cout << endl;
}

//层序遍历
template<class T>
void BinarySortTree<T>::BST_levelOrder()
{

    queue < Node<T>*> q;
    q.push(root);

    while (q.empty() == false)  //队列不为空判断
    {
        cout << q.front()->value << " ";

        if (q.front()->left != nullptr)
        {
            q.push(q.front()->left);
        }

        if (q.front()->right != nullptr)
        {
            q.push(q.front()->right);
        }
        q.pop();
    }

}

