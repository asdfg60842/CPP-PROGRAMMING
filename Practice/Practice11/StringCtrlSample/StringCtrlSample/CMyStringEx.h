#pragma once
#include "CMyString.h"

class CMyStringEx :
    public CMyString
{
public:
    CMyStringEx();
    ~CMyStringEx();

    // 痕発 持失切
    explicit CMyStringEx(const char* pszParam);

    int Find(const char* pszParam); 
    int SetString(const char* pszParam);
};

