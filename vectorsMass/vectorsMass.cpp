#include <iostream>
#include <vector>
#include <ctime> 

//Вектор в C++ — это замена стандартному динамическому массиву,
//память для которого выделяется вручную, с помощью оператора new.
//Разработчики языка рекомендуют в использовать именно vector вместо 
//ручного выделения памяти для массива. Это позволяет избежать утечек памяти и облегчает работу программисту.

void inArray(int array[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		std::cin >> array[i];
		if (std::cin.fail())
		{
			//std::cerr << "Некорректный ввод!" << std::endl;
			throw std::exception("Некорректный ввод!");
		}
	}
}
void outArray(int array[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

bool isOrderedArray(int array[], const int SIZE)
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		if (array[i] >= array[i + 1])
		{
			return false;
		}
	}
	return true;
}

void permutationArray(int array[], const int SIZE)
{
	for (int i = 0; i < SIZE - 1; i += 2)
	{
		std::swap(array[i], array[i + 1]);
	}
}


void random(int array[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		array[i] = rand() % 100 - 50;
	}
}

//ИНДИВИДУАЛЬНОЕ
// 13 Вариант
//В массиве целых чисел определить наибольшую длину
//монотонного убывающего фрагмента последовательности 
//(то есть такого фрагмента, где каждый элемент меньше предыдущего)

int isMonotoneDecreasing(int array[], const int SIZE)
{
	int res = 0, max = 0;

	for (int i = 0; i < SIZE ; i++)
	{
		if (array[i] > array[i + 1])
		{
			res++;
			if (res > max)
			{
				max = res;
				res = 0;
			}
		}
	}
	
	if (res > max)
	{
		max = res;
	}

	return max;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	//установка генератора случайных чисел; функция time(0) объявлена в <ctime>
	srand(time(0));

	std::cout << "Введите кол-во элементов для динамического массива: " << std::endl;
	int size_array;
	std::cin >> size_array;
	if (std::cin.fail())
	{
		throw std::exception("Некорректный ввод!");
	}

	//динамический
	int* mas_array = new int[size_array];

	//статический
	const int SIZE = 10;
	int array[SIZE] = { 3, 2, 1, -3, 6, 1, -9, 5, 6, 6 };


	try
	{
		//std::cout << "Введите элементы динамического массива: " << std::endl;
		//inArray(mas_array, size_array);

		random(mas_array, size_array);
		std::cout << "Вывод массива: " << std::endl;
		outArray(mas_array, size_array);

		std::cout << "Массив идет по возрастанию?" << std::endl;
		std::cout << isOrderedArray(mas_array, size_array) << std::endl;

		std::cout << "Перестановка соседних элементов массива: " << std::endl;
		permutationArray(mas_array, size_array);
		outArray(mas_array, size_array);

		std::cout << "Hаибольшую длинa монотонного убывающего фрагмента последовательности = ";
		std::cout << isMonotoneDecreasing(mas_array, size_array) << std::endl;


		delete[] mas_array;


		std::cout << "======================================================================================" << std::endl;


		std::cout << "Вывод статического массива: " << std::endl;
		outArray(array, SIZE);

		std::cout << "Массив идет по возрастанию?" << std::endl;
		std::cout << isOrderedArray(array, SIZE) << std::endl;

		std::cout << "Hаибольшая длинa монотонного убывающего фрагмента последовательности = ";
		std::cout << isMonotoneDecreasing(array, SIZE) << std::endl;

		std::cout << "Перестановка соседних элементов массива: " << std::endl;
		permutationArray(array, SIZE);
		outArray(array, SIZE);


	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

