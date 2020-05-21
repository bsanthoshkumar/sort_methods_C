#ifndef __SORT__H_
#define __SORT__H_

#include "linkedlist.h"
typedef Status (*Matcher)(Element, Element);
void selection_sort(List_ptr, Matcher);

#endif