
// HideTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HideTest.h"
#include "HideTestDlg.h"
#include "afxdialogex.h"
#include "resource.h"
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


// CHideTestDlg �Ի���



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


// CHideTestDlg ��Ϣ�������

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
	// ��ʼ�� Combo Box
	m_comboBox.AddString(_T("Item 1"));
	m_comboBox.AddString(_T("Item 2"));
	m_comboBox.AddString(_T("Item 3"));

	// ����Ĭ��ѡ��Ϊ��һ��
	m_comboBox.SetCurSel(0);

	// ��ȡ���пؼ��ĳ�ʼλ��
	GetControlRect(IDC_COMBO2, m_rectCombo2);
	GetControlRect(IDC_COMBO3, m_rectCombo3);
	GetControlRect(IDC_COMBO4, m_rectCombo4);
	GetControlRect(IDC_STATIC1, m_rectStatic1);
	GetControlRect(IDC_STATIC2, m_rectStatic2);
	GetControlRect(IDC_STATIC3, m_rectStatic3);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CHideTestDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
			// �ָ�λ��
			pWnd->MoveWindow(pRect);
		}
		else
		{
			// �ƶ����µ�λ��
			pWnd->MoveWindow(pRect);
		}
		pWnd->ShowWindow(SW_SHOW);
	}
}


void CHideTestDlg::RestoreControls()
{
	// �ָ����пؼ���ԭʼλ��
	MoveOrRestoreControl(IDC_COMBO2, &m_rectCombo2, TRUE);
	MoveOrRestoreControl(IDC_COMBO3, &m_rectCombo3, TRUE);
	MoveOrRestoreControl(IDC_COMBO4, &m_rectCombo4, TRUE);
	MoveOrRestoreControl(IDC_STATIC1, &m_rectStatic1, TRUE);
	MoveOrRestoreControl(IDC_STATIC2, &m_rectStatic2, TRUE);
	MoveOrRestoreControl(IDC_STATIC3, &m_rectStatic3, TRUE);
}

void CHideTestDlg::HideAndMoveControls()
{
	// ���� IDC_COMBO2 �� IDC_STATIC1
	GetDlgItem(IDC_COMBO2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);

	// �ƶ��ؼ����µ�λ��
	MoveOrRestoreControl(IDC_COMBO3, &m_rectCombo2, FALSE);
	MoveOrRestoreControl(IDC_STATIC2, &m_rectStatic1, FALSE);
	MoveOrRestoreControl(IDC_COMBO4, &m_rectCombo3, FALSE);
	MoveOrRestoreControl(IDC_STATIC3, &m_rectStatic2, FALSE);
}

void CHideTestDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CRect rect;
	int sel = m_comboBox.GetCurSel();

	if (sel == 1)
	{
		// ִ�пؼ������غ�λ�õ���
		HideAndMoveControls();
	}
	else
	{
		// �ָ����пؼ���ԭʼλ�ú��ı�
		RestoreControls();
	}
}
