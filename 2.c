#include<math.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct point{
	float x;
	float y;
}point;
typedef struct line{
	struct point p1;
	struct point p2;
}line;
typedef struct cirle{
	struct point p;
 	float r;
}circle;
typedef struct tri{
	struct point v1;
	struct point v2;
	struct point v3;
}tri;
void print(int a){
	if(a==0){
		printf("The primitives do not intersect.");}
	else{
		printf("The primitives intersect.");}
}
float dis(point p,point q)
{
	float a=pow((p.x-q.x),2)+pow((p.y-q.y),2);
	return sqrt(a);
}	 
int pp(point p1,point p2)
{
	if(p1.x==p2.x && p1.y==p2.y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int pl(point p,line l)
{
	float a=dis(p,l.p1);
	float b=dis(p,l.p2);
	float c=dis(l.p1,l.p2);
	if(c==a+b)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
int pc(point p,circle c)
{
	float q=dis(p,c.p);
	if(q==c.r)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int pt(point p,tri t)
{
	int a,b,c;
	line l1,l2,l3;
	l1.p1=t.v1;l1.p2=t.v2;
	l2.p1=t.v2;l2.p2=t.v3;
	l3.p1=t.v3;l3.p2=t.v1;
	a=pl(p,l1);b=pl(p,l3);c=pl(p,l3);
	return a+b+c;
}
int ll(line l1,line l2)
{
	int a1,b1,c1,a2,b2,c2,x,y;
	point p1,p2,p3,p4,p5;
	p1.x = l1.p1.x , p1.y = l1.p1.y;
	p2.x = l1.p2.x , p2.y = l1.p2.y;
	p3.x = l2.p1.x , p3.y = l2.p1.y;
	p4.x = l2.p2.x , p4.y = l2.p2.y;
	a1 = (p2.y - p1.y) , b1 = (p1.x - p2.x) , c1 = (p1.y*p2.x - p1.x*p2.y); 
	a2 = (p4.y - p3.y) , b2 = (p3.x - p4.x) , c2 = (p3.y*p4.x - p3.x*p4.y);
	if((b1*a2-a1*b2)==0)
	{
		if(dis(p1,p3)+dis(p2,p3)==dis(p1,p2)||dis(p1,p4)+dis(p2,p4)==dis(p1,p2))
				return 1;
		else
		{
			if(dis(p3,p1)+dis(p4,p1)==dis(p3,p4)||dis(p3,p2)+dis(p4,p2)==dis(p3,p4))
				return 1;
			else 
				return 0;
		}	
	}
	else
	{
		p5.y=(a1*c2-a2*c1)/(float)(b1*a2-a1*b2);
		p5.x=(c2*b1-c1*b2)/(float)(a1*b2-a2*b1);
		if(dis(p1,p5)+dis(p2,p5)==dis(p1,p2))
		{
			if(dis(p3,p5)+dis(p4,p5)==dis(p3,p4))
				return 1;
			else
				return 0;
		}
		else 	
			return 0;
	}
}	
int lc(line l1,circle c1)
{
	float dist,n,c;
	c = sqrt( pow(l1.p2.y-l1.p1.y,2) + pow(l1.p1.x-l1.p2.x,2) );
	n = (l1.p2.y-l1.p1.y)*c1.p.x + c1.p.y*(l1.p1.x-l1.p2.x) - (l1.p1.x*l1.p2.y) + (l1.p1.y*l1.p2.x);
	dist=n/(float) c;
	point p1, p2, p3, p4;
	p1.x=c1.p.x;
	p1.y=c1.p.y;
	p2.x=l1.p1.x;
	p2.y=l1.p1.y;
	p3.x=l1.p2.x;
	p3.y=l1.p2.y;
	float seg_a=dis(p1,p2);
	float seg_b=dis(p1,p3);

	float a1,b1,d1,a2,b2,d2;
	if(dist < 0)
		dist=-dist;
	if(dist > c1.r)
		return 0;
	else{
		if(c1.r != 0){
			if( (dis(p2,p1) >= c1.r && dis(p3,p1) <= c1.r) || (dis(p2,p1) <=c1.r && dis(p3,p1) >= c1.r))
				return 1; 
			if( dis(p1,p2) < c1.r && dis(p1,p3) < c1.r){
				return 0;}
			if(p2.x - p3.x == 0){
				p4.x = p2.x , p4.y = c1.p.y;	
				if( dis(p2,p4) + dis(p3,p4) == dis(p2,p3) )
					return 1;
				else
					return 0;
			}
			if(p2.y - p3.y == 0){
				p4.x = c1.p.x , p4.y = p2.y;
				if( dis(p2,p4) + dis(p3,p4) == dis(p2,p3) )
					return 1;
				else 
					return 0;
			}
			else {
				a1 = (p3.y - p2.y), b1 = (p2.x - p3.x), d1 = (p2.y*p3.x - p2.x*p3.y);
				a2 = (p2.x - p3.x), b2 = (p2.y - p3.y), d2 = p1.y*(p3.y - p2.y) + p1.x*(p3.x - p2.x);		 
				p4.y = (a1*d2 - a2*d1)/(float) (b1*a2 - a1*b2);
				p4.x = (d2*b1 - d1*b2)/(float) (a1*b2 - a2*b1);		     
				if(dis(p4,p2) + dis(p4,p3) == dis(p2,p3) )
					return 1;
				else
					return 0;
			}
		}
		else{
			if(dis(p1,p2)+dis(p1,p3)==dis(p2,p3))
				return 1;
			else 
				return 0;
		}
	}
}	
int lt(line l,tri t)
{
	line l1,l2,l3;
	l1.p1=t.v1;l1.p2=t.v2;
	l2.p1=t.v1;l2.p2=t.v3;
	l3.p1=t.v2;l3.p2=t.v3;
	int a=ll(l,l1);
	int b=ll(l,l2);
	int c=ll(l,l3);
	return a+b+c;	
}	
int cc(circle c1,circle c2)
{
	int a;
	if(c2.r>c1.r)
		a=c2.r-c1.r;
	else 
		a=c1.r-c2.r;
	if(a<dis(c1.p,c2.p) && dis(c1.p,c2.p)<=c1.r+c2.r)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int ct(circle c,tri t)
{
	line l1,l2,l3;
	l1.p1=t.v1;l1.p2=t.v2;
	l2.p1=t.v1;l2.p2=t.v3;
	l3.p1=t.v2;l3.p2=t.v3;
	int a=lc(l1,c);
	int b=lc(l2,c);
	int c1=lc(l3,c);
	return a+b+c1;
}
int tt(tri t1,tri t2)
{
	line l1,l2,l3;
	l1.p1=t1.v1;l1.p2=t1.v2;
	l2.p1=t1.v1;l2.p2=t1.v3;
	l3.p1=t1.v2;l3.p2=t1.v3;
	line q1,q2,q3;
	q1.p1=t2.v1;q1.p2=t2.v2;
	q2.p1=t2.v1;q2.p2=t2.v3;
	q3.p1=t2.v2;q3.p2=t2.v3;
	int a1=ll(l1,q1);int a2=ll(l1,q2);int a3=ll(l1,q3);
	int b1=ll(l2,q1);int b2=ll(l2,q2);int b3=ll(l2,q3);
	int c1=ll(l1,q1);int c2=ll(l1,q2);int c3=ll(l1,q3);
	return a1+a2+a3+b1+b2+b3+c1+c2+c3;
}	
int main()
{
	char a;
	char b;
	int g;
	point p1;line l1;circle c1;tri t1;
	point p2;line l2;circle c2;tri t2;
	scanf("%s",&a);
	if(a=='P')
		scanf("%f%f",&p1.x,&p1.y);
	else if(a=='L')
		scanf("%f%f%f%f",&l1.p1.x,&l1.p1.y,&l1.p2.x,&l1.p2.y);
	else if(a=='C')
		scanf("%f%f%f",&c1.p.x,&c1.p.y,&c1.r);
	else if(a=='T')
		scanf("%f%f%f%f%f%f",&t1.v1.x,&t1.v1.y,&t1.v2.x,&t1.v2.y,&t1.v3.x,&t1.v3.y);
	scanf("%s",&b);
	if(b=='P')
		scanf("%f%f",&p2.x,&p2.y);
	else if(b=='L')
		scanf("%f%f%f%f",&l2.p1.x,&l2.p1.y,&l2.p2.x,&l2.p2.y);
	else if(b=='C')
		scanf("%f%f%f",&c2.p.x,&c2.p.y,&c2.r);
	else if(b=='T')
		scanf("%f%f%f%f%f%f",&t2.v1.x,&t2.v1.y,&t2.v2.x,&t2.v2.y,&t2.v3.x,&t2.v3.y);



	if(a=='P' && b=='P')
	{
		g=pp(p1,p2);
		print(g);
	}
	else if(a=='P' && b=='L')
	{
		g=pl(p1,l2);
		print(g);
	}
	else if(a=='P' && b=='C')
	{
		g=pc(p1,c2);
		print(g);
	}
	else if(a=='P' && b=='T')
	{
		circle c={p1,0};
		g=ct(c,t2);
		print(g);
	}
	else if(a=='L' && b=='P')
	{
		g=pl(p2,l1);
		print(g);
	}
	else if(a=='L' && b=='L')
	{
		g=ll(l1,l2);
		print(g);
	}	
	else if(a=='L' && b=='C')
	{
		g=lc(l1,c2);
		print(g);
	}	
	else if(a=='L' && b=='T')
	{
		g=lt(l1,t2);
		print(g);
	}
	else if(a=='C' && b=='P')
	{
		g=pc(p2,c1);
		print(g);
	}
	else if(a=='C' && b=='L')
	{
		g=lc(l2,c1);
		print(g);
	}
	else if(a=='C' && b=='C')
	{
		g=cc(c1,c2);
		print(g);
	}
	else if(a=='C' && b=='T')
	{
		g=ct(c1,t2);
		print(g);
	}
	else if(a=='T' && b=='P')
	{
		circle c={p2,0};
		g=ct(c,t1);
		print(g);
	}
	else if(a=='T' && b=='L')
	{
		g=lt(l2,t1);
		print(g);
	}
	else if(a=='T' && b=='C')
	{
		g=ct(c2,t1);
		print(g);
	}
	else if(a=='T' && b=='T')
	{
		g=tt(t1,t2);
		print(g);
	}
	return 0;
}	

