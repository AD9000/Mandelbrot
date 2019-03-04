# Mandelbrot Set
## Description:
Program to calculate the mandelbrot set and print it to the screen that I developed in while taking a course at UNSW.

The function escapeSteps() is used to calculate whether a point exists in the mandelbrot set or not.
The function drawMandelbrot() is then used to call the functions in server.c which then converts the set into a 512 x 512 pixel bmp file. A range of bmp files are used to create a coherent image on the screen.

The pixelColor.h and pixelColor.c files are used to set the colors of the mandelbrot set.
By setting the value of zoom variable, the picture generated can be zoomed in or out.

## Other Files:
1. chessMandel.c is used to create a primitive version of the mandelbrot set with white and black colors only.
2. The numbered bmp files are some of the mandelbrot sets produced during testing.
3. xanadu.h is used to set the centre of the 512 x 512 bmp image of the mandelbrot set.

## Notes:
I am currently trying to develop a server.c file to be able to complete this project and display the mandelbrot set on the server of your choice.


