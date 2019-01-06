
// 042_RandomNumberDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "042_RandomNumber.h"
#include "042_RandomNumberDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMy042_RandomNumberDlg 对话框



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


// CMy042_RandomNumberDlg 消息处理程序

BOOL CMy042_RandomNumberDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetWindowPos(&wndTop, 100, 100, 700, 300, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON1)->SetWindowPos(NULL, 50, 50, 100, 30, SWP_NOZORDER);
	GetDlgItem(IDC_BUTTON2)->SetWindowPos(NULL, 200, 50, 100, 30, SWP_NOZORDER);
	GetDlgItem(IDC_BUTTON3)->SetWindowPos(NULL, 550, 50, 100, 30, SWP_NOZORDER);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy042_RandomNumberDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy042_RandomNumberDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy042_RandomNumberDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_STATIC_X)->SetWindowPos(NULL, 84, 100, 32, 32, SWP_NOZORDER);
	GetDlgItem(IDC_STATIC_X)->ShowWindow(true);

	HICON hicon = AfxGetApp()->LoadIcon(129+rand()%10);
	tuX.SetIcon(hicon);

}


void CMy042_RandomNumberDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_STATIC_X)->ShowWindow(false);
	const int N = 10;//数组最大范围
	int Array[N];
	int i, j;
	bool flag = false;

	for (i = 0; i<N; i++)
	{
		Array[i] = rand() % N;//N范围内任意整数，即0-N
		//检查有没有重复赋值，即检查在Array[i]之前的所有数组值是否和新赋值的Array[i]相等
		for (j = 0; j<i; j++)
		{
			//Array[i]为新值，Array[j]为旧值
			while (Array[j] == Array[i])
			{
				//相等：flag=true；重新赋值
				flag = true;
				Array[i] = rand() % N;
			}
			if (flag == true)
			{
				j = -1;//j++后j=0，即从Array[0]重新循环判断
				flag = false;
			}
		}
	}

	for (i = 0; i<N; i++)	//IDC_STATIC0-IDC_STATIC9控件显示
	{
		GetDlgItem(1004 + i)->ShowWindow(true);
		//横排显示，间隔为32,图像大小为32*32，即紧凑排列
		GetDlgItem(1004 + i)->SetWindowPos(NULL, 200 + 32 * i, 100, 32, 32, SWP_NOZORDER);
		hicon = AfxGetApp()->LoadIcon(129 + Array[i]);
		tu[i].SetIcon(hicon);
	}
}


void CMy042_RandomNumberDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	const int N = 9;//数组最大范围
	int Array[N];
	int i, j;
	bool flag = false;

	for (i = 0; i<N; i++)
	{
		Array[i] = rand() % N + 1;//N范围内任意整数，即0-N
							  //检查有没有重复赋值，即检查在Array[i]之前的所有数组值是否和新赋值的Array[i]相等
		for (j = 0; j<i; j++)
		{
			//Array[i]为新值，Array[j]为旧值
			while (Array[j] == Array[i])
			{
				//相等：flag=true；重新赋值
				flag = true;
				Array[i] = rand() % N + 1;
			}
			if (flag == true)
			{
				j = -1;//j++后j=0，即从Array[0]重新循环判断
				flag = false;
			}
		}
	}
	//多余控件不显示，大小位置随意
	GetDlgItem(1004 + 9)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_X)->ShowWindow(false);
	GetDlgItem(1004 + 9)->SetWindowPos(NULL, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOMOVE | SWP_NOSIZE);

	for (i = 0; i<N; i++)	//IDC_STATIC0-IDC_STATIC9控件显示
	{
		GetDlgItem(1004 + i)->ShowWindow(true); 
		//横排显示，间隔为32,图像大小为32*32，即紧凑排列
		GetDlgItem(1004 + i)->SetWindowPos(NULL, 550 + 32 * (i%3), 100+32*(i/3), 32, 32, SWP_NOZORDER);
		hicon = AfxGetApp()->LoadIcon(129 + Array[i]);
		tu[i].SetIcon(hicon);
	}
}
