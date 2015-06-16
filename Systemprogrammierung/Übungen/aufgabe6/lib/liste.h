#ifndef LISTE_H
#define LISTE_H

#include "fachnote.h"


fach_note *einfuegen(fach_note *head, fach_note *neues, fach_note **altes);
fach_note *entfernen(fach_note *head, fach_note **aktuell); 
void schleife(fach_note *l, void (*ausgeben)(const fach_note *n));



#endif
