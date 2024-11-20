#define TRMNTR '\0'


int intStrlen(char str[]){
    int i = 0;
    while(str[i] != TRMNTR){
        i++;
    }
    return i;
}

void voidStrcat(char dest[],char src[],int sizeOfDest){
    int i=0,j = 0;
    while(dest[i] != TRMNTR){
        i++;
    }
    if(intStrlen(src)+intStrlen(dest)<sizeOfDest){
            while(src[j] != TRMNTR){
        dest[i] = src[j];
        i++;
        j++;
            }
            dest[i] = TRMNTR;
    }
    else{
        printf("Size of destination is smaller than source");
    }
}

int intStrcmp(char str1[],char str2[]){
  int firstLength = intStrlen(str1);
  int secondLength = intStrlen(str2);
  if(firstLength == secondLength) return 0;
  else if(firstLength < secondLength) return -1;
  else return 1;
}
void voidStringCopy(char dest[],char source[],int sizeOfDest){
    int i=0;
    if(intStrlen(source)< sizeOfDest){
      \
        while(source[i] != TRMNTR){

            dest[i]=source[i];
            i++;
        }
        dest[i]='\0';
    }
    else {
        printf("INVALID ATTEMPT");
    }


}
