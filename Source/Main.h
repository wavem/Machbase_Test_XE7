//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
//#include <machbase_sqlcli.h>
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "AdvMemo.hpp"
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.ODBC.hpp>
#include <FireDAC.Phys.ODBCDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FireDAC.Phys.SQLiteVDataSet.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TPanel *___pnBase;
	TAdvMemo *memo;
	TFDConnection *FDConnection;
	TFDQuery *FDQuery;
	TButton *btn_Connect;
	TButton *btn_Check;
	TButton *btn_Get;
	TFDGUIxWaitCursor *FDGUIxWaitCursor;
	TDBGrid *DBGrid;
	TDataSource *DataSource;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btn_ConnectClick(TObject *Sender);
	void __fastcall btn_CheckClick(TObject *Sender);
	void __fastcall btn_GetClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);

public: // Basic Member Variables

public: // Basic Functions
	void __fastcall InitProgram();
	void __fastcall ExitProgram();
	void __fastcall PrintMsg(UnicodeString _str);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
