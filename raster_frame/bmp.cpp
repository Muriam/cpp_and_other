//---------------------------------------------------------------------------

#pragma hdrstop
#include "bmp.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Tbmp::Tbmp()
{
    buf = 0;
    bfsize = 0;
    hight = 0, width = 0;
};

Tbmp::~Tbmp()
{
    delete [] buf;
};

/* открытие файла для чтения */
void Tbmp::Open(char *image_1)
{
    FILE *ptrFile;
    ptrFile = fopen(image_1, "rb");           //открытие файла для чтения
    int handle = _fileno(ptrFile);				   
    bfsize = filelength(handle);	      //определение размера файла
    buf = new byte[bfsize];       	      //выделение буфера
    fread(buf, bfsize, 1, ptrFile);	      //чтение всей информации из файла
    fclose(ptrFile);			      //закрытие файла
};

/* Вычисление количества пустых байтов в конце строки, выровненной по 32-битной границе */
int Tbmp::Offset()
{
    int tmpWidth = width;
    int offset = 0;
	
    while (tmpWidth % 4 != 0)
    {
        tmpWidth++;
        offset++;
    }
	
    return offset;
};

/* создание рамки и сохранение картинки с рамкой в новый файл */
void Tbmp::saveResult(char *image_2)
{
    FileHeader head;
    FILE *ptrFile2;
  
    ptrFile2 = fopen(image_2, "wb");	       //открытие файла для записи
    fwrite(buf, bfsize, 1, ptrFile2);	       //запись всей информации в новый файл
    fclose(ptrFile2);			       //закрытие файла
  
    ptrFile2 = fopen(image_2, "rb+");          //открытие нового файла для чтения и записи
    fread(&head, sizeof(head), 1, ptrFile2);   //чтение заголовка
    width = head.biwidth;		       //ширина картинки в пикселях
    hight = head.biheight;		       //высота картинки в пикселях
    fseek(ptrFile2, head.bfoffbits, SEEK_SET); //смещение к растру
    int offset = Offset();                     //вызов функции Offset
    const int pix = 15;                        //ширина рамки         
    byte p;
    /* рисование рамки */
    for (int i = 0; i < hight; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i < pix || i >= hight - pix || j < pix || j >= width - pix)
            {
                p = (byte) random(256);
                fwrite(&p, 1, 1, ptrFile2);
            } 
	        else
                fseek(ptrFile2, 1, SEEK_CUR);
        }
        fseek(ptrFile2, offset, SEEK_CUR);     //пропуск пустых байтов в конце строки
    }
    fclose(ptrFile2);                          //закрытие файла
};
