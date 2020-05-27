#include "sort.h"

void display_number(Void_Ptr number)
{
  printf("%d ", *(int *)number);
}

Void_Ptr create_number(int value)
{
  int *number = malloc(sizeof(int));
  *number = value;
  return (Void_Ptr)number;
}

Boolean is_number_less_than(Void_Ptr a, Void_Ptr b)
{
  return *(int *)a < *(int *)b;
}

void display_character(Void_Ptr character)
{
  printf("%c ", *(char *)character);
}

Void_Ptr create_character(char value)
{
  char *character = malloc(sizeof(char));
  *character = value;
  return (Void_Ptr)character;
}

Boolean is_character_less_than(Void_Ptr a, Void_Ptr b)
{
  return *(char *)a < *(char *)b;
}

void display_string(Void_Ptr character)
{
  printf("%s ", (char *)character);
}

Void_Ptr create_string(char *value, int length)
{
  char *string = malloc(sizeof(char) * length);
  memcpy(string, value, length);
  return string;
}

Boolean is_string_less_than(Void_Ptr a, Void_Ptr b)
{
  return strcmp((char *)a, (char *)b) < 0;
}

void perform_selection_sort_on_numbers()
{
  Array_ptr list = create_array(6);
  list->values[0] = create_number(8);
  list->values[1] = create_number(1);
  list->values[2] = create_number(3);
  list->values[3] = create_number(10);
  list->values[4] = create_number(12);
  list->values[5] = create_number(7);

  printf("selection sort on numbers: \n");
  display_array(list, display_number);
  selection_sort(list, &is_number_less_than);
  display_array(list, display_number);
}

void perform_selection_sort_on_characters()
{
  Array_ptr list = create_array(6);
  list->values[0] = create_character('c');
  list->values[1] = create_character('f');
  list->values[2] = create_character('b');
  list->values[3] = create_character('d');
  list->values[4] = create_character('e');
  list->values[5] = create_character('a');

  printf("selection sort on characters: \n");
  display_array(list, display_character);
  selection_sort(list, &is_character_less_than);
  display_array(list, display_character);
}

void perform_selection_sort_on_strings()
{
  Array_ptr list = create_array(6);
  list->values[0] = create_string("bca", 3);
  list->values[1] = create_string("abc", 3);
  list->values[2] = create_string("bac", 3);
  list->values[3] = create_string("cba", 3);
  list->values[4] = create_string("acb", 3);
  list->values[5] = create_string("cab", 3);

  printf("selection sort on strings: \n");
  display_array(list, display_string);
  selection_sort(list, &is_string_less_than);
  display_array(list, display_string);
}

void perform_bubble_sort_on_numbers()
{
  Array_ptr list = create_array(6);
  list->values[0] = create_number(4);
  list->values[1] = create_number(13);
  list->values[2] = create_number(1);
  list->values[3] = create_number(10);
  list->values[4] = create_number(6);
  list->values[5] = create_number(7);

  printf("bubble sort on numbers: \n");
  display_array(list, display_number);
  bubble_sort(list, &is_number_less_than);
  display_array(list, display_number);
}

void perform_insertion_sort_on_numbers()
{
  Array_ptr list = create_array(6);
  list->values[0] = create_number(8);
  list->values[1] = create_number(5);
  list->values[2] = create_number(3);
  list->values[3] = create_number(1);
  list->values[4] = create_number(12);
  list->values[5] = create_number(7);

  printf("insertion sort on numbers: \n");
  display_array(list, display_number);
  insertion_sort(list, &is_number_less_than);
  display_array(list, display_number);
}

void perform_quick_sort_on_numbers()
{
  Array_ptr list = create_array(6);
  list->values[0] = create_number(8);
  list->values[1] = create_number(5);
  list->values[2] = create_number(3);
  list->values[3] = create_number(1);
  list->values[4] = create_number(12);
  list->values[5] = create_number(7);

  printf("quick sort on numbers: \n");
  display_array(list, display_number);
  quick_sort(list, 0, 5, &is_number_less_than);
  display_array(list, display_number);
}

int main(void)
{
  perform_selection_sort_on_numbers();
  perform_selection_sort_on_characters();
  perform_selection_sort_on_strings();
  perform_bubble_sort_on_numbers();
  perform_insertion_sort_on_numbers();
  perform_quick_sort_on_numbers();
}