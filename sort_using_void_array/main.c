#include "sort.h"

void display_number(Void_Ptr number)
{
  printf("%d ", *(int *)number);
}

Void_Ptr create_number(int value)
{
  int *number = malloc(sizeof(int));
  *number = value;
  return (Void_Ptr)number;
}

Boolean is_less_than(Void_Ptr a, Void_Ptr b)
{
  return *(int *)a < *(int *)b;
}

void perform_selection_sort()
{
  Array_ptr list = create_array(6);
  list->values[0] = create_number(8);
  list->values[1] = create_number(1);
  list->values[2] = create_number(3);
  list->values[3] = create_number(10);
  list->values[4] = create_number(12);
  list->values[5] = create_number(7);

  printf("selection sort: \n");
  display_array(list, display_number);
  selection_sort(list, &is_less_than);
  display_array(list, display_number);
}

int main(void)
{
  perform_selection_sort();
}