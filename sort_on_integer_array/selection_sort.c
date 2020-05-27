#include <stdio.h>

void print_array(int *array, int length)
{
  for (size_t i = 0; i < length; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void sort(int *array, int length)
{
  for (size_t i = 0; i < length; i++)
  {
    int min_index = i;
    for (size_t j = i + 1; j < length; j++)
    {
      if (array[j] < array[min_index])
      {
        min_index = j;
      }
    }
    int temp = array[i];
    array[i] = array[min_index];
    array[min_index] = temp;
  }
}

int main(void)
{
  int array[] = {8, 10, 3, 10, 12, 7};
  sort(array, 6);
  print_array(array, 6);

  return 0;
}