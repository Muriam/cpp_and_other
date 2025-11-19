//---------------------------------------------------------------------------

#ifndef bmpH
#define bmpH
#include <vcl.h>
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
//---------------------------------------------------------------------------

struct FileHeader
{
  short bftype;         // тип файла
  long  temp;           // размер файла
  short rez1, rez2;     // не используется
  long  bfoffbits;      // смещение данных битового образа от заголовка в байтах
  long  bisize;		      // размер картинки
  long  biwidth;        // ширина картинки в пикселях
  long  biheight;	      // высота картинки в пикселях
};

class Tbmp
{
private:
  byte *buf;
  long  bfsize;
  int hight, width;
  int bfoffbits;
  int Offset();

public:
  Tbmp();
  ~Tbmp();
  void Open(char *image_1);
  void saveResult(char *image_2);
};

#endif
