#include <stdio.h>

typedef enum
{
  False,
  True
} Boolean;

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
    Boolean swap = False;
    for (size_t j = 0; j < length - i - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        swap = True;
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
    if (!swap)
    {
      break;
    }
  }
}

int main(void)
{
  int array[] = {4, 13, 1, 10, 6, 7};
  sort(array, 6);
  print_array(array, 6);

  return 0;
}