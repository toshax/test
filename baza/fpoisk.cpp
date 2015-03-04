#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "fbaza.h"

int poiskmenu(void)		// Функция меню поиска
{
	int poisk;
	int a = 1;
	while (a == 1)
	{
		system("cls");
		printf("1. Найти запись по номеру телефона\n");
		printf("2. Найти запись по имени\n");
		printf("3. Найти запись по e-mail\n");
		printf("4. Найти запись по дате\n");
		printf("5. Найти запись по номеру записи\n");
		scanf("%d", &poisk);
		if (poisk<1 || poisk>5){ system("cls"); printf("Ошибка вводаю. Повторите.\n\n"); }
		// Сообщает об ошибке если введено неправильное число
		else a = 0;
	}
	return poisk;	// Возвращает номер по какому полю искать
}

void poiskvvod(baza **baz, int poisks)	// Функция для ввода в поле искомые данные
{
	baza *bazp = *baz;
	int a = 0, a1;
	system("cls");
	switch (poisks)	// Выбирается по какому полю искать
	{
	case 1: printf("Введите номер\n"); scanf("%lld", &bazp->namber); break;
	case 2: while (a == 0)
	{
		a1 = 1;
		printf("Имя владельца: ");
		scanf("%s", bazp->name);
		for (int n = 0; bazp->name[n] != '\0'; n++)
		{
			if (bazp->name[n] >= 'а'&&bazp->name[n] <= 'я' || bazp->name[n] >= 'А'&&bazp->name[n] <= 'Я')
				a = 1;
			else a1 = 0;
			a = a1;
		}
		if (a == 0)
		{
			memset(bazp->name, '\0', 26);
			system("cls");
			printf("Неправильный ввод. Вводите русскими буквами.\n\n");
		}
	} break;
	case 3: while (a == 0)
	{
		a1 = 1;
		printf("e-mail владельца: ");
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
			printf("Неправильный ввод. Вводите английскими буквами.\n\n");
		}
	} break;
	case 4: printf("Введите дату\n"); scanf("%s", bazp->date); break;
	case 5: printf("Введите номер записи\n"); scanf("%d", &bazp->zapis); break;
	}
}

void poisk(baza **first)	// Функция поиска
{
	int poisk, a = 1;
	baza *baz = *first;
	baza *bazp = (baza *)calloc(1, sizeof(baza)); // Новый элемент в котором заполняется поле для поиска
	while (a == 1)
	{
		system("cls");
		printf("1. Найти запись по номеру телефона\n");
		printf("2. Найти запись по имени\n");
		printf("3. Найти запись по e-mail\n");
		printf("4. Найти запись по дате\n");
		printf("5. Найти запись по номеру записи\n");
		scanf("%d", &poisk);
		if (poisk<1 || poisk>5) { system("cls"); printf("Ошибка ввода. Повторите.\n\n"); }
		else a = 0;
	}
	poiskvvod(&bazp, poisk);	// Функция для ввода поиска
	system("cls");
	printf("%3Номер тел."); printf(" | "); printf("%20Ф.И.О."); printf(" | "); printf("%14 "); printf("e-mail"); printf(" | "); printf("%7Дата"); printf(" | "); printf("%4Запись");
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
	free(bazp);	// Очищает память от элемента
	system("pause");
}

int filtrbaza(baza **first, baza **end, baza **firsttmp, baza **endtmp)	// Функция для фильтрации списка
{
	baza *baz = *first;
	*firsttmp = *endtmp = NULL;	// Указателям нового списка устанавливается NULL, т.к. список не создан еще
	long long int namber1, namber2;
	int zapis1, zapis2;
	char name1[26], email1[21], date1[11], name2[26], email2[21], date2[11];
	int poisk, a = 1, b = 0;
	system("cls");
	printf("1. Фильтровать по номеру телефона\n");
	printf("2. Фильтровать по имени владельца\n");
	printf("3. Фильтровать по e-mail\n");
	printf("4. Фильтровать по дате\n");
	printf("5. Фильтровать по записи\n");
	scanf("%d", &poisk);
	while (baz)
	{
		switch (poisk)	// Выбор по какому полю искать
		{
		case 1: if (a == 1)
		{
			system("cls");
			printf("Введите начало поиска\n");
			scanf("%lld", &namber1);
			printf("Введите конец поиска\n");
			scanf("%lld", &namber2); a = 0;
		}
				if (baz->namber >= namber1&&baz->namber <= namber2)
				{
					b = 1;
				} break;
		case 2:  if (a == 1)
		{
			system("cls");
			printf("Введите начало поиска\n");
			scanf("%s", name1);
			printf("Введите конец поиска\n");
			scanf("%s", name2); a = 0;
		}
				 if ((strcmp(baz->name, name1) >= 0) && (strcmp(baz->name, name2) <= 0))
				 {
					 b = 1;
				 } break;
		case 3:  if (a == 1)
		{
			system("cls");
			printf("Введите начало поиска\n");
			scanf("%s", email1);
			printf("Введите конец поиска\n");
			scanf("%s", email2); a = 0;
		}
				 if ((strcmp(baz->email, email1) >= 0) && (strcmp(baz->email, email2) <= 0))
				 {
					 b = 1;
				 } break;
		case 4:  if (a == 1)
		{
			system("cls");
			printf("Введите начало поиска\n");
			scanf("%s", date1);
			printf("Введите конец поиска\n");
			scanf("%s", date2); a = 0;
		}
				 if ((strcmp(baz->date, date1) >= 0) && (strcmp(baz->date, date2) <= 0))
				 {
					 b = 1;
				 } break;
		case 5:  if (a == 1)
		{
			system("cls");
			printf("Введите начало поиска\n");
			scanf("%d", &zapis1);
			printf("Введите конец поиска\n");
			scanf("%d", &zapis2); a = 0;
		}
				 if (baz->zapis >= zapis1&&baz->zapis <= zapis2)
				 {
					 b = 1;
				 }
		}
		if (b == 1)	// Если поле найдено то данные полей переносится новому элементу списка
		{
			baza *tmp = (baza *)calloc(1, sizeof(baza)); // Создание нового элемента
			tmp->namber = baz->namber;	// Перенос данных
			strcpy(tmp->name, baz->name);
			strcpy(tmp->email, baz->email);
			strcpy(tmp->date, baz->date);
			tmp->zapis = baz->zapis;
			if (!*firsttmp || !*endtmp)		// Если указатели равны, то новый элемент первый
			{
				*endtmp = tmp;
				*firsttmp = tmp;
				tmp->next = NULL;
				tmp->pred = NULL;
			}
			else	// Иначе новый элемент добавляется в начала списка
			{
				tmp->next = *firsttmp;
				*firsttmp = tmp;
				tmp->pred = NULL;
				tmp = tmp->next;
				tmp->pred = *firsttmp;
			}
			b = 0;	// Ключ скидывается на 0
		}
		baz = baz->next;		// Переход к следующему элементу списка
	}
	*first = *firsttmp; *end = *endtmp;	// Меняем указателям адреса списка
	return 1;	// Возвращает значение 1
}
