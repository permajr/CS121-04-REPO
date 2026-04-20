//File name :list.t
//B.J. Streller
//templated implementation of a linked list as defined in list.h

#ifndef LIST_T_
#define LIST_T_

#include <iostream>

using std::cout;
using std::endl;


template <class BaseData>
List <BaseData>::List()
{
  this -> previous = 0;
  this -> currentNode = 0;
  this -> head = 0;
  this -> numNodes = 0;
  this -> currentPos = 0;
}

template <class BaseData>
List <BaseData>::List(List<BaseData> &init)
{
  if (this == &init) return;
  ListNode<BaseData> *newList, *current, *newNode;
  this -> current = init.head;
  newList = 0;
  this -> head = 0;
  while (this -> current)
    {
      newNode = new ListNode<BaseData>;
      newNode->listData = current->listData;
      newNode->link = 0;

      if (newList)
        {
          newList->link = newNode;
          newList = newList->link;
        }

      else newList = newNode;

      if (this -> current == init.head)
        this -> head = newNode;
      this -> current = current->link;
    }

  this -> numNodes = init.numNodes;
  this -> currentPos = 0;
  this -> previous = 0;
  this -> currentNode = 0;
}


template <class BaseData>
BaseData * List<BaseData>::examine()
{
  BaseData *temp;
  if (this -> currentNode)
    {
      temp = new BaseData;
      *temp = this -> currentNode->listData;
      return (temp);
    }
  else
    return 0;
}

template <class BaseData>
List <BaseData>::~List()
{
  this -> destroy();
}

template <class BaseData>
void List<BaseData>::destroy()
{
  ListNode<BaseData> *temp;
  this -> currentNode = head;
  while (this -> currentNode)
    {
      temp = currentNode;
      this -> currentNode = currentNode->link;
      delete temp;

    }

  this -> previous = 0;
  this -> currentNode = 0;
  this -> head = 0;
  this -> numNodes = 0;
  this -> currentPos = 0;
}



template <class BaseData>
void List <BaseData>::first()
{
  if (this -> numNodes)
    {
      this -> previous = 0;
      this -> currentNode = head;
      this -> currentPos = 1;
    }
  else
    this -> currentPos = 0;
}



template <class BaseData>
void List <BaseData>::last()
{
  while (this -> currentNode->link)
    {
      this -> previous = this -> currentNode;
      this -> currentNode = this -> currentNode->link;
    }
  this -> currentPos = this -> numNodes;
}


template <class BaseData>
void List<BaseData>::makeCurrent (int position)
{
  if (( position < 1) || (position > this -> numNodes))
    cout << "invalid position: "<< endl;
  else
    {
      this -> first();
      for (int i = 1; i < position; i++)
        {
          this -> previous = this -> currentNode;
          this -> currentNode = this -> currentNode->link;
        }
      this -> currentPos = position;
    }
}

template <class BaseData>
void List<BaseData>::prev()
{
  int tempCurrPos = this -> currentPos;
  if (this -> currentPos > 1)
    {
      ListNode<BaseData> *temp = previous;
      this -> first();
      if (this -> currentNode == temp)
        {
          this -> previous = 0;
          this -> currentNode = temp;
        }
      else
        {
          while (this -> currentNode->link != temp)
            this -> currentNode = this -> currentNode->link;
          this -> previous = this -> currentNode;
          this -> currentNode = temp;
        }
      this -> currentPos = tempCurrPos -1;
    }
  else
    {
      cout << "walking over front of list";
      this -> currentPos = 0;
    }

}

template <class BaseData>
void List<BaseData>::next()
{
  if (this -> currentNode->link)
    {
      this -> previous = this -> currentNode;
      this -> currentNode = this -> currentNode->link;
      this -> currentPos++;
    }
  else
    {
      cout << "walking over end of list";
      this -> currentPos = 0;
    }
}

template <class BaseData>
int List<BaseData>::current()
{
  return (this -> currentPos);
}

template <class BaseData>
int List<BaseData>::count()
{
  return (this -> numNodes);
}



template <class BaseData>
void List <BaseData>::insertBefore(const BaseData &item)
{
  ListNode<BaseData> *p;
  p = new ListNode<BaseData>;
  p->listData = item;
  if (this -> numNodes)
    {
      if (this -> head == currentNode) head = p;
      p->link = this -> currentNode;
      if (this -> previous) this -> previous ->link = p;
      this -> numNodes++;
      this -> currentNode = p;
    }
  else
    {
      this -> head = p;
      p->link = 0;
      this -> previous = 0;
      this -> numNodes++;
      this -> currentNode = p;
    }
}





template <class BaseData>
void List<BaseData>::insertAfter(const BaseData &item)
{
  ListNode<BaseData> *p;
  p = new ListNode<BaseData>;
  p->listData = item;
  if (this -> numNodes)
    {
      p->link = this -> currentNode->link;
      this -> currentNode->link = p;
      this -> numNodes++;
      this -> previous = this -> currentNode;
      this -> currentNode = p;
      this -> currentPos++;
    }
  else
    {
      this -> head = p;
      p->link = 0;
      this -> previous = 0;
      this -> numNodes++;
      this -> currentNode = p;
      this -> currentPos++;
    }
}

template <class BaseData>
void List<BaseData>::remove()
  {
    ListNode<BaseData> *p, *temp;
    p = this -> currentNode;
    if (this -> numNodes)	//there are nodes
      {if (this -> previous)	//this is not the first node in the list
        {	//any other node in list but first
          this -> previous->link = this -> currentNode->link;
          if (this -> currentNode->link != 0)
            this -> currentNode = this -> currentNode->link;
          else	//deleting last node in list
            {
              this -> currentPos--;
              this -> currentNode = previous;
              temp = this -> head;
              if (temp == this -> currentNode)
                this -> previous = 0;
              else
                {
                  while (temp->link != this -> currentNode && temp)
                    temp = temp->link;
                  this -> previous = temp;
                }
            }
          delete p;
          this -> numNodes--;
        }
        else
          {	//delete first node in list
            this -> head = this -> head->link;
            delete p;
            this -> currentNode = this -> head;
            this -> numNodes--;

            //if first and last node in list
            if (!(this -> numNodes)) this -> currentPos = 0;
          }
      }
    else cout << "empty list" << endl;
  }


template <class  BaseData>
void List<BaseData>::replace(BaseData &item)
{
  if (this -> currentNode)
    this -> currentNode-> listData = item;
}


template <class  BaseData>
List<BaseData>&  List<BaseData>:: operator = (List<BaseData> &init)
{
  if (this == &init) return *this;

  ListNode<BaseData> *temp, *newList, *current, *newNode;
  this -> currentNode = this -> head;
  while (this -> currentNode) //delete existing left side list
    {
      temp = this -> currentNode;
      this -> currentNode = this -> currentNode->link;
      delete temp;
    }

  this -> current = init.head;
  newList = 0;
  while (this -> current)              //copy list
    { newNode = new ListNode<BaseData>;
      newNode->listData = this -> current->listData;
      newNode->link = 0;
      if (newList)
        {
          newList->link = newNode;
          newList = newList->link;
        }
      else newList = newNode;
      if (this -> current == init.head)
        this -> head = newNode;
      this -> current = this -> current->link;
    }

  this -> numNodes = init.numNodes;
  this -> currentPos = 0;
  this -> previous = 0;
  this -> currentNode = 0;
  return *this;
}

#endif
