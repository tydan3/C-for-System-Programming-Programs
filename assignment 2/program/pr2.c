#include <stdio.h>
#include <string.h>
#include <math.h>

/** 
Daniel Ty
TCSS 333
Programming assignment 2
Tested in cssgate server
*/      

#define HEADER_SIZE 54

int main(void) {
    char inputFile[32];
    int height;
    int width;

    // user input for file name
    printf("---\nEnter the filename: ");
    scanf("%s", inputFile);
    // append .bmp to file name
    char bmp[5] = ".bmp";
    strcat( inputFile, bmp);
    // user input for height and width
    printf("Enter height and width (in pixels): ");
    scanf("%i%i", &height, &width);

    // opens files
    FILE *infile = fopen(inputFile, "rb"); 
    FILE *outSepia = fopen("sepia.bmp", "wb");
    FILE *outPop = fopen("pop.bmp", "wb");
    FILE *outFlip = fopen("flip.bmp", "wb");
    FILE *outMirror = fopen("mirror.bmp", "wb");
    FILE *outSurprise = fopen("surprise.bmp", "wb");

    
    // sets up an array for bmp header
    char header[HEADER_SIZE]; 
    // sets up a matrix for the image
    unsigned char pixels[height][width * 3];
    unsigned char newPixels[height][width * 3];

    // reads header from the image into the header array
    fread( header, 1 , HEADER_SIZE , infile);
    // reads image into the matrix
    fread( pixels, 1 , height * width * 3 , infile);


    int r,c;
    // Sepia
    // iterates over the image pixel by pixel and applies sepia algorithm
    for( r = 0; r < height; r++) {
        for ( c = 0; c < width * 3; c += 3) {

            // sepia algorithm 
            double newValueB = pixels[r][c+2] * 0.272 + pixels[r][c+1] * 0.534
                + pixels[r][c] * 0.131;
            if (newValueB > 255) {
                newValueB = 255;
            }
            double newValueG = pixels[r][c+2] * 0.349 + pixels[r][c+1] * 0.686
                + pixels[r][c] * 0.168;
            if (newValueG > 255) {
                newValueG = 255;
            }
            double newValueR = pixels[r][c+2] * 0.393 + pixels[r][c+1] * 0.769
                + pixels[r][c] * 0.189;
            if (newValueR > 255) {
                newValueR = 255;
            }

            // assign new colors
            char newBlue = newValueB;
            char newGreen = newValueG;
            char newRed = newValueR;

            newPixels[r][c] = newBlue;
            newPixels[r][c + 1] = newGreen;
            newPixels[r][c + 2] = newRed;                     
        }
    }
    // writes the header to the sepia output file
    fwrite( header, sizeof(char)  , HEADER_SIZE  ,  outSepia);
    // writes the matrix to the sepia output file
    fwrite( newPixels, sizeof(char)  , height * width * 3  ,  outSepia);


    // Color Pop
    // middle pixel rgb
    double middleB = pixels[height / 2][(width / 2) * 3];
    double middleG = pixels[height / 2][(width / 2) * 3 + 1];
    double middleR = pixels[height / 2][(width / 2) * 3 + 2]; 
    // iterates over the image pixel by pixel and applies color pop algorithm
    for( r = 0; r < height; r++) {
        for ( c = 0; c < width * 3; c += 3) {
            double blueValue = pixels[r][c];
            double greenValue = pixels[r][c + 1];
            double redValue = pixels[r][c + 2];

            double blueDiffSquared = (blueValue - middleB) * (blueValue - middleB);
            double greenDiffSquared = (greenValue - middleG) * (greenValue - middleG);
            double redDiffSquared = (redValue - middleR) * (redValue - middleR);
            // if distance from middle is greater than 55, change pixel to greyscale
            if (sqrt(redDiffSquared + greenDiffSquared + blueDiffSquared) > 55) {
                double average = (blueValue + greenValue + redValue) / 3;
                blueValue = average;
                greenValue = average; 
                redValue = average; 
            }

            newPixels[r][c] = blueValue;
            newPixels[r][c + 1] = greenValue;
            newPixels[r][c + 2] = redValue;                     
        }
    }
    // writes the header to the pop output file
    fwrite( header, sizeof(char)  , HEADER_SIZE  ,  outPop);
    // writes the matrix to the pop output file
    fwrite( newPixels, sizeof(char)  , height * width * 3  ,  outPop);


    // Vertical Axis Flip
    // iterates over the image pixel by pixel and applies vertical axis flip algorithm
    for( r = 0; r < height; r++) {
        // iterate over first half of row
        for ( c = 0; c < (width * 3) / 2; c += 3) {
            // index of corresponding right side pixel
            int rightIndex = (width - 1) * 3 - c;
            
            // left side rgb
            double blueValue = pixels[r][c];
            double greenValue = pixels[r][c + 1];
            double redValue = pixels[r][c + 2];
            // assign to right side rgb
            newPixels[r][rightIndex] = blueValue;
            newPixels[r][rightIndex + 1] = greenValue;
            newPixels[r][rightIndex + 2] = redValue;

            // right side rgb
            blueValue = pixels[r][rightIndex];
            greenValue = pixels[r][rightIndex + 1];
            redValue = pixels[r][rightIndex + 2];
            // assign to left side rgb
            newPixels[r][c] = blueValue;
            newPixels[r][c + 1] = greenValue;
            newPixels[r][c + 2] = redValue;                    
        }
    }
    // writes the header to the flip output file
    fwrite( header, sizeof(char)  , HEADER_SIZE  ,  outFlip);
    // writes the matrix to the flip output file
    fwrite( newPixels, sizeof(char)  , height * width * 3  ,  outFlip);


    // Horizontal Axis Mirror
    // iterates over the image pixel by pixel and applies horizontal axis mirror algorithm
    int top = height - 1;
    for( r = 0; r < height; r++) {
        for ( c = 0; c < width * 3; c += 3) {
            double blueValue;
            double greenValue;
            double redValue;

            if (r < height / 2) { // rgb of lower half of image
                // copy top row of original image
                blueValue = pixels[top][c];
                greenValue = pixels[top][c + 1];
                redValue = pixels[top][c + 2];

            } else { // rgb of upper half image
                // same as original image
                blueValue = pixels[r][c];
                greenValue = pixels[r][c + 1];
                redValue = pixels[r][c + 2];
            }

            // assign new pixels' rgb
            newPixels[r][c] = blueValue;
            newPixels[r][c + 1] = greenValue;
            newPixels[r][c + 2] = redValue;
        }
        if (r < height / 2) // decrement top 
            top--;
    }
    // writes the header to the mirror output file
    fwrite( header, sizeof(char)  , HEADER_SIZE  ,  outMirror);
    // writes the matrix to the mirror output file
    fwrite( newPixels, sizeof(char)  , height * width * 3  ,  outMirror);


    // Surprise (top half of image mirrors the bottom half)
    // iterates over the image pixel by pixel and applies surprise algorithm
    int bottom = (height - 1) / 2;
    for( r = 0; r < height; r++) {
        for ( c = 0; c < width * 3; c += 3) {
            double blueValue;
            double greenValue;
            double redValue;

            if (r > height / 2) { // rgb of upper half image
                // copy bottom half starting at its top, going down
                blueValue = pixels[bottom][c];
                greenValue = pixels[bottom][c + 1];
                redValue = pixels[bottom][c + 2];

            } else { // rgb of lower half of image
                // same as original image
                blueValue = pixels[r][c];
                greenValue = pixels[r][c + 1];
                redValue = pixels[r][c + 2];
            }

            // assign new pixels' rgb
            newPixels[r][c] = blueValue;
            newPixels[r][c + 1] = greenValue;
            newPixels[r][c + 2] = redValue;
        }
        if (r > height / 2)
            bottom--;
    }
    // writes the header to the surprise output file
    fwrite( header, sizeof(char)  , HEADER_SIZE  ,  outSurprise);
    // writes the matrix to the surprise output file
    fwrite( newPixels, sizeof(char)  , height * width * 3  ,  outSurprise);

    // close files
    fclose(infile);
    fclose(outSepia);
    fclose(outPop);
    fclose(outFlip);
    fclose(outMirror);
    fclose(outSurprise);

    
    printf("Done. Check the generated images.\n---\n");
    return 0;

}