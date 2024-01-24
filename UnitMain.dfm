object FormMain: TFormMain
  Left = 0
  Top = 0
  Caption = 'GfxLibConv'
  ClientHeight = 523
  ClientWidth = 840
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  DesignSize = (
    840
    523)
  TextHeight = 13
  object ScrollBox1: TScrollBox
    Left = 0
    Top = 0
    Width = 840
    Height = 521
    Anchors = [akLeft, akTop, akRight, akBottom]
    BevelInner = bvNone
    BevelOuter = bvNone
    TabOrder = 0
    ExplicitWidth = 838
    ExplicitHeight = 517
    object Image1: TImage
      Left = 0
      Top = 0
      Width = 105
      Height = 105
      AutoSize = True
    end
  end
  object MainMenu1: TMainMenu
    Left = 24
    Top = 464
    object File1: TMenuItem
      Caption = '&File'
      object FileLoadImage: TMenuItem
        Caption = '&Load image'
        OnClick = FileLoadImageClick
      end
      object FileSaveGBM: TMenuItem
        Caption = '&Save .gbm'
        OnClick = FileSaveGBMClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object N2: TMenuItem
        Caption = 'E&xit'
        OnClick = N2Click
      end
    end
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 112
    Top = 464
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '*.gbm'
    FileName = '*.gbm'
    Filter = 'GFX Lib bitmap .gbm|*.gbm'
    Options = [ofHideReadOnly, ofPathMustExist, ofEnableSizing]
    Left = 200
    Top = 464
  end
end
