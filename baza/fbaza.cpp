#include <stdio.h>		// ���������� ����������
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fbaza.h"

int writebaza(baza **first, baza **end, int N)     // ������� ���������� ����� ��������� � ������
{
	system("cls");
	struct tm *tk;		// ��������� ���� ��� tm
	time_t t; int n;
	int kolzap;
	printf("������� ������� ��������?\n");
	scanf("%d", &kolzap);
	baza *baz;		// ��������� ���� ��� baza
	for (int i = 0; i<kolzap; i++)	// ���� ����������� ���� �� ����� ������� ������ ����������� ��������� ������
	{
		system("cls");
		N++;
		baz = (baza *)calloc(1, sizeof(baza));	// ������� ����� ������� ������
		if (!baz) { printf("��� ��������� ������!\n"); return N; }	// ��� �������� ������ ������� �������� ������

		printf("����� ��������: ");
		scanf("%12lld", &baz->namber);

		system("cls");
		int a1, a = 0;
		while (a == 0)
		{
			a1 = 1;
			printf("��� ���������: ");
			scanf("%s", baz->name);
			for (n = 0; baz->name[n] != '\0'; n++)	// ����������� ��������� ������
			{
				if (baz->name[n] >= '�'&&baz->name[n] <= '�' || baz->name[n] >= '�'&&baz->name[n] <= '�')		// ���� ������� �������������, �� ����������� �������� �����
					a = 1;
				else a1 = 0;		// ����� ����������� ������ ��������
				a = a1;
			}
			if (a == 0)
			{
				memset(baz->name, '\0', 25);	// ������� ������� �� ������
				system("cls");
				printf("������������ ����. ������� �������� �������.\n\n");
			}
		}
		baz->name[25] = '\0';	// �������� ������ ��������� ������, �� ������ ���������� ���������� ��������
		baz->name[n] = '\0';

		system("cls");
		a = 0;
		while (a == 0)
		{
			a1 = 1;
			printf("e-mail ���������: ");
			scanf("%s", baz->email);
			for (n = 0; baz->email[n] != '\0'; n++)
			{
				if (baz->email[n] >= 'a'&&baz->email[n] <= 'z' || baz->email[n] >= 'A'&&baz->email[n] <= 'Z' || baz->email[n] == '@' || baz->email[n] == '.')
					a = 1;
				else a1 = 0;
				a = a1;
			}
			if (a == 0)
			{
				memset(baz->email, '\0', 20);
				system("cls");
				printf("������������ ����. ������� ����������� �������.\n\n");
			}
		}
		baz->email[20] = '\0';
		baz->email[n] = '\0';

		time(&t);	// ������� ���������� ������� ����������� ����� �������
		tk = localtime(&t);	// ������� ���������� ��������� �� ��������� ���� tm
		sprintf(baz->date, "%d.%d.%d", tk->tm_mday, 1 + tk->tm_mon, 1900 + tk->tm_year);
		system("cls");
		baz->zapis = N;
		if (!*first || !*end)		// ���� ������ ������ ����� ����� ������, �� ����������� ��������� �������
		{
			*end = baz;	// ��������� ����� ������ ��������������� �� ����� �������
			*first = baz;      // ��������� ������ ������ ��������������� �� ����� �������
			baz->next = NULL;	// ����-��������� �� ��������� ������� ��������������� �� NULL
			baz->pred = NULL;	// ����-��������� �� ���������� ������� ��������������� �� NULL
		}
		else	// ���� ������� �� �������������, �� ����������� ������ ���������
		{
			baz->next = *first;	// ������ �������� ����-��������� ���������� �������� ��������������� �� ������ �������
			*first = baz;	// ��������� ��������������� �� ����� �������
			baz->pred = NULL;	// ������ �������� ����-��������� ����������� �������� ��������������� NULL
			baz = baz->next;		// ���������� ����� �� ������� � �����
			baz->pred = *first;	// ������� �������� ����-��������� �� ���������� ������� ��������������� �� ������ �������
		}
	}
	return N;	// ������� ���������� ���������� ����� � ���� ������
}

