#include "stdafx.h"

HANDLE	g_hProcess;
int		g_iListCnt;
DWORD	g_List[1024];

int main()
{
	char szCommand[] = "02Testor.exe";
	STARTUPINFO si = {};
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = TRUE;
	PROCESS_INFORMATION	pi;
	BOOL bRet = CreateProcess(NULL, szCommand, NULL, NULL, FALSE, CREATE_NEW_CONSOLE,
		NULL, NULL, &si, &pi);
	if (!bRet)
	{
		cout << "CreateProcess is failed.\n";
		return -1;
	}
	else
	{
		cout << "CreateProcess is succesed.\n";
		g_hProcess = pi.hProcess;

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);

	}


	return 0;
}