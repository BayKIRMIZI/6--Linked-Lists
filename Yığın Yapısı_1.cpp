#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define YBoyut 20
typedef struct YIGIN{
        int data;
        struct YIGIN *next;
        }ygn;
ygn *ilk=NULL,*gcc,*add;
int liste_buyuklugu=0;
void Yigina_Ekle(int sayi)
{
	if(liste_buyuklugu==YBoyut)
	{
		printf("Yigin dolu");
	}
	else
    {
	   add=new ygn;
       if(ilk==NULL)
       {
          add->data=sayi;
          add->next=NULL;
          ilk=add;
       }
       else
       {
          add->data=sayi;
	      add->next=ilk;
          ilk=add;
       }
    }
}
void Listeleme()
{ 
    ygn *gecici=ilk;
    while(gecici!=NULL)
    {
        printf("%d \n",gecici->data);
 		gecici=gecici->next;
    }
    if(gecici == ilk)printf("Liste Bos\n");
    printf("\n");
}
void Yigindan_Cikar()
{
	gcc=ilk;
	ilk=ilk->next;
	delete(gcc);
}
int kontrol(int eleman){
	gcc=ilk;
	while(gcc){
		if(gcc->data == eleman) return 1;
		else gcc=gcc->next;
	}
	printf("Boyle Bir Sayi Yok\n\n");
	return 0;
}
int Yigindan_Istenileni_Cikar(int cikacak_eleman)
{
	int array[YBoyut],i=0;
	while(kontrol(cikacak_eleman) == 1 && ilk!=NULL)
    {
		if(ilk->data==cikacak_eleman)
        {
			Yigindan_Cikar();
		    break;
	     }
		else 
        {
			array[i]=ilk->data;
			i++;
			Yigindan_Cikar();
		}	
	}	
	for(i=i-1;i>=0;i--)
    {
		Yigina_Ekle(array[i]);
	}
}
main()
{
      int sayi,cikacak_sayi; 
      while (11)
      {
         int secim;
         printf("1-ekleme \n2-listeleme\n3-Cikarma\n4-Cikis\nSecim : ");
         scanf("%d",&secim); printf("\n");
         switch (secim)
         {
             case 1: 
			  			printf("sayi gir : ");
                     	scanf("%d",&sayi);printf("\n");
                     	liste_buyuklugu++;
                       	Yigina_Ekle(sayi);
                       	break;
             case 2: 
                    	Listeleme();
						break;
			 case 3:
			 			printf("Hangi sayiyi cikarmak istiyorsunuz : ");
			 			scanf("%d",&cikacak_sayi);printf("\n");
			 			Yigindan_Istenileni_Cikar(cikacak_sayi);
			 			break;
			 case 4:	
			 			exit(0);
			 default:
			 			printf("Hatali Tuslama!!!\n\n");
         }
      }
      getch();
      return 0;
}
