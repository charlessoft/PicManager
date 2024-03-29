// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"

#include "MainDlg.h"

//LRESULT CMainDlg::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//{
//	// center the dialog on the screen
//	CenterWindow();
//
//	// set icons
//	HICON hIcon = AtlLoadIconImage(IDR_MAINFRAME, LR_DEFAULTCOLOR, ::GetSystemMetrics(SM_CXICON), ::GetSystemMetrics(SM_CYICON));
//	SetIcon(hIcon, TRUE);
//	HICON hIconSmall = AtlLoadIconImage(IDR_MAINFRAME, LR_DEFAULTCOLOR, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON));
//	SetIcon(hIconSmall, FALSE);
//
//	return TRUE;
//}
//
//LRESULT CMainDlg::OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//{
//	CSimpleDialog<IDD_ABOUTBOX, FALSE> dlg;
//	dlg.DoModal();
//	return 0;
//}
//
//LRESULT CMainDlg::OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//{
//	// TODO: Add validation code 
//	EndDialog(wID);
//	return 0;
//}
//
//LRESULT CMainDlg::OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//{
//	EndDialog(wID);
//	return 0;
//}

void	CMainDlg::OnBkBtnClose()
{
	EndDialog(IDOK);
}

void CMainDlg::OnSysCommand(UINT nID, CPoint point)
{
	SetMsgHandled(FALSE);

	switch (nID & 0xFFF0)
	{
	case SC_CLOSE:
		SetMsgHandled(TRUE);
		//OnClose();
		EndDialog(IDOK);
		return;
		break;
	case SC_RESTORE:
		{
			DWORD dwStyle = GetStyle();
			if (WS_MINIMIZE == (dwStyle & WS_MINIMIZE))
				break;

			if (WS_MAXIMIZE == (dwStyle & WS_MAXIMIZE))
			{
				SetItemAttribute(IDC_BTN_MAX, "skin", "dlg_btn_max");
				break;
			}
		}
	case SC_MAXIMIZE:
		SetItemAttribute(IDC_BTN_MAX, "skin", "dlg_btn_normal");
		break;
	default:
		break;
	}
}

LRESULT CMainDlg::OnInitDialog(HWND, LPARAM)
{
	SetIcon(::LoadIcon((HMODULE)&__ImageBase,MAKEINTRESOURCE(IDI_BIG)));
	SetIcon(::LoadIcon((HMODULE)&__ImageBase,MAKEINTRESOURCE(IDI_SMALL)),FALSE);
	
		m_ListViewCtrl.Create( 
		GetViewHWND(), NULL,NULL, 
		WS_CHILD | WS_VISIBLE | LVS_REPORT | LVS_SHOWSELALWAYS | LVS_OWNERDRAWFIXED | LVS_SINGLESEL , 
		0, IDC_LISTVIEW_CTRL, NULL);

	{
		INT nRow = 0;
		m_ListViewCtrl.InsertColumn(nRow++, BkString::Get(106), LVCFMT_CENTER, 56);
		m_ListViewCtrl.InsertColumn(nRow++, BkString::Get(107), LVCFMT_CENTER, 120);
		m_ListViewCtrl.InsertColumn(nRow++, BkString::Get(108), LVCFMT_CENTER, 150);
		m_ListViewCtrl.InsertColumn(nRow++, BkString::Get(109), LVCFMT_CENTER, 100);
		m_ListViewCtrl.InsertColumn(nRow++, BkString::Get(110), LVCFMT_CENTER, 60);


		//int nItem = m_wndAccountListView.Append(_T("#1"), NULL, 0, LISTITEM_CHECKBOX);
		//m_wndAccountListView.AppendSubItem(nItem, _T("iseeeyou1234@changyou.com"));
		//m_wndAccountListView.AppendSubItem(nItem, _T("西南电信一区"));
		//m_wndAccountListView.AppendSubItem(nItem, _T("蜀南竹海"));
		//m_wndAccountListView.AppendSubItem(nItem, _T("角色1"),2012, SUBITEM_COMBO);
		////m_wndListView.AppendSubItem(nItem, _T(""));

		//nItem = m_wndAccountListView.Append(_T("#2"), NULL, 0, LISTITEM_CHECKBOX);
		//m_wndAccountListView.AppendSubItem(nItem, _T("iseeeyou1234@changyou.com"));
		//m_wndAccountListView.AppendSubItem(nItem, _T("西南电信一区"));
		//m_wndAccountListView.AppendSubItem(nItem, _T("蜀南竹海"));
		//m_wndAccountListView.AppendSubItem(nItem, _T("角色2"),2012, SUBITEM_COMBO);
		//m_wndListView.AppendSubItem(nItem, _T(""));

		//m_wndAccountListView.SetCheckState(nItem, TRUE);
	}
//	m_ListViewCtrl.SetObserverWindow(m_hWnd);
	return 1;
}