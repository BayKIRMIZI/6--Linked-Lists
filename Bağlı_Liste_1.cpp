#include<stdio.h>
#include<conio.h>
int t1=0,t2=0;
typedef struct listeleme{
        int sayi;
        struct listeleme *sonraki;
        }list;
int ciftler(int s)
{
    t2+=s;
}
int tekler(int s)
{
    t1+=s;
}
void goster(list *g,int kontrol,int n){
	list *gcc;
	gcc=g;
	if(kontrol == 0){
		for(int i=0;i<n;i++)
		{
			for(int j=n-i;j>1;gcc=gcc->sonraki,j--);
			printf("%d\t",gcc->sayi);
			gcc=g;
		}
	}
	else{
		for(;gcc;gcc=gcc->sonraki)printf("%d\t",gcc->sayi);
	}
}
int fonk(list *gecici)
{
    int n;
    int s;
    list *baslangic;
    printf("Bagli liste kac elemandan olusacak? ");
	scanf("%d",&n);
    gecici=baslangic=new list;
    printf("1. sayiyi giriniz : ");
	scanf("%d",&s);
    gecici->sayi=s;
    gecici->sonraki=NULL;
    if(s%2==0)ciftler(s);
    else tekler(s);
    for(int i=1;i<n;i++)
	{
        gecici->sonraki=new list;
        gecici=gecici->sonraki;
        printf("%d. sayiyi giriniz : ",i+1);
		scanf("%d",&s);
        gecici->sayi=s;
		if(s%2==0){ciftler(s);}
        else if(s%2!=0){tekler(s);}
    }
    printf("Tekler Toplami-> %d\nCiftler Toplami-> %d\n",t1,t2);
    gecici->sonraki=NULL;
    gecici=baslangic;
    printf("-----TEK  SAYILAR-----\n");
    for(;gecici;gecici=gecici->sonraki)
    {
        if((gecici->sayi)%2!=0){printf("%d\n",gecici->sayi);}
    }
    gecici=baslangic;
    printf("-----CIFT SAYILAR-----\n");
    for(;gecici;gecici=gecici->sonraki)
    {
        if((gecici->sayi)%2==0){printf("%d\n",gecici->sayi);}
    }
    gecici=baslangic;
    if(t1>t2)
	{
		printf("Tekler Toplami Buyuk\n");
		printf("Bagli liste elemanlari NORMAL listeleme\n");
		goster(baslangic,1,n);
	}
    else if(t2>t1)
	{
		printf("Ciftler Toplami Buyuk\n");
		printf("Bagli liste elemanlari TERSTEN listeleme\n");
		goster(baslangic,0,n);
	}
}
int main()
{
    int n;
    int sayi;
    list *l,*m;
    fonk(l);
    getch();
}
