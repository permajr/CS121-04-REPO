#include <string>
#include <fstream>
#include <iomanip>
#include "treeNode.h"

#ifndef TREE_H__
#define TREE_H__

#pragma once


template <class BaseData>
struct  TreeNode
{
    BaseData TreeData;
    TreeNode* left = NULL, * right = NULL;
};


template <class BaseData>
class  tree
{    
    
    friend class oxyRecord;

public:
    tree();
    ~tree();
    tree(tree<BaseData>& t);
    tree<BaseData>& operator = (const tree<BaseData>& t);
    void insert(BaseData& item);
    void SearchAndDestroy(BaseData target);
    void writeTree(int);
    int fullTree() const;
    int emptyTree() const;

protected:   //helping functions
    void remove(TreeNode<BaseData>*& current);
    void inOrder(TreeNode<BaseData>*);
    void preOrder(TreeNode<BaseData>*);
    void postOrder(TreeNode<BaseData>*);
    void destroy(TreeNode<BaseData>* p);
    void copyTreeNode(TreeNode <BaseData>** into,
        TreeNode<BaseData>* from);
    void insertNode(TreeNode<BaseData>** into,
        BaseData& item);
    TreeNode <BaseData>* getnode(BaseData& item);

private:
    TreeNode<BaseData>* root;

};

//gets storage for a new node to be inserted into the tree
template <class BaseData>
TreeNode <BaseData>* tree<BaseData>::getnode(BaseData& item)
{
    TreeNode<BaseData>* temp = new TreeNode<BaseData>;
    if (temp)
    {
        temp->TreeData = item;
        temp->left = 0;
        temp->right = 0;
    }
    return temp;
}

#include "tree.t"

#endif