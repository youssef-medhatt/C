#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Arr[5]={1,4,2,5,-2};
    int max,min;
    max =0;
    min=0;
    for(int i = 0;i<5;i++){
        if(max<Arr[i]){
            max = Arr[i];
        }
        if(min>Arr[i]){
            min = Arr[i];
        }
    }
    printf("max=%d, min=%d",max,min);
    return 0;
}
