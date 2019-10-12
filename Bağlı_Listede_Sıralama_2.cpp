#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct liste
{
        int d;
        struct liste *n;
}LST;
main()
{
      LST *p,*q,*r;
      p=q=new LST;
      int dizi[]={55,11,1,5,9,7};
      int i;
      //printf("1.sayiyi giriniz : ");
      //scanf("%d",&p->d);
      p->d=dizi[0];
      p->n='\0';
      
      for(i=1;i<7;i++)
      {
            r=new LST;
            //printf("%d.sayiyi giriniz : ",i);
            //scanf("%d",&r->d);
            r->d=dizi[i];
            r->n=NULL;
            if((q->d)>(r->d))
            { 
                r->n=q;
                q=r;
            }
            else
            {
                 for(p=q;(p->n != '\0') && ((p->n->d) < (r->d));p=p->n);
                 if(p->n == '\0')
                 { 
                     p->n=r;
                     //r->n='\0';
                 }
                 else
                 {
                     r->n=p->n;
                     p->n=r;    
                 } 
            }
      }
      for(p=q;p->n!='\0';p=p->n)
      { printf("%d\n",p->d); }
      system("pause");
}
