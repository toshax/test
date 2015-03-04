#ifndef __fbaza_h
#define __fbaza_h


struct	baza	// —труктура содержащие различные типы полей
{
	long long int namber;
	char name[25];
	char email[20];
	char date[10];
	int zapis;
	baza *next;
	baza *pred;
};

int writebaza(baza **, baza **, int);
void printscr(baza **);
void sortbaza(int, int, baza **, baza **);
int poiskmenu(void);
void poiskvvod(baza **, int);
void deletebaza(baza **, baza **);
void redactbaza(baza **);
void poisk(baza **);
void freebaza(baza **, baza **);
void savefile(baza **);
int openfile(baza **, baza **, int);
int filtrbaza(baza **, baza **, baza **, baza **);

#endif
