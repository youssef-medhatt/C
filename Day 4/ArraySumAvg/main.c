#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define COL 4

int main()
{
    int inputFlag = 0;
    int arr[ROW][COL]={0};
    for(int i = 0;i<ROW;i++){
        for(int j = 0;j<COL;j++){
                inputFlag = 0;
            while(inputFlag != 1){
            printf("Enter element [%d][%d]: ",i,j);
            fflush(stdin);
            inputFlag = scanf("%d",&arr[i][j]);
            }
        }
    }


    for(int i = 0;i<ROW;i++){
            int sumOfRow;
        for(int j = 0;j<COL;j++){
            sumOfRow+= arr[i][j];
        }
        printf("Sum of Row %d = %d\n",i,sumOfRow);
    }
     for(int j = 0;j<COL;j++){
            float avgOfCol;
        for(int i = 0;i<ROW;i++){
            avgOfCol+= arr[i][j];
        }
        printf("Average of Col %d = %f\n",j,(float)avgOfCol/ROW);
    }
    return 0;
}
