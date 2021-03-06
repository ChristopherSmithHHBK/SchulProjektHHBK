/*
============================================================================
Autor		: Christopher Smith
Klasse		: FA1
Dateiname	: spielmenue.h
Datum		: 03.05.2013
Beschreibung: 
============================================================================
*/

/*
============================================================================
Pr�prozessoranweisungen
==============================================================================
*/

#define _CRT_SECURE_NO_DEPRECATE 1

   /* Microsoft hat alle g�ngigen Ein- und Ausgabefunktionen
      als gef�hrlich eingestuft und durch neue Varianten ersetzt.
      Mit den neuen Funktionen sind die Programme aber nicht
      kompatible zu anderen Entwicklungsumgebungen.
      Bei Verwendung der alten Funktionen wird eine Warnung ausgegeben.
      Diese Warnung kann durch die obige Definition unterdr�ckt werden.
  */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Statistik.h"
#include "checkers.h"
#include "Reversi.h"
#include "bridges.h"
#include "4Gewinnt.h"

/*
============================================================================
externe Variablen
==============================================================================
*/
extern int g_iVerbunden;

/*
============================================================================
Funktionsprototypen
==============================================================================
*/
void zeigeSpielmenu(const char[12]);
void drawTop(int iType);
void starteSpiel(const char[12]);
void zeigeHilfe(const char[12]);
void waehleKI();