#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


typedef struct yigin{
    char ad;
    struct yigin * n;
}Stack;

void push(Stack**head, char deger);
char pop(Stack**head);



int main (int argc, const char * argv[]) {


    char kelime[11];
    int i=0;
    int l = 0; 
    Stack*ilk = NULL;
    printf("Lutfen bir kelime giriniz: ");
    scanf("%s", kelime);
    l = strlen(kelime);
    while(kelime[i]!='\0'){
        push(&ilk, kelime[i]);
        i++;
        }

   
    int j=0;
    i=0;
    for (j=0; j<l; j++) {
    if (pop(&ilk) == kelime[j])
    
        i++;
    //}
    }


    if(i==l) printf("palindrom kelime");
    else printf("palindrom kelime degil");

    getch();
    return 0;
}

void push(Stack**ilk,char deger){

    Stack *gecici = (Stack*)malloc(sizeof(Stack));
   gecici->ad = deger;
    gecici->n = *ilk;
    *ilk = gecici; 
}

char pop(Stack**ilk){

    Stack* gecici;

    char deg;
   gecici = *ilk;
    deg = gecici->ad;
    *ilk= (*ilk)->n;

    free(gecici);
    return deg;
}
