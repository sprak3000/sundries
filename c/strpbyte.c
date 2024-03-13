#include <stdio.h>
#include <stdlib.h>

#define LENGTH 512

int main(int argc, char *argv[])
{
   FILE *out, *in;
   char *buf;
   long curpos, length, trim_size;

   if(argc < 4)
   {
    fprintf(stderr, "\aUsage:  strpbyte <# of bytes to strip> <input filename> <output filename>");
    exit(1);
   }

   if((in = fopen(argv[2], "rb")) == NULL) /* open file TEST.$$$ */
   {
    fprintf(stderr, "Cannot open input file.\n");
    return 1;
   }

   if((out = fopen(argv[3], "wb")) == NULL) /* open file TEST.$$$ */
   {
    fprintf(stderr, "Cannot open output file.\n");
    return 1;
   }

   trim_size = atol(argv[1]);
   curpos = ftell(in);
   fseek(in, 0L, SEEK_END);
   length = ftell(in);
   fseek(in, curpos, SEEK_SET);

   fseek(in, trim_size, SEEK_SET);
   length -= trim_size;

   while(length > 0)
   {
    if(length < LENGTH)
    {
     buf = malloc(length);
     fread(buf, length, 1, in);
     fwrite(buf, length, 1, out);
     length -= length;
     free(buf);
    }
    else
    {
     buf = malloc(LENGTH);
     fread(buf, LENGTH, 1, in);
     fwrite(buf, LENGTH, 1, out);
     length -= LENGTH;
     free(buf);
    }
   }

   fclose(in); /* close file */
   fclose(out); /* close file */
   return 0;
}
