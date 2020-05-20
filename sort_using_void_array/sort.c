#include "sort.h"

Array_ptr create_array(int length)
{
  Array_ptr array = malloc(sizeof(Array));
  array->length = length;
  array->values = malloc(sizeof(Void_Ptr) * array->length);
  return array;
}

void display_array(Array_ptr array, Displayer displayer)
{
  for (size_t i = 0; i < array->length; i++)
  {
    displayer(array->values[i]);
  }
  printf("\n");
}

void selection_sort(Array_ptr array, Matcher matcher)
{
  for (size_t i = 0; i < array->length; i++)
  {
    int min_index = i;
    for (size_t j = i + 1; j < array->length; j++)
    {
      if (matcher(array->values[j], array->values[min_index]))
      {
        min_index = j;
      }
    }
    Void_Ptr temp = array->values[i];
    array->values[i] = array->values[min_index];
    array->values[min_index] = temp;
  }
}