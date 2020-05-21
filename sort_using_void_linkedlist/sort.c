#include "sort.h"

void selection_sort(List_ptr list, Matcher matcher)
{
  Prev_Current_Pair_ptr pair = malloc(sizeof(Prev_Current_Pair));
  pair->prev = list->first;
  while (pair->prev != NULL)
  {
    Node_ptr min_element = pair->prev;
    pair->current = pair->prev->next;
    while (pair->current != NULL)
    {
      if (matcher(pair->current->element, min_element->element))
      {
        min_element = pair->current;
      }
      pair->current = pair->current->next;
    }

    Element temp = pair->prev->element;
    pair->prev->element = min_element->element;
    min_element->element = temp;

    pair->prev = pair->prev->next;
  }
}