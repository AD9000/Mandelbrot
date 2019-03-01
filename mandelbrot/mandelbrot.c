
// Assignment 1 Mandelbrot: Mandelbrot generation functions
// mandelbrot.c
//
// Completed by
// Atharv Damle (z5232949)
//
// Modified on 27-08-2018
// Tutor's name (dayHH-lab)
//
// Version 1.0.2: Fix minor typos in comments.
// Version 1.0.1: Fix issues with spacing and indentation.
// Version 1.0.0: Assignment released.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "mandelbrot.h"
#include "pixelColor.h"

//Typedefs
typedef struct complex complex;

//Constants
#define MAX_SIZE 512

//Function prototypes
static complex multiply(complex a, complex b);
static complex add(complex a, complex b);


// Take a pixel grid and and the path from the web browser used to
// request the 'tile'.
//
// The requestPath will be in the form 
// "/mandelbrot/2/{zoom}/{x}/{y}.bmp".
// In the query, 'x' and 'y' are decimals and describe the 'center'
// of the tile and need to be converted into a complex number.
// 'zoom' is an integer representing the zoom level for the tile.


void serveMandelbrot(
    struct pixel pixels[TILE_SIZE][TILE_SIZE],
    char *requestPath
) {
    complex center = {0.0, 0.0};
    int z = 7;

    sscanf(
        requestPath,
        "/mandelbrot/2/%d/%lf/%lf.bmp",
        &z, &center.re, &center.im
    );

    // Use drawMandelbrot to draw the image.
    drawMandelbrot(pixels, center, z);
}

// Draw a single Mandelbrot tile, by calculating and 
// colouring each of the pixels in the tile.
//
// Your function "returns" this tile by filling in the 
// `pixels` 2D array that is passed in to your function.
//
// The `pixels` array is TILE_SIZE high and TILE_SIZE wide.
// The bottom left corner of the image is pixels[0][0].
//
// `center` is a complex number, representing the center of the tile.
// `z` is used to calculate the distance between each pixel in the 
// image.
// Each pixel is 2^(-z) apart from each other.


void drawMandelbrot(
    struct pixel pixels[TILE_SIZE][TILE_SIZE],
    complex center,
    int z
) {
    //Complex number to calculate and store each point
    complex num;
    
    //Initialize to zero
    num.re = 0;
    num.im = 0;
    
    //Calculate zoom (positive power)
    double zoom = pow(2, z);
    
    //Counter variable for columns
    int column = 0;
    
    //Iterate over all columns
    while (column < MAX_SIZE)
    {
        //Counter variable for rows
        int row = 0;
        
        //Calculate the real part of num
        //Using (MAX_SIZE/2 - column) generates both 
        //positive and negative values
        num.re = center.re - (MAX_SIZE/2.0 - (double)column)/zoom;
        
        //Iterate over all rows
        while (row < 512)
        {
            //Similar to calculating the real part
            //calculate imaginary part of num
            num.im = center.im - (MAX_SIZE/2.0 - (double)row)/zoom;
            
            //Assign colour to pixel at (row, column) index
            pixels[row][column] = pixelColor(escapeSteps(num));
            
            //Go to next row
            row++;
            
        }
        //next column
        column++;
    }    
}

// Determine the number of steps required to escape the Mandelbrot set
// for the given complex number `c`.
int escapeSteps(complex c) {
    
    //Assign steps taken to 1
    //Skip first step: 0^2 + c
    int steps = 1;
    
    //complex number for calculation
    complex z;
    
    //Initialize it to c 
    //(Skips one step every time function is called)
    z.re = c.re;
    z.im = c.im;
        
    // modulus of z < 2
    // (ie square of modulus < 4)
    while (steps < MAX_STEPS &&  
           z.re*z.re + z.im*z.im < 4)
    {
        //Square z
        z = multiply(z, z);
        
        //z + c
        z = add(z, c);
        
        //One step done. Increase total steps by 1
        steps++;
        
        //Check if z = c. If so, the number c will never exit 
        //out of the loop and thus exists in the mandelbrot set.
        //(Because the loop restarts from c)
        if (z.re == c.re && z.im == c.im)
        {
            steps = MAX_STEPS;
        }
        
    }
    
    //Check if the point never escapes from set
    if (steps == MAX_STEPS)
    {
        steps = NO_ESCAPE;
    }
    
    //Return total number of steps taken  
    return steps;
}


