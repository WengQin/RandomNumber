
// 042_RandomNumber.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy042_RandomNumberApp: 
// �йش����ʵ�֣������ 042_RandomNumber.cpp
//

class CMy042_RandomNumberApp : public CWinApp
{
public:
	CMy042_RandomNumberApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy042_RandomNumberApp theApp;