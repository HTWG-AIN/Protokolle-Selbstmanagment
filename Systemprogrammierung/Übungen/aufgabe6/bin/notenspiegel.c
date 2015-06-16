/*notenspiegel.c*/
/*mein method*/



#include "liste.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>




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
