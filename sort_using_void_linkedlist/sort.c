#include "sort.h"

void selection_sort(List_ptr list, Matcher matcher)
{
  Node_ptr node1 = list->first;
  while (node1 != NULL)
  {
    Node_ptr min_element = node1;
    Node_ptr node2 = node1->next;
    while (node2 != NULL)
    {
      if (matcher(node2->element, min_element->element))
      {
        min_element = node2;
      }
      node2 = node2->next;
    }

    Element temp = node1->element;
    node1->element = min_element->element;
    min_element->element = temp;

    node1 = node1->next;
  }
}

void bubble_sort(List_ptr list, Matcher matcher)
{
  Node_ptr node1 = list->first;
  for (size_t i = 0; i < list->length && node1 != NULL; i++)
  {
    Status swap = Failure;
    Node_ptr node2 = list->first;
    for (size_t j = 0; j < list->length - i - 1; j++)
    {
      if (matcher(node2->next->element, node2->element))
      {
        swap = Success;
        Element temp = node2->element;
        node2->element = node2->next->element;
        node2->next->element = temp;
      }
      node2 = node2->next;
    }
    if (!swap)
    {
      break;
    }
    node1 = node1->next;
  }
}

void insertion_sort(List_ptr list, Matcher matcher)
{
  Node_ptr node1 = list->first;
  while (node1 != NULL)
  {
    Node_ptr node2 = node1;
    while (node2->prev != NULL && matcher(node2->element, node2->prev->element))
    {
      Element temp = node2->element;
      node2->element = node2->prev->element;
      node2->prev->element = temp;
      node2 = node2->prev;
    }
    node1 = node1->next;
  }
}