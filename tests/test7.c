/* FILENAME : TASK43.C */
/* Eugene V. Ogurtsov */
/* Last update : 4.03.2004 */
/* Вывести N-ое число Каталана (быстро). */
/* Написать программу, которая вводит славиатуры натуральное число N
 * (N < 20) и выводит N-ое число Каталана, которое можное определить
 * при помощи рекурсивной формулы:
 * b_0 = 1; b_n = sum_{k=0}^n b_k * b_{n-1-k}. */

#include <stdio.h>

long Data[30];

/* Рекурсивное вычисление чисел Каталана с использованием массива */
long Cat( int n )
{
  int k;
  long s = 0;

  if (n < 2)
    return 1;

  for (k = 0; k < n; k ++)
    s += Data[k] * Data[n - 1 - k];

  return s;
} /* End of 'Cat' function */

int main()
{
  int N, i;

  printf("Введите натуральное число, не больше 19 > ");
  scanf("%i", &N);

  for (i = 0; i < N; i ++)
    Data[i] = Cat(i);

  printf("%i-ое число Каталана равно %li.\n", N, Cat(N));
} /* End of 'main' function */