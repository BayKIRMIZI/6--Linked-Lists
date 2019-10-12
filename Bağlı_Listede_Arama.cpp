#include<stdio.h>
#include<conio.h>
int dizi[]={9,1,3,11,72,55,91,5,13,25,32};
typedef struct Liste{
	int veri;
	struct Liste *sonra;
}L;
L *kok,*gcc;
int sirayla_arama(int aranan)
{
	gcc=kok;
	for(;gcc;gcc=gcc->sonra)
	{
		if(gcc->veri == aranan)
		{
			printf("\n%d bulundu...!!!",gcc->veri);
			return aranan;
		}
	}
	printf("\n%d bulunamadi...!!!",aranan);
}
main()
{
	int sayi;
	kok=gcc=new L;
	kok->veri=dizi[0];
	kok->sonra=NULL;
	for(int i=1;i<11;i++)
	{
		gcc->sonra=new L;
		gcc=gcc->sonra;
		gcc->veri=dizi[i];
		gcc->sonra=NULL;
	}
	gcc=kok;
	for(;gcc;gcc=gcc->sonra)printf("%d ",gcc->veri);
	printf("\nAranan sayi = ");scanf("%d",&sayi);
	sirayla_arama(sayi);
	getch();
}
