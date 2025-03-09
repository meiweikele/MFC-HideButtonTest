class CHideTestDlg : public CDialogEx
{
	// 构造
public:
	CHideTestDlg(CWnd* pParent = nullptr);

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HIDETEST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

														// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	void OnSysCommand(UINT nID, LPARAM lParam);
	void OnPaint();
	afx_msg void OnCbnSelchangeCombo1();
	DECLARE_MESSAGE_MAP()

private:
	CComboBox m_comboBox;
	CRect m_rectCombo2, m_rectCombo3, m_rectCombo4, m_rectCombo5;
	CRect m_rectStatic1, m_rectStatic2, m_rectStatic3, m_rectStatic4;
	// 成员变量用于存储静态控件的初始文本
	CString m_textStatic1;
	CString m_textStatic2;
	CString m_textStatic3;

	HCURSOR OnQueryDragIcon();
	void GetControlRect(int nID, CRect& rect);
	void MoveOrRestoreControl(int nID, CRect* pRect, BOOL bRestore);
	void RestoreControls();
	void HideAndMoveControls();
};
