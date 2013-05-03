/*
===============================================================================
	Autor			: Christopher Smith
	Klasse			: FA1
	Dateiname		: hauptmenue.c
	Datum			: 02.05.2013
    Beschreibung    : 
===============================================================================
*/

/* 
===============================================================================
   Include-Dateien
===============================================================================
*/

#include "hauptmenue.h"

/*
===============================================================================
   Funktion:      hauptmenue()
   in:            -
   out:           -
   Beschreibung:  Nach dem Login beider Spieler oder der Wahl eines 
                  Computergegners gelangen sie ins Hauptmenue, um forzufahren.
                  Das entsprechende Spiel wird gestartet oder die Statistik 
                  angezeigt.
                  Die Spieler haben auch die Möglichkeit sich wieder 
                  auszuloggen, um das Spiel ggf. zu beenden.
===============================================================================
*/
void hauptmenue(void)
{
   int iAuswahl;
   int iRun = 1;
   int iError = 0;

   do
   {

      //Ausgabe
      drawTop(6);
      printf("\n\n");
      printf("\t1: Checkers");
      if (!strcmp(g_cSpieler2, "COMPUTER"))
         printf("(Im Computer-Modus nicht verfuegbar)");
      printf("\n");
      printf("\t2: Reversi\n");
      printf("\t3: 4-Gewinnt\n");
      printf("\t4: Bridges");
      if (!strcmp(g_cSpieler2, "COMPUTER"))
         printf("(Im Computer-Modus nicht verfuegbar)");
      printf("\n");
	  if(g_iVerbunden==1)
		printf("\t5: Statistiken anzeigen\n");
      printf("\n");
	  if(g_iVerbunden==1)
	      printf("\t6: Logout\n");
	  else
			printf("\t6: Beenden\n");
      printf("\n");
   

	  if(iError == 1){
	  	  printf("\tBitte nur Zahlen 1-6 eingeben.\n\n");
	  }
      //Eingabe
      printf("\tIhre Eingabe: ");
      scanf("%i", &iAuswahl);
      fflush(stdin);
      printf("\n\n");

      switch(iAuswahl){
         case 1:
            // Checkers 
            if (strcmp(g_cSpieler2, "COMPUTER"))
               zeigeSpielmenu("Checkers");
            break;
   
         case 2:
            // Reversi 
            zeigeSpielmenu("Reversi");
            break;

         case 3:
            // 4-Gewinnt 
            zeigeSpielmenu("4Gewinnt");
            break;

         case 4:
            // Bridges
            if (strcmp(g_cSpieler2, "COMPUTER"))
               zeigeSpielmenu("Bridges");
            break;

         case 5:
			 if(g_iVerbunden == 1)
				zeigeGesamtStatistik();
            break;

         case 6:
            iRun = 0;
            break;
		 default:
			 iError = 1;
			 break;
      }
   }
   while(iRun);
}

/*
===============================================================================
   Funktion:      zeigeGesamtStatistik()
   in:            -
   out:           -
   Beschreibung:  Zeigt ein Untermenü für die Statistik an. Man kann sich          
                  verschiedene Statistiktabellen anzeigen lassen. 
===============================================================================
*/
void zeigeGesamtStatistik(void)
{
   int iEingabe;
   int iError = 0;

   drawTop(7);
   printf("\n\n");
   printf("\t1: Eigene Punktbewertung (Spieler 1 und Spieler 2) "); 
   printf("\n\t   aller Spiele anzeigen\n");
   printf("\t2: Punktbewertung aller Sieler aller Spiele anzeigen \n");
   printf("\t3: Anzahl der eigenen (Spieler 1 und Spieler 2) Siege, \n");
   printf("\t   Niederlagen und Remis anzeigen\n");
   printf("\t4: Zurück zum Hauptmenü\n");
   printf("\n");

   //Eingabe
   printf("\tIhre Eingabe: ");
   scanf("%i", &iEingabe);
   fflush(stdin);
   printf("\n\n");

   switch(iEingabe){
         case 1:
            eigeneBewertungAllerSpiele();
            break;
   
         case 2:
            bewertungKomplett();
            break;

         case 3:
            anzahlSpieleAlle();
            break;
		 case 4:
			 //just do nothing
			 break;
         default:
            printf("falsche Eingabe. Bitte wiederholen");
			break;
   }
}
