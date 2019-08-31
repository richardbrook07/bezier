#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

// pre-processor directories to calculate co-ordinates for the displaying window in the form of Cartesian co-ordinates
#define fx(x) (getmaxx()/2+x)    
#define fy(y) (getmaxy()/2-y)

// pre-processor directory to calculate the round-off value to the nearest integer
#define R(x) ((int)(x+0.5))

// required constants
#define X 640
#define Y 480

// colors
#define LRED 4
#define LCYAN 3
#define IYELLOW 14
#define LGREEN 2

struct input
{
       int x[4];
       int y[4];
};

typedef struct input S;

void drawQuadrants(int);   // function prototype to create quadrants
void bezier(S);
void drawBoundaries(S,int); 

int main(void)
{
    S inp; 
    int i;
    initwindow(X,Y);     // creating window
    drawQuadrants(LCYAN); // calling function to draw quadrants
    inp.x[0]=-10,inp.x[1]=100,inp.x[2]=-100,inp.x[3]=10;
    inp.y[0]=-10,inp.y[1]=200,inp.y[2]=200,inp.y[3]=-10;
    drawBoundaries(inp,LGREEN);
    bezier(inp);
}

// function definition to create quadrants
void drawQuadrants(int color)
/* Functions Description:-
             Predefined:
                  setcolor()- to draw a particular segment of the program with a particular color passed as an argument
                  line()- to draw a line
*/
{
    setcolor(color);   // setting a color for the co-ordinate axes
    line(0,fy(0),X,fy(0));   // drawing the X-axis; fy(0)=480/2=240;
    line(fx(0),0,fx(0),Y);   // drawing the Y-axis; fx(0)=640/2=320;
}  // end of function definition

void bezier (S inp)
{
    int i;
    double t=0.0,xt,yt;
 
    
    for (i=0; i<4; i++)
	      putpixel (fx(inp.x[i]),fy(inp.y[i]),IYELLOW);
    
    while(1)
    {
	      xt = pow(1-t,3)*inp.x[0]+3*t*pow(1-t,2)*inp.x[1]
                      +3*pow(t,2)*(1-t)*inp.x[2]+pow(t,3)*inp.x[3];
        yt = pow(1-t,3)*inp.y[0]+3*t*pow(1-t,2)*inp.y[1]
                      +3*pow(t,2)*(1-t)*inp.y[2]+pow(t,3)*inp.y[3];
        putpixel (fx(R(xt)),fy(R(yt)),LRED);
        t=t+0.0005;
        if(t>1.0)
           break;
        delay(1);
    }
    
 
    getch();
    return;
}

void drawBoundaries(S inp,int color)
{
     setcolor(color);
     line(fx(inp.x[0]),fy(inp.y[0]),fx(inp.x[1]),fy(inp.y[1]));
     line(fx(inp.x[1]),fy(inp.y[1]),fx(inp.x[2]),fy(inp.y[2]));
     line(fx(inp.x[2]),fy(inp.y[2]),fx(inp.x[3]),fy(inp.y[3]));
}

