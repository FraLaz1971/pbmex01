#include <stdio.h>
#include "simplepbm.h"

int main(int argc, char **argv){
    char c1[MDIM] = "# This is an example bitmap of the symbol of peace";
    char *infilename = "peace.pbm";
    char *outfilename = "out.pbm";
    fprintf(stderr,"%s: program START!\n", argv[0]);
    pbmImage mypbm;
    strcpy(mypbm.format, "P1");
    mypbm.comment = (char **) malloc(1 * MDIM * sizeof(char));
    mypbm.comment[0] = (char*)&c1;
    mypbm.width  = 11;
    mypbm.height = 11;
    set_pbm_default(&mypbm);
    read_pbm(&mypbm, infilename);
    write_pbm(&mypbm, outfilename);
    fprintf(stderr,"%s: program END!\n", argv[0]);
    return 0;
}

