#include<stdio.h>
#include<math.h>
#include<locale.h>

int main()
{
  int N;
  int work = 1;
  setlocale(LC_ALL, "rus");
  while (work) {
	  printf("  for exit enter 0\n");
	  int flag = 0;
	  printf("ввeдите число: \n");

	  do {
		  if (flag) printf("error!!!\n");
		  printf("Input positiv naber: ");
		  scanf_s("%d", &N);
		  if (N == 0) {
			  work = 0;
			  break;
		  }
		  /*if (flag) {
			  printf("It was first input\n");
			  flag = ;
			  continue;
		  }
		  flag = 1;
		  */
		flag = (N <= 0);
	  } while (flag);

	  int rem, isr = 0;
	  //reshenie
	  do {
		  rem = N % 10;
		  isr = isr * 10 + rem;
		  N = N / 10;
	  }while (N > 0);
	  printf("result: %d", isr);
  }
  return 0;
}