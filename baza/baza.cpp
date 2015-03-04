// baza.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>		// ���������� ����������
#include <locale.h>
#include <stdlib.h>
#include "fbaza.cpp"
#include "fpoisk.cpp"

int main(void)		// ������� �������
{
	baza *first1 = NULL, *first = NULL;		// ������� ��������� �� ������ �������
	baza *end1 = NULL, *end = NULL;		// ������� ��������� �� ��������� �������
	baza *firsttmp;
	baza *endtmp;
	setlocale(LC_ALL, "");		// ���������� ������� ���������
	int key, key0, key1 = 0, key2, key3, key40, key41, key5 = 2;    // ���������� ������ ���� ������
	int N = 0;		// ���������� N ����� ������������ ��� �������� �������
	while (key1 == 0)		// ���� ��� ����������� ������ ���� �� �����
	{
		system("cls");		// ��������� ������� ��� ������� ������ �������
		printf("1. ������� ��\n");
		printf("2. ������� ��\n");
		printf("3. ����� �� ���������\n");
		scanf("%d", &key);		// ������ � ���� ��� �����
		system("cls");
		switch (key)		// �������� ������
		{
		case 1:	N = writebaza(&first, &end, N); //������ � ������� ��� ������ ������
			key0 = 1;
			break;	// �������� ������. ����� ����� �� ��������� ������
		case 2:	key0 = 1;
			N = openfile(&first, &end, N); // ������ � ������� ��� �������� �����
			break;
		case 3: key1 = 1;		// ���������� ���������� ���������
		}
		while (key0 == 1)		// ���� ��� �������� ����
		{
			system("cls");
			printf("1. ������� �� �� �����\n");
			printf("2. �������������\n");
			printf("3. ������������� ��\n");
			if (key5 == 2) printf("4. �����������\n");  // ���������� � ����������� ��
			else if (key5 == 1) printf("4. �������� � ��������� ������\n");	  // ���������
			printf("5. �����\n");
			printf("6. ��������� � ����\n");
			printf("7. �����\n");
			scanf("%d", &key2);
			switch (key2)		// �������� ������ ��� �������� ����
			{
			case 1: printscr(&first); system("pause"); break; // ����������� ������. ����������� ��������� ������� ��� ��������� ���������� �� ������
			case 2: 	system("cls");
				printf("1. ����������� �� ������ ��������\n");
				printf("2. ����������� �� ����� ���������\n");
				printf("3. ����������� �� e-mail\n");
				printf("4. ����������� �� ���� ������\n");
				printf("5. ����������� �� ������ ������\n");
				scanf("%d", &key40); system("cls");
				printf("1. ����������� �� �����������\n");
				printf("2. ����������� �� ��������\n");
				scanf("%d", &key41);
				sortbaza(key40, key41, &first, &end);
				break;
			case 3: system("cls");
				printf("1. �������� ������\n");
				printf("2. ������� ������\n");
				printf("3. ������������� ������\n");
				printf("4. ������\n");
				scanf("%d", &key3);
				switch (key3)     // �������� ������ ��� ��������������
				{
				case 1: N = writebaza(&first, &end, N); break;
					// ������ � ������� ��� ������ ������
				case 2: deletebaza(&first, &end); break;
					// ������ � ������ ��� �������� ������							
				case 3: redactbaza(&first); break;
					// ������ � ������� ��� �������������� ������
				case 4: break;	// ������
				}
				break;
			case 4: if (key5 == 2) {
						first1 = first; end1 = end;
						key5 = filtrbaza(&first, &end, &firsttmp, &endtmp);
			}	// ���� � ������� ����������, �������������� �������� ������ � ����� ������ � ������ ���������
					else if (key5 == 1) { first = first1; end = end1;  freebaza(&firsttmp, &endtmp); key5 = 2; } break;	// ���������� �������������� ������. ��������������� ������ ���������
			case 5: poisk(&first); break;	// ���� � ������� ������
			case 6: savefile(&first); break;	// ��������� ������ � ����
			case 7: freebaza(&first, &end); key0 = 0; break;
				// ������� �� �������� ����, �������������� ������ ������ �� ������
			}
		}
	}
	return 0;	// ������� ������ �� ����������
}

