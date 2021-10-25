#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "Rus");

	int N = 0, i = 0, min = 0, max = 0, mant = 0;
	float x = 0.0, sum = 0.0, drob = 0;
	float* mas;

	printf("Введите кол-во элементов:\t");			//
	scanf_s("%d", &N);								//
													//	
	printf("Введите минимальный элемент:\t");		//	Ввод значений пользователем
	scanf_s("%d", &min);							//
													//
	printf("Введите максимальный элемент:\t");		//
	scanf_s("%d", &max);



	if (min > max)				//
	{							//	проверка на 
		printf("ERROR");		//	допустимые значения
		return 0;				//
	}							//
		



	mas = (float*)malloc(N * sizeof(float));
	
	for (i = 0; i < N; i++)
	{
		x = rand();									//	создание случайного 
		x = (x / RAND_MAX) * (max - min) + min;		//	вещесвенного числа 	
		mas[i] = x;                                 //	в заданном диапазоне

		
		
		drob = x - (int)x;				//  дробная часть 

		mant = (int)(drob * 1000000);	//	мантисса
		

		if (mant == i)					//	сравнение мантиссы и дробной части
			sum -= x;					//  при совпадении число вычетается из общей суммы
		else							//	иначе
			sum += x;					//	прибавляется к общей сумме


		
	}


	printf("Полученная сумма:\t%f", sum);

	free(mas);

	return 0;
}