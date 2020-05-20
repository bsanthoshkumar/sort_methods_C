#include <stdio.h>
#include <string.h>

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
  for (size_t i = 1; i < length; i++)
  {
    for (int j = i - 1; j >= 0 && strcmp(array[j], array[j + 1]) > 0; j--)
    {
      char *temp = array[j];
      array[j] = array[j + 1];
      array[j + 1] = temp;
    }
  }
}

int main(void)
{
  char *strings[] = {"bca", "abc", "bac", "cba", "acb", "cab"};
  sort(strings, 6);
  print_array(strings, 6);

  return 0;
}