//Function to multiply (square) the complex number
static complex multiply(complex a, complex b) {
    
    //Complex number to store the product
    complex prod;
    
    //Calculate real part
    prod.re = a.re * b.re - a.im * b.im;
    
    //Caluclate imaginary part
    prod.im = a.im * b.re + a.re * b.im;
    
    return prod;
}

//To add two complex numbers
static complex add(complex a, complex b) {
    
    //Complex number to store the sum
    complex c;
    
    //Calculate real part
    c.re = a.re + b.re;
    
    //Calculate imaginary part
    c.im = a.im + b.im;
    
    return c;
}

//SPARE FUNCTIONS (FOR DEVELOPERS)
/*
//NEW (EFFICIENT) TEST FUNCTION FOR ESCAPESTEPS -> Ascii-brot
//DOES NOT WORK FOR DRAW MANDELBROT
int main()
{
    //array to store output of escapeSteps()
    char a[512][512];
    
    //Temporary variable
    complex num;
    
    //Initialize
    num.re = 0;
    num.im = 0;
    
    //counter 1
    int i = 0;
    
    //512 x 512 image
    while (i < 512)
    {
        //counter 2
        int j = 0;
        
        //calculate real part
        num.re = (double)(256 - i)/100.0;
        
        //make only half the image
        while (j < 257)
        {
            //calculate imaginary part
            num.im = (double)(256 - j)/100.0;
            
            //Does the point lie in mandelbrot set?
            if (escapeSteps(num) == 256)
            {
                //Yes
                a[i][j] = '*';
            }
            else
            {
                //No
                a[i][j] = ' ';
            }
            //Increment
            j++;
        }
        //increment
        i++;
    }
    
    //mandelbrot set is symmetric about x axis
    //Copy half the image onto the other half
    i = 0;
    while (i < 512)
    {
        int j = 257;
        while (j < 512)
        {
            a[i][j] = a[i][511 - j];
            j++;
        }
        i++;
    }
      
    //print out the output
    i = 0;
    while (i < 512)
    {
        int j = 511;
        while (j >= 0)
        {
            printf("%c", a[j][i]);
            j--;
        }
        i++;
        printf("\n");
    }
    
    //success
    return 0;
}
*/
/*
//TEST FUNCTION FOR ESCAPESTEPS -> ascii-brot
int main()
{
    //array to store output of escapeSteps()
    char a[512][512];
    
    //temporary variable
    complex num;
    num.re = 0;
    num.im = 0;
    
    //Counter 1
    int i = 0;
    
    //for 512 x 512 image
    while (i < 512)
    {
        //counter 2
        int j = 0;
        
        //calculate real part
        num.re = (double)(256 - i)/100.0;
        
        while (j < 512)
        {
            //Calculate imaginary part
            num.im = (double)(256 - j)/100.0;
            
            //is the number in mandelbrot set?
            if (escapeSteps(num) == 256)
            {
                //Yes
                a[j][511-i] = '*';
            }
            else
            {
                //No
                a[j][511-i] = ' ';
            }
            //increment
            j++;
            
        }
        //increment
        i++;
    }
    
    //print out the output
    i = 0;
    while (i < 512)
    {
        int j = 511;
        while (j >= 0)
        {
            printf("%c", a[j][i]);
            j--;
        }
        i++;
        printf("\n");
    }
    
    //success
    return 0;
}
*/
