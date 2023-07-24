#pragma once
#include "CMyString.h"

class CMyStringEx :
    public CMyString
{
public:
    CMyStringEx();
    ~CMyStringEx();

    int Find(const char* pszParam); 
    int SetString(const char* pszParam);
};

