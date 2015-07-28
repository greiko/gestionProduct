//
// Created by greiko on 28/07/15.
//

#ifndef GESTIONNAIREDEFILM_INVENTAIRE_H
#define GESTIONNAIREDEFILM_INVENTAIRE_H

typedef struct inventory * Product_t;

Product_t createProduct(int id, char* name,char* currentPossesion,char* owner);

char* getName(Product_t product);

char* getCurrentPossesion(Product_t product);

char* getOwner(Product_t product);

int getId(Product_t product);

#endif //GESTIONNAIREDEFILM_INVENTAIRE_H
