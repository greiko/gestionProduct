//
// Created by greiko on 28/07/15.
//

#ifndef GESTIONNAIREDEFILM_LIST_H
#define GESTIONNAIREDEFILM_LIST_H

#include "inventaire.h"

typedef struct list * List_t;

List_t createListProduct();

void addToList(List_t list,Product_t product);

void deleteFromList(List_t list,int posistion);

int getNumberElements(List_t list);

Product_t getProduct(List_t list,int position);

int getSequence(List_t list);

#endif //GESTIONNAIREDEFILM_LIST_H
