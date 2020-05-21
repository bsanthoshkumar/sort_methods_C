#include "linkedlist.h"
#include "sort.h"

void display_number(Element number)
{
  printf("%d ", *(int *)number);
}

Element create_number(int value)
{
  int *number = malloc(sizeof(int));
  *number = value;
  return (Element)number;
}

Status is_number_less_than(Element a, Element b)
{
  return *(int *)a < *(int *)b;
}

void perform_selection_sort()
{
  List_ptr list = create_list();
  add_to_list(list, create_number(8));
  add_to_list(list, create_number(3));
  add_to_list(list, create_number(12));
  add_to_list(list, create_number(7));
  add_to_list(list, create_number(1));
  add_to_list(list, create_number(10));

  printf("selection sort on  numbers:\n");
  display(list, &display_number);
  selection_sort(list, &is_number_less_than);
  display(list, &display_number);
}

int main(void)
{
  perform_selection_sort();
}