// Win32Project1.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Win32Project1.h"



// ȫ�ֱ���: 
HINSTANCE hInst;								// ��ǰʵ��
bool ISRUN = true;

// �˴���ģ���а����ĺ�����ǰ������: 
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO:  �ڴ˷��ô��롣


	


	MSG msg;
	

	HWND hWnd = (HWND)DialogBox ( hInst , MAKEINTRESOURCE ( IDD_ABOUTBOX ) , NULL , About );
	ShowWindow ( hWnd ,SW_SHOW);
	UpdateWindow ( hWnd );

	// ����Ϣѭ��: 
	while (PeekMessage(&msg,hWnd,NULL,NULL,PM_REMOVE))
	{
		if (! ISRUN )
		{
			return 0;
		}

		else
		{
			TranslateMessage ( &msg );
			DispatchMessage ( &msg );
		}
	}

	return (int) msg.wParam;
}


// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (msg)
	{
	//case WM_INITDIALOG:
	//	return (INT_PTR)TRUE;

	case WM_COMMAND:
		switch ( LOWORD ( wParam ) )
		{
			case IDOK:
				{
					ISRUN = false;
					EndDialog ( hDlg , LOWORD ( wParam ) );
					return ( INT_PTR ) TRUE;
				}
			default:
				return false;
		}
	
	case WM_QUIT:
		return false;
	}
	return false;
}
