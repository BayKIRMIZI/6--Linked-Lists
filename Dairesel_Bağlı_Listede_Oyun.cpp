/*	Ka� veriden olu�tu�u kullan�cadan al�nan ve elemanlar� otomatik numaraland�r�lan �embersel ba�l� listeden her turda liste ba��ndan random belirlenen bir say� kadar ilerlenir ve
hangi elemana denk geliyorsa o eleman listeden kald�r�l�r. E�er ba�l� listede kalan eleman say�s� 5'ten fazla ise her ikinci eleman listeden ��kt���nda liste sonuna yine de�eri 
otomatik atanacak �ekilde bir eleman gelir. Bu i�lemler �embersel ba�l� listede bir eleman kalana dek devam eder ve her turda �embersel listemizin kalan elemanlar� ekran ��kt�s� 
olarak verilir. �embersel ba�l� liste elemanlar�n� birer oyuncu olarak g�r�rsek oyunun ka� turda tamamland��� ve ka� numaral� oyuncunun oyunu kazand��� bilgisi ekrana verilir... */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct liste{
	int data;
	struct liste *n;
}LST;

int main(){
	srand(time(NULL));
	int i=0,j=0,k=0,sayac=0,sayi,el_s;
	LST *p,*q,*r;
	p=q=new LST;
	r=new LST;
	printf("Bagli Liste Veri Sayisini Giriniz : "); scanf("%d",&el_s); 
	p->data=1;
		for(k=1;k<el_s;k++){
			p->n=new LST;
			p=p->n;
			p->data=k+1;
		}
	p->n=q;
		for(i=0;q->n!=q;i++){
			p=q;
			sayi = (rand() % 55) + 1;
			for(j=0;j<sayi-1;j++){
				p=p->n;
			}
			r=p->n;
			if(r==q) q=q->n;
			p->n=r->n;
			sayac++;
			p=q;
			for(j=1;;j++){
					p=p->n;
					if(p->n==q) break;
				}
			if(j+1>5){
			if(sayac % 2 == 0){
				k++;
				r->data=k;
				p=q;
				for(j=0;;j++){
					p=p->n;
					if(p->n==q) break;
				}
				r->n=p->n;
				p->n=r;
			}
		}
			r=q;
			if(q->n!=q){
			printf("\n%d.Tur : ",i+1);
				for(j=0;;j++){
					printf("%d ",r->data);
					r=r->n;
					if(r==q) break;
				}
			}
			
		}
	printf("\n\tKazanan Oyuncu\n");
	printf("\t%d. Turda %d...",i,q->data);
	
	printf("\n\n");
	system("pause");
	return 0;
}
