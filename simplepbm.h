/* handle pbm ascii image format data structures input/output */
#ifndef PBM_H
#define PBM_H
#define MDIM 64 // fixed max dimension of buffers & arrays
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int ddata[MDIM][MDIM] =  { {1,0,0,0,0,0,0,0,0,0,0}, \
                           {0,1,0,0,0,0,0,0,0,0,0}, \
                           {0,0,1,0,0,0,0,0,0,0,0}, \
                           {0,0,0,1,0,0,0,0,0,0,0}, \
                           {0,0,0,0,1,0,0,0,0,0,0}, \
                           {0,0,0,0,0,1,0,0,0,0,0}, \
                           {0,0,0,0,0,0,1,0,0,0,0}, \
                           {0,0,0,0,0,0,0,1,0,0,0}, \
                           {0,0,0,0,0,0,0,0,1,0,0}, \
                           {0,0,0,0,0,0,0,0,0,1,0}, \
                           {0,0,0,0,0,0,0,0,0,0,1} };

FILE *ifptr; // define a pointer to input file
FILE *ofptr; // define a pointer to output file
char es[MDIM];
char buff[MDIM];
int ch, i, j, ret;
/* name, surname, id, address and age */
struct pbmImage{
    char format[3];
    char ** comment;
    int width;
    int height;
    int data[MDIM][MDIM];
};

typedef struct pbmImage pbmImage;

/* write the pbm image in memory on file */
int write_pbm(pbmImage *pbm, const char *outfile);   

/* read the pbm image from file into volatile memory */
int read_pbm(pbmImage *pbm, const char *infile);   

int arrcpy(int destdata[MDIM][MDIM], int srcdata[MDIM][MDIM], int nrow, int ncol);

/* set default data into pbm image struct */
int set_pbm_default(pbmImage *image);

#endif  //PBM_H
