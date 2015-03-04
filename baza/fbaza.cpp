#include <stdio.h>		// Подключаем библиотеки
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fbaza.h"

int writebaza(baza **first, baza **end, int N)     // Функция добавления новых элементов в список
{
	system("cls");
	struct tm *tk;		// Указателю даем тип tm
	time_t t; int n;
	int kolzap;
	printf("Сколько записей добавить?\n");
	scanf("%d", &kolzap);
	baza *baz;		// Указателю даем тип baza
	for (int i = 0; i<kolzap; i++)	// Цикл повторяется пока не будет введено нужное количествро элементов списка
	{
		system("cls");
		N++;
		baz = (baza *)calloc(1, sizeof(baza));	// Создаем новый элемент списка
		if (!baz) { printf("Нет свободной памяти!\n"); return N; }	// При нехватки памяти функция завершит работу

		printf("Номер телефона: ");
		scanf("%12lld", &baz->namber);

		system("cls");
		int a1, a = 0;
		while (a == 0)
		{
			a1 = 1;
			printf("Имя владельца: ");
			scanf("%s", baz->name);
			for (n = 0; baz->name[n] != '\0'; n++)	// Проверяется введенные данные
			{
				if (baz->name[n] >= 'а'&&baz->name[n] <= 'я' || baz->name[n] >= 'А'&&baz->name[n] <= 'Я')		// Если условие удовлетворяет, то выполняется оператор цикла
					a = 1;
				else a1 = 0;		// иначе выполняется другой оператор
				a = a1;
			}
			if (a == 0)
			{
				memset(baz->name, '\0', 25);	// Очистка массива от данных
				system("cls");
				printf("Неправильный ввод. Вводите русскими буквами.\n\n");
			}
		}
		baz->name[25] = '\0';	// Ставится символ окончании строки, на случай превышении допустимых значений
		baz->name[n] = '\0';

		system("cls");
		a = 0;
		while (a == 0)
		{
			a1 = 1;
			printf("e-mail владельца: ");
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
				printf("Неправильный ввод. Вводите английскими буквами.\n\n");
			}
		}
		baz->email[20] = '\0';
		baz->email[n] = '\0';

		time(&t);	// Функция возвращает текущее календарное время системы
		tk = localtime(&t);	// Функция возвращает указатель на структуру типа tm
		sprintf(baz->date, "%d.%d.%d", tk->tm_mday, 1 + tk->tm_mon, 1900 + tk->tm_year);
		system("cls");
		baz->zapis = N;
		if (!*first || !*end)		// Если начало списка равно конца списка, то выполняется операторы условия
		{
			*end = baz;	// Указателю конца списка устанавливается на новый элемент
			*first = baz;      // Указателю начала списка устанавливается на новый элемент
			baz->next = NULL;	// Поле-указатель на следующий элемент устанавливается на NULL
			baz->pred = NULL;	// Поле-указатель на предыдущий элемент устанавливается на NULL
		}
		else	// Если условие не удовлетворяет, то выполняются другие операторы
		{
			baz->next = *first;	// Новому элементу полю-указателю следующему элементу устанавливается на первый элемент
			*first = baz;	// Указатель устанавливается на новый элемент
			baz->pred = NULL;	// Новому элементу полю-указателю предыдущему элементу устанавливается NULL
			baz = baz->next;		// Происходит сдвиг на элемент в перед
			baz->pred = *first;	// Второму элементу полю-указателю на предыдущий элемент устанавливается на первый элемент
		}
	}
	return N;	// Функция возвращает количество полей в базе данных
}

void printscr(baza **first)	// Функция отображения списка на экран
{
	baza *baz;
	baz = *first;	// Переходим к первому элементу списка
	system("cls");
	printf("%3Номер тел."); printf(" | "); printf("%20Ф.И.О."); printf(" | "); printf("%14 "); printf("e-mail"); printf(" | "); printf("%7Дата"); printf(" | "); printf("%4Запись");
	printf("\n-------------|---------------------------|----------------------|------------|-----------\n");
	while (baz)	// Цикл для отображения списка на экране
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
		baz = baz->next;		// Перемещаемся к следующему элементу списка
	}
}

