#include <stdio.h>
#include <stdlib.h>

#ifndef __LINKEDLIST_H_
#define __LINKEDLIST_H_

typedef enum
{
  Failure,
  Success
} Status;

typedef void *Element;

typedef struct node
{
  Element element;
  struct node *prev;
  struct node *next;
} Node;

typedef Node *Node_ptr;

typedef struct linklist
{
  Node *first;
  Node *last;
  int length;
} LinkedList;

typedef LinkedList *List_ptr;

typedef struct
{
  Node_ptr prev;
  Node_ptr current;
} Prev_Current_Pair;

typedef Prev_Current_Pair *Prev_Current_Pair_ptr;

typedef void (*Displayer)(Element);

List_ptr create_list(void);
Node_ptr create_newnode(Element);

Status add_to_list(List_ptr, Element);
void display(List_ptr list, Displayer displayer);

#endif
