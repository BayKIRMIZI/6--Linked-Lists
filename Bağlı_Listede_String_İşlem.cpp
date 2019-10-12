#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h> 

typedef struct isim{
	char data;
	struct isim *n;
}LST;

int main(){
	LST *p,*q;
	p=q=new LST;
	char isim[20],kar[2];
	int sayac=0;
	printf("Ismi Gir : "); gets(isim);
		for(int i=0;isim[i]!='\0';i++){
			p->n=new LST;
			p->data=isim[i];
			p=p->n;
		}
	p->data='\0';
		printf("Karakter Giriniz : "); gets(kar);
		p=q;
			for(int i=0;p->data!='\0';i++){
				if(p->data==kar[0]) sayac++;
				p=p->n;
				
			}
			if(sayac==0) printf("Karakter Isimde Mevcut Degildir...");
			else{
				printf("\n");
				int i=0;
				for(;i<sayac;i++){
				
				}printf("%c karakteri isimde %d defa gecmektedir.",kar[0],i);
			}
		
	
	
	
	printf("\n\n");
	system("pause");
	return 0;
}
