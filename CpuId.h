 
#if !defined(AFX_14BEC153_17B9_47BE_845F_71A27BF26B59__INCLUDED_)
#define AFX_14BEC153_17B9_47BE_845F_71A27BF26B59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
#include <string>
#ifdef UNICODE
typedef wchar_t TCHAR;
#else
typedef char TCHAR;
#endif
using namespace std;

//--------------------------------------------------------------
//						CPU���к�
//--------------------------------------------------------------
bool GetCpuByCmd(char *lpszCpu, int len = 128);


#endif // !defined(AFX_14BEC153_17B9_47BE_845F_71A27BF26B59__INCLUDED_)

