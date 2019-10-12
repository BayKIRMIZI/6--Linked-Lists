#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>



typedef struct kisi
{
        char isim[50];
        struct kisi *sonra;
        /*Bu pointera sürekli bir sonraki structi gösterecek olan adres atanacak.
          Bu sayede her struct kendinden sonraki structun bellekte
        nerede oldugunu bilecek*/
        struct kisi *once;
        /*Bu pointera sürekli bir onceki structi gösterecek olan adres atanacak.
          Bu sayede her struct kendinden onceki structun bellekte
        nerede oldugunu bilecek*/
}a;



struct kisi *yeni , *ilk , *son;/*struct kisi tipinde yeni , ilk ve son isminde tanimlamalar yaptik.*/

void menu();
void dugum_ekleme();
void listele();
void silme();


int main()
{
    yeni=NULL;
    ilk=NULL;
    son=NULL;
    /*Bütün structlari NULL yaptik*/
    
    menu();/*Menu fonksiyonunu çagirdik*/
    getch();
    return 0;
}
/****************************/
/*Menu*/
void menu()
{
     system("cls");/*Ekran temizleme fonksiyonu*/
     int cevap;
     printf("\n\n\n\n\t\t1-Kayit ekle\n");
     printf("\t\t2-Kayitlari listele\n");
     printf("\t\t3-Kayit sil\n");
     printf("\t\t4-Cikis\n");
     printf("\t\tLutfen seciminizi yapiniz :");
     scanf("%d",&cevap);
     switch(cevap)
     {
                  case 1 : dugum_ekleme(); break;
                  case 2 : listele(); break;
                  case 3 : silme(); break;
                  case 4 : exit(1); break;

     }
     
}
/****************************/

/************************************************/
/*Dugum Ekleme Fonksiyonu*/
void dugum_ekleme()
{
     if(ilk==NULL)/*Dugumde eleman var mi?*/
     {
       /*Dugumde eleman yoksa ilk=NULL olacaktir.*/
        //struct kisi *yeni = ((kisi *) malloc(sizeof(kisi)));
        yeni=new a;
        /*struct kisi tipinde yeni tanimladik ve bellekten structin boyutu kadar yer aldik*/
        printf("\n\tLutfen kisinin adini giriniz : ");
        scanf("%s",&yeni->isim);/*Yeni icin bilgiler kullanicidan alindi*/
        yeni->sonra=NULL;
        /*Yeni alinan bilgilerden sonra hiç bi eleman olmadigi için NULL yapildi*/
        ilk=yeni;
        son=yeni;
        /*Dügüm için alinan ilk eleman oldugundan yeni ve son ilke esitlendi*/
     }
     else
     {
        struct kisi *yeni = ((kisi *) malloc(sizeof(kisi)));
        /*struct kisi tipinde yeni tanimladik ve bellekten structin boyutu kadar yer aldik*/
        printf("\n\tLutfen kisinin adini giriniz : ");
        scanf("%s",&yeni->isim);/*Yeni icin bilgiler kullanicidan alindi*/
        yeni->sonra=NULL;  
        /*Yeni alinan bilgilerden sonra hiç bi eleman olmadigi için NULL yapildi*/
        son->sonra=yeni;
        /*Bi önceki structun sonra adindaki göstericisi yeniye esitlendi*/
        yeni->once=son;/*Tek yönlü bagli liste olusturmadan tek farki*/
        /*Su an olusturulmus olan structun once adindaki gostericisi bir onceki structa esitlendi*/
        son=yeni; 
        /*Son adindaki struct artik yeni structi oldu.
        Bunun yapilmasindaki amac 
        yeni bir dugum ekleneceginde en son hangi structin eklendigini bilmek
        en son eklenen structun sonrasini yeni structina esitlemek 
        yeni olusturulan structun once adindaki gostericisini sona esitlemek.*/
     }
     printf("\n\tAna menuye donmek icin bir tusa basiniz...");
     getch();
     menu();

}
/**************************************************/


/***************************************/
/*Kayit listeleme*/
void listele()/*Tek yönlü bagli listeyi listeleme ile aynidir*/
{
   struct kisi *ara;
   /*struct kisi tipinde ara isminde bir tip tanimladik*/
   printf("\n\n");
   /*ara structunu ilk structa esitledik ve NULL görene kadar dügümde ilerledik*/
   for(ara=ilk;ara!=NULL;ara=ara->sonra)
   {
                  printf("\t\t->%s \n",ara->isim);
                  
   }
   printf("\n\tAna menuye donmek icin bir tusa basiniz...");
   getch();
   menu();

}
/***********************************/

/********************************/
/*Kayit silme*/
void silme()
{
     char ad[20];
     struct kisi *sil;
     printf("\n\tSilmek istediginiz adini giriniz..");
     scanf("%s",&ad);
     sil=ilk;
       while(sil)
       {                    
                if(!strcmp(ad,sil->isim))/*Aranan isim dugumde bulunursa*/
                break;
                sil=sil->sonra;
       }             
     if(sil==NULL)
     printf("\tBulunamadi.\n");
     else if(sil==ilk)
     {
                 if(ilk->sonra == NULL){
                 	ilk=NULL;
				 }
				 else{
				 	ilk->sonra->once=NULL;
              	 	ilk=ilk->sonra;
				 }
				 
                 free(sil);
                 printf("\tKayit silindi..");
     }
     else if(sil==son)
     {
                 son=sil->once;
                 sil->once->sonra=NULL;
                 free(sil);
                  printf("\tKayit silindi..");
                  
     }
     else 
     {
                sil->once->sonra=sil->sonra;
                sil->sonra->once=sil->once;
                free(sil);
                 printf("\tKayit silindi..");
     }
     printf("\n\tAna menuye donmek icin bir tusa basiniz...");
     getch();
     menu();
}
