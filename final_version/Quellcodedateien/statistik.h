/*
============================================================================
Autor		: Christopher Smith
Klasse		: FA1
Dateiname	: statistik.h
Datum		: 03.05.2013
Beschreibung: 
============================================================================
*/
/*
============================================================================   
	Praeprozessoranweisungen
=============================================================================
*/
#define _CRT_SECURE_NO_DEPRECATE 1
#include "sql_anbindung.h"
/*
============================================================================   
	externe Variablen
============================================================================
*/
extern MYSQL *conn;
extern MYSQL_RES *result;
extern MYSQL_ROW row;
extern char g_cSpieler1[25];
extern char g_cSpieler2[25];

/*
============================================================================   
	Funktionsprototypen
============================================================================
*/
void anzahlSpiele(int);
void drawTop(int iType);
void anzahlSpieleAlle();