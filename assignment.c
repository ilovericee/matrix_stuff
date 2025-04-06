#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS1 2
#define COLS1 3

#define ROWS2 3
#define COLS2 2

int array1[ROWS1][COLS1];
int array2[ROWS2][COLS2];


void randomValueGenerator(int a[ROWS1][COLS1],int b[ROWS2][COLS2]);
void printMat(size_t row,size_t col,int matrix[row][col]);
void matSum(int a[ROWS1][COLS1],int b[ROWS2][COLS2],int target[ROWS1][COLS2]);
void matMul(int a[ROWS1][COLS1],int b[ROWS2][COLS2],int target[ROWS1][COLS2]);
void neutralizeTarget(int target[ROWS1][COLS2]);

int main()
{
  if(!(COLS1 == ROWS2))
  {
    printf("Can't multiply...\n");return 1;
  }

  int target[ROWS1][COLS2]; // for multiplication

  srand(time(NULL));
  randomValueGenerator(array1,array2);
  neutralizeTarget(target);
    
  printf("-----------*Matrix-1*-----------\n");
  printMat(ROWS1, COLS1, array1);
  printf("-----------*Matrix-2*-----------\n");
  printMat(ROWS2, COLS2, array2);
    
  // SUM
  if(ROWS1 != ROWS2 || COLS1 != COLS2)
  {
     printf("--------------------------------------------------\n");
     printf("Matrix sizes are not the same, so we can't add them\n");
     printf("--------------------------------------------------\n");
  }
  else
  {
    neutralizeTarget(target);
    matSum(array1,array2,target);
    printMat(ROWS1,COLS2,target);
  }
  // MULTIPLICATION
  if(COLS1 == ROWS2){
  neutralizeTarget(target);
  matMul(array1,array2,target);
  printMat(ROWS1,COLS2,target);
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
      a[i][j] = rand()%100 +1;
    }
  }
  for(size_t i = 0;i<ROWS2;i++)
  {
    for(size_t j = 0;j<COLS2;j++)
    {
      b[i][j] = rand()%100 +1;
    }
  }

}

void printMat(size_t row,size_t col,int matrix[row][col])
{
  for(size_t i = 0;i<row;i++)
  {
    for(size_t j = 0;j<col;j++)
    {
      printf("%d ",matrix[i][j]);
    }
    printf("\n");
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
