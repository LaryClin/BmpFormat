
#include <stdio.h>
#include <stdlib.h>


#pragma pack(push, 1)
typedef struct{
unsigned short type;
unsigned long size;
unsigned short reserved1;
unsigned short reserved2;
unsigned long offsetbits;
}bmpheader;
#pragma pack(pop)
typedef struct{
unsigned long headersize;
unsigned long width;
unsigned long height;
unsigned short planes;
unsigned short bitcount;
unsigned long compression;
unsigned long sizeimage;
unsigned long xpelspermeter;
unsigned long ypelspermeter;
unsigned long colorsused;
unsigned long colorsimportant;
unsigned char *palette;
unsigned char *pixels;
}bmpinfo;

void readbmpheader(char *bitmapfilename)
{
FILE *bitmapfile;
bmpheader header;
bmpinfo info;
bitmapfile=fopen(bitmapfilename,"rb");
if(bitmapfile == NULL)
{
   printf("Error when reading...!\n");
   exit(-1); 
}

fread(&header,sizeof(header),1,bitmapfile);
printf("Taille de bitmap en octets:\n");
printf("%d\n",header.size);
printf("Taille de bitmap en bits:\n");
printf("%d\n",header.size*8);
fread(&info,sizeof(bmpinfo),1,bitmapfile);
printf("Largeur de l'image:\n");
printf("%d\n",info.width);
printf("Hauteur de l'image:\n");
printf("%d\n",info.height);

fclose(bitmapfile);

}



int main()
{
readbmpheader("image.bmp");
getchar();
return 0;
}
