//list.h
//B.J. Streller
//Templated definitions of a linked list



#ifndef LIST_H_
#define LIST_H_

#include "listNode.h"




template <class BaseData>
class List
{
	
public:

	List();
	List(List &init);
	~List();
	void first();
	void last();
	void makeCurrent(int position);
	void prev();
	void next();
	int current();
	int count();
	void insertBefore(const BaseData &item);
	void insertAfter(const BaseData &item);
	void remove();
	void replace(BaseData &item);
	BaseData * examine();
	List<BaseData>& operator = (List<BaseData> &source);
	void destroy();

protected:

	ListNode<BaseData> *head, *currentNode, *previous;
	int numNodes;
	int currentPos;

};



#include "list.t"
#endif 
