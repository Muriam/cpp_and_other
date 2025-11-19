//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
/* преобразование картинки из цветной(24-битный пиксель) в черно-белую */
  Graphics::TBitmap *Bitmap = new Graphics::TBitmap();
  Bitmap->Assign(Image1->Picture);

  Image1->Canvas->FillRect(Image1->Canvas->ClipRect);

  if (Bitmap->PixelFormat == pf24bit)
  {
    Byte *ptr, R, G, B, F;
    for(int y = 0; y < Bitmap->Height; y++)
    {
      ptr = (Byte*)Bitmap->ScanLine[y];
      for (int x = 0; x < Bitmap->Width; x++)
      {
        B = *(ptr + x*3);
        G = *(ptr + x*3+1);
        R = *(ptr + x*3+2);
        F = (R + G + B) / 3;

        Bitmap->Canvas->Pixels[x][y]=(TColor) RGB(F, F, F);
      }
    }
    Image1->Canvas->Draw(0, 0, Bitmap);
  }

/* сохранение черно-белой картинки отдельным файлом в формате bmp */
  Image1->Picture->SaveToFile("gvozdika_new.bmp");

  delete Bitmap;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
/* закрытие приложения */
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        /* вывод характеристик изображения */
        TImage* Source= new TImage(this);
        Source->Picture->LoadFromFile("gvozdika_new.bmp");
        Source->AutoSize = true;

        int iSourceSize = Source->Width;
        Edit1->Text = IntToStr(iSourceSize);
        
        int iSourceSize2 = Source->Height;
        Edit2->Text = IntToStr(iSourceSize2);
        
        //http://docwiki.embarcadero.com/Libraries/Rio/en/Vcl.Graphics.TPixelFormat
        String bpp[9] = {"DBB", "1", "4", "8", "15", "16", "24", "32", "N/A"};
        Edit3->Text = bpp[(int)(Source->Picture->Bitmap->PixelFormat)];
        
        Edit4->Text = GetBigFileSize("gvozdika_new.bmp");
}
//---------------------------------------------------------------------------

