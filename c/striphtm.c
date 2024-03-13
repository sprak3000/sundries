/* Program to strip all HTML tags from a document
   Written by Luis A. Cruz
   Last Revision:  11 August 1995 */

#include <stdio.h>
#include <conio.h>

int main(int argc, char *argv[])
{
 FILE *infile, *outfile;
 char cur_char, choice, user_filename[80];
 int dot_num = 0;

/* Terminate program if less than 3 arguments */
 if(argc < 3)
 {
  printf("\a\aSTRIPHTML by Luis A. Cruz\nVersion 1.5\n \
	 \nusage:  striphtm <input file> <output file>\n");
  return 1;
 }

/* Terminate program if input file cannot be opened */
 if((infile = fopen(argv[1], "r")) == NULL)
 {
  printf("\a\aSTRIPHTML by Luis A. Cruz\nVersion 1.5\n \
	\nUnable to open input file.  Program terminated.\n");
  return 1;
 }

/* Terminate program if output file cannot be opened */
 else if((outfile = fopen(argv[2], "w")) == NULL)
 {
  printf("\a\aSTRIPHTML by Luis A. Cruz\nVersion 1.5\n \
	\nUnable to open output file.  Program terminated.\n");
  return 1;
 }

 clrscr();
 printf("STRIPHTML by Luis A. Cruz\nVersion 1.5\n\n");
 printf("\n\nPlease stand by.  Processing file");

/* Process file */
 while(!feof(infile))
 {
  if((dot_num % 3500) == 0) putch('.');

/* If '<' seen, don't write to file until '>' is found */
  if((cur_char = fgetc(infile)) == '<')
  {
   while((cur_char = fgetc(infile)) != '>') {} /* Get all of tag */
  }

/* Else write characters to output file */
  else
  {
   fputc(cur_char, outfile);
  }
  dot_num++;
 }

 printf("\a\nDone!\n");

/* Close all files */
 fclose(infile);
 fclose(outfile);
 return 0;
}