void sortbaza(int vbr1, int vbr2, baza **first, baza **end)	// Функция сортировки
{
	baza *s1, *s2=NULL, *s3, *s4, *hh = NULL;
	s1 = s3 = *first;		// Ссылка на голову очереди
	s4 = (baza *)calloc(1, sizeof(baza));
	int vbr3 = 0;
	for (; s1->next; s1 = s1->next)		// Выбор элемента для упорядочивания
	{
		for (s2 = s1->next; s2; s3 = s3->next, s2 = s2->next)    // Перебор последующих элементов
		{
			if (s2 == s1->next) s3 = s1;	// s3-элемент расположенный перед s2
			switch (vbr1)	// Выбор по какому полю сортировать
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
			if (vbr3 == 1)	// Сортировка по возрастанию
			{
				s3->next = s2->next;	// Элементы меняются полями-указателями на следующий элемент
				s2->next = s1;	// Элемент с min становится перед s1
				s4->next = s2;   // s4 – элемент расположенный перед s1
				s1 = s2;	// Новый адрес s1 – (после замены s1<->s2)
			}
			else if (vbr3 == 2)	// Сортировка по убыванию
			{
				s3->next = s2->next;
				s2->next = s1;	// Элемент с max становится перед s1
				s4->next = s2;
				s1 = s2;
			}
			vbr3 = 0;
		}
		if (!hh)
		{
			hh = s1;	        // Модификация текущего указателя на голову очереди
			free(s4);
		}
		s4 = s1;
	}
	*first = hh;	// Возврат возможно измененного указателя на голову
	for (s1 = *first; s1->next; s1 = s1->next)	// Цикл для перестановки поля-указателя на предыдущий элемент
	{
		if (s1 == *first) s1->pred = NULL;		// Если элемент первый, то устанавливаем поле-указатель на NULL
		s2 = s1->next;	// Передвигаемся к следующему элементу
		s2->pred = s1;	// Устанавливаем поле-указатель предыдущего элемента на предыдущий элемент
	}
	*end = s2;	// Устанавливаем указатель на последний элемент
}



void deletebaza(baza **first, baza **end)	// Удаление элементов из списка
{
	baza *baz = *first, *temp, *tmp;
	baza *bazp;
	bazp = (baza *)calloc(1, sizeof(baza));	// Создаем, что бы потом ввести в поле данные для поиска
	int a;
	int poisk = poiskmenu();		// Вход в меню поиска и получения по какому полю искать
	poiskvvod(&bazp, poisk);	// Функция в котором вводим в поле для поиска удаления
	while (baz)
	{
		if (bazp->namber == baz->namber || (strcmp(bazp->name, baz->name)) == 0 || (strcmp(bazp->email, baz->email)) == 0 || (strcmp(bazp->date, baz->date)) == 0 || bazp->zapis == baz->zapis)
		{
			system("cls");
			printf("Удалить?\n1. Да\n2. Нет\n\n"); 	// Дается выбор удалять этот элемент или нет
			printf("%3Номер тел."); printf(" | "); printf("%20Ф.И.О."); printf(" | "); printf("%14 "); printf("e-mail"); printf(" | "); printf("%7Дата"); printf(" | "); printf("%4Запись");
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
			if (a == 1)	// Если 1, то элемент удаляется
			{
				if (baz == *first) // Если элемент первый, то удаляется первый элемент
				{
					if (baz->next == NULL){ *first = NULL; free(baz); baz = *first; }
					else { temp = baz->next; free(baz); baz = temp; temp->pred = NULL; *first = temp; }
				}
				else if (baz->next == NULL)	 // Если элемент последний, то удаляется последний элемент
				{
					temp = baz->pred; free(baz); baz = temp; temp->next = NULL; *end = temp;
				}
				else	// Если элемент в середине списка, то удаляется этот элемент, а соседние элементы связываются между собой полями-указателями
				{
					temp = baz->pred; tmp = baz->next; temp->next = tmp; tmp->pred = temp; free(baz); baz = tmp;
				}
			}
			else if (a == 2) { baz = baz->next; }	// Если 2, то продвигаемся по списку без удаления
			else printf("Ошибка ввода. Повторите.\n");	// При неправильном вводе выдает ошибку
		}
		else baz = baz->next;	// Если поле в списке не совпадает, то передвигаемся к следующему элементу
	}
	free(bazp);	// Очищаем память от элемента
}