void printscr(baza **first)	// ������� ����������� ������ �� �����
{
	baza *baz;
	baz = *first;	// ��������� � ������� �������� ������
	system("cls");
	printf("%3����� ���."); printf(" | "); printf("%20�.�.�."); printf(" | "); printf("%14 "); printf("e-mail"); printf(" | "); printf("%7����"); printf(" | "); printf("%4������");
	printf("\n-------------|---------------------------|----------------------|------------|-----------\n");
	while (baz)	// ���� ��� ����������� ������ �� ������
	{
		printf("%12lld", baz->namber);
		printf(" | ");
		printf("%25s", baz->name);
		printf(" | ");
		printf("%20s", baz->email);
		printf(" | ");
		printf("%10s", baz->date);
		printf(" | ");
		printf("%9d\n", baz->zapis);
		baz = baz->next;		// ������������ � ���������� �������� ������
	}
}

void sortbaza(int vbr1, int vbr2, baza **first, baza **end)	// ������� ����������
{
	baza *s1, *s2=NULL, *s3, *s4, *hh = NULL;
	s1 = s3 = *first;		// ������ �� ������ �������
	s4 = (baza *)calloc(1, sizeof(baza));
	int vbr3 = 0;
	for (; s1->next; s1 = s1->next)		// ����� �������� ��� ��������������
	{
		for (s2 = s1->next; s2; s3 = s3->next, s2 = s2->next)    // ������� ����������� ���������
		{
			if (s2 == s1->next) s3 = s1;	// s3-������� ������������� ����� s2
			switch (vbr1)	// ����� �� ������ ���� �����������
			{
			case 1: if (vbr2 == 1)
				if (s1->namber>s2->namber)
					vbr3 = 1;
				if (vbr2 == 2)
					if (s1->namber<s2->namber)
						vbr3 = 2;
				break;
			case 2: if (vbr2 == 1)
				if ((strcmp(s1->name, s2->name))>0)
					vbr3 = 1;
				if (vbr2 == 2)
					if ((strcmp(s1->name, s2->name))<0)
						vbr3 = 2;
				break;
			case 3: if (vbr2 == 1)
				if ((strcmp(s1->email, s2->email))>0)
					vbr3 = 1;
				if (vbr2 == 2)
					if ((strcmp(s1->email, s2->email))<0)
						vbr3 = 2;
				break;
			case 4: if (vbr2 == 1)
				if ((strcmp(s1->date, s2->date))>0)
					vbr3 = 1;
				if (vbr2 == 2)
					if ((strcmp(s1->date, s2->date))<0)
						vbr3 = 2;
				break;
			case 5: if (vbr2 == 1)
				if (s1->zapis>s2->zapis)
					vbr3 = 1;
				if (vbr2 == 2)
					if (s1->zapis<s2->zapis)
						vbr3 = 2;
				break;
			}
			if (vbr3 == 1)	// ���������� �� �����������
			{
				s3->next = s2->next;	// �������� �������� ������-����������� �� ��������� �������
				s2->next = s1;	// ������� � min ���������� ����� s1
				s4->next = s2;   // s4 � ������� ������������� ����� s1
				s1 = s2;	// ����� ����� s1 � (����� ������ s1<->s2)
			}
			else if (vbr3 == 2)	// ���������� �� ��������
			{
				s3->next = s2->next;
				s2->next = s1;	// ������� � max ���������� ����� s1
				s4->next = s2;
				s1 = s2;
			}
			vbr3 = 0;
		}
		if (!hh)
		{
			hh = s1;	        // ����������� �������� ��������� �� ������ �������
			free(s4);
		}
		s4 = s1;
	}
	*first = hh;	// ������� �������� ����������� ��������� �� ������
	for (s1 = *first; s1->next; s1 = s1->next)	// ���� ��� ������������ ����-��������� �� ���������� �������
	{
		if (s1 == *first) s1->pred = NULL;		// ���� ������� ������, �� ������������� ����-��������� �� NULL
		s2 = s1->next;	// ������������� � ���������� ��������
		s2->pred = s1;	// ������������� ����-��������� ����������� �������� �� ���������� �������
	}
	*end = s2;	// ������������� ��������� �� ��������� �������
}



