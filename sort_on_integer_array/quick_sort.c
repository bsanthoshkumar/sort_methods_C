#include <stdio.h>

void print_array(int *array, int length)
{
  for (size_t i = 0; i < length; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort(int *array, int start_index, int pivot_index)
{
  if (start_index < pivot_index)
  {
    int i = start_index;
    for (int j = start_index; j < pivot_index; j++)
    {
      if (array[j] < array[pivot_index])
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
  int array[] = {13, 2, 8, 28, 19, 9, 25, 18, 16, 4};
  sort(array, 0, 9);
  print_array(array, 10);

  return 0;
}