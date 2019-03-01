// Assignment 1 Mandelbrot: Pixel coloring functions
// pixelColor.c
//
// Completed by
//  Atharv Damle (z5232949)
//
// Modified on 2018-??-??
// Tutor's name (dayHH-lab)
//
// Version 1.0.1: Fix issues with spacing and indentation.
// Version 1.0.0: Assignment released.

#include "mandelbrot.h"
#include "pixelColor.h"

// This function should take a number (of steps taken to escape the
// Mandelbrot set), and convert it to a color.
//
// You have artistic licence here, 
// so make your Mandelbrot look amazing.
struct pixel pixelColor(int steps) {
    struct pixel color = {
        .red = steps,
        .green = steps,
        .blue = steps,
    };

    // TODO: Change the color of the pixel for different numbers of
    // steps.
    
    /*
    //RED, BLUE, YELLOW, WHITE AND BLACK
    
    //initialize
    int cl = 0;
    
    if (steps == NO_ESCAPE)
    {
        color.red = 0;
        color.blue = 0;
        color.green = 0;
    }
    else if (steps > 75)
    {
        //cyan-blue
        color.red = 170;
        color.blue = 255;
        color.green = 170;
    }
    else if (steps > 60)
    {
        //white
        color.red = 255;
        color.blue = 255;
        color.green = 255;
    }
    else if (steps > 40)
    {
        //yellow
        color.red = 255;
        color.blue = 0;
        color.green = 255;
    }
    else if (steps > 20)
    {
        //orange-red
        color.red = 255;
        color.blue = 0;
        color.green = 13;
    }
    else
    {
        //different shades of red
        cl = 10 * steps;
        color.red = cl;
        color.blue = 0;
        color.green = 0;
    }
    */
    
    /*
    //ORANGE AND YELLOW COLOUR COMBINATION
    //initialize
    int cl = 0;
    
    //choose colour
    if (steps == NO_ESCAPE)
    {
        //black
        color.red = 0;
        color.blue = 0;
        color.green = 0;
    }
    else if (steps > 55)
    {
        //yellow
        color.red = 255;
        color.blue = 0;
        color.green = 215;
    }
    else if (steps > 50)
    {
        //black
        color.red = 0;
        color.blue = 0;
        color.green = 0;
    }
    
    else if (steps > 15)
    {
        //orange-red
        color.red = 255;
        color.blue = 0;
        color.green = 13;
    }
    
    else
    {
        //different shades of yellow
        cl = 5 * steps;
        color.red = cl;
        color.blue = 0;
        color.green = cl/4;
    }
    */
    
    /*
    
    //BLACK WHITE AND SHADES OF GREY
    
    //initialize
    int cl = steps;
    
    //choose shade
    if (steps == NO_ESCAPE)
    {
        cl = 0;
    }
    else if (steps > 45)
    {
        cl = 170;
    }
    else if (steps > 35)
    {
        cl = 120;
    }
    else if (steps > 20)
    {
        cl = 70;
    }
    else
    {
        cl = 20;
    }
    
    //set colour
    color.red = cl;
    color.blue = cl;
    color.green = cl;
    */
    
    /*
    //cocoa and purple
    
    //initialize
    int cl = steps;
    
    //choose colour
    if (steps == NO_ESCAPE)// || steps > 200)
    {
        //black
        color.red = 42;
        color.blue = 27;
        color.green = 14;
    }
    else 
    {
        color.red = (int)(cl);
        color.blue = (int)(cl);
        color.green = 0;//(int)(2*cl/3);
    }
    */
    
    /*
    //ICE BLUE
    
    //initialize
    int cl = steps;
    
    //choose colour
    if (steps == NO_ESCAPE)// || steps > 200)
    {
        //black
        color.red = 0;
        color.blue = 0;
        color.green = 0;
    }
    else 
    {
        color.red = (int)(2/3*cl);
        color.blue = cl;
        color.green = (int)(2*cl/3);
    }
    */
    
    
    //Almondbread?
    
    //initialize
    int cl = steps;
    
    //choose colour
    if (steps == NO_ESCAPE)// || steps > 200)
    {
        //black
        color.red = 0;
        color.blue = 0;
        color.green = 0;
    }
    else
    {
        
        color.red = cl;
        color.blue = 0;
        color.green = (int)(cl/1.5);
    }
    
    
    return color;
}
