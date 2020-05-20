#ifndef __SORT__H_
#define __SORT__H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void *Void_Ptr;
typedef struct
{
  Void_Ptr *values;
  int length;
} Array;

typedef Array *Array_ptr;

typedef enum
{
  False,
  True
} Boolean;

typedef Boolean (*Matcher)(Void_Ptr, Void_Ptr);
typedef void (*Displayer)(Void_Ptr);

Array_ptr create_array(int length);
void display_array(Array_ptr, Displayer);
void selection_sort(Array_ptr, Matcher);

#endif