﻿
// Demo2Dlg.h: файл заголовка
//

#pragma once

#include"TreeNode.h"

#include <string>
#include <fstream>
#include <iostream>
#include <deque>
#include <unordered_map>


// Диалоговое окно CDemo2Dlg
class CDemo2Dlg : public CDialogEx
{
// Создание
public:
	CDemo2Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEMO2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	

public:
	// Вывод выбранного пути
	CString m_ctrlPathInfo;
	// Переменная Browse Control
	CString m_ctrlPathEdit;
	afx_msg void OnUpdateEditBrowse();
	void AddNode(std::string node_info);
	void LoadInfoFromFile(std::string path_);

private:
	std::deque<TreeNode> nodes_;
	std::unordered_map<int, TreeNode*> nodes_id;
public:
	// переменная управления дерева
	CTreeCtrl m_ctrlTree;
};