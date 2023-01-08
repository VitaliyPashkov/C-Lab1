#include <cstddef>
#include <stdio.h>
#include <string.h>
char* findChar(char* s, int c)
{
	size_t len = 0; // стартовый индекс
	char* rest_of_string = NULL; // указатель на оставшуюся часть строки (его нужно вернуть)
	// проходим до конца строки (пока не встретим символ 0)
	while (s[len] != '\0')
	{
		// при этом если очередной символ оказался равен искомому с,
		if (s[len] == c) {
			rest_of_string = s + len; // то запоминаем указатель на него
			break; // и выходим из цикла
		}
		len++;
	}
	// возвращаем присвоенный указатель
	return rest_of_string;
}

int main()
{
	// тестовая строка
	char s[] = "www.some_address.and_something_else.com";
	// проверяем стандартную функцию (ищем первое вхождеие символа ".")
	char* standard_result = strchr(s, '.');
	// проверяем свою версию стандартной функции
	char* my_result = findChar(s, '.');
	// выводим на экран строку,
	// затем результат стандартной функции
	// и затем результат своей версии
	printf("Initial string: %s\nStandard: %s\nMy version: %s\n",
		s, standard_result, my_result);
	return 0;
}
