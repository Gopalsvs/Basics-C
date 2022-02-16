#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
const int md[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
typedef struct time{
	int YR,MT,DY,HR,MN,SE;
	char DAY[10];char TZ[3];
}calender;
struct date
{
	int d,m,y;
};
calender a;
int leapyear(int q){
	int w;
	if(q%4 == 0)
	{
        	if( q%100 == 0)
		{
          	        if ( q%400 == 0)
       	         		w=1;
        		else
				w=0;     
		}
       		else
           		w=1;
	}	
    	else
       		w=0;
	return w;
}
void changedate(int* a,int* b,int* c,int q){
	int count;
	while( q > 0 )
		{
		if(*b==1 || *b==3 || *b==5 || *b==7 || *b==8 || *b==10)
		{
			if( (*c+q) < 32 )	
			{
				count=*c;		
				*c=*c+q;
				q=(count+q)-31;
			}
			else
			{
				q=(*c+q)-32;
				*b=*b+1;
				*c=1;
			}
		}
		else if(*b==2)
		{
			if(leapyear(*a))
			{
				if( (*c+q) < 30 )
				{
					count=*c;
					*c=*c+q;
					q=(count+q)-29;
				}
				else
				{
					q=(*c+q)-30;
					*b=*b+1;
					*c=1;
				}
			}
			else
			{
				if( (*c+q) < 29 )
				{
					count=*c;
					*c=*c+q;
					q=(count+q)-28;				
				}
				else
				{
					q=(*c+q)-29;
					*b=*b+1;
					*c=1;
				}
			}
		}		
		else if(*b==4 || *b==6 || *b==9 || *b==11)
			{
			if( (*c+q) < 31 )
			{
				count=*c;
				*c=*c+q;
				q=(count+q)-30;
			}
			else
			{
				q=(*c+q)-31;
				*b=*b+1;
				*c=1;
			}
		}
		else if(*b==12)
		{
			if( (*c+q) < 32 )
			{
				count=*c;
				*c=*c+q;
				q=(count+q)-31;
			}
			else
			{
				q=(*c+q)-32;
				*b=1;
				*c=1;
				*a=*a+1;
			}
		}
	}
}		
void changedate1(int* a,int* b,int* c,int q)
{	
		int count;	
		while(q>0)
		{
			if( *b==5 || *b==7 || *b==10 || *b==12 )
			{
				if(*c>q)
				{
					count=*c;
					*c=*c-q;
					q=0;
				}
				else
				{
					q=q-*c;
					*b=*b-1;
					*c=30;
				}
			}
			if(*b==1)
			{
				if(*c>q)
				{
					count=*c;
					*c=*c-q;
					q=0;
				}
				else
				{
					q=q-*c;
					*a=*a-1;
					*b=12;
					*c=31;
				}
			}
			if(*b==2 || *b==4 || *b==6 || *b==8 || *b==9 || *b==11 ){
				if(*c>q)
				{
					count=*c;
					*c=*c-q;
					q=0;
				}
				else
				{
					q=q-*c;
					*b=*b-1;
					*c=31;
				}
			}
			if(*b==3)
			{
				if(*c>q)
				{
					count=*c;
					*c=*c-q;
					q=0;
				}
				else
				{
					if(leapyear(*a))
					{
						q=q-*c;
						*b=*b-1;
						*c=29;
					}
					else
					{
						q=q-*c;
						*b=*b-1;
						*c=28;
					}
				}
			}
		}
}
int leapyears(struct date d) 
{ 
    int years = d.y; 
    if (d.m <= 2) 
        years--; 
    return (years / 4)-(years/100)+(years/400); 
}  
int findingday(int a,int b)
{
	int p;
	p=(a+b)%7;
	if(p<0){
		p=p+7;
	}
	return p;
}
int today(char* a)
{
	if(a[0] == 'S' && a[1] == 'u' && a[2] == 'n')
		return 0;
	else if(a[0] == 'M' && a[1] == 'o' && a[2] == 'n')
		return 1;
	else if(a[0] == 'T' && a[1] == 'u' && a[2] == 'e')
		return 2;
	else if(a[0] == 'W' && a[1] == 'e' && a[2] == 'd')
		return 3;
	else if(a[0] == 'T' && a[1] == 'h' && a[2] == 'u')
		return 4;
	else if(a[0] == 'F' && a[1] == 'r' && a[2] == 'i')
		return 5;
	else if(a[0] == 'S' && a[1] == 'a' && a[2] == 't')
		return 6;
}
int change(struct date d1,struct date d2) 
{ 
    int n=d1.d+d1.y*365; 
    for (int i=0; i<d1.m - 1; i++) 
        n=n+md[i]; 
 
    n=n+leapyears(d1);  
    long int m = d2.y*365 + d2.d; 
    for (int j=0; j<d2.m-1; j++) 
        m=m+md[j]; 
    m=m+leapyears(d2);
    return(m-n); 
}
int hours(int* x,int q,char y){
	int p;
	if(y=='+')
	{
		p=(*x+q)/24;
		*x=(*x+q)%24;
		return p;
	}
	else
	{
		if(*x>q)
		{
			*x=*x-q;
			return 0;
		}
		else
		{
			q=q-*x;
			if(q==0)	
			{		
				p=0;
				*x=0;
			}
			else
			{			
				p=1;
				*x=0;
				p=p+(*x+q)/24;
				*x=24-((*x+q)%24);
			}
			return p;
		}
	}
}
int minutes(int* y,int c,char x)
{
	int p;
	if(x=='+')
	{
		p=(*y+c)/60;
		*y=(*y+c)%60;
		return p;
	}
	else
	{
		if(*y>c)
		{
			*y=*y-c;
			return 0;
		}
		else
		{
			c=c-*y;
			p=1;
			*y=0;
			p=p+(*y+c)/60;
			*y=60-(*y+c)%60;
			return p;
		}
	}
}

	

int main()
{
	char ct[50];
	char sign[1]={'\0'};
	char u[5]={'\0'};
	int ex;
	char qwe[3];
	scanf("%s",ct);
	scanf("%s",sign);
	scanf("%d",&ex);
	scanf("%s",u);
	int x,y,z,a1,b,c,d,e,f,g,h;
	int i,j,k,l,m;
	l=0;i=0;m=0,k=-1;
	while(ct[i]!='-')
	{
		k=k+1;
		i++;
	}
	i=0;			
	while(ct[i]!='-')
	{
		x=(int)(ct[i]-'0');
		a.YR+=x*(int)pow(10,k-i);	
		i++;
	}
	j=i;
	j=j+1;
	if(ct[j]!='-')
	{
		y=(int)(ct[j]-'0');
		z=(int)(ct[j+1]-'0');
		a.MT=y*pow(10,1)+z;
	}
	j=j+3;
	if(ct[j]!='-')
	{
		a1=(int)(ct[j]-'0');
		b=(int)(ct[j+1]-'0');
		a.DY=a1*pow(10,1)+b;
	}
	j=j+3;
	int p=j,v;
	while(ct[j+1]!='/')
	{
		j=j+1;
	}
	if(ct[p]!='/')
	{
		for(k=p;k<j+1;k++)
		{
			a.DAY[l++]=ct[k];
		}		
	}
	j=j+2;
	if(ct[j]!=':')
	{
		c=(int)(ct[j]-'0');
		d=(int)(ct[j+1]-'0');
		a.HR=c*pow(10,1)+d;
	}
	j=j+3;
	if(ct[j]!=':')
	{
		e=(int)(ct[j]-'0');
		f=(int)(ct[j+1]-'0');
		a.MN=e*pow(10,1)+f;
	}
	j=j+3;
	if (ct[j]!='/')
	{
		g=(int)(ct[j]-'0');
		h=(int)(ct[j+1]-'0');
		a.SE=g*pow(10,1)+h;
	}
	j=j+3;
	
	
	int min,year1=a.YR,mon1=a.MT,dat1=a.DY,dat2;
	if(sign[0]=='+')
	{
		if(u[0]=='Y'&&u[1]=='R')
		{
			if(leapyear(a.YR) && a.MT==2 && a.DY==29)
			{
				if(leapyear(a.YR+ex))		
					a.YR=a.YR+ex;
				else{ 
					a.YR=a.YR+ex;
					a.MT=2;
					a.DY=28;
				}
			}
			else
				a.YR=a.YR+ex;
		}
		else if(u[0]=='M' && u[1] =='T')
		{
			a.YR=a.YR+(a.MT+ex)/12;
			a.MT=(a.MT+ex)%12;
			if(a.MT==0)
			{					
				a.MT=12;
				a.YR=a.YR-1;
			}
			if(leapyear(a.YR))
			{
				if(a.MT==2)
				{
					if(a.DY>=29)
					{
						a.DY=29;
					}
				}
				if(a.MT==4 || a.MT ==6 || a.MT==9 || a.MT==11)
				{	
					if(a.DY>30)
					{
						a.DY=30;
					}
				}
			}
			else
			{
				if(a.MT==2)
				{
					if(a.DY>=28)
					{
						a.DY=28;
					}
				}
				if(a.MT==4 || a.MT ==6 || a.MT==9 || a.MT==11)
				{
					if(a.DY>30)
					{
						a.DY=30;
					}
				}
			}
		}
		else if(u[0]=='D' && u[1] == 'Y')
			changedate(&a.YR,&a.MT,&a.DY,ex);			
		else if(u[0]=='H' && u[1]=='R')
			changedate(&a.YR,&a.MT,&a.DY,hours(&a.HR,ex,sign[0]));
		else if(u[0]=='M' && u[1]=='N'){
			min=minutes(&a.MN,ex,'+');
			changedate(&a.YR,&a.MT,&a.DY,hours(&a.HR,min,'+'));
		}	
	}
	else{
		if(u[0]=='Y' && u[1]=='R'){
			if(leapyear(a.YR) && a.MT==2 && a.DY==29){
				if(leapyear(a.YR-ex))
					a.YR=a.YR-ex;
				else{ 
					a.YR=a.YR-ex;
					a.DY=28;
				}
			}
			else
				a.YR=a.YR-ex;
		}
		else if(u[0]=='M' && u[1]=='T'){
			a.YR=a.YR+(a.MT-ex)/12;
			a.MT=(a.MT-ex)%12;
			if(a.MT<=0){
				a.MT=12+a.MT;
				a.YR=a.YR-1;
			}
			
			if(leapyear(a.YR)){
				if(a.MT==2){
					if(a.DY>=29){
						a.DY=29;
					}
				}
				if(a.MT==4 || a.MT ==6 || a.MT==9 || a.MT==11){
					if(a.DY>30){
						a.DY=30;
					}
				}
			}
			else{
				if(a.MT==2){
					if(a.DY>=28){
						a.DY=28;
					}
				}
				if(a.MT==4 || a.MT ==6 || a.MT==9 || a.MT==11){
					if(a.DY>30){
						a.DY=30;
					}
				}
			}
			
		}
		else if(u[0] == 'D' && u[1] == 'Y')
			changedate1(&a.YR,&a.MT,&a.DY,ex);
		else if(u[0] == 'H' && u[1] == 'R')
			changedate1(&a.YR,&a.MT,&a.DY,hours(&a.HR,ex,sign[0]));
		else if(u[0] == 'M' && u[1] == 'N'){
			min=minutes(&a.MN,ex,'-');
			changedate1(&a.YR,&a.MT,&a.DY,hours(&a.HR,min,'-'));
		}
	}
	int pd;
	struct date dt1={dat1,mon1,year1};
	struct date dt2={a.DY,a.MT,a.YR};
	dat2=change(dt1,dt2);
	dat1=today(a.DAY);
	pd=findingday(dat2,dat1);
	switch(pd){
		case 0:						a.DAY[0]='S',a.DAY[1]='u',a.DAY[2]='n',a.DAY[3]='d',a.DAY[4]='a',a.DAY[5]='y',a.DAY[6]='\0';
		break;		
		case 1:	a.DAY[0]='M',a.DAY[1]='o',a.DAY[2]='n',a.DAY[3]='d',a.DAY[4]='a',a.DAY[5]='y',a.DAY[6]='\0';				
		break;
		case 2:	a.DAY[0]='T',a.DAY[1]='u',a.DAY[2]='e',a.DAY[3]='s',a.DAY[4]='d',a.DAY[5]='a',a.DAY[6]='y',a.DAY[7]='\0';
		break;
		case 3:	a.DAY[0]='W',a.DAY[1]='e',a.DAY[2]='d',a.DAY[3]='n',a.DAY[4]='e',a.DAY[5]='s',a.DAY[6]='d',a.DAY[7]='a',a.DAY[8]='y';
		break;
		case 4:	a.DAY[0]='T',a.DAY[1]='h',a.DAY[2]='u',a.DAY[3]='r',a.DAY[4]='s',a.DAY[5]='d',a.DAY[6]='a',a.DAY[7]='y',a.DAY[8]='\0';
		break;
		case 5:
	a.DAY[0]='F',a.DAY[1]='r',a.DAY[2]='i',a.DAY[3]='d',a.DAY[4]='a',a.DAY[5]='y',a.DAY[6]='\0';
		break;		
		case 6:	a.DAY[0]='S',a.DAY[1]='a',a.DAY[2]='t',a.DAY[3]='u',a.DAY[4]='r',a.DAY[5]='d',a.DAY[6]='a',a.DAY[7]='y',a.DAY[8]='\0';
		break;
	}
	printf("%d-",a.YR);
	if(a.MT<10)
		printf("0%d-",a.MT);
	else 
		printf("%d-",a.MT);
	if(a.DY<10)
		printf("0%d/",a.DY);
	else 
		printf("%d/",a.DY);
	printf("%s/",a.DAY);
	if(a.HR<10)	
		printf("0%d:",a.HR);
	else 
		printf("%d:",a.HR);
	if(a.MN<10)
		printf("0%d:",a.MN);
	else
		printf("%d:",a.MN);
	printf("0%d/",a.SE);
	printf("IST\n");						
	return 0;
}

		 

	

