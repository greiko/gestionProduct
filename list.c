//
// Created by greiko on 28/07/15.
//

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct list
{
  int sequence;
  int numberOfElements;
  Product_t * list;
};

List_t createListProduct()
{
  List_t list = (List_t) malloc(sizeof(struct list));
  list->sequence = 1;
  list->numberOfElements = 0;
  return list;
}

void addToList(List_t list,Product_t product)
{
  int n = list->numberOfElements;
  list->list = (Product_t*) realloc(list->list,sizeof(Product_t*) * (n + 1));
  list->list[n] = product;
  list->sequence++;
  list->numberOfElements++;
}

Product_t getProduct(List_t list,int position)
{
  return (Product_t) list->list[position];
}

int getNumberElements(List_t list)
{
  return list->numberOfElements;
}

int getSequence(List_t list)
{
  return list->sequence;
}