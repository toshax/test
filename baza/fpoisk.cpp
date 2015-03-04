#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "fbaza.h"

int poiskmenu(void)		// ������� ���� ������
{
	int poisk;
	int a = 1;
	while (a == 1)
	{
		system("cls");
		printf("1. ����� ������ �� ������ ��������\n");
		printf("2. ����� ������ �� �����\n");
		printf("3. ����� ������ �� e-mail\n");
		printf("4. ����� ������ �� ����\n");
		printf("5. ����� ������ �� ������ ������\n");
		scanf("%d", &poisk);
		if (poisk<1 || poisk>5){ system("cls"); printf("������ ������. ���������.\n\n"); }
		// �������� �� ������ ���� ������� ������������ �����
		else a = 0;
	}
	return poisk;	// ���������� ����� �� ������ ���� ������
}

void poiskvvod(baza **baz, int poisks)	// ������� ��� ����� � ���� ������� ������
{
	baza *bazp = *baz;
	int a = 0, a1;
	system("cls");
	switch (poisks)	// ���������� �� ������ ���� ������
	{
	case 1: printf("������� �����\n"); scanf("%lld", &bazp->namber); break;
	case 2: while (a == 0)
	{
		a1 = 1;
		printf("��� ���������: ");
		scanf("%s", bazp->name);
		for (int n = 0; bazp->name[n] != '\0'; n++)
		{
			if (bazp->name[n] >= '�'&&bazp->name[n] <= '�' || bazp->name[n] >= '�'&&bazp->name[n] <= '�')
				a = 1;
			else a1 = 0;
			a = a1;
		}
		if (a == 0)
		{
			memset(bazp->name, '\0', 26);
			system("cls");
			printf("������������ ����. ������� �������� �������.\n\n");
		}
	} break;
	case 3: while (a == 0)
	{
		a1 = 1;
		printf("e-mail ���������: ");
		scanf("%s", bazp->email);
		for (int n = 0; bazp->email[n] != '\0'; n++)
		{
			if (bazp->email[n] >= 'a'&&bazp->email[n] <= 'z' || bazp->email[n] >= 'A'&&bazp->email[n] <= 'Z')
				a = 1;
			else a1 = 0;
			a = a1;
		}
		if (a == 0)
		{
			memset(bazp->email, '\0', 21);
			system("cls");
			printf("������������ ����. ������� ����������� �������.\n\n");
		}
	} break;
	case 4: printf("������� ����\n"); scanf("%s", bazp->date); break;
	case 5: printf("������� ����� ������\n"); scanf("%d", &bazp->zapis); break;
	}
}

void poisk(baza **first)	// ������� ������
{
	int poisk, a = 1;
	baza *baz = *first;
	baza *bazp = (baza *)calloc(1, sizeof(baza)); // ����� ������� � ������� ����������� ���� ��� ������
	while (a == 1)
	{
		system("cls");
		printf("1. ����� ������ �� ������ ��������\n");
		printf("2. ����� ������ �� �����\n");
		printf("3. ����� ������ �� e-mail\n");
		printf("4. ����� ������ �� ����\n");
		printf("5. ����� ������ �� ������ ������\n");
		scanf("%d", &poisk);
		if (poisk<1 || poisk>5) { system("cls"); printf("������ �����. ���������.\n\n"); }
		else a = 0;
	}
	poiskvvod(&bazp, poisk);	// ������� ��� ����� ������
	system("cls");
	printf("%3����� ���."); printf(" | "); printf("%20�.�.�."); printf(" | "); printf("%14 "); printf("e-mail"); printf(" | "); printf("%7����"); printf(" | "); printf("%4������");
	printf("\n-------------|---------------------------|----------------------|------------|-----------\n");
	while (baz)
	{
		if (bazp->namber == baz->namber || (strcmp(bazp->name, baz->name)) == 0 || (strcmp(bazp->email, baz->email)) == 0 || (strcmp(bazp->date, baz->date)) == 0 || bazp->zapis == baz->zapis)
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
		}
		baz = baz->next;
	}
	free(bazp);	// ������� ������ �� ��������
	system("pause");
}

