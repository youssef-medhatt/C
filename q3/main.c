#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define UP 72
#define ENTER 13
#define DOWN 80
void New(){
printf("\n\n\n\n\n\n\n\n");
printf("1.NEW* \n");
printf("2.DISPLAY \n");
printf("3.EXIT \n");
}
void Display(){
printf("\n\n\n\n\n\n\n\n");

printf("1.NEW \n");
printf("2.DISPLAY* \n");
printf("3.EXIT\n");
}
void Exit(){
printf("\n\n\n\n\n\n\n\n");

printf("1.NEW \n");
printf("2.DISPLAY \n");
printf("3.EXIT* \n");
}
void NewPressed(){
printf("\n\n\n\n\n\n\n\n");
printf("1.NEW PRESSED \n");

}
void DisplayPressed(){
printf("\n\n\n\n\n\n\n\n");


printf("2.DISPLAY PRESSED\n");

}
void ExitPressed(){
printf("\n\n\n\n\n\n\n\n");


printf("3.EXIT PRESSED \n");
}
int main()
{



int Option = 1;
char ch = 0;
        printf("Choose an item: \n");
        printf("1.NEW \n");
        printf("2.DISPLAY \n");
        printf("3.EXIT \n");
    while(ch != 27){
        ch = getch();
            if(ch == -32){
                ch = getch();
                        }
                        if(ch == UP){
                                if(Option == 1){
                                    Option = 3;
                                }
                                else{
                            Option--;
                                }
                        }
                        else if(ch == DOWN){
                            if(Option == 3){
                                Option = 1;
                            }
                            else{
                                Option++;
                            }
                        }
                        else if(ch == ENTER){
                                    switch(Option){
                                        case 1:
                                            NewPressed();
                                            break;
                                        case 2:
                                            DisplayPressed();
                                            break;
                                        case 3:
                                            ExitPressed();
                                            break;
                                        default:
                                            printf("INVALID!");

        }
                        break;
                        }
                        else{
                            continue;
                        }
        switch(Option){
    case 1:
        New();
        break;
    case 2:
        Display();
        break;
    case 3:
        Exit();
        break;
    default:
        printf("INVALID!");

        }

    }



    return 0;
}
