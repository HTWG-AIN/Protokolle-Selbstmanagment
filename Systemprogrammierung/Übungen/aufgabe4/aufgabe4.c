/*
 * aufgabe4.c
 * Liest Fachnamen mit Beurteilung ein und gibt dann einen Notenspiegel aus.
 * Autor: Abusaleh
 * Erstellt am: 10.05.15
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME_LENGTH 20
enum p_arten {BENOTET, UNBENOTET};


struct strukturen
{
    struct strukturen *vor;
    struct strukturen *nach;
    char fachname[NAME_LENGTH + 1];
    enum p_arten art;
    union
    {
        int note;
        char beurteilung;   /* 'B' oder 'N' */
    } u;
};
typedef struct strukturen fach_note;

int einlesen(fach_note *n);
void ausgeben(const fach_note *n);
fach_note *einfuegen(fach_note *head, fach_note *neues, fach_note **altes);
fach_note *entfernen(fach_note *head, fach_note **aktuell); 
void schleife(fach_note *l, void (*ausgeben)(const fach_note *n));

int main(void)
{
    fach_note *notenspiegel = NULL;
    fach_note *p;
    fach_note *q;

    /*------------------------------------------- Notenspiegel einlesen */
    fprintf(stderr, "Faecher mit Noten eingeben (Ende mit Strg-D):\n");

    for (;;)
    {
        p = (fach_note *) malloc(sizeof (fach_note));
        if (p == NULL) /* Datei aufgabe4-in.tt für den automatisierten Test entnehmen */
        {
            fprintf(stderr, "Zu viele Faecher!\nc");
            break;
        }

        if (! einlesen(p))
        {
            fprintf(stderr, "Eingabeende!\n");
            free(p);
            break;
        }

        notenspiegel = einfuegen(notenspiegel, p, &q);
        if (q != NULL)
        {
            fprintf(stderr, "Alte Eingabe ueberschrieben!\n");
            free(q);
        }
    }

    /*------------------------------------------- Notenspiegel ausgeben */
    printf("Notenspiegel:\n");

    schleife(notenspiegel, ausgeben);

    /*------------------------------------------- Notenspiegel loeschen */
    while (notenspiegel != NULL)
    {
        notenspiegel = entfernen(notenspiegel, &p);
        free(p);
    }

    return 0;
}


int einlesen(fach_note *n)   /*kann auch int* sein  ? */
{

    char *pos;

    if (scanf("%20s", n->fachname) == 1)
    {
         pos = strchr(n->fachname, '_'); /*ab dem Zeichen; also alles davor ist weg */
        /*  for( pos = 0; pos < n->fachname; pos++)
            {}
        */
        while (pos != NULL)
        {
            *pos = ' ';
            pos = strchr(pos++, '_'); /*ab dem Zeichen; also alles davor ist weg */


        }
    
        if (scanf("%d", &(n->u.note)) == 1) 		/* oder (*n).fachname  */
        {
            n->art = BENOTET;   /* Beurteilung ist B oder N*/
            return 1;

        }
        else if (scanf("%c", &(n->u.beurteilung)) == 1)
        {

            n->art = UNBENOTET;
            return 1;
        }
        else
        {
            return 0;
        }

    } else {
        return 0;
    }
   
}


void ausgeben(const fach_note *n)
{
    /*n = (fach_note *) malloc(sizeof(fach_note));
    */
    if (n->art == BENOTET)
    {
        switch(n->u.note)
        {
        case 10:
        case 13:
        case 17:
        case 20:
        case 23:
        case 27:
        case 30:
        case 33:
        case 37:
        case 40:
        case 50:
            printf("%-20s %d,%d\n", n->fachname, n->u.note / 10, n->u.note % 10);
            break;
        default :

            printf("%-20s Fehler : %d\n", n->fachname, n->u.note );
            break;
        }
    }
    else
    {
        switch(n->u.beurteilung)
        {
        case 'B':
            printf("%-20s %s\n" , n->fachname , "bestanden");
            break;
        case 'N':
            printf("%-20s %s\n" , n->fachname, "nicht bestanden");
            break;

        default :

            printf("%-20s Fehler : %c\n", n->fachname, n->u.beurteilung );
            break;
        }
    }
    return;

}


fach_note *einfuegen(fach_note *head, fach_note *neues, fach_note **removed)
{
    fach_note *p;
    *removed = NULL;
    
    if(head == NULL){
        neues->nach = NULL;
        neues->vor = NULL;
        return neues;
    }
    for (p=head ; p != NULL; p = p->nach)
    {
        if (!strcmp(p->fachname,  neues->fachname) )
        {
                *removed = p;
                if(p->nach != NULL)
                {
                    p->nach->vor = p->vor;
                }
                if(p == head)
                {
                    if(p->nach)
                    {
                        head = p->nach;
                        break;
                    }
                    neues->nach=NULL;
                    neues->vor =NULL;
                    return neues;
                }
                if(p->vor)
                {
                    p->vor->nach= p->nach;
                }
                break;

         }
    }
    neues->nach=head;
    neues->vor=NULL;
    head->vor = neues;
    return neues;

}


fach_note *entfernen(fach_note *head, fach_note **del)
{
    if(head->nach)
    {
        head->nach->vor = NULL;
        
    }
    *del=head;
    return head->nach;
}

void schleife(fach_note *liste, void (*ausgeben) (const fach_note *n))
{
    fach_note *p;
    for(p = liste ; p != NULL; p = p->nach )
    {
        ausgeben(p);
    }
    return;
}
