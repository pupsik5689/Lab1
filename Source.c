#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "Rus");

	int N = 0, i = 0, min = 0, max = 0, mant = 0;
	float x = 0.0, sum = 0.0, drob = 0;
	float* mas;

	printf("������� ���-�� ���������:\t");			//
	scanf_s("%d", &N);								//
													//	
	printf("������� ����������� �������:\t");		//	���� �������� �������������
	scanf_s("%d", &min);							//
													//
	printf("������� ������������ �������:\t");		//
	scanf_s("%d", &max);



	if (min > max)				//
	{							//	�������� �� 
		printf("ERROR");		//	���������� ��������
		return 0;				//
	}							//
		



	mas = (float*)malloc(N * sizeof(float));
	
	for (i = 0; i < N; i++)
	{
		x = rand();									//	�������� ���������� 
		x = (x / RAND_MAX) * (max - min) + min;		//	������������ ����� 	
		mas[i] = x;                                 //	� �������� ���������

		
		
		drob = x - (int)x;				//  ������� ����� 

		mant = (int)(drob * 1000000);	//	��������
		

		if (mant == i)					//	��������� �������� � ������� �����
			sum -= x;					//  ��� ���������� ����� ���������� �� ����� �����
		else							//	�����
			sum += x;					//	������������ � ����� �����


		
	}


	printf("���������� �����:\t%f", sum);

	free(mas);

	return 0;
}