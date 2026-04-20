#pragma once
//q array based implementation  streller

#include "array_v.h"
#ifndef Q_ARRAY_H__
#define Q_ARRAY_H__

template <class BaseData>
class Queue
{
public:
	Queue();  //constructor
	Queue(int size);
	Queue(Queue& initq); // copy constructor
	~Queue();    //destructor
	BaseData front();
	int emptyQ();
	int fullQ();
	void enQ(BaseData item);
	void deQ();

private:
	int maxQ;
	Array_V<int, BaseData>* nodes;
	int frontI, rearI;
};

#include "q_array.t"

#endif

