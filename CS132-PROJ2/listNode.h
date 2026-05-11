//ListNode.h
//B.J. Streller
//defintion of a node


#ifndef LISTNODE_H_
#define LISTNODE_H_



template <class BaseData>
struct ListNode
{
public:
	BaseData listData;
	ListNode *link;
};



#endif 
