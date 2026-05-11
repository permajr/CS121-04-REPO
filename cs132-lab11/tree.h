


#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

#ifndef TREE_H__
#define TREE_H__

//header file for a Binary tree with the ordering property
//BaseData class is assumed to have overloaded relational
//> < == !=  <= >=       operators if not a base type

template <class BaseData>
struct  TreeNode
{
    BaseData TreeData;
    TreeNode* left, * right;
};

//these are file level because traversals are recursive
//void openOutFile();  //probably not the same as yours
//ofstream opf;         //opf is ofstream object used

template <class BaseData>
class  tree
{      //friend class stated here;
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

#include "tree.t"
#endif
#pragma once

