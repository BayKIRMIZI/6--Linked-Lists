#include<stdio.h>
#include<conio.h>
int dizi1[]={9,1,3,11,72,55,91,5,13,25,32};
int dizi2[]={11,55,93,27,35,7,1,8,17,63,9};
typedef struct Liste{
	int veri;
	struct Liste *sonra;
}L;

L *kok1,*gcc1,*kok2,*gcc2;

void Ortak_Bul(L *ilk1,L*ilk2)
{
	gcc1=ilk1;
	gcc2=ilk2;
	if(gcc1 != NULL)
	{
		if(gcc2 != NULL)
		{
			if(gcc1->veri == gcc2->veri)
			{
				printf("%d ortak eleman... \n",gcc2->veri);
			}
			if(gcc2->sonra != NULL)
				Ortak_Bul(gcc1,gcc2->sonra);
		}
		if(gcc1->sonra != NULL)
			Ortak_Bul(gcc1->sonra,kok2);
		else return;
	}
	return;
}

main()
{
	int sayi;
	kok1=gcc1=new L;	kok1->veri=dizi1[0];	kok1->sonra=NULL;
	for(int i=1;i<11;i++)
	{
		gcc1->sonra=new L;
		gcc1=gcc1->sonra;
		gcc1->veri=dizi1[i];
	}
	gcc1->sonra=NULL;
	gcc1=kok1;
	
	kok2=gcc2=new L;	kok2->veri=dizi2[0];	kok2->sonra=NULL;
	for(int j=1;j<11;j++)
	{
		gcc2->sonra=new L;
		gcc2=gcc2->sonra;
		gcc2->veri=dizi2[j];
	}
	gcc2->sonra=NULL;
	gcc2=kok2;
	
	for(;gcc1;gcc1=gcc1->sonra)printf("%d ",gcc1->veri);
	printf("\n");
	for(;gcc2;gcc2=gcc2->sonra)printf("%d ",gcc2->veri);
	printf("\n");
	
	Ortak_Bul(kok1,kok2);
	
	getch();
}
