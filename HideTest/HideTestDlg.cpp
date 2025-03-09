
// HideTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "HideTest.h"
#include "HideTestDlg.h"
#include "afxdialogex.h"
#include "resource.h"
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


// CHideTestDlg 对话框



CHideTestDlg::CHideTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HIDETEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHideTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_comboBox);
}

BEGIN_MESSAGE_MAP(CHideTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CHideTestDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CHideTestDlg 消息处理程序

void CHideTestDlg::GetControlRect(int nID, CRect& rect)
{
	CWnd* pWnd = GetDlgItem(nID);
	if (pWnd)
	{
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
	}
}

BOOL CHideTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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
	// 初始化 Combo Box
	m_comboBox.AddString(_T("Item 1"));
	m_comboBox.AddString(_T("Item 2"));
	m_comboBox.AddString(_T("Item 3"));

	// 设置默认选项为第一项
	m_comboBox.SetCurSel(0);

	// 获取所有控件的初始位置
	GetControlRect(IDC_COMBO2, m_rectCombo2);
	GetControlRect(IDC_COMBO3, m_rectCombo3);
	GetControlRect(IDC_COMBO4, m_rectCombo4);
	GetControlRect(IDC_STATIC1, m_rectStatic1);
	GetControlRect(IDC_STATIC2, m_rectStatic2);
	GetControlRect(IDC_STATIC3, m_rectStatic3);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CHideTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CHideTestDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CHideTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CHideTestDlg::MoveOrRestoreControl(int nID, CRect* pRect, BOOL bRestore)
{
	CWnd* pWnd = GetDlgItem(nID);
	if (pWnd)
	{
		if (bRestore)
		{
			// 恢复位置
			pWnd->MoveWindow(pRect);
		}
		else
		{
			// 移动到新的位置
			pWnd->MoveWindow(pRect);
		}
		pWnd->ShowWindow(SW_SHOW);
	}
}


void CHideTestDlg::RestoreControls()
{
	// 恢复所有控件的原始位置
	MoveOrRestoreControl(IDC_COMBO2, &m_rectCombo2, TRUE);
	MoveOrRestoreControl(IDC_COMBO3, &m_rectCombo3, TRUE);
	MoveOrRestoreControl(IDC_COMBO4, &m_rectCombo4, TRUE);
	MoveOrRestoreControl(IDC_STATIC1, &m_rectStatic1, TRUE);
	MoveOrRestoreControl(IDC_STATIC2, &m_rectStatic2, TRUE);
	MoveOrRestoreControl(IDC_STATIC3, &m_rectStatic3, TRUE);
}

void CHideTestDlg::HideAndMoveControls()
{
	// 隐藏 IDC_COMBO2 和 IDC_STATIC1
	GetDlgItem(IDC_COMBO2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);

	// 移动控件到新的位置
	MoveOrRestoreControl(IDC_COMBO3, &m_rectCombo2, FALSE);
	MoveOrRestoreControl(IDC_STATIC2, &m_rectStatic1, FALSE);
	MoveOrRestoreControl(IDC_COMBO4, &m_rectCombo3, FALSE);
	MoveOrRestoreControl(IDC_STATIC3, &m_rectStatic2, FALSE);
}

void CHideTestDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	CRect rect;
	int sel = m_comboBox.GetCurSel();

	if (sel == 1)
	{
		// 执行控件的隐藏和位置调整
		HideAndMoveControls();
	}
	else
	{
		// 恢复所有控件的原始位置和文本
		RestoreControls();
	}
}
