#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<iostream.h>         // Owner:-- Rahul Dhingra
#include<dos.h>


class Line
{
public:
int x1,y1,x2,y2;

Line();
void get(int x1, int y1, int x2, int y2);
void put();

}

Line::Line()
{
 x1=100;y1=100;x2=100;y2=300;
}

void Line::get(int x1, int y1, int x2, int y2)
{
 this->x1=x1;
 this->y1=y1;
 this->x2=x2;
 this->y2=y2;
}

// for debug purpose
void Line::put(){
 cout<<x1<<" "<<y1<<"  "<<x2<<" "<<y2<<endl;

}

struct Lin{
  int x1,y1,x2,y2;
};
void swapLine(struct Lin *L1,struct Lin *L2)
{

       //Line  animation
      // delay(1000); // First line
	 setcolor(0);
	 line((*L1).x1,(*L1).y1,(*L1).x2,(*L1).y2);
	 for(int j=(*L1).x1; j< (*L2).x1;j++)
	 {
	 setcolor(2);
	 line(j ,(*L1).y1 ,j, (*L1).y2);
	 //	delay(10);
	 setcolor(0);
	 line(j ,(*L1).y1 ,j, (*L1).y2);

	 }

	  setcolor(0);
	  line((*L2).x1,(*L2).y1,(*L2).x2,(*L2).y2);
	  setcolor(4);
	  line(j ,(*L1).y1 ,j, (*L1).y2);


	   //Second line animation
	//  delay(1000);

	  for( j=(*L2).x1-1; j> (*L1).x1;j--)
	  {
	     setcolor(7);
	     line(j ,(*L2).y1 ,j, (*L2).y2);
	     delay(10);
	     setcolor(0);
	     line(j ,(*L2).y1 ,j, (*L2).y2);

	  }
	 setcolor(8);
	 line(j ,(*L2).y1 ,j, (*L2).y2);

	 setcolor(0);
	 line(j ,(*L2).y1 ,j, (*L2).y2);

}
void main()
{

int x1=100,y1=100,i,x2=100,y2=400,X=550;
const int size=80;
	int g=DETECT,d;
       initgraph(&g,&d,"C:\\TC\\BGI");
       cleardevice();
	Line L[size];

      // make 10 lines of random y1
     for(i=0; i <size && y1<400; x1=x1+5,y1=rand()%370,x2=x1,i++)
     {   L[i].get(x1,y1,x2,y2);

       line(x1,y1,x2,y2);
	// L[i].put();

     }



	     //Storing all the value in array
	     int a[size];
	     for(int q=0;q<size;q++)
	     {
		a[q]=L[q].y1;

	     }
     for(int m=0;m<size-1;m++)
     {
	 for(int n=0;n<size-m-1;n++)
	 {
		if(a[n]>a[n+1])
		{
		 int temp=a[n];
		 a[n]=a[n+1];
		 a[n+1]=temp;
		}
	  }

      }


	 //bubble sort


     for( m=0;m<size-1;m++)
     {
	 for(int n=0;n<size-m-1;n++)
	 {
	   if(L[n].y1 > L[n+1].y1)
	   {
	     //swap
	     struct Lin l1,l2;
	     l1.x1=L[n].x1;
	     l1.y1=L[n].y1;
	     l1.x2=L[n].x2;
	     l1.y2=L[n].y2;

	     l2.x1=L[n+1].x1;
	     l2.y1=L[n+1].y1;
	     l2.x2=L[n+1].x2;
	     l2.y2=L[n+1].y2;

	       swapLine(&l1, &l2);

	       //x1 and x2 value updated
	       int t=L[n].x1;
	       L[n].x1=L[n+1].x1;
	       L[n+1].x1=t;

	       L[n].x2=L[n].x1;
	       L[n+1].x2=L[n+1].x1  ;


	   }



	 }
	     setcolor(0);
	     line(L[size-1-m].x1, L[size-1-m].y1, L[size-1-m].x2,L[size-1-m].y2);
		 setcolor(15);
	 for(i=0;i<size;i++)
	 {

	     if(a[size-1-m] == L[i].y1)
	     {
	       line(X,L[i].y1,X,L[i].y2);
	       X-=5;
	     }
	 }

     }

	 setcolor(0);
	 line(L[0].x1,L[0].y1,L[0].x2,L[0].y2);


 getch();


}