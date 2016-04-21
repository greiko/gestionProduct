//
// Created by greiko on 28/07/15.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestionnaire.h"


char *getAnswer()
{
  char *input = (char *) malloc(sizeof(char) * 50);
  scanf("%s", input);
  return input;
}

int menuSelection()
{
  int checkError = 0;
  List_t list = createListProduct();
  ERROR:
  while (checkError == 0)
  {
    menuMessage();
    Boolean_t validate = FALSE;
    char *selection = getAnswer();
    validate = validateMenuSelection(selection);
    if (validate == FALSE)
    {
      errorMessage("ERROR DE SELECTION DE MENU\n");
      printf("Press 'c' to Continue\n");
      while( getchar() != 'c' );
      goto ERROR;
    }
    switch (getSelection(selection))
    {
      case 'a'  :
        checkError = newProductMenu(list);
        break; /* optional */
      case 's'  :
        checkError = showInventory(list);
        break; /* optional */
      case 'd'  :
        eraseProduct(list);
        break; /* optional */
      case 'w'  :
        saveInventory(list);
        break;
      case 'l'  :
        list = loadInventory(list);
        break;
      case 'q'  :
        exit(0);
    }
  }
  return 0;
}

void menuMessage()
{
  printf("Choose an option: \n");
  printf("------------------\n"
                 "Add product    --> a\n"
                 "Show product   --> s\n"
                 "Delete product --> d\n"
                 "Save List      --> w\n"
                 "Load List      --> l\n"
                 "Quit           --> q\n");
}

char getSelection(char *selection)
{
  return selection[0];
}


Boolean_t validateMenuSelection(char *selection)
{
  if (strcmp(selection, "a") == 0 || strcmp(selection, "s") == 0 ||
      strcmp(selection, "d") == 0 || strcmp(selection, "w") == 0 ||
      strcmp(selection, "l") == 0 || strcmp(selection, "q") == 0)
  {
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

int validateInformation(char *name, char *currentPossesion, char *owner)
{
  return 0;
}


int showInventory(List_t list)
{
  if (getNumberElements(list) == 0)
  {
    errorMessage("List is empty!\n");
    printf("Press 'c' to Continue\n");
    while( getchar() != 'c' );
    return 0;
  }
  int current_nb = getNumberElements(list);
  int i;
  for (i = 0; i < current_nb; i++)
  {
    Product_t currentProduct = getProduct(list,i);
      if(currentProduct == 0){
          printf("========================================================\n");
          printf("PRODUCT DELETED\n");
          printf("========================================================\n");
          printf("Press 'c' to continue\n");
      }
      else {
          printf("========================================================\n");
          printf("Id of product: %d\n", getId(currentProduct));
          printf("Name of Product: %s\n", getName(currentProduct));
          printf("Current Possession: %s\n", getCurrentPossesion(currentProduct));
          printf("Owner: %s\n\n", getOwner(currentProduct));
          printf("========================================================\n");
          printf("Press 'c' to continue\n");
      }
    while( getchar() != 'c' );
  }
  return 0;
}

int newProductMenu(List_t list)
{
  int checkError = 0;
  char *name;
  char *currentPossesion;
  char *owner;
  printf("Enter name of product: \n");
  name = getAnswer();
  printf("Enter current possesion of product name: \n");
  currentPossesion = getAnswer();
  printf("Enter owner of product: \n");
  owner = getAnswer();
  checkError = validateInformation(name, currentPossesion, owner);
  Product_t newProduct = createProduct(getSequence(list), name, currentPossesion, owner);
  addToList(list, newProduct);
  if (checkError != 0)
  {
    //error
  }
  else
  {
    printf("ADDED WITH SUCCESS!\n\n");
  }
  return checkError;
}

int eraseProduct(List_t list)
{
    deleteFromList(list,2);
  return 0;
}

void errorMessage(char *errMessage)
{
  printf("%s\n", errMessage);
}



