#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Liste{
	int Ogr_no;
	char Ogr_ad[11];
	char Ogr_soyad[11];
	Liste *sonra;
}list;
list *kok=NULL;
list *kok2=NULL;
list *gcc,*gcc2; 
list *son,*son2; 
list *yeni;
int sayacy=0; 
int sayack=0; 
void yigin_ekle(list *temp)
{
	if(kok==NULL)
	{
		son=kok=temp;
		sayacy++;
	}
	else
	{
		temp->sonra = kok;
		kok = temp;
		sayacy++;
	}
}
void kuyruk_ekle(list *temp)
{
	if(kok2==NULL)
	{
		son2=gcc2=kok2=temp;
		sayack++;
	}
	else
	{
		gcc2->sonra=temp;
		gcc2=gcc2->sonra;
		son2=gcc2; 
		sayack++;
	}
}

void goster_yigin(list *gostery)
{
	if(gostery==NULL)
	{
		return;
	}
	else
	{
		printf("%d %s %s\n",gostery->Ogr_no,gostery->Ogr_ad,gostery->Ogr_soyad);
		goster_yigin(gostery->sonra);
	}
}
void goster_kuyruk(list *gosterk)
{
	if(gosterk==NULL)
	{
		return;
	}
	else
	{
		printf("%d %s %s\n",gosterk->Ogr_no,gosterk->Ogr_ad,gosterk->Ogr_soyad);
		goster_kuyruk(gosterk->sonra);
	}
}

void yigin_cikar()
{
	if(sayacy<=1)
	{
		if(sayacy==1)
		{
			kuyruk_ekle(kok);
			kok=NULL;
			sayacy--;
		}
		else
		{
			printf("Yiginda eleman yok...!!!\n");
			return;
		}
	}
	else
	{
		list *cikary;
		cikary=kok;
		kok=kok->sonra;
		cikary->sonra = NULL;
		sayacy--;
		kuyruk_ekle(cikary);
	}
}

void kuyruk_cikar()
{
	if(sayack<=1)
	{
		if(sayack==1)
		{
			yigin_ekle(kok2);
			kok2=NULL;
			sayack--;
		}
		else
		{
			printf("Kuyrukta eleman yok...!!!\n");
			return;
		}
	}
	else
	{
		list *cikark;
		cikark=kok2;
		kok2=kok2->sonra;
		cikark->sonra=NULL;
		sayack--;
		yigin_ekle(cikark);
	}
	
}
main()
{
	gcc=kok;
	gcc2=kok2;
	
	FILE *dosya;
	
	char satir[100],*p,dizi[50];
	dosya=fopen("yigin.txt","r");
	if(dosya==NULL)
	{
		printf("Dosya bulunamadi...");
	}
	else
	{
		while( !feof(dosya) )                   
   		{ 
      		yeni = new list;
      		yeni->sonra = NULL;
      		fscanf(dosya,"%s",&satir);
      		p=strtok(satir,"#");
      		strcpy(dizi,p);
      		yeni->Ogr_no=atoi(dizi);
      		
      		p=strtok(NULL,"#");
      		strcpy(yeni->Ogr_ad,p);
      		
      		p=strtok(NULL,"#");
      		strcpy(yeni->Ogr_soyad,p);
      		
      		yigin_ekle(yeni);  
   		}
	}
	fclose(dosya);
	
	
	
	dosya=fopen("kuyruk.txt","r");
	if(dosya==NULL)
	{
		printf("Dosya bulunamadi...");
	}
	else
	{
		while( !feof(dosya) )                   
   		{ 
      		yeni = new list;
      		yeni->sonra = NULL;
      		fscanf(dosya,"%s",&satir);
      		p=strtok(satir,"#");
      		strcpy(dizi,p);
      		yeni->Ogr_no=atoi(dizi);
      		
      		p=strtok(NULL,"#");
      		strcpy(yeni->Ogr_ad,p);
      		
      		p=strtok(NULL,"#");
      		strcpy(yeni->Ogr_soyad,p);
      		
      		kuyruk_ekle(yeni);  
   		}
	}
	fclose(dosya);
	int secim;
	while(11)
	{
		printf("");
		printf("1-Yigindan sil Kuyruga ekle\n");
		printf("2-Kuyruktan sil Yigina ekle\n");
		printf("3-Listele\n");
		printf("4-Dosya'ya yaz ve cik\n");
		printf("Secim: ");
		scanf("%d",&secim);
		switch(secim)
		{
			case 1:
				printf("\n");
				yigin_cikar();
				break;
			case 2:
				printf("\n");
				kuyruk_cikar();
				break;
			case 3:
				printf("\n*******************************************************\nYigin\n\n");
				goster_yigin(kok);
				printf("\n*******************************************************\nKuyruk\n\n");
				goster_kuyruk(kok2);
				printf("\n*******************************************************\n\n");
				break;
			case 4:
                    dosya = fopen ("Yigin_son.txt","w");
                    if(dosya == NULL)
                    {
                       printf("Boyle dosya yok!!!");
                    }
                    else
                    {
                       gcc=kok;
                       for(;gcc;gcc=gcc->sonra)
                       {
                          fprintf(dosya,"%d#%s#%s\n",gcc->Ogr_no,gcc->Ogr_ad,gcc->Ogr_soyad);
                       } 
                    }
                    fclose(dosya);
                    dosya = fopen ("Kuyruk_son.txt","w");
                    if(dosya == NULL)
                    {
                       printf("Boyle dosya yok!!!");
                    }
                    else
                    {
                       gcc2=kok2;
                       for(;gcc2;gcc2=gcc2->sonra)
                       {
                          fprintf(dosya,"%d#%s#%s\n",gcc2->Ogr_no,gcc2->Ogr_ad,gcc2->Ogr_soyad);
                       } 
                    }
					return 0;
				break;
			default:
				printf("\nHata !!! Tekrar dene....\n");
				break;
		}
	}
	getch();
}
