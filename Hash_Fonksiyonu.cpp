#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX_ROW 11

typedef struct Satir{
	int index;
	int numara;
	struct Satir *sonrasi;
};
typedef struct Tablo{
	Satir satirlar[MAX_ROW];
};
	Tablo tablo;
	
void Baslangic_Tablosu()
{
	int i;
	for(i=0;i<MAX_ROW;i++)
	{
		tablo.satirlar[i].index=-1;
		tablo.satirlar[i].sonrasi=NULL;
	}
}

int Hash (int numara)
{
	return numara % MAX_ROW;
}

void Kiyasla(Satir *satir/*Hazirlanan kayit*/,Satir *baslangic_satiri /*Bu satirdan itibaren eklenmeye baþlanacak*/)
{
	while(baslangic_satiri->sonrasi != NULL)
	{
		baslangic_satiri = baslangic_satiri->sonrasi;
	}
	baslangic_satiri->sonrasi=satir;
}

void Ekle(int numara)
{
	int hash_index;
	Satir *satir;
	hash_index=Hash(numara);
	if(tablo.satirlar[hash_index].index == -1)
	{
		tablo.satirlar[hash_index].index = hash_index;
		tablo.satirlar[hash_index].numara = numara;
		return ;
	}
	
	satir = (Satir *) malloc(sizeof(Satir));
	satir->index = hash_index;
	satir->numara = numara;
	satir->sonrasi = NULL;
	
	Kiyasla(satir,&tablo.satirlar[hash_index]);
}

int Satir_Bul(int no) // Arama Kodu
{
	Satir *satir;
	int hash_index;
	hash_index=Hash(no);	
	if(tablo.satirlar[hash_index].numara==no)
	{
		return tablo.satirlar[hash_index].index;
	}
	else
	{
		satir = tablo.satirlar[hash_index].sonrasi;
		while(satir!=NULL)
		{
			if(satir->numara==no)
			{
				return satir->index;
			}
			satir = satir->sonrasi;
		}
		return -1;
	}
}
void Gosterge_Tablosu() // Listeleme Kodu
{
	Satir *satir;
	for(int i=0;i<MAX_ROW;i++)
	{
		if(tablo.satirlar[i].index!=-1)
		{
			printf("%d. hucrede %d var \n",i,tablo.satirlar[i].numara);
			satir=tablo.satirlar[i].sonrasi;
			while(satir!=NULL)
			{
				printf("%d. hucreye bagli listede %d var \n",i,satir->numara);
				satir=satir->sonrasi;
			}
		}
	}
}
int main ()
{
	Baslangic_Tablosu();
	for(int i=0;i<11;i++)
	{
		Ekle(i);
	}
	Ekle(15);Ekle(28);Ekle(19);Ekle(22);Ekle(23);Ekle(33);Ekle(44);
	Gosterge_Tablosu();
	printf("%d sayisi %d. indexte Bulundu  (%d)mod(%d) = %d ",44,Satir_Bul(44),44,MAX_ROW,44%MAX_ROW);
	getch();
	return 0;
}





























