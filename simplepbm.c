/* handle pbm ascii image format data structures input/output */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simplepbm.h"

/* write the pbm image in memory on file */
int write_pbm(pbmImage *pbm, const char *outfile){
     strcat(es, ": Can't open file "); strcat(es, outfile); strcat(es, " for writing\n");
     ofptr = fopen(outfile,"w");
     if (ofptr == NULL){
       fprintf(stderr,"%s: Error OPENING FILE for writing: err msg = %s\n","write_pbm()" ,strerror(errno));
       fprintf(stderr,"%s: fopen() failed in file %s at line # %d\n","write_pbm()", __FILE__,__LINE__);
       perror(es); // then handle the error
       fprintf(stderr,"%s: exit value = %d : exiting\n","write_pbm()", EXIT_FAILURE);
       return EXIT_FAILURE;
     } else
     {
       ret = ferror ( ofptr  );
     }
     strcpy(es, __FILE__);
     fprintf(stderr, "%s: file %s correctly open for writing\n", es, outfile);
#ifdef DEBUG
     fprintf(stderr, "%s: PNM image format is:%s\n","write_pbm()", pbm->format);
     fprintf(stderr, "%s: PNM image comment:%s\n","write_pbm()", pbm->comment[i]);
     fprintf(stderr, "%s: PNM image width:%d\n","write_pbm()", pbm->width);
     fprintf(stderr, "%s: PNM image height:%d\n","write_pbm()", pbm->height);
#endif
     i=0;
     fprintf(ofptr,"%s\n", pbm->format);
     fprintf(ofptr,"%s\n", pbm->comment[i]);
     fprintf(ofptr,"%d %d\n", pbm->width, pbm->height);
    /* write image dimensions on stdout width height */
        /* write image array on stdout */
     for (i=0; i<pbm->height; i++){
         for (j=0; j<pbm->width; j++){
            fprintf(ofptr,"%d ", pbm->data[i][j]);
         }
         puts("");
     }
    fclose(ofptr);
    return 0;
}

/* read the pbm image from file into volatile memory */
int read_pbm(pbmImage *pbm, const char *infile){
     strcat(es, ": Can't open file "); strcat(es, infile); strcat(es, " for reading\n");
     ifptr = fopen(infile,"r");
     if (ifptr == NULL){
       fprintf(stderr,"Error OPENING FILE for reading: err msg = %s\n", strerror(errno));
       fprintf(stderr,"fopen() failed in file %s at line # %d\n", __FILE__,__LINE__);
       perror(es); // then handle the error
       fprintf(stderr,"exit value = %d : exiting\n", EXIT_FAILURE);
       return EXIT_FAILURE;
     } else
     {
        ret = ferror ( ifptr  );
        strcpy(es, __FILE__);
        fprintf(stderr, "%s: file %s correctly open for reading\n", es, infile);
    #ifdef DEBUG
        printf("PNM image format is:%s\n", pbm->format);
        printf("PNM image comment:%s\n", pbm->comment[i]);
        printf("PNM image width:%d\n", pbm->width);
        printf("PNM image height:%d\n", pbm->height);
    #endif
        line = (char *) malloc(MDIM*sizeof(char));
        line[0] = '\0';
        len = 0;
#ifdef DEBUG
        while ((read = getline(&line, &len, ifptr)) != -1) {
            fprintf(stderr, "Retrieved line of length %zu:, value: %s\n", read, line);
        }
#endif

        i=0;
        if ((read = getline(&line, &len, ifptr)) != -1){
            fprintf(stderr, "Retrieved pbm format line, length %zu, value: %s\n", read, line);
            strncpy(pbm->format, line, 3);
        } else {
            perror("read_pbm() error in reading format line ");
        }

        if ((read = getline(&line, &len, ifptr)) != -1){
            fprintf(stderr, "Retrieved pbm comment line, length %zu, value: %s\n", read, line);
            strcpy(pbm->comment[i], line);
        } else {
            perror("read_pbm() error in reading comment line ");
        }

        if ((read = fscanf(ifptr, "%d %d", &pbm->width, &pbm->width )) != -1){
            fprintf(stderr, "Retrieved pbm dimensions line, n.values %zu, width: %d, height: %d \n", read, pbm->width, pbm->width);
        } else {
            perror("read_pbm() error in reading image dimensions line ");
        }

        for (i=0; i<pbm->height; i++){
            for (j=0; j<pbm->width; j++){
                if ((read = fscanf(ifptr, "%d", &pbm->data[i][j])) != -1){
                    fprintf(stderr, "Retrieved pbm image element, n.values %zu, row: %d, column: %d, val: %d\n", read, i, j, pbm->data[i][j] );
                } else {
                    perror("read_pbm() error in reading image dimensions line ");
                }
            }
            puts("");
        }

#ifdef DEBUG
        printf("%s\n", pbm->format);
        printf("%s\n", pbm->comment[i]);
        printf("%d %d\n", pbm->width, pbm->height);
        /* write image dimensions on stdout width height */
        arrcpy(pbm->data, ddata, 11, 11);
        /* write image array on stdout */
        for (i=0; i<pbm->height; i++){
            for (j=0; j<pbm->width; j++){
                printf("%d ", pbm->data[i][j]);
            }
            puts("");
        }
#endif // DEBUG
     }
     free(line);
     fclose(ifptr);
     return 0;
}


int dump_pbm(pbmImage *pbm){
#ifdef DEBUG
     fprintf("PNM image format is:%s\n", pbm->format);
     fprintf("PNM image comment:%s\n", pbm->comment[i]);
     fprintf("PNM image width:%d\n", pbm->width);
     fprintf("PNM image height:%d\n", pbm->height);
#endif
     for (i=0; i<pbm->height; i++){
         for (j=0; j<pbm->width; j++){
            printf("%d", pbm->data[i][j]);
         }
         puts("");
     }

    return 0;
}

int arrcpy(int destdata[MDIM][MDIM], int srcdata[MDIM][MDIM], int nrow, int ncol){
        for (i=0; i<nrow; i++){
            for (j=0; j<ncol; j++){
                destdata[i][j] = srcdata[i][j];
         }
     }
    return 0;
}


int set_pbm_default(pbmImage *image){
    strcpy(image->format, "P1");
    image->comment[0] = "# PBM image generated by fralaz1971 libsimplepbm";
    image->width =  11;
    image->height = 11;
    arrcpy(image->data, ddata, 11, 11);
    return 0;
}
