#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main()
{
  setlocale(LC_ALL, "Rus");

  int N = 0, i = 0, mant = 0;
  float x = 0.0f, drob = 0.0f, min = 0.0f, max = 0.0f;
  float* mas;
  int* mantissa;
  long double sum = 0.0;


  printf("Введите кол-во элементов:\t");
  scanf_s("  \t%d", &N);

  if (N <= 0)
  {
    printf("ERROR");
    return 0;
  }
  
  printf("Введите минимальный элемент:\t");		 
  scanf_s("  \t%f", &min);							            
                                                
  printf("Введите максимальный элемент:\t");		
  scanf_s("  \t%f", &max);


  if (min >= max)
  {
    printf("ERROR");
    return 0;
  }


  mas = (float*)malloc(N * sizeof(float));
  mantissa = (int*)malloc(N * sizeof(int));

  for (i = 0; i < N; i++)
  {

    x = (((float)rand()) / RAND_MAX) * (max - min) + min;			
    mas[i] = x;                                             

    drob = x - (int)x;				      

    drob = drob * 1000000;
    mant = (int)drob;              

    mantissa[i] = mant;

  }

  for (i = 0; i < N; i++)
  {
    if (mantissa[i] < N)
    {
      sum -= mas[mantissa[i]];
      mas[mantissa[i]] = 0;
    }
  }

  for (i = 0; i < N; i++)
  {
    sum += mas[i];
  }

  printf("Полученная сумма:\t%f", sum);

  free(mas);
  free(mantissa);

  return 0;
}