void deletebaza(baza **first, baza **end)	// �������� ��������� �� ������
{
	baza *baz = *first, *temp, *tmp;
	baza *bazp;
	bazp = (baza *)calloc(1, sizeof(baza));	// �������, ��� �� ����� ������ � ���� ������ ��� ������
	int a;
	int poisk = poiskmenu();		// ���� � ���� ������ � ��������� �� ������ ���� ������
	poiskvvod(&bazp, poisk);	// ������� � ������� ������ � ���� ��� ������ ��������
	while (baz)
	{
		if (bazp->namber == baz->namber || (strcmp(bazp->name, baz->name)) == 0 || (strcmp(bazp->email, baz->email)) == 0 || (strcmp(bazp->date, baz->date)) == 0 || bazp->zapis == baz->zapis)
		{
			system("cls");
			printf("�������?\n1. ��\n2. ���\n\n"); 	// ������ ����� ������� ���� ������� ��� ���
			printf("%3����� ���."); printf(" | "); printf("%20�.�.�."); printf(" | "); printf("%14 "); printf("e-mail"); printf(" | "); printf("%7����"); printf(" | "); printf("%4������");
			printf("\n-------------|---------------------------|----------------------|------------|-----------\n");
			printf("%12lld", baz->namber);
			printf(" | ");
			printf("%25s", baz->name);
			printf(" | ");
			printf("%20s", baz->email);
			printf(" | ");
			printf("%10s", baz->date);
			printf(" | ");
			printf("%9d\n", baz->zapis);
			scanf("%d", &a);
			if (a == 1)	// ���� 1, �� ������� ���������
			{
				if (baz == *first) // ���� ������� ������, �� ��������� ������ �������
				{
					if (baz->next == NULL){ *first = NULL; free(baz); baz = *first; }
					else { temp = baz->next; free(baz); baz = temp; temp->pred = NULL; *first = temp; }
				}
				else if (baz->next == NULL)	 // ���� ������� ���������, �� ��������� ��������� �������
				{
					temp = baz->pred; free(baz); baz = temp; temp->next = NULL; *end = temp;
				}
				else	// ���� ������� � �������� ������, �� ��������� ���� �������, � �������� �������� ����������� ����� ����� ������-�����������
				{
					temp = baz->pred; tmp = baz->next; temp->next = tmp; tmp->pred = temp; free(baz); baz = tmp;
				}
			}
			else if (a == 2) { baz = baz->next; }	// ���� 2, �� ������������ �� ������ ��� ��������
			else printf("������ �����. ���������.\n");	// ��� ������������ ����� ������ ������
		}
		else baz = baz->next;	// ���� ���� � ������ �� ���������, �� ������������� � ���������� ��������
	}
	free(bazp);	// ������� ������ �� ��������
}

void redactbaza(baza **first)	// ������� �������������� ����� ���������
{
	baza *baz = *first;
	baza *bazp = (baza *)calloc(1, sizeof(baza));	// �������, ��� �� ����� ������ � ���� ������ ��� ������
	struct tm *tk;
	time_t t;
	int b, n;
	int poisk = poiskmenu();
	poiskvvod(&bazp, poisk);
	while (baz)
	{
		if (bazp->namber == baz->namber || (strcmp(bazp->name, baz->name)) == 0 || (strcmp(bazp->email, baz->email)) == 0 || (strcmp(bazp->date, baz->date)) == 0 || bazp->zapis == baz->zapis)
		{
			system("cls");
			printf("�������������?\n1. ��\n2. ���\n\n");
			printf("%3����� ���."); printf(" | "); printf("%20�.�.�."); printf(" | "); printf("%14 "); printf("e-mail"); printf(" | "); printf("%7����"); printf(" | "); printf("%4������");
			printf("\n-------------|---------------------------|----------------------|------------|-----------\n");
			printf("%12lld", baz->namber);
			printf(" | ");
			printf("%25s", baz->name);
			printf(" | ");
			printf("%20s", baz->email);
			printf(" | ");
			printf("%10s", baz->date);
			printf(" | ");
			printf("%9d\n", baz->zapis);
			scanf("%d", &b);
			if (b == 1)
			{
				system("cls");
				printf("����� ��������: %lld\n", baz->namber);
				printf("����� ��������: "); scanf("%12lld", &baz->namber);
				system("cls");
				int a = 0, a1;
				system("cls");
				printf("��� ���������: %s\n", baz->name);
				printf("��� ���������: "); scanf("%s", baz->name);
				while (a == 0)	// �������� ��������� ������
				{
					a1 = 1;
					for (n = 0; baz->name[n] != '\0'; n++)
					{
						if (baz->name[n] >= '�'&&baz->name[n] <= '�' || baz->name[n] >= '�'&&baz->name[n] <= '�')
							a = 1;
						else a1 = 0;
						a = a1;
					}
					if (a == 0)
					{
						memset(baz->name, '\0', 25);
						system("cls");
						printf("������������ ����. ������� �������� �������.\n\n");
						printf("��� ���������: "); scanf("%s", baz->name);
					}
				}
				baz->name[25] = '\0';
				baz->name[n] = '\0';

				system("cls");
				printf("e-mail ���������: %s\n", baz->email);
				printf("e-mail ���������: "); scanf("%s", baz->email);
				a = 0;
				while (a == 0)	// �������� ��������� ������
				{
					a1 = 1;
					for (n = 0; baz->email[n] != '\0'; n++)
					{
						if (baz->email[n] >= 'a'&&baz->email[n] <= 'z' || baz->email[n] >= 'A'&&baz->email[n] <= 'Z' || baz->email[n] == '@' || baz->email[n] == '.')
							a = 1;
						else a1 = 0;
						a = a1;
					}
					if (a == 0)
					{
						memset(baz->email, '\0', 20);
						system("cls");
						printf("������������ ����. ������� ����������� �������.\n\n");
						printf("e-mail ���������: "); scanf("%s", baz->email);
					}
				}
				baz->email[20] = '\0';
				baz->email[n] = '\0';

				time(&t);
				tk = localtime(&t);
				sprintf(baz->date, "%d.%d.%d", tk->tm_mday, 1 + tk->tm_mon, 1900 + tk->tm_year);
				system("cls");
				baz = baz->next;
			}
			else if (b == 2) baz = baz->next;
			else printf("������ �����. ���������.\n");
		}
		else baz = baz->next;
	}
	free(bazp);
}

