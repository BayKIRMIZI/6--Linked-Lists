//bagli liste ayni olani sil

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct liste{
	int d;
	struct liste *next,*previous;
}LST;

int main(){
	LST *p,*q,*r,*z;
	p=q=new LST;
	int sayi,i;
	q->previous=new LST;
	q->previous->d='\0';
	printf("Kac Deger Gireceksiniz? : "); scanf("%d",&sayi);
	printf("1. Deger : "); scanf("%d",&p->d);
		for(int i=1;i<sayi;i++){
			p->next=new LST;
			printf("%d. Deger : ",i+1); scanf("%d",&p->next->d);
			p->next->previous=p;
			p=p->next;	
		}	
		p->next=new LST;
		p->next->d='\0';
		p->next->previous=p;
		printf("\n\n\tBagli Liste\n\n");
			for(i=0,p=q;p->d!='\0';p=p->next,i++){
				printf("%d. Deger : %d\n",i+1,p->d);
			}
			
			z=new LST; r=new LST;
			
			for(z=q;z->d!='\0';z=z->next){
				for(p=z->next;p->d!='\0';p=p->next){
					if(p->d==z->d){
						p->previous->next=p->next;
						p->next->previous=p->previous;
						r=p->previous;
						free(p);
						p=r;
					}	
				}
			}
			printf("\n\n\tDuzenlenmis Bagli Liste\n\n");
			for(i=0,p=q;p->d!='\0';p=p->next,i++){
				printf("%d. Deger : %d\n",i+1,p->d);
			}
			printf("\n\n");
			
	
	
	
	system("pause");
	return 0;
}
