class CHideTestDlg : public CDialogEx
{
	// ����
public:
	CHideTestDlg(CWnd* pParent = nullptr);

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HIDETEST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

														// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	void OnSysCommand(UINT nID, LPARAM lParam);
	void OnPaint();
	afx_msg void OnCbnSelchangeCombo1();
	DECLARE_MESSAGE_MAP()

private:
	CComboBox m_comboBox;
	CRect m_rectCombo2, m_rectCombo3, m_rectCombo4, m_rectCombo5;
	CRect m_rectStatic1, m_rectStatic2, m_rectStatic3, m_rectStatic4;
	// ��Ա�������ڴ洢��̬�ؼ��ĳ�ʼ�ı�
	CString m_textStatic1;
	CString m_textStatic2;
	CString m_textStatic3;

	HCURSOR OnQueryDragIcon();
	void GetControlRect(int nID, CRect& rect);
	void MoveOrRestoreControl(int nID, CRect* pRect, BOOL bRestore);
	void RestoreControls();
	void HideAndMoveControls();
};