void redactbaza(baza **first)	// Функция редактирования полей элементов
{
	baza *baz = *first;
	baza *bazp = (baza *)calloc(1, sizeof(baza));	// Создаем, что бы потом ввести в поле данные для поиска
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
			printf("Редактировать?\n1. Да\n2. Нет\n\n");
			printf("%3Номер тел."); printf(" | "); printf("%20Ф.И.О."); printf(" | "); printf("%14 "); printf("e-mail"); printf(" | "); printf("%7Дата"); printf(" | "); printf("%4Запись");
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
				printf("Номер телефона: %lld\n", baz->namber);
				printf("Номер телефона: "); scanf("%12lld", &baz->namber);
				system("cls");
				int a = 0, a1;
				system("cls");
				printf("Имя владельца: %s\n", baz->name);
				printf("Имя владельца: "); scanf("%s", baz->name);
				while (a == 0)	// Проверка введенных данных
				{
					a1 = 1;
					for (n = 0; baz->name[n] != '\0'; n++)
					{
						if (baz->name[n] >= 'а'&&baz->name[n] <= 'я' || baz->name[n] >= 'А'&&baz->name[n] <= 'Я')
							a = 1;
						else a1 = 0;
						a = a1;
					}
					if (a == 0)
					{
						memset(baz->name, '\0', 25);
						system("cls");
						printf("Неправильный ввод. Вводите русскими буквами.\n\n");
						printf("Имя владельца: "); scanf("%s", baz->name);
					}
				}
				baz->name[25] = '\0';
				baz->name[n] = '\0';

				system("cls");
				printf("e-mail владельца: %s\n", baz->email);
				printf("e-mail владельца: "); scanf("%s", baz->email);
				a = 0;
				while (a == 0)	// Проверка введенных данных
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
						printf("Неправильный ввод. Вводите английскими буквами.\n\n");
						printf("e-mail владельца: "); scanf("%s", baz->email);
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
			else printf("Ошибка ввода. Повторите.\n");
		}
		else baz = baz->next;
	}
	free(bazp);
}

void freebaza(baza **first, baza **end)	// Функция очистка памяти от списка
{
	baza *baz = *first, *tmp;
	while (baz)	// Цикл повторяется пока не дойдет до конца списка
	{
		tmp = baz;
		baz = baz->next;
		free(tmp);
	}
	*first = *end = NULL;	// Указатели устанавливаются на NULL, т.к. списка не существует
}

void savefile(baza **first)	// Функция сохранения списка в файл
{
	system("cls");
	char fail[128];
	printf("Введите название файла с БД\n");
	scanf("%s", fail);	// Вводим название файла
	FILE *file = fopen(fail, "wb");	// Открываем бинарный файл для редактирования
	if (file == NULL) { printf("Ошибка при открытии файла.\n"); return; }
	baza *baz = *first;
	while (baz)	// Цикл сохранения списка в файл поэлементно пока элементы в списке не закончатся
	{
		fprintf(file, "%lld\n", baz->namber);
		fprintf(file, "%s\n", baz->name);
		fprintf(file, "%s\n", baz->email);
		fprintf(file, "%s\n", baz->date);
		fprintf(file, "%d\n", baz->zapis);
		baz = baz->next;
	}
	fclose(file);	// Закрытие файла
}

int openfile(baza **first, baza **end, int N)	// Функция открытия файла
{
	char fail[128];
	baza *baz;
	printf("Введите название файла с БД\n");
	scanf("%s", fail);	// Вводим название файла
	FILE *file = fopen(fail, "rb");	// Открываем бинарный файл для чтения
	if (file == NULL) { printf("Ошибка при открытии файла.\n"); return N; }
	while (!feof(file))	// Цикл сохранения данных из файла в поля списка по элементно пока не будет достигнут конец файла
	{
		baz = (baza *)calloc(1, sizeof(baza));	// Создание нового элемента для списка
		fscanf(file, "%lld\n", &baz->namber);
		fscanf(file, "%s\n", baz->name);
		fscanf(file, "%s\n", baz->email);
		fscanf(file, "%s\n", baz->date);
		fscanf(file, "%d\n", &baz->zapis);
		if (!*first || !*end)		// Если указатели начала и конца списка равны, то новый элемент становится первым
		{
			*end = baz;
			*first = baz;
			baz->next = NULL;
			baz->pred = NULL;
		}
		else	// Иначе новый элемент добавляется в конец списка
		{
			baz->pred = *end;
			*end = baz;
			baz->next = NULL;
			baz = baz->pred;
			baz->next = *end;
		}
		if (baz->zapis>N) N = baz->zapis;
	}
	fclose(file);	// Закрываем файл
	return N;	// Возвращаем количество полей в списке
}
