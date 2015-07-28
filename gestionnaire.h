//
// Created by greiko on 28/07/15.
//

#ifndef GESTIONNAIREDEFILM_GESTIONNAIRE_H
#define GESTIONNAIREDEFILM_GESTIONNAIRE_H

#include "inventaire.h"
#include "list.h"
#include "fichier.h"

typedef enum Boolean_t
{
  TRUE,FALSE
} Boolean_t;

char* getAnswer();

Boolean_t validateMenuSelection(char *selection);

char getSelection(char* selection);

int validateInformation(char* name,char* currentPossesion,char* owner);

void menuMessage();

int menuSelection();

int showInventory(List_t list);

int newProductMenu(List_t list);

int eraseProduct();

void errorMessage(char* errMessage);


#endif //GESTIONNAIREDEFILM_GESTIONNAIRE_H
