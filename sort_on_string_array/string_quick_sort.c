#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(char **array, int length)
{
  for (size_t i = 0; i < length; i++)
  {
    printf("%s\n", array[i]);
  }
  printf("\n");
}

void swap(char **a, char **b)
{
  char *temp = *a;
  *a = *b;
  *b = temp;
}

void sort(char **array, int start_index, int pivot_index)
{
  if (start_index < pivot_index)
  {
    int i = start_index;
    for (int j = start_index; j < pivot_index; j++)
    {
      if (strcmp(array[j], array[pivot_index]) < 0)
      {
        swap(&array[i], &array[j]);
        i++;
      }
    }
    swap(&array[i], &array[pivot_index]);
    sort(array, start_index, i - 1);
    sort(array, i + 1, pivot_index);
  }
}

int main(void)
{
  char *strings[] = {"bca", "abc", "bac", "cba", "acb", "cab", "aab", "aac", "aba", "aca", "caa", "baa"};
  sort(strings, 0, 11);
  print_array(strings, 12);

  return 0;
}