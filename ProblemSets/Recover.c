#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//write a program to recover the photos
/*
the first three bytes of JPEGs are: 0xff 0xd8 0xff
The fourth byte, meanwhile, is either 0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5,
0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, or 0xef.


Opening memory card
Repeat until end of card:
    Read 512 bytes into a buffer
    If start of new JPEG
      If first JPEG
      else
    Else
    If already found JPEG
Close any remainingfiles


//Read Files = fread
//Write Files = fwrite
fread(data, size, number, inptr);
-data: pointer to where to store data you're reading, likely some buffer or some kind e.g. array
-size: size of each element to read
-number: number of elements to read all at once
-inptr: File * to read from, e.g. the memeory card in 512 byte chunks

*/

//define size of each buffer
#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Usage: ./recover image\n");
    return 1;
  }

  //open memory card to read file, if no such file, exit
  FILE *input_file = fopen(argv[1], "r");
  if (!input_file)
  {
    return 1;
  }

  //create buffer, each buffer is 512 bytes
  unsigned char buffer[BUFFER_SIZE];

  //new_file name is a string of 7 chars + \0, e.g. "000.jpg"
  char new_file[8];

  FILE *new_file_img;

  int jpgCount = 0;

  //loop through memory card, read 1 buffer at a time (read 512 bytes at a time)
  while (fread(buffer, BUFFER_SIZE, 1, input_file) == 1)
  {
    // if is a JPEG
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
    {
      if ((buffer[3] & 0xf0) == 0xe0) //check if 4th ele is also a jpg code
      {
        if (jpgCount == 0) //if there was no JPEG found before
        {
          //make this file the 1st JPEG and print to check
          sprintf(new_file, "%03i.jpg", jpgCount);

          //open to write the file, make a new JPEG file
          new_file_img = fopen(new_file, "w");

          //Write 512 bytes into new file image
          fwrite(buffer, BUFFER_SIZE, 1, new_file_img);

          jpgCount++; //add one to count
        }
        else if (jpgCount > 0)
        {
          fclose(new_file_img); //close the previous file

          //name new file and print to check
          sprintf(new_file, "%03i.jpg", jpgCount);

          //open to write the file, make a new JPEG file
          new_file_img = fopen(new_file, "w");

          //Write 512 bytes into new file image
          fwrite(buffer, BUFFER_SIZE, 1, new_file_img);

          jpgCount++; //add one to count
        }
      }
    }
    else if (jpgCount > 0)
    {
      fwrite(buffer, BUFFER_SIZE, 1, new_file_img);
    }
  }
  // Close files
  fclose(input_file);
  fclose(new_file_img);
  return 0;
}
