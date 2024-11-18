#include <stdio.h>
#include <stdlib.h>
int Power(int n,int p){
if(p==0){
    return 1;
}
if(p==1){
    return n;
}

return n*Power(n,p-1);
}
int main()
{
   printf("%d",Power(10,3));
    return 0;
}
