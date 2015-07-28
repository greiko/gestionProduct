//
// Created by greiko on 28/07/15.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventaire.h"


struct inventory
{
  int id;
  char* name;
  char* currentPosssion;
  char* owner;
};

Product_t createProduct(int id,char* name,char* currentPossesion,char* owner)
{
  Product_t newProduct = (Product_t) malloc(sizeof(struct inventory));
  newProduct->name = (char*) malloc(sizeof(name));
  newProduct->currentPosssion = (char*) malloc(sizeof(currentPossesion));
  newProduct->owner = (char*) malloc(sizeof(owner));
  newProduct->id = id;
  strcpy(newProduct->name,name);
  strcpy(newProduct->currentPosssion,currentPossesion);
  strcpy(newProduct->owner,owner);

  return newProduct;
}

char* getName(Product_t product)
{
  return product->name;
}

char* getCurrentPossesion(Product_t product)
{
  return product->currentPosssion;
}

char* getOwner(Product_t product)
{
  return product->owner;
}

int getId(Product_t product)
{
  return product->id;
}
