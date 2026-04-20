#pragma once
#include "q_array.h"

#ifndef Q_ARRAY_T_
#define Q_ARRAY_T_

template <class BaseData>
Queue<BaseData>::Queue()
{
	cout << "q constr " << endl;
	(*this).maxQ = 11;
	this->nodes = new Array_V<int, BaseData>(1, (*this).maxQ);
	(*this).frontI = 1;
	(*this).rearI = maxQ;
}

template <class BaseData>
Queue<BaseData>::Queue(int size)
{
	(*this).maxQ = size + 1;
	this->nodes = new Array_V<int, BaseData>(1, (*this).maxQ);
	(*this).frontI = 1;
	(*this).rearI = (*this).maxQ;
}

template <class BaseData>
Queue<BaseData>::Queue(Queue<BaseData>& initq)

{
	(*this).maxQ = initq.maxQ;
	(*this).frontI = initq.frontI;
	(*this).rearI = initq.rearI;
	this->nodes = new Array_V<int, BaseData>(1, (*this).maxQ);
	for (int i = 1; i <= (*this).maxQ; i++)
		(*nodes)[i] = (*initq.nodes)[i];
}
template <class BaseData>
Queue<BaseData>::~Queue()
{
	delete nodes;
}

template <class BaseData>
int Queue<BaseData>::emptyQ()
{
	return (((*this).rearI % (*this).maxQ) + 1 == (*this).frontI);
}

template <class BaseData>
int Queue<BaseData>::fullQ()
{
	return ((((*this).rearI + 1) % (*this).maxQ + 1) == (*this).frontI);
}

template <class BaseData>
BaseData Queue<BaseData>::front()
{
	return ((*nodes)[(*this).frontI]);
}

template <class BaseData>
void Queue<BaseData>::enQ(BaseData item)
{
	if (!Queue<BaseData>::fullQ())
	{
		(*this).rearI = (*this).rearI % (*this).maxQ + 1;
		(*nodes)[(*this).rearI] = item;
	}
	else cout << " full q! " << endl;
}
template <class BaseData>
void Queue<BaseData>::deQ()
{
	if (!Queue<BaseData>::emptyQ())
		(*this).frontI = (*this).frontI % (*this).maxQ + 1;
	else cout << "empty Q " << endl;
}

#endif
