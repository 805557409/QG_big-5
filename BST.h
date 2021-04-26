#pragma once
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

//
// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int

template <typename T>
class Node
{
public:
    T value;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
};

template <typename T>
class BinarySortTree :public Node<T>
{
private:
    Node<T>* root;
public:
//初始化
    BinarySortTree();

//销毁排序二叉树
    ~BinarySortTree();

/**
* BST insert
* @param BinarySortTreePtr BST
* @param ElemType value to insert
* @return is successful
*/
    bool BST_insert(const T value);

/**
* BST delete
* @param BinarySortTreePtr BST
* @param ElemType the value for Node which will be deleted
* @return is successful
*/
    bool BST_delete(T value);

/**
* BST search
* @param BinarySortTreePtr BST
* @param ElemType the value to search
* @return is exist
*/
    Node<T>* BST_search(T value);

/**
* BST preorder traversal without recursion
* @param BinarySortTreePtr BST
* @param (*visit) callback
* @return is successful
*/
    void BST_preorderI();

/**
* BST preorder traversal with recursion
* @param BinarySortTreePtr BST
* @param (*visit) callback
* @return is successful
*/
    void BST_preorderR(Node<T>* p);

/**
* BST inorder traversal without recursion
* @param BinarySortTreePtr BST
* @param (*visit) callback
* @return is successful
*/
    void BST_inorderI();

/**
* BST inorder traversal with recursion
* @param BinarySortTreePtr BST
* @param (*visit) callback
* @return is successful
*/
    void BST_inorderR(Node<T>* p);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
    void BST_postorderI();

/**
* BST postorder traversal with recursion
* @param BinarySortTreePtr BST
* @param (*visit) callback
* @return is successful
*/
    void BST_postorderR(Node<T>* p);

/**
* BST preorder traversal with recursion
* @param BinarySortTreePtr BST
* @param (*visit) callback
* @return is successful
*/
    void BST_preorderR();

/**
* BST inorder traversal with recursion
* @param BinarySortTreePtr BST
* @param (*visit) callback
* @return is successful
*/
    void BST_inorderR();

/**
* BST postorder traversal with recursion
* @param BinarySortTreePtr BST
* @param (*visit) callback
* @return is successful
*/
    void BST_postorderR();

 /**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
    void BST_levelOrder();


    void destroy(Node<T>* p);

    Node<T>* getParent(Node<T>* p);

    void show_Menu();
    void exitSystem();
};

#endif //BINARYSORTTREE_BINARY_SORT_TREE_H