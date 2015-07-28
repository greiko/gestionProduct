//
// Created by greiko on 28/07/15.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"

int saveInventory(List_t list)
{
  FILE* fichier = fopen("list.txt","w");
  int n = getNumberElements(list);
  int i;
  for (i = 0;i < n;i++)
  {
    fprintf(fichier,"%d",getId(getProduct(list,i)));
    fputs("\n",fichier);
    fputs(getName(getProduct(list,i)),fichier);
    fputs("\n",fichier);
    fputs(getCurrentPossesion(getProduct(list,i)),fichier);
    fputs("\n",fichier);
    fputs(getOwner(getProduct(list,i)),fichier);
    fputs("\n",fichier);
  }
  printf("\nFILE SAVED!\n");
  printf("Press 'c' to Continue\n");
  while( getchar() != 'c' );
  fclose(fichier);
  return 0;
}

List_t loadInventory(List_t list)
{
  FILE* fichier = fopen("list.txt","r");
  char c = fgetc(fichier);
  char mot[50];
  Product_t newProduct;
  char name[50];
  char currentPoss[50];
  char owner[50];
  int id = 0;
  int info = 0;
  int n = 0;
  while (c != EOF)
  {
    if (c != '\n')
    {
      mot[n] = c;
      n++;
    }
    else
    {
      mot[n] = '\0';
      n = 0;
      switch (info)
      {
        case 0  :
          id = atoi(mot);
          info++;
          break;
        case 1  :
          strcpy(name,mot);
          info++;
          break;
        case 2  :
          strcpy(currentPoss,mot);
          info++;
          break;
        case 3  :
          strcpy(owner,mot);
          info = 0;
          newProduct = createProduct(id,name,currentPoss,owner);
          addToList(list,newProduct);
          break;
      }
    }
    c = fgetc(fichier);
  }
  printf("\nFILE LOADED!\n");
  printf("Press 'c' to Continue\n");
  while( getchar() != 'c' );
  fclose(fichier);
  return list;
}