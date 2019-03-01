// Mandelbrot generation functions
// mandelbrot.h
//
// You can compile the full server with the command
// dcc -o mandelbrotServer server.c mandelbrot.c pixelColor.c
// However, server.c files has to be created first.

// Size of each image
// Each tile should be TILE_SIZE pixels wide and TILE_SIZE pixels tall.
#define TILE_SIZE 512

// Escape Steps
//
// The maximum number of steps that we loop to test if a complex number
// is in the mandelbrot set.
//
// Any number that is assumed to be in the mandelbrot set has NO_ESCAPE
// number of steps.
#define MAX_STEPS 256
#define NO_ESCAPE -1

// Structs used by the program

// BMP is made of pixels
struct pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

// Complex Numbers
// Complex number is (re + im * i)
struct complex {
    double re;
    double im;
};

// To create the mandelbrot set calling server.c functions
void serveMandelbrot(
    struct pixel pixels[TILE_SIZE][TILE_SIZE],
    char *requestPath
);

// Create the Mandelbrot pattern.
void drawMandelbrot(
    struct pixel pixels[TILE_SIZE][TILE_SIZE],
    struct complex center,
    int z
);

// Count the number of steps for c to escape the mandelbrot set.
int escapeSteps(struct complex c);
