#include <stdio.h>
#include <iostream>

double processArray(double arr[], size_t n, double exitArr[])
{
	printf("[");
	for (size_t i = 0; i < n; ++i) // заполнение массива случ. числами [20 до 100]
	{
		arr[i] = (double)(rand() % 80) + 20.0;
		printf("%2.0f ", arr[i]); //печать для наглядности

	}
	printf("\b]\n");
	double min = arr[0];
	double indexOfMin = 0;
	for (size_t i = 0; i < n; ++i) // подсчет минимального значения среди элементов
	{
		if (min > arr[i]) {
			min = arr[i];
			indexOfMin = i;
		}
	}

	for (size_t i = 0; i < n; ++i) // формирование выходного массива
	{
		if (i > indexOfMin)
			exitArr[i] = min;
		else exitArr[i] = arr[i];
	}
	for (size_t i = 0; i < n; ++i) //  преобразование первоначального массива (по заданию)
	{
		arr[i] -= min;
		if (arr[i] == 0)
			indexOfMin = i;
	}
	return min; // возвращаем минимальное значение
}

void printArray(double* arr, size_t n) //вывод массива на экран
{
	printf("[");

	for (size_t i = 0; i < n; ++i)
	{
		printf("%2.0f ", arr[i]);
	}
	printf("\b]\n");
}

int main()
{
	// размер массива равен 15 (по заданию)
	const size_t N = 15;
	double a[N] = { 0.0 }; // создаем массивы и инициализируем нулями
	double b[N] = { 0.0 }; 
	// инициализация генератора случайных чисел
	srand(0);
	// подсчет минимального значения в массиве а, изменение массива b
	double result = processArray(a, N, b);
	// вывод массивов на экран
	printf("min value: %2.0f\n", result);
	printArray(a, N); 
	printArray(b, N);

	return 0;
}

