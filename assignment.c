#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS1 2
#define COLS1 3

#define ROWS2 3
#define COLS2 2

#if (ROWS1 == COLS2)
int target[ROWS1][COLS2]; // for multiplication
#else
printf("Can't multiply or add up quitting...\n");return 1;
#endif 

int array1[ROWS1][COLS1];
int array2[ROWS2][COLS2];



int did_print = 0;

void randomValueGenerator(int a[ROWS1][COLS1],int b[ROWS2][COLS2]);
void printMat(int a[ROWS1][COLS1],int b[ROWS2][COLS2],int target[ROWS1][COLS2]);
void matSum(int a[ROWS1][COLS1],int b[ROWS2][COLS2],int target[ROWS1][COLS2]);
void matMul(int a[ROWS1][COLS1],int b[ROWS2][COLS2],int target[ROWS1][COLS2]);
void neutralizeTarget(int target[ROWS1][COLS2]);

int main()
{
  srand(time(NULL));
  randomValueGenerator(array1,array2);
  neutralizeTarget(target);
  printMat(array1,array2,target);

    
  // SUM
  if(ROWS1 != ROWS2 || COLS1 != COLS2)
  {
    printf("--------------------------------------------------\nMatrix sizes are not the same so we can't add them\n--------------------------------------------------\n");
  }
  else
  {
    matSum(array1,array2,target);
    printMat(array1,array2,target);
  }
  // MULTIPLICATION
  if(ROWS1 == COLS2){
  neutralizeTarget(target);
  matMul(array1,array2,target);
  printMat(array1,array2,target);
  }
  else
  {
    printf("Matrix-1 row and Matrix-2 colon num isn't equal therefore we can not multiply\n");
  }
  return 0;
}

void randomValueGenerator(int a[ROWS1][COLS1],int b[ROWS2][COLS2])
{
  for(size_t i = 0;i<ROWS1;i++)
  {
    for(size_t j = 0;j<COLS1;j++)
    {
      a[i][j] = rand()%10 +1;
    }
  }
  for(size_t i = 0;i<ROWS2;i++)
  {
    for(size_t j = 0;j<COLS2;j++)
    {
      b[i][j] = rand()%10 +1;
    }
  }

}

void printMat(int a[ROWS1][COLS1],int b[ROWS2][COLS2],int target[ROWS1][COLS2])
{
  if(did_print == 0){
  printf("-----------*Matrix-1*-----------\n");
  for(size_t i = 0;i<ROWS1;i++)
  {
    for(size_t j = 0;j<COLS1;j++)
    {
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
  printf("-----------*Matrix-2*-----------\n");
  for(size_t i = 0;i<ROWS2;i++)
  {
    for(size_t j = 0;j<COLS2;j++)
    {
      printf("%d ",b[i][j]);
    }
    printf("\n");
  }
    did_print = 1;
  }
  
  if(target[0][0] != 0)
  {
     for(size_t i = 0;i<ROWS1;i++)
  {
    for(size_t j = 0;j<COLS2;j++)
    {
      printf("%d ",target[i][j]);
    }
    printf("\n");
    }
  }
}

void neutralizeTarget(int target[ROWS1][COLS2])
{
  for(size_t i = 0;i<ROWS1;i++)
  {
    for(size_t j = 0;j<COLS2;j++)
    {
       target[i][j] = 0; 
    }
  }

}

void matSum(int a[ROWS1][COLS1],int b[ROWS2][COLS2],int target[ROWS1][COLS2])
{
  printf("-----------*Matrix-Addition*-----------\n");
  for(size_t i = 0;i<ROWS1;i++)
  {
    for(size_t j = 0;j<COLS1;j++)
    {
       target[i][j] =  a[i][j] + b[i][j]; 
    }
  }
}

void matMul(int a[ROWS1][COLS1],int b[ROWS2][COLS2],int target[ROWS1][COLS2])
{
  printf("-----------*Matrix-Multiplication*-----------\n");
  for(size_t i = 0;i<ROWS1;i++)
  {
    for(size_t j = 0;j<COLS2;j++)
    {
      for(size_t k = 0;k<COLS1;k++)
      {
          target[i][j] += a[i][k]*b[k][j];
      }
    }
  }
}
