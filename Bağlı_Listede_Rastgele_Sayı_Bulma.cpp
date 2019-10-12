/*
1-9 ARASINDA RASTGELE SAYILAR ATANARAK BAÐLI LÝSTE OLUÞTURUP
KULLANICIDAN BÝR SAYI GÝRMESÝ ÝSTENÝR. DAHA SONRA VOÝD FONKSÝYONUNUN
ÇÝZDÝÐÝ ÞEKÝLDE EÐER KULLANICI RASTGELE SAYILARDAN BÝR TANESÝNÝ
BÝLÝRSE O SÜTÜN "X" ÝLE DEÐÝL TÜMÜYLE "!" ÝLE DOLDURULUR.*/

#include <conio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

typedef struct sekil{
		int d;
		struct sekil *n;
		}LST;
		int h=9;
		void yap(LST *p, LST *q, int x);
		
int main(){
	srand(time(NULL));
		LST *p, *q;
		p=q=new LST;
		int FTY=1;
		int x;
		int ilksayi;
		int sayi;
		ilksayi=rand()%9+1;
		p->d=ilksayi;	
	
		for(int i=1; i<9; i++){
		
			p->n=new LST;
			sayi=rand()%9+1;
			p=p->n;
			p->d=sayi;
			
		}
		
		p->n=new LST;
		p=p->n;
		p->d='\0';
		
		while(FTY){
            cout << "1-9 arasinda bir sayi giriniz: ";
		    cin >> x;
		    if(x>9 || x<1){
                cout << "Hatali giris! ";
		        FTY=1;
            }else{
                FTY=0;
            }
        }
            
        cout << "\nRastgele olarak atanan bagli listedeki sayi degerleri:\n";
		p=q;		
		
		for(int i=0; p->d!='\0'; i++){
		cout << p->d << " ";
		p=p->n;
		}
		
		cout << "\n";
		
		yap(p,q,x);
		
getch();
return 0;		
}

void yap(LST *p, LST *q, int x){
    p=q;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(p->d == x){
                cout << "! ";
            }else{
                  if(p->d >= h){
                      cout << "x ";
                  }else{
                      cout << "  ";
                  }
            }
        p=p->n;    
        }
        cout << endl;
        h--;
        p=q;
    }
}

