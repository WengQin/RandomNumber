
// 042_RandomNumberDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "042_RandomNumber.h"
#include "042_RandomNumberDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy042_RandomNumberDlg �Ի���



CMy042_RandomNumberDlg::CMy042_RandomNumberDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MY042_RANDOMNUMBER_DIALOG, pParent)
{
	srand(time(NULL));
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy042_RandomNumberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_X, tuX);
	for (int i = 0; i < 10; i++)
	{
		DDX_Control(pDX, 1004+i, tu[i]);
	}
	
}

BEGIN_MESSAGE_MAP(CMy042_RandomNumberDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy042_RandomNumberDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy042_RandomNumberDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy042_RandomNumberDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMy042_RandomNumberDlg ��Ϣ�������

BOOL CMy042_RandomNumberDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetWindowPos(&wndTop, 100, 100, 700, 300, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON1)->SetWindowPos(NULL, 50, 50, 100, 30, SWP_NOZORDER);
	GetDlgItem(IDC_BUTTON2)->SetWindowPos(NULL, 200, 50, 100, 30, SWP_NOZORDER);
	GetDlgItem(IDC_BUTTON3)->SetWindowPos(NULL, 550, 50, 100, 30, SWP_NOZORDER);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy042_RandomNumberDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy042_RandomNumberDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMy042_RandomNumberDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy042_RandomNumberDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_STATIC_X)->SetWindowPos(NULL, 84, 100, 32, 32, SWP_NOZORDER);
	GetDlgItem(IDC_STATIC_X)->ShowWindow(true);

	HICON hicon = AfxGetApp()->LoadIcon(129+rand()%10);
	tuX.SetIcon(hicon);

}


void CMy042_RandomNumberDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_STATIC_X)->ShowWindow(false);
	const int N = 10;//�������Χ
	int Array[N];
	int i, j;
	bool flag = false;

	for (i = 0; i<N; i++)
	{
		Array[i] = rand() % N;//N��Χ��������������0-N
		//�����û���ظ���ֵ���������Array[i]֮ǰ����������ֵ�Ƿ���¸�ֵ��Array[i]���
		for (j = 0; j<i; j++)
		{
			//Array[i]Ϊ��ֵ��Array[j]Ϊ��ֵ
			while (Array[j] == Array[i])
			{
				//��ȣ�flag=true�����¸�ֵ
				flag = true;
				Array[i] = rand() % N;
			}
			if (flag == true)
			{
				j = -1;//j++��j=0������Array[0]����ѭ���ж�
				flag = false;
			}
		}
	}

	for (i = 0; i<N; i++)	//IDC_STATIC0-IDC_STATIC9�ؼ���ʾ
	{
		GetDlgItem(1004 + i)->ShowWindow(true);
		//������ʾ�����Ϊ32,ͼ���СΪ32*32������������
		GetDlgItem(1004 + i)->SetWindowPos(NULL, 200 + 32 * i, 100, 32, 32, SWP_NOZORDER);
		hicon = AfxGetApp()->LoadIcon(129 + Array[i]);
		tu[i].SetIcon(hicon);
	}
}


void CMy042_RandomNumberDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	const int N = 9;//�������Χ
	int Array[N];
	int i, j;
	bool flag = false;

	for (i = 0; i<N; i++)
	{
		Array[i] = rand() % N + 1;//N��Χ��������������0-N
							  //�����û���ظ���ֵ���������Array[i]֮ǰ����������ֵ�Ƿ���¸�ֵ��Array[i]���
		for (j = 0; j<i; j++)
		{
			//Array[i]Ϊ��ֵ��Array[j]Ϊ��ֵ
			while (Array[j] == Array[i])
			{
				//��ȣ�flag=true�����¸�ֵ
				flag = true;
				Array[i] = rand() % N + 1;
			}
			if (flag == true)
			{
				j = -1;//j++��j=0������Array[0]����ѭ���ж�
				flag = false;
			}
		}
	}
	//����ؼ�����ʾ����Сλ������
	GetDlgItem(1004 + 9)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_X)->ShowWindow(false);
	GetDlgItem(1004 + 9)->SetWindowPos(NULL, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOMOVE | SWP_NOSIZE);

	for (i = 0; i<N; i++)	//IDC_STATIC0-IDC_STATIC9�ؼ���ʾ
	{
		GetDlgItem(1004 + i)->ShowWindow(true); 
		//������ʾ�����Ϊ32,ͼ���СΪ32*32������������
		GetDlgItem(1004 + i)->SetWindowPos(NULL, 550 + 32 * (i%3), 100+32*(i/3), 32, 32, SWP_NOZORDER);
		hicon = AfxGetApp()->LoadIcon(129 + Array[i]);
		tu[i].SetIcon(hicon);
	}
}
