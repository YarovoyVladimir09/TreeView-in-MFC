
// Demo2.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CDemo2App:
// Сведения о реализации этого класса: Demo2.cpp
//

class CDemo2App : public CWinApp
{
public:
	CDemo2App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CDemo2App theApp;
