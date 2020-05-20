#include <stdio.h>
#include <string.h>

typedef enum
{
  False,
  True
} Boolean;

void print_array(char **array, int length)
{
  for (size_t i = 0; i < length; i++)
  {
    printf("%s\n", array[i]);
  }
  printf("\n");
}

void sort(char **array, int length)
{
  for (size_t i = 0; i < length; i++)
  {
    Boolean swap = False;
    for (size_t j = 0; j < length - i - 1; j++)
    {
      if (strcmp(array[j], array[j + 1]) > 0)
      {
        swap = True;
        char *temp = array[j];
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
  char *strings[] = {"bca", "abc", "bac", "cba", "acb", "cab", "aab", "aac", "aba", "aca", "caa", "baa"};
  sort(strings, 12);
  print_array(strings, 12);

  return 0;
}