
// 042_RandomNumberDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMy042_RandomNumberDlg �Ի���
class CMy042_RandomNumberDlg : public CDialog
{
// ����
public:
	HICON hicon;
	CMy042_RandomNumberDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY042_RANDOMNUMBER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CStatic tuX;
};
