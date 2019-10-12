#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct liste
{
        int deger;
        struct liste *sonraki;
        struct liste *onceki;
}LST;

int main()
{
      LST *p,*q,*r,*y;
      int t,i;
      printf("Kac sayi girceksiniz : ");
      scanf("%d",&t);
      p=q=new LST;
      printf("1.sayiyi giriniz : ");
      scanf("%d",&p->deger);
      p->onceki=NULL;
      p->sonraki=NULL;
      for(i=2;i<=t;i++)
      {
          r=new LST;
          printf("%d.sayiyi giriniz : ",i);
          scanf("%d",&r->deger);
          if((q->deger)>(r->deger))
          {
               r->sonraki=q;
               q->onceki=r;
               r->onceki=NULL;
               q=r;
          }
          else
          {
               for(p=q;p->sonraki!=NULL && (p->sonraki->deger)<(r->deger);p=p->sonraki);
               if(p->sonraki==NULL)
               {
                    //y=r;
                    p->sonraki=r;
                    r->sonraki=NULL;
                    r->onceki=p;
               }
               else
               {
                    r->sonraki=p->sonraki;
                    p->sonraki=r;
                    r->sonraki->onceki=r;
                    r->onceki=p;
               }
          }
      }
      p=q;
      for(i=1;i<=t;i++)
      {
              printf("\n%d",p->deger);
              p=p->sonraki;
      }
      getch();
}








