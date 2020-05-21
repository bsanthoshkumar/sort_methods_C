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
  for (size_t i = 1; i < length; i++)
  {
    for (int j = i - 1; j >= 0 && array[j] > array[j + 1]; j--)
    {
      int temp = array[j];
      array[j] = array[j + 1];
      array[j + 1] = temp;
    }
  }
}

int main(void)
{
  int array[] = {8, 5, 3, 1, 12, 7};
  sort(array, 6);
  print_array(array, 6);

  return 0;
}