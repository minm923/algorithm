/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution 
{
private:
    int GetListLen(ListNode* pHead)
    {
        if (!pHead)
            return 0;

        int iLen = 0;
        ListNode* tmp = pHead;   

        while (tmp)
        {
            ++iLen;
            tmp = tmp->next;
        }

        return iLen;
    }

    ListNode* GetNListNode(ListNode* pHead, int n)
    {
        if (!pHead || n<0)
            return NULL;

        ListNode* pTmp = pHead;
        while (n-- && pTmp)
        {
            pTmp = pTmp->next;
        }

        return pTmp;
    }
    
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) 
    {
        if (!pHead1 || !pHead2)    
            return NULL;        

        int iLen1 = GetListLen(pHead1);
        int iLen2 = GetListLen(pHead2);

        ListNode* pTmp1 = pHead1;
        ListNode* pTmp2 = pHead2;

        if (iLen1 > iLen2)
        {
            pTmp1 = GetNListNode(pTmp1, iLen1-iLen2);
        }
        else if (iLen1 < iLen2)
        {
            pTmp2 = GetNListNode(pTmp2, iLen2-iLen1);
        }

        while(pTmp1 != pTmp2)
        {
            pTmp1 = pTmp1->next;
            pTmp2 = pTmp2->next;
        }

        return pTmp1;
    }
};