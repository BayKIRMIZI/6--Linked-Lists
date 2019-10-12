/* Sayý deðerleri kullanýcýdan alýnan baðlý liste ekranda gösterilecektir. Sonrasýnda elemanlarýn tau sayýsý olup olmadýðý kontrol edilip, tau sayý olmayan elemanlar baðlý listeden
silineceklerdir. Tau sayýlarýna göre düzenlenmiþ baðlý listenin ekrana çýktýsý verilecektir.
TAU Sayý : Bir sayýnýn tam bölenlerinin sayýsýna modu 0 ise o sayý Tau sayýdýr. Örnek: 8'in bölenleri = 1,2,4,8 yani 4 adet sayýdýr ve 8 % 4 = 0 olduðundan '8' bir TAU sayýdýr.
Örnek TAU Sayýlar : 1--2--8--9--12--18--24--36--40--56  
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct liste{
	int data;
	struct liste *n;
}LST;


int main(){
	LST *p,*q,*r;
	p=q=r=new LST;
	int s,k=0,kntrl=1;
		printf("Kac Sayi Gireceksiniz : "); scanf("%d",&s);
		printf("1. Sayi : "); scanf("%d",&p->data);	
			for(int i=1;i<s;i++){        //Bu döngüde elemanlarý alýyoruz...
				p->n=new LST;
				p=p->n;
				printf("%d. Sayi : ",i+1); scanf("%d",&p->data);
			}
			
		p->n=new LST;
		p=q;
		printf("\n\n\tBagli Liste\n\n");	//Bu döngüde ilk oluþturulan baðlý listenin ekran çýktýsýný alýyoruz...
			for(int i=0;i<s;i++){
				printf("%d. Sayi : %d\n",i+1,p->data);
				p=p->n;
			}
		p->data='\0';
		p=q;
			for(int i=0;i<s;i++){ 		//Bu döngü içerisinde tüm elemanlar sýra ile tau sayý denetlenmesi için çaðrýlýyor...
				if(kntrl==0){
					p=r;
					r=r->n;	
				}
				for(int j=1;j<=r->data;j++){	//Bu döngüde o elemanýn tau sayý olup olmadýðýný belirlemek için bölenlerinin sayýsý bulunuyor...
					if(r->data%j==0) k++;
				}
				if(r->data%k!=0){		//Burada tau sayýsý olup olmadýðý kontrol ediliyor...
					if(kntrl==1){		//Burada eðer ilk eleman ise q pointer'ýnýn da yer deðiþtirmesi saðlanýyor...
						q=p->n;
						p=q;
						r=q;
						k=0;
						kntrl=1;
						continue;
					}
					else if(kntrl==0){		//Burada ilk eleman olmadýðý koþulda tau sayýsý olmayan elemanýn baðlý listeden silinmesi saðlanýyor...
						p->n=r->n;
						free(r);
						r=p;
					}
				}
				kntrl=0;
				k=0;
			}
		p=q;
		printf("\n\n\tTau Bagli Liste\n\n");		//Bu döngüde de yeni baðlý listemizin ekran çýktýsý alýnýyor...
			for(int i=0;p->data!='\0';i++){
				printf("%d. Sayi : %d\n",i+1,p->data);
				p=p->n;
			}
	printf("\n\n");
	system("pause");
	return 0;
}
	
		
