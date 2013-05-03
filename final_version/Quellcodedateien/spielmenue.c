/*
===============================================================================
   Autor :         Christopher Smith
   Klasse :        FA1
   Dateiname :     Spielmenu.c
   Datum :         02.05.2013
   Beschreibung:   Zeigt das Spielmenü an, von dem aus man das Spiel starten
				   kann, die Statistik anzeigen kann oder die Schwierigkeits-
				   stufe des Computers einstellen kann.
===============================================================================
*/

/* 
===============================================================================
   Include Anweisungen
===============================================================================
*/

#include "Spielmenue.h"
#include "elo.h"


/*
===============================================================================
   Funktion:      zeigeSpielmenu()
   in:            cSpieltyp[]
   out:           -
   Beschreibung:  Jedes Spiel hat noch ein Untermenü. Von dort kann die Hilfe       
                  und die Statistik des jeweiligen Spiels aufgerufen werde, 
                  sowie die Schwierigkeitsstufe des Computers (bei 4-Gewinnt 
                  und Reversi) eingestellt werden. 
===============================================================================
*/
void zeigeSpielmenu(const char cSpieltyp[12])
{
   int iZeige = 1;
   int iEingabe;
   int iSpieltyp;

   if (cSpieltyp == "Reversi")
   {
      iSpieltyp = 3;
   }
   else if (cSpieltyp == "Checkers")
   {
      iSpieltyp = 2;
   }
   else if (cSpieltyp == "4Gewinnt")
   {
      iSpieltyp = 0;
   }
   else if (cSpieltyp == "Bridges")
   {
      iSpieltyp = 1;
   }

   while(iZeige)
   {
      drawTop(iSpieltyp+2);
      printf("\n\n");
      printf("\t1: Spiel starten\n");
      if (!strcmp(g_cSpieler2, "COMPUTER"))
         printf("\t2: Schwierigkeitsstufe des Computers einstellen\n");
      else
         printf("\n");
	  if(g_iVerbunden==1)
	      printf("\t3: Statistik anzeigen\n");
      printf("\t4: Hilfe anzeigen\n");
      printf("\t5: Zurueck zum Hauptmenue\n");
      printf("\n");

      printf("\n\tIhre Eingabe: ");
      scanf("%i", &iEingabe);
      fflush(stdin);

      switch (iEingabe)
      {
         case 1:
            starteSpiel(cSpieltyp);
            break;
         case 2:
            waehleKI();
            break;
         case 3:
            if (g_iVerbunden)
            {
               printf("%20s", g_cSpieler1);
               if (strcmp(g_cSpieler2, "COMPUTER"))
                  printf("%20s", g_cSpieler2);
               printf("\n");
               anzahlSpiele(iSpieltyp);
            }
            break;
         case 4:
            zeigeHilfe(cSpieltyp);
            break;
         case 5:
            iZeige = 0;
            break;
      }
   }
}

/*
===============================================================================
   Funktion:      starteSpiel()
   in:            cSpieltyp[]
   out:           -
   Beschreibung:  Startet das jeweils ausgewählte Spiel. 
===============================================================================
*/
void starteSpiel(const char cSpieltyp[12])
{
   int iSpieltyp;
   float fRueckgabeSpiel = 0;;
   if (cSpieltyp == "Reversi")
   {
      fRueckgabeSpiel = starteReversi();
      iSpieltyp = 3;
      
      // -1 = Beenden
      if (fRueckgabeSpiel != -1 && g_iVerbunden)
      {
         zeigeStatistikNachSpielende(fRueckgabeSpiel, iSpieltyp);
      }
   }
   else if (cSpieltyp == "Checkers")
   {
      fRueckgabeSpiel = starteCheckers();
      iSpieltyp = 2;

      // -1 = Beenden
      if (fRueckgabeSpiel != -1 && g_iVerbunden)
      {
         zeigeStatistikNachSpielende(fRueckgabeSpiel, iSpieltyp);
      }
   }
   else if (cSpieltyp == "4Gewinnt")
   {
      fRueckgabeSpiel = starte4Gewinnt();
      iSpieltyp = 0;

      // -1 = Beenden
      if (fRueckgabeSpiel != -1 && g_iVerbunden)
      {
         zeigeStatistikNachSpielende(fRueckgabeSpiel, iSpieltyp);
      }
   }
   else if (cSpieltyp == "Bridges")
   {
      fRueckgabeSpiel = starteBridges();
      iSpieltyp = 1;

      // -1 = Beenden
      if (fRueckgabeSpiel != -1 && g_iVerbunden)
      {
         zeigeStatistikNachSpielende(fRueckgabeSpiel, iSpieltyp);
      }
   }
}

/*
===============================================================================
   Funktion:      zeigeHilfe()
   in:            cSpieltyp[]
   out:           -
   Beschreibung:  Ruft die Online-Hilfe für das jeweilige Spiel auf
===============================================================================
*/
void zeigeHilfe(const char cSpieltyp[12])
{
   char cBefehl[30] = "start ";
   strcat(cBefehl, cSpieltyp);
   strcat(cBefehl, "-Hilfe.html");
   system(cBefehl);
}

/*
===============================================================================
   Funktion:      waehleKI()
   in:            -
   out:           -
   Beschreibung:  Hier kann die Schwierigkeitsstufe des Computers eingestellt       
                  werden (leicht, mittel schwer). 
===============================================================================
*/
void waehleKI()
{
   // KI auf leicht zurücksetzen, da man nach einem beendeten Spiel erneut 
   //spielen kann
   g_iKI = 1;

   do
   {
      system("cls");
      printf("\n----- S C H W I E R I G K E I T S S T U F E N -----\n\n");
      printf("\t1: leicht\n");
      printf("\t2: mittel\n");
      printf("\t3: schwer\n");

      printf("\n\tIhre Eingabe: ");
      scanf("%i", &g_iKI);
      fflush(stdin);

   }while(g_iKI != 1 && g_iKI != 2 && g_iKI != 3);

   printf("\n\tSchwierigkeitsstufe des Computers: %i\n", g_iKI);
   printf("\t");
   system("pause");
}
