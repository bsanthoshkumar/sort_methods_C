#include "linkedlist.h"

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(LinkedList));
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return list;
}

Node_ptr create_newnode(Element element)
{
  Node_ptr newnode = malloc(sizeof(Node));
  newnode->element = element;
  newnode->prev = NULL;
  newnode->next = NULL;
  return newnode;
}

Status add_to_list(List_ptr list, Element element)
{
  Node_ptr newnode = create_newnode(element);
  if (newnode == NULL)
  {
    return Failure;
  }
  if (list->first == NULL)
  {
    list->first = newnode;
  }
  else
  {
    newnode->prev = list->last;
    list->last->next = newnode;
  }
  list->last = newnode;
  list->length++;

  return Success;
}

void display(List_ptr list, Displayer displayer)
{
  Node_ptr current = list->first;
  while (current != NULL)
  {
    displayer(current->element);
    current = current->next;
  }
  printf("\n");
}