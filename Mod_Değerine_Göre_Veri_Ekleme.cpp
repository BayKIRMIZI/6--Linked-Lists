#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
typedef struct Liste{
        int veri;
        int listmod;
        Liste *sonra;
}list;
        
main()
{
    FILE *dosya;
    int no,n=0;      
    dosya = fopen ("Liste.txt","r");
    
    if(dosya == NULL)
    {
       printf("Boyle dosya yok!!!");
    }
    else
    {
        while (!feof(dosya)) 
        {
           no=fgetc(dosya);
           if(no==' ')
           {
              n++;
           }
        }
    }
    fclose(dosya);
    int dizi[n];
    int b=0;
    dosya = fopen ("Liste.txt","r");
    if(dosya == NULL)
    {
       printf("Boyle dosya yok!!!");
    }
    else
    {
        while (!feof(dosya)) 
        {
           no=fgetc(dosya);
           if(no==' ')
           {
              fscanf(dosya,"%d",&dizi[b]);
              b++;
           }
        }
    }
    fclose(dosya);
    

    int mod;
    list *gcc,*kok,*yeni,*son;  
    
    printf("Mod degeri giriniz: ");
    scanf("%d",&mod);
    
    kok=new list;
    kok->veri=mod;
    kok->listmod=0;
    kok->sonra=NULL;
    gcc=kok;
    
    printf("\n\n\n");
    
    for(int k=0;k<n;k++)
    {
         if(gcc->listmod > dizi[k]%mod)
         {
            gcc=kok;
            for(;gcc;gcc=gcc->sonra)
            {
                 if(gcc->sonra != NULL && dizi[k]%mod<gcc->sonra->listmod)
                 {
                    yeni=new list;
                    yeni->veri=dizi[k];
                    yeni->listmod=dizi[k]%mod;
                    yeni->sonra=gcc->sonra;
                    gcc->sonra=yeni;
                    
                    for(;gcc->sonra;gcc=gcc->sonra);
                    son=gcc;
                 }
            }
            gcc=son;
         }
         else if(gcc->listmod < dizi[k]%mod)
         {
             gcc->sonra=new list;
             gcc=gcc->sonra;
             gcc->veri=dizi[k];
             gcc->listmod=dizi[k]%mod;
             gcc->sonra=NULL;
             
             
         }
         else
         {
             gcc->sonra=new list;
             gcc=gcc->sonra;
             gcc->veri=dizi[k];
             gcc->listmod=dizi[k]%mod;
             gcc->sonra=NULL;
         }
         
    }
    while(11)
    {
           int secim;
           printf("1-Ekle\n2-Listele\n3-Ara\n4-Sil\n5-DosyaYazVeCik\nSecim gir :");
           scanf("%d",&secim);
           switch(secim)
           {
               case 1:
                    int sayi;
                    list *tutulan;
                    printf("Sayi gir: ");
                    scanf("%d",&sayi);
                    gcc=kok;
                    for(;gcc->sonra;gcc=gcc->sonra)
                    {
                       if(sayi%mod > gcc->listmod)
                       {
                          for(;gcc->sonra && gcc->sonra->listmod <= sayi%mod;gcc=gcc->sonra);
                          if(gcc->sonra==NULL)
                          {
                             yeni=new list;
                             yeni->veri=sayi;
                             yeni->listmod=sayi%mod;
                             yeni->sonra=NULL;
                             gcc->sonra=yeni;
                          }
                          else
                          {
                             yeni=new list;
                             yeni->veri=sayi;
                             yeni->listmod=sayi%mod;
                             yeni->sonra=gcc->sonra;
                             gcc->sonra=yeni;
                          }
                       }
                       else if(sayi%mod == gcc->sonra->listmod)
                       {
                          for(;gcc->sonra->listmod <= sayi%mod;gcc=gcc->sonra);
                          yeni=new list;
                          yeni->veri=sayi;
                          yeni->listmod=sayi%mod;
                          yeni->sonra=gcc->sonra;
                          gcc->sonra=yeni;
                       }
                    }
                    printf("\n");
                    break;
               case 2:
                    gcc=kok;
                    printf("\n");
                    for(;gcc->sonra;gcc=gcc->sonra)
                    {
                       printf("%d\t%d\n",gcc->sonra->veri,gcc->sonra->listmod);
                    }
                    printf("\n");
                    break;
               case 3:
                    int aranan,kontrol;
                    printf("Aranacak sayi gir : ");
                    scanf("%d",&aranan);
                    gcc=kok;
					kontrol=0;
                    for(int k=0;gcc;gcc=gcc->sonra,k++)
                    {
                    	if(k == 0)
                    	{
                    		printf("\nMod Degeri -> %d\n",kok->veri);
						}
                        if(aranan == gcc->veri && k != 0)
                        {
                        	kontrol = 1;
                        	printf("Aranan sayi=%d-%d. siradadir.!!!\n",aranan,k);
                        }
                    }
                    if(kontrol != 1)
                    {
                    	printf("Boyle Bir Sayi Dosyada Yok :( \n");
					}
                    printf("\n");
                    break;
               case 4:
                    list *sil;
                    int silinecek;
                    printf("Silinecek sayi gir : ");
                    scanf("%d",&silinecek);
                    
                    gcc=kok;
                    for(;gcc->sonra;gcc=gcc->sonra)
                    {
                       if(gcc->sonra->veri==silinecek)
                       {
                          sil=gcc->sonra;
                             if(sil->sonra==NULL)
                             {
                                gcc->sonra=NULL;
                                delete(sil);
                                break;
                             }
                             else
                             {
                                gcc->sonra=sil->sonra;
                                sil->sonra=NULL;
                                delete(sil);
                             }
                       }
                    }
                    printf("\n");
                    break;
               case 5:
                    FILE *dosya;   
                    dosya = fopen ("Dosya.txt","w");
    
                    if(dosya == NULL)
                    {
                       printf("Boyle dosya yok!!!");
                    }
                    else
                    {
                       gcc=kok;
                       for(;gcc->sonra;gcc=gcc->sonra)
                       {
                          fprintf(dosya,"%d ",gcc->sonra->veri);
                       } 
                    }
                    fclose(dosya);
                    return 0;
               default:
                       printf(" ERROR !!!");
                       printf("\n");
                       break;
           }
    }
    getch();
}