void freebaza(baza **first, baza **end)	// ������� ������� ������ �� ������
{
	baza *baz = *first, *tmp;
	while (baz)	// ���� ����������� ���� �� ������ �� ����� ������
	{
		tmp = baz;
		baz = baz->next;
		free(tmp);
	}
	*first = *end = NULL;	// ��������� ��������������� �� NULL, �.�. ������ �� ����������
}

void savefile(baza **first)	// ������� ���������� ������ � ����
{
	system("cls");
	char fail[128];
	printf("������� �������� ����� � ��\n");
	scanf("%s", fail);	// ������ �������� �����
	FILE *file = fopen(fail, "wb");	// ��������� �������� ���� ��� ��������������
	if (file == NULL) { printf("������ ��� �������� �����.\n"); return; }
	baza *baz = *first;
	while (baz)	// ���� ���������� ������ � ���� ����������� ���� �������� � ������ �� ����������
	{
		fprintf(file, "%lld\n", baz->namber);
		fprintf(file, "%s\n", baz->name);
		fprintf(file, "%s\n", baz->email);
		fprintf(file, "%s\n", baz->date);
		fprintf(file, "%d\n", baz->zapis);
		baz = baz->next;
	}
	fclose(file);	// �������� �����
}

int openfile(baza **first, baza **end, int N)	// ������� �������� �����
{
	char fail[128];
	baza *baz;
	printf("������� �������� ����� � ��\n");
	scanf("%s", fail);	// ������ �������� �����
	FILE *file = fopen(fail, "rb");	// ��������� �������� ���� ��� ������
	if (file == NULL) { printf("������ ��� �������� �����.\n"); return N; }
	while (!feof(file))	// ���� ���������� ������ �� ����� � ���� ������ �� ��������� ���� �� ����� ��������� ����� �����
	{
		baz = (baza *)calloc(1, sizeof(baza));	// �������� ������ �������� ��� ������
		fscanf(file, "%lld\n", &baz->namber);
		fscanf(file, "%s\n", baz->name);
		fscanf(file, "%s\n", baz->email);
		fscanf(file, "%s\n", baz->date);
		fscanf(file, "%d\n", &baz->zapis);
		if (!*first || !*end)		// ���� ��������� ������ � ����� ������ �����, �� ����� ������� ���������� ������
		{
			*end = baz;
			*first = baz;
			baz->next = NULL;
			baz->pred = NULL;
		}
		else	// ����� ����� ������� ����������� � ����� ������
		{
			baz->pred = *end;
			*end = baz;
			baz->next = NULL;
			baz = baz->pred;
			baz->next = *end;
		}
		if (baz->zapis>N) N = baz->zapis;
	}
	fclose(file);	// ��������� ����
	return N;	// ���������� ���������� ����� � ������
}
