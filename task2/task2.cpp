#include <iostream>
#include <iomanip>


int fact(int n) //вспомогательная функция для вычисления факториала
{
	int result = 1;
	for (int i = 2; i <= n; i++)
		result *= i;
	return result;
}

void initializeArray(int** arr, size_t n) //функция инициализации массива по варианту (7)
{
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j) {
			*(*(arr + i) + j) = fact(i) + fact(j); // эквивалентно: arr[i][j] = i! + j!
		}
		
	}
}

int* makeArray1D(int** arr2D, size_t size2D) 
{
	int* arr1D = new int[size2D * (size2D - 1) / 2]; // выделяем память под выходной массив

	for (size_t i = 1; i < size2D; i += 2)
	{
		for (size_t j = 0; j < size2D; ++j)
		{
			// заполняем массив ("j + size2D * (i - 1) / 2" - формула для подсчета кол-ва нечетных строк)
			*(arr1D + j + size2D * (i - 1) / 2) = *(*(arr2D + i) + j); 
		}
	}
	return arr1D; // возвращаем указатель на выделенную память под 1-мерный массив
}

void printArray1D(int* arr, size_t size) // функция печати одномерного массива
{
	std::cout << "[";
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\b]" << std::endl;
}

void printArray2D(int** arr, size_t n) // функция печати двумерного массива
{
	std::cout << "[";

	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
			std::cout << std::setw(8) << arr[i][j]; // 8 символов для каждого элемента

		if (i + 1 != n)
			std::cout << std::endl << " ";
		else
			std::cout << std::setw(8) << "]\n\n" << std::setw(30) << "=>\n\n";

	}


}

void freeArray1D(int* arr) {
	delete[] arr; // очистка памяти - удаление массива
}

void freeArray2D(int** arr, size_t N) {
	for (int i = 0; i < N; ++i)
		delete[] arr[i];
	delete[] arr;
}


int main()
{
	const size_t N = 5;
	int** arr2D = new int* [N]; // пять строк в массиве
	for (size_t i = 0; i < N; ++i)
		*(arr2D + i) = new int[N]; // и пять столбцов
	// заполнение массива// выделяем память под входной массив
	initializeArray(arr2D, N); // инициализируем массив (по варианту)
	int* arr1D = makeArray1D(arr2D, N); // конвертируем 2-мерный массив в 1-мерный (по варианту)
	printArray2D(arr2D, N); // выводим на консоль 2-мерный массив-результат
	printArray1D(arr1D, N * (N - 1) / 2); // выводим на консоль массив

	freeArray1D(arr1D); // освобождаем память 1-мерного массива
	freeArray2D(arr2D, N); // освобождаем память 2-мерного массива
	return 0;
}
