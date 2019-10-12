/* Say� de�erleri kullan�c�dan al�nan ba�l� liste ekranda g�sterilecektir. Sonras�nda elemanlar�n tau say�s� olup olmad��� kontrol edilip, tau say� olmayan elemanlar ba�l� listeden
silineceklerdir. Tau say�lar�na g�re d�zenlenmi� ba�l� listenin ekrana ��kt�s� verilecektir.
TAU Say� : Bir say�n�n tam b�lenlerinin say�s�na modu 0 ise o say� Tau say�d�r. �rnek: 8'in b�lenleri = 1,2,4,8 yani 4 adet say�d�r ve 8 % 4 = 0 oldu�undan '8' bir TAU say�d�r.
�rnek TAU Say�lar : 1--2--8--9--12--18--24--36--40--56  
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
			for(int i=1;i<s;i++){        //Bu d�ng�de elemanlar� al�yoruz...
				p->n=new LST;
				p=p->n;
				printf("%d. Sayi : ",i+1); scanf("%d",&p->data);
			}
			
		p->n=new LST;
		p=q;
		printf("\n\n\tBagli Liste\n\n");	//Bu d�ng�de ilk olu�turulan ba�l� listenin ekran ��kt�s�n� al�yoruz...
			for(int i=0;i<s;i++){
				printf("%d. Sayi : %d\n",i+1,p->data);
				p=p->n;
			}
		p->data='\0';
		p=q;
			for(int i=0;i<s;i++){ 		//Bu d�ng� i�erisinde t�m elemanlar s�ra ile tau say� denetlenmesi i�in �a�r�l�yor...
				if(kntrl==0){
					p=r;
					r=r->n;	
				}
				for(int j=1;j<=r->data;j++){	//Bu d�ng�de o eleman�n tau say� olup olmad���n� belirlemek i�in b�lenlerinin say�s� bulunuyor...
					if(r->data%j==0) k++;
				}
				if(r->data%k!=0){		//Burada tau say�s� olup olmad��� kontrol ediliyor...
					if(kntrl==1){		//Burada e�er ilk eleman ise q pointer'�n�n da yer de�i�tirmesi sa�lan�yor...
						q=p->n;
						p=q;
						r=q;
						k=0;
						kntrl=1;
						continue;
					}
					else if(kntrl==0){		//Burada ilk eleman olmad��� ko�ulda tau say�s� olmayan eleman�n ba�l� listeden silinmesi sa�lan�yor...
						p->n=r->n;
						free(r);
						r=p;
					}
				}
				kntrl=0;
				k=0;
			}
		p=q;
		printf("\n\n\tTau Bagli Liste\n\n");		//Bu d�ng�de de yeni ba�l� listemizin ekran ��kt�s� al�n�yor...
			for(int i=0;p->data!='\0';i++){
				printf("%d. Sayi : %d\n",i+1,p->data);
				p=p->n;
			}
	printf("\n\n");
	system("pause");
	return 0;
}
	
		
