#ifndef __SORT__H_
#define __SORT__H_

#include "linkedlist.h"
typedef Status (*Matcher)(Element, Element);
void selection_sort(List_ptr, Matcher);
void bubble_sort(List_ptr, Matcher);
void insertion_sort(List_ptr, Matcher);

#endif