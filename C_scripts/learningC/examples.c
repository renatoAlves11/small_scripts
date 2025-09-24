#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main(void) {

    List lista = list();
    List *self = &lista;

    lista.append(self, 45);
    lista.append(self, 1);
    lista.append(self, 8);
    lista.append(self, 76);

    lista.printList(self);

    lista.bubble(self);


    lista.printList(self);
    
    return 0;
}