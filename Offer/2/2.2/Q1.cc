char * m_pData;

CMyString& operator = (const CMyString& str)
{
    if (this != &str)
    {
        CMyString tmp(str);
        char * pTmp = tmp.m_pData;
        tmp.m_pData = m_pData;
        m_pData = pTmp;
    }                                                                }
        
    return *this;
} 
