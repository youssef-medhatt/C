
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int q2()
{
  int N;
  scanf("%d",&N);

  int x = 0, y=1;

  for(int i = 0;i<N*N;i++){
    if(i % N != 0){
       if(x != 0) x--;
       else x = N-1;
       if(y != 0) y--;
       else y = N-1;



    }
    else{
        if(x=N-1) x=0;
        else x++;


    }
  }

    return 0;
}
