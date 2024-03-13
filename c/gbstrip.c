#include <stdio.h>

#define LENGTH 512

int main(int argc, char *argv[])
{
   FILE *out, *in;
   char buf[LENGTH];
   long curpos, length;

   if(argc < 2)
   {
    fprintf(stderr, "\aUsage:  gbstrip <filename>");
    exit(1);
   }

   if((in = fopen(argv[1], "rb")) == NULL) /* open file TEST.$$$ */
   {
    fprintf(stderr, "Cannot open input file.\n");
    return 1;
   }

   if((out = fopen("output.rom", "wb")) == NULL) /* open file TEST.$$$ */
   {
    fprintf(stderr, "Cannot open output file.\n");
    return 1;
   }

   curpos = ftell(in);
   fseek(in, 0L, SEEK_END);
   length = ftell(in);
   fseek(in, curpos, SEEK_SET);

   fseek(in, LENGTH, SEEK_SET);
   length -= LENGTH;

   while(length > 0)
   {
    if(length < LENGTH)
    {
     fread(buf, length, 1, in);
     fwrite(buf, length, 1, out);
    }
    else
    {
     fread(buf, LENGTH, 1, in);
     fwrite(buf, LENGTH, 1, out);
    }
    length -= LENGTH;
   }

   fclose(in); /* close file */
   fclose(out); /* close file */
   return 0;
}
