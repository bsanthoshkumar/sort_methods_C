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

void bubble_sort(Array_ptr array, Matcher matcher)
{
  for (size_t i = 0; i < array->length; i++)
  {
    Boolean swap = False;
    for (size_t j = 0; j < array->length - i - 1; j++)
    {
      if (matcher(array->values[j + 1], array->values[j]))
      {
        swap = True;
        Void_Ptr temp = array->values[j];
        array->values[j] = array->values[j + 1];
        array->values[j + 1] = temp;
      }
    }
    if (!swap)
    {
      break;
    }
  }
}

void insertion_sort(Array_ptr array, Matcher matcher)
{
  for (size_t i = 1; i < array->length; i++)
  {
    for (int j = i - 1; j >= 0 && matcher(array->values[j + 1], array->values[j]); j--)
    {
      Void_Ptr temp = array->values[j];
      array->values[j] = array->values[j + 1];
      array->values[j + 1] = temp;
    }
  }
}

void quick_sort(Array_ptr array, int start_index, int pivot_index, Matcher matcher)
{
  if (start_index < pivot_index)
  {
    int i = start_index;
    for (int j = start_index; j < pivot_index; j++)
    {
      if (matcher(array->values[j], array->values[pivot_index]))
      {
        Void_Ptr temp = array->values[i];
        array->values[i] = array->values[j];
        array->values[j] = temp;
        i++;
      }
    }
    Void_Ptr temp = array->values[i];
    array->values[i] = array->values[pivot_index];
    array->values[pivot_index] = temp;
    quick_sort(array, start_index, i - 1, matcher);
    quick_sort(array, i + 1, pivot_index, matcher);
  }
}