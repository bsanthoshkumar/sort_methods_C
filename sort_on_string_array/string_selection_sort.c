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
  for (size_t i = 0; i < length; i++)
  {
    int min_index = i;
    for (size_t j = i + 1; j < length; j++)
    {
      if (strcmp(array[j], array[min_index]) < 0)
      {
        min_index = j;
      }
    }
    char *temp = array[i];
    array[i] = array[min_index];
    array[min_index] = temp;
  }
}

int main(void)
{
  char *strings[] = {"bca", "abc", "bac", "cba", "acb", "cab", "aab", "aac", "aba", "aca", "caa", "baa"};
  sort(strings, 12);
  print_array(strings, 12);

  return 0;
}