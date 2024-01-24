//---------------------------------------------------------------------------

#ifndef UnitMainH
#define UnitMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *FileLoadImage;
	TMenuItem *FileSaveGBM;
	TMenuItem *N1;
	TMenuItem *N2;
	TScrollBox *ScrollBox1;
	TImage *Image1;
	TOpenPictureDialog *OpenPictureDialog1;
	TSaveDialog *SaveDialog1;
	void __fastcall N2Click(TObject *Sender);
	void __fastcall FileLoadImageClick(TObject *Sender);
	void __fastcall FileSaveGBMClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);

	int __fastcall writeUshort( FILE *out, unsigned short value );
	int __fastcall writeUlong( FILE *out, unsigned long value );

};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
