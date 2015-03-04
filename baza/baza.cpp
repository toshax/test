// baza.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>		// Подключаем библиотеки
#include <locale.h>
#include <stdlib.h>
#include "fbaza.cpp"
#include "fpoisk.cpp"

int main(void)		// Главная функция
{
	baza *first1 = NULL, *first = NULL;		// Создаем указатели на первый элемент
	baza *end1 = NULL, *end = NULL;		// Создаем указатели на последний элемент
	baza *firsttmp;
	baza *endtmp;
	setlocale(LC_ALL, "");		// Подключаем русскую кодировку
	int key, key0, key1 = 0, key2, key3, key40, key41, key5 = 2;    // Переменные играют роль ключей
	int N = 0;		// Переменную N будем использовать для подсчета записей
	while (key1 == 0)		// Цикл для постоянного вывода меню на экран
	{
		system("cls");		// Системная команда для очистки экрана консоля
		printf("1. Создать БД\n");
		printf("2. Открыть БД\n");
		printf("3. Выйти из программы\n");
		scanf("%d", &key);		// Вводим в ключ наш выбор
		system("cls");
		switch (key)		// Оператор выбора
		{
		case 1:	N = writebaza(&first, &end, N); //Входим в функцию для записи списка
			key0 = 1;
			break;	// Оператор выхода. Здесь выход из оператора выбора
		case 2:	key0 = 1;
			N = openfile(&first, &end, N); // Входим в функцию для открытия файла
			break;
		case 3: key1 = 1;		// Происходит завершение программы
		}
		while (key0 == 1)		// Цикл для главного меню
		{
			system("cls");
			printf("1. Вывести БД на экран\n");
			printf("2. Отсортировать\n");
			printf("3. Редактировать БД\n");
			if (key5 == 2) printf("4. Фильтровать\n");  // Отображает в зависимости от
			else if (key5 == 1) printf("4. Вернутся к исходному списку\n");	  // программы
			printf("5. Поиск\n");
			printf("6. Сохранить в файл\n");
			printf("7. Выйти\n");
			scanf("%d", &key2);
			switch (key2)		// Оператор выбора для главного меню
			{
			case 1: printscr(&first); system("pause"); break; // Отображение списка. Применяется системная команда для удержания информации на экране
			case 2: 	system("cls");
				printf("1. Сортировать по номеру телефона\n");
				printf("2. Сортировать по имени владельца\n");
				printf("3. Сортировать по e-mail\n");
				printf("4. Сортировать по дате записи\n");
				printf("5. Сортировать по номеру записи\n");
				scanf("%d", &key40); system("cls");
				printf("1. Сортировать по возрастанию\n");
				printf("2. Сортировать по убыванию\n");
				scanf("%d", &key41);
				sortbaza(key40, key41, &first, &end);
				break;
			case 3: system("cls");
				printf("1. Добавить запись\n");
				printf("2. Удалить запись\n");
				printf("3. Редактировать запись\n");
				printf("4. Отмена\n");
				scanf("%d", &key3);
				switch (key3)     // Оператор выбора для редактирования
				{
				case 1: N = writebaza(&first, &end, N); break;
					// Входим в функцию для записи списка
				case 2: deletebaza(&first, &end); break;
					// Входим в фунцию для удаления записи							
				case 3: redactbaza(&first); break;
					// Входим в функцию для редактирования записи
				case 4: break;	// Отмена
				}
				break;
			case 4: if (key5 == 2) {
						first1 = first; end1 = end;
						key5 = filtrbaza(&first, &end, &firsttmp, &endtmp);
			}	// Вход в функцию фильтрации, предварительно сохранив начало и конец списка в другие указатели
					else if (key5 == 1) { first = first1; end = end1;  freebaza(&firsttmp, &endtmp); key5 = 2; } break;	// Возвращает первоначальный список. Отфильтрованный список удаляется
			case 5: poisk(&first); break;	// Вход в функцию поиска
			case 6: savefile(&first); break;	// Сохраняем список в файл
			case 7: freebaza(&first, &end); key0 = 0; break;
				// Выходим из главного меню, предварительно удалив список из памяти
			}
		}
	}
	return 0;	// Функция ничего не возвращает
}

