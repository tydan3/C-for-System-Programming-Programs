#include <stdio.h>

/* This program changes the coloring of the image.
   Each pixel is made from a combination of Red, Green, Blue.
   For each of these 3 colors, there is a number indicating the intensity or brightness.
   These numbers range from 0 (none) to 255 (full).  The program interchanges 
   the intensities of the green and blue components. 
   The blue sky becomes green.   The green tree becomes purple/blue.
   The red things remain red.
*/      

#define HEADER_SIZE 54
#define HEIGHT 160
#define WIDTH 240

int main(void) {


    // opens files
    FILE *infile = fopen("uwt.bmp", "rb"); 
    FILE *outfile = fopen("newtest1.bmp", "wb");  
    
    // sets up an array for bmp header
    char header[HEADER_SIZE]; 
    // sets up a matrix for the image
    unsigned char pixels[HEIGHT][WIDTH * 3];

    // reads header from the image into the header array
    fread( header, 1 , HEADER_SIZE , infile);
    // reads image into the matrix
    fread( pixels, 1 , HEIGHT * WIDTH * 3 , infile);

    int r,c;

    // iterates over the image pixel by pixel and interchanges green and blue components
    for( r = 0; r < HEIGHT; r++) {
         for ( c = 0; c < WIDTH * 3; c += 3) {
             char temp = pixels[r][c];
             
             pixels[r][c] = pixels[r][c+1];
             pixels[r][c+1] = temp;
         }
    }

    // writes the header to the output file
    fwrite( header, sizeof(char)  , HEADER_SIZE  ,  outfile);
    // writes the matrix to the output file
    fwrite( pixels, sizeof(char)  , HEIGHT * WIDTH * 3  ,  outfile);

    fclose(infile);
    fclose(outfile);

    return 0;

}
