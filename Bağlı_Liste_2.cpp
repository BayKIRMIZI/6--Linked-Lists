/*
Baðlý liste kullanýlarak öðrencinin numarasýný adýný ve soyadýný struct yapýsýna ekleyen silen ve listeleyen program ...
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Liste{
int numara;
char ad[15];
char soyad[15];
struct Liste *sonraki;
}BListe;
BListe *ilk=NULL,*son=NULL;



void Ekle(BListe *bilgi){
if(ilk==NULL)
    {
        ilk=bilgi;
        son=ilk;
        son->sonraki=NULL;
    }
    else
    {
        son->sonraki=bilgi;
        son=bilgi;
        son->sonraki=NULL;
    }
}
void Listele()
{
    BListe *gecici;
    //gecici=new BListe;
    gecici=ilk;
    while(gecici!=NULL && ilk!=NULL)
    {
        printf("%d  %s  %s\n",gecici->numara,gecici->ad,gecici->soyad);
        gecici=gecici->sonraki;
    }
}

void Silme(int num)
{
    BListe *gecici,*onceki;
    gecici=ilk;
    while(gecici)
    {
        if(gecici->numara==num)
            break;
        onceki=gecici;
        gecici=gecici->sonraki;
        if(gecici==ilk)
            break;
    }
    if(gecici!=NULL)
    {
        if(gecici==ilk)
        {
            if(gecici==son)
            {
                ilk=NULL;
                son=NULL;
            }
            else
            {
                ilk=ilk->sonraki;
            }
        }
        else
        {
            onceki->sonraki=gecici->sonraki;
            if(gecici==son)
               son=onceki;
        }
        printf("%d silindi.\n",gecici->numara);
        free(gecici);
    }
}



int main(){
BListe *Bilgi;
char secim;
while (1==1)
{
      
    printf("\nEkleme : E\nListele : L\nSil : S\nCikis : C\n");
    secim=getch();
    switch(secim)
    {
                 
        case 'e':
        {
             system("cls");
            Bilgi=new BListe;
            printf("numara gir :");
            scanf("%d",&Bilgi->numara);
            printf("ad giriniz :");
            scanf("%s",&Bilgi->ad);
            printf("soyad giriniz :");
            scanf("%s",&Bilgi->soyad);
            Ekle(Bilgi);
            break;
        }
        case 'l':
        {
             system("cls");
            Listele();
            break;
        }
        case 'c':
        {
            return 0;
            break;
        }
        case 's':
        {
             system("cls");
            printf("silinecek sayiyi gir.");
            int a;
            scanf("%d",&a);
            Silme(a);
            break;
        }
        default:
        {
            printf("Hatali Giris\n");
            break;
        }
    }
}
return 0;
}