int filtrbaza(baza **first, baza **end, baza **firsttmp, baza **endtmp)	// ������� ��� ���������� ������
{
	baza *baz = *first;
	*firsttmp = *endtmp = NULL;	// ���������� ������ ������ ��������������� NULL, �.�. ������ �� ������ ���
	long long int namber1, namber2;
	int zapis1, zapis2;
	char name1[26], email1[21], date1[11], name2[26], email2[21], date2[11];
	int poisk, a = 1, b = 0;
	system("cls");
	printf("1. ����������� �� ������ ��������\n");
	printf("2. ����������� �� ����� ���������\n");
	printf("3. ����������� �� e-mail\n");
	printf("4. ����������� �� ����\n");
	printf("5. ����������� �� ������\n");
	scanf("%d", &poisk);
	while (baz)
	{
		switch (poisk)	// ����� �� ������ ���� ������
		{
		case 1: if (a == 1)
		{
			system("cls");
			printf("������� ������ ������\n");
			scanf("%lld", &namber1);
			printf("������� ����� ������\n");
			scanf("%lld", &namber2); a = 0;
		}
				if (baz->namber >= namber1&&baz->namber <= namber2)
				{
					b = 1;
				} break;
		case 2:  if (a == 1)
		{
			system("cls");
			printf("������� ������ ������\n");
			scanf("%s", name1);
			printf("������� ����� ������\n");
			scanf("%s", name2); a = 0;
		}
				 if ((strcmp(baz->name, name1) >= 0) && (strcmp(baz->name, name2) <= 0))
				 {
					 b = 1;
				 } break;
		case 3:  if (a == 1)
		{
			system("cls");
			printf("������� ������ ������\n");
			scanf("%s", email1);
			printf("������� ����� ������\n");
			scanf("%s", email2); a = 0;
		}
				 if ((strcmp(baz->email, email1) >= 0) && (strcmp(baz->email, email2) <= 0))
				 {
					 b = 1;
				 } break;
		case 4:  if (a == 1)
		{
			system("cls");
			printf("������� ������ ������\n");
			scanf("%s", date1);
			printf("������� ����� ������\n");
			scanf("%s", date2); a = 0;
		}
				 if ((strcmp(baz->date, date1) >= 0) && (strcmp(baz->date, date2) <= 0))
				 {
					 b = 1;
				 } break;
		case 5:  if (a == 1)
		{
			system("cls");
			printf("������� ������ ������\n");
			scanf("%d", &zapis1);
			printf("������� ����� ������\n");
			scanf("%d", &zapis2); a = 0;
		}
				 if (baz->zapis >= zapis1&&baz->zapis <= zapis2)
				 {
					 b = 1;
				 }
		}
		if (b == 1)	// ���� ���� ������� �� ������ ����� ����������� ������ �������� ������
		{
			baza *tmp = (baza *)calloc(1, sizeof(baza)); // �������� ������ ��������
			tmp->namber = baz->namber;	// ������� ������
			strcpy(tmp->name, baz->name);
			strcpy(tmp->email, baz->email);
			strcpy(tmp->date, baz->date);
			tmp->zapis = baz->zapis;
			if (!*firsttmp || !*endtmp)		// ���� ��������� �����, �� ����� ������� ������
			{
				*endtmp = tmp;
				*firsttmp = tmp;
				tmp->next = NULL;
				tmp->pred = NULL;
			}
			else	// ����� ����� ������� ����������� � ������ ������
			{
				tmp->next = *firsttmp;
				*firsttmp = tmp;
				tmp->pred = NULL;
				tmp = tmp->next;
				tmp->pred = *firsttmp;
			}
			b = 0;	// ���� ����������� �� 0
		}
		baz = baz->next;		// ������� � ���������� �������� ������
	}
	*first = *firsttmp; *end = *endtmp;	// ������ ���������� ������ ������
	return 1;	// ���������� �������� 1
}
