//---------------------------------------------------------------------------

#include <vcl.h>


#include <stdlib.h>
#include <stdio.h>


#pragma hdrstop

#include "UnitMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
}


int __fastcall TFormMain::writeUshort( FILE *out, unsigned short value )
{

	fputc( (unsigned char)( value & 0xff ), out );
	fputc( (unsigned char)( ( value >> 8 ) & 0xff ), out );

	return 0;
}

int __fastcall TFormMain::writeUlong( FILE *out, unsigned long value )
{
	fputc( (unsigned char)( value & 0xff ), out );
	fputc( (unsigned char)( ( value >> 8 ) & 0xff ), out );
	fputc( (unsigned char)( ( value >> 16 ) & 0xff ), out );
	fputc( (unsigned char)( ( value >> 24 ) & 0xff ), out );


	return 0;
}



//---------------------------------------------------------------------------
void __fastcall TFormMain::N2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FileLoadImageClick(TObject *Sender)
{
	if( OpenPictureDialog1->Execute() )
	{


		Image1->Picture->LoadFromFile( OpenPictureDialog1->FileName );


	}

}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FileSaveGBMClick(TObject *Sender)
{
	FILE *out;
	int x,y;
	TColor pixel;
	unsigned short r,g,b,pixel565;
	char path[1024];

	if( !SaveDialog1->Execute() )
	{
		return;
	}

	//Convert wchar shit to string
	memset( path, 0, sizeof( path ));
	wcstombs( path, SaveDialog1->FileName.c_str(), SaveDialog1->FileName.Length() );


	out = fopen( path, (const char*)"wb" );

	if( ! out )
	{

		ShowMessage( "Can't save file" );

		return;
	}


	writeUshort( out, Image1->Picture->Width );
	writeUshort( out, Image1->Picture->Height );
	writeUshort( out, 0 ); //flags
	writeUshort( out, 0 ); //transparent color
	writeUlong ( out, 12 ); //framebuffer location index (from beginning of the file)

	//convert image to rgb 565 and write

	for( y = 0; y < Image1->Picture->Height; y++ )
	{
		for( x = 0; x < Image1->Picture->Width; x++ )
		{
			pixel = Image1->Picture->Bitmap->Canvas->Pixels[x][y];

			r = pixel & 0xff;
			g = ( pixel >> 8 ) & 0xff;
			b = ( pixel >> 16 ) & 0xff;


			pixel565 =( unsigned short )((((unsigned short)b >> 3) & 31 ) |
				(((unsigned short)g & 252 ) << 3 ) | (((unsigned short)r & 248 ) << 8 ));

			writeUshort( out, pixel565 );

		}
	}

	fclose( out );

}
//---------------------------------------------------------------------------
