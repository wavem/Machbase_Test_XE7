//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvMemo"
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
	InitProgram();

}
//---------------------------------------------------------------------------

void __fastcall TFormMain::InitProgram() {



	PrintMsg(L"Init Complete");
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	ExitProgram();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ExitProgram() {

}
//---------------------------------------------------------------------------

void __fastcall TFormMain::PrintMsg(UnicodeString _str) {
	int t_Line = memo->Lines->Add(_str);
	memo->SetCursor(0, t_Line);
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::btn_ConnectClick(TObject *Sender)
{
	FDConnection->Connected = true;
	if(FDConnection->Connected) {
		FDQuery->Active = true;
	} else {
		PrintMsg(L"FD Fail to Connect");
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::btn_CheckClick(TObject *Sender)
{
	if(FDConnection->Connected) {
		PrintMsg(L"FD Connected");
	} else {
		PrintMsg(L"FD Not Connected");
	}


	if(FDQuery->Active) {
		PrintMsg(L"Query Activated");
	} else {
		PrintMsg(L"Query Not Activated");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::btn_GetClick(TObject *Sender)
{
	// Get Count
	if(!FDQuery->Active) {
		PrintMsg(L"Query Not Activated");
		return;
	}

	// Common
	UnicodeString tempStr = L"";
	int t_Count = 0;
	int t_Recno = 0;

	FDQuery->Close();
	FDQuery->Active = true;
	t_Count = FDQuery->RecordCount;
	tempStr.sprintf(L"Record Count : %d", t_Count);
	//PrintMsg(tempStr);





	//for(int i = 0 ; i < 10 ; i++) {
	tempStr = FDQuery->FieldByName(L"OPER_DT")->Text;
	PrintMsg(tempStr);

	TByteDynArray temp;
	//temp.
	temp = FDQuery->FieldByName(L"RAWDATA")->AsBytes;
	int t_Size = temp.get_length();
	tempStr.sprintf(L"Length : %d", t_Size);
	PrintMsg(tempStr);

	tempStr = L"";
	UnicodeString t_Str = L"";
	for(int i = 0 ; i < 10 ; i++) {
		tempStr.sprintf(L"%02X ", temp[i]);
		t_Str += tempStr;
	}
	PrintMsg(t_Str);

		//FDQuery->FieldByName(L"OPER_DT")
		//FDQuery->Next();
	//}
	//FDQuery->Active = false;
	//FDQuery->Active = true;


	//tempStr = FDQuery_JSON_FAULT->FieldByName(L"fa_date")->Text;
	//chart_C->BottomAxis->Items->Items[t_BottomAxisIdx--]->Text = tempStr;
}
//---------------------------------------------------------------------------

