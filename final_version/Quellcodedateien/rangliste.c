/*
============================================================================
Autor		: Christopher Smith
Klasse		: FA1
Dateiname	: rangliste.h
Datum		: 03.05.2013
Beschreibung: 
============================================================================
*/

/*
==============================================================================
   Include Anweisungen
==============================================================================
*/

#include "Rangliste.h"

/*
===============================================================================
   Funktion:      bewertungKomplett()
   in:            -
   out:           -
   Beschreibung:  Steuert die Anzeige der Statistikausgabe aller Spieler der 
                  Punktebewertungen.
===============================================================================
*/
void bewertungKomplett (void)
{
   strcpy(sBefehlRang, "");
   rangliste();
   getchar();
}

/*
===============================================================================
   Funktion:      rangliste()
   in:            -
   out:           -
   Beschreibung:  Ausgabe der Rangliste (Punktebewertung) für alle Spieler 
                  über alle Spiele. Daten werden aus der Datenbank gelesen
===============================================================================
*/
void rangliste(void)
{
   int i = 0;

   drawTop(8);

   printf("\t\t    Name    4Gewinnt  Bridges   Checkers  Reversi\n\n");

   // 4 Gewinnt Punktezahl

   strcpy(sBefehlRang, 
      "SELECT 4ge_bewertung from 4gewinnt order by b_id DESC");
   
   iVerbindung = verbindeDB();

   if(mysql_query(conn, sBefehlRang))
   {
      ausgebenFehlermeldung("SQL Anfrage fehlgeschlagen");
   }
   else if((result = mysql_store_result(conn)) == NULL)
   {
      if(mysql_errno(conn))
      {
         ausgebenFehlermeldung
            ("Ergebnis Struktur konnte nicht angelegt werden.");
      }
      else
      {
         ausgebenFehlermeldung("Anfrage lieferte keine Ergebnisse.");
      }
   }

   while((row= mysql_fetch_row(result)))
   {
      strcpy(c4ge[i], row[0]);
      i++;
   }
   

   i = 0;

   // Bridges Punktezahl

   strcpy(sBefehlRang, 
      "SELECT bri_bewertung from bridges order by b_id DESC");
   
   iVerbindung = verbindeDB();
   if(mysql_query(conn, sBefehlRang))
   {
      ausgebenFehlermeldung("SQL Anfrage fehlgeschlagen");
   }
   else if((result = mysql_store_result(conn)) == NULL)
   {
      if(mysql_errno(conn))
      {
         ausgebenFehlermeldung
            ("Ergebnis Struktur konnte nicht angelegt werden.");
      }
      else
      {
         ausgebenFehlermeldung("Anfrage lieferte keine Ergebnisse.");
      }
   }

   while((row= mysql_fetch_row(result)))
   {
      strcpy(cBri[i], row[0]);
      i++;
   }
   

   i = 0;

   // Checkers Punktezahl

   strcpy(sBefehlRang, 
      "SELECT che_bewertung from checkers order by b_id DESC");
   
   iVerbindung = verbindeDB();
   if(mysql_query(conn, sBefehlRang))
   {
      ausgebenFehlermeldung("SQL Anfrage fehlgeschlagen");
   }
   else if((result = mysql_store_result(conn)) == NULL)
   {
      if(mysql_errno(conn))
      {
         ausgebenFehlermeldung
            ("Ergebnis Struktur konnte nicht angelegt werden.");
      }
      else
      {
         ausgebenFehlermeldung("Anfrage lieferte keine Ergebnisse.");
      }
   }

   while((row= mysql_fetch_row(result)))
   {
      strcpy(cChe[i], row[0]);
      i++;
   }
   

   i = 0;

   // Reversi Punktezahl

   strcpy(sBefehlRang, 
      "SELECT rev_bewertung from reversi order by b_id DESC");
   
   iVerbindung = verbindeDB();
   if(mysql_query(conn, sBefehlRang))
   {
      ausgebenFehlermeldung("SQL Anfrage fehlgeschlagen");
   }
   else if((result = mysql_store_result(conn)) == NULL)
   {
      if(mysql_errno(conn))
      {
         ausgebenFehlermeldung
            ("Ergebnis Struktur konnte nicht angelegt werden.");
      }
      else
      {
         ausgebenFehlermeldung("Anfrage lieferte keine Ergebnisse.");
      }
   }

   while((row= mysql_fetch_row(result)))
   {
      strcpy(cRev[i], row[0]);
      i++;
   }
   

   i = 0;



   strcpy(sBefehlRang,"SELECT b_name FROM benutzer order by b_id desc");

   iVerbindung = verbindeDB();
   if(mysql_query(conn, sBefehlRang))
   {
      ausgebenFehlermeldung("SQL Anfrage fehlgeschlagen");
   }
   else if((result = mysql_store_result(conn)) == NULL)
   {
      if(mysql_errno(conn))
      {
         ausgebenFehlermeldung
            ("Ergebnis Struktur konnte nicht angelegt werden.");
      }
      else
      {
         ausgebenFehlermeldung("Anfrage lieferte keine Ergebnisse.");
      }
   }

   while((row= mysql_fetch_row(result)))
   {
      //Bewertung(atof(cBewertung[i]));
      printf("%24s%10s%10s%10s%10s\n",
         row[0], c4ge[i], cBri[i], cChe[i], cRev[i]);
      i++;
   }
}

