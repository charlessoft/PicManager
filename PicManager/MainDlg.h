// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

//class CMainDlg : public CDialogImpl<CMainDlg>
//{
//public:
//	enum { IDD = IDD_MAINDLG };
//
//	BEGIN_MSG_MAP(CMainDlg)
//		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
//		COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
//		COMMAND_ID_HANDLER(IDOK, OnOK)
//		COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
//	END_MSG_MAP()
//
//// Handler prototypes (uncomment arguments if needed):
////	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
////	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
////	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)
//
//	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
//	LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
//	LRESULT OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
//	LRESULT OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
//};
#include "wtlhelper/whwindow.h"
#include "ListViewCtrlEx.h"
class CMainDlg : public CBkDialogImpl<CMainDlg> ,
	public CWHRoundRectFrameHelper<CMainDlg>
{
public:
	CMainDlg(): CBkDialogImpl<CMainDlg>(IDR_BK_MAIN_DIALOG)
	{}

	BK_NOTIFY_MAP(IDC_RICHVIEW_WIN)
		BK_NOTIFY_ID_COMMAND(IDC_BTN_SYS_CLOSE, OnBkBtnClose)
		//BK_NOTIFY_ID_COMMAND(IDC_BTN_MAX, OnMaxWindow)
		//BK_NOTIFY_ID_COMMAND(IDC_BTN_START_CHANGE,OnChange)
		//BK_NOTIFY_ID_COMMAND(IDC_BTN_ADD,OnAdd)
		//BK_NOTIFY_ID_COMMAND(IDC_BTN_EDIT,OnEdit)
		//BK_NOTIFY_ID_COMMAND(IDC_DATIKA,OnDATIKA)

	BK_NOTIFY_MAP_END()

		BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_BK_NOTIFY(IDC_RICHVIEW_WIN)
		MSG_WM_SYSCOMMAND(OnSysCommand)
		CHAIN_MSG_MAP(CBkDialogImpl<CMainDlg>)
		CHAIN_MSG_MAP(CWHRoundRectFrameHelper<CMainDlg>)
		MSG_WM_INITDIALOG(OnInitDialog)
		//COMMAND_HANDLER(2012, CBN_SELCHANGE, OnComboBoxSelectChange)
		//COMMAND_RANGE_HANDLER(2012,NB_CLICK, OnListItemClick)

		REFLECT_NOTIFICATIONS_EX()

		END_MSG_MAP()
public:
		void	OnSysCommand(UINT nID, CPoint point);
		LRESULT OnInitDialog(HWND, LPARAM);
		void OnBkBtnClose();

public:
	CListViewCtrlEx m_ListViewCtrl;
};