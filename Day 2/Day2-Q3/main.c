#include <stdio.h>
#include <stdlib.h>

int main()
{
   for(char i = 9;i>0;i--){
    printf("*******************\n");
    for(char j = 0;j<10;j++){
        printf("%d*%d=%d\n",i,j,i*j);
    }
   }    return 0;
}
