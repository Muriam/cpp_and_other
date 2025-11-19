//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include "Unit1.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Tbmp head_file;

//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------

char image_1[] = "dream.bmp";
char image_2[] = "frame.bmp";

/* вызов методов из модуля bmp.cpp */
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  head_file.Open(image_1);                 //вызов метода Open
  head_file.saveResult(image_2);		   //вызов метода saveResult
  Image1->Picture->LoadFromFile(image_2);  //загрузка результирующей картинки, с рамкой, из второго файла (frame) компонент Image1
}
//---------------------------------------------------------------------------

/* загрузка картинки из первого файла (dream) в комплнент Image1 */
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    Image1->Picture->LoadFromFile(image_1);
}
//---------------------------------------------------------------------------

/* закрытие приложения */
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

