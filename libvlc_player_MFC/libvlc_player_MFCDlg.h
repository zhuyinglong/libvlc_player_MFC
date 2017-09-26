
// libvlc_player_MFCDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

#include <string>//std::string
#include "configs.h"//libvlc

#define MAX_URL_LENGTH 100

enum PlayerState {
	STATE_PREPARE,
	STATE_PLAY,
	STATE_PAUSE
};

// Clibvlc_player_MFCDlg 对话框
class Clibvlc_player_MFCDlg : public CDialogEx
{
// 构造
public:
	Clibvlc_player_MFCDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIBVLC_PLAYER_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_url;

	libvlc_instance_t * libvlc_inst;
	libvlc_media_player_t *libvlc_mp;
	libvlc_media_t *libvlc_m;
	PlayerState playerState;

	afx_msg void OnBnClickedButtonUrl();
	afx_msg void OnBnClickedPlay();
	void UNICODE_to_UTF8(CStringW& unicodeString, std::string& str);
	void InitSystem();
	afx_msg void OnBnClickedButtonStop();
	virtual BOOL DestroyWindow();
	afx_msg void OnBnClickedButtonPause();
	// 当前播放时长
	CEdit m_curtime;
	// 总时长
	CEdit m_totaltime;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	// 进度条
	CScrollBar m_progress;
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnFileOpen();
	afx_msg void OnCsdn();
	afx_msg void OnAbout();
	afx_msg void OnBnClickedButtonInfo();
};
