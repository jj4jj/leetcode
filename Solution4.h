
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution4 {
	public:
		void quickSort(ListNode* pHead, ListNode* pTail)
		{
			if(pHead == pTail)
			{
				return ;	
			}
			int len = 0;
			ListNode* p = pHead;
			while(p != pTail)
			{
				len++;
				p = p->next;	
			}
			p = pHead;
			ListNode* pPivot = pHead;
			int irand = rand()%len;
			while(irand--)
			{
				pPivot = pPivot->next;
			}
			bool after = false;
			while(p != pTail )
			{
				if(p == pPivot)
				{
					after = true;	
				}
				if(p->val < pPivot->val)
				{
					int t = p->val;
					p->val = pPivot->val;
					pPivot->val = t;
					pPivot = pPivot->next;

					if(pPivot != NULL)
					{
						t = p->val;
						p->val = pPivot->val;
						pPivot->val = t;
					}

				}
				p = p->next;	
			}
			quickSort(pHead,pPivot);
			quickSort(pPivot->next,pTail);
			
		}
		ListNode *sortList(ListNode *head) {
			quickSort(head,NULL);
			return head;
		}
		void OnGetLine(string & line)
		{
			TokenNizer tn;
			vector<string> lst = tn.Split(line," ");
			vector<Point>	points;
			ListNode * pHead = NULL,*pTail = NULL;
			for(int i = 0; i < lst.size(); i++)
			{
				ListNode* pNode = new ListNode(std::atoi(lst[i].c_str()));
				if(!pHead)
				{
					pHead = pTail = pNode;
				}
				pTail->next = pNode;
				pTail = pNode;
			}
			sortList(pHead);
			while(pHead)
			{
				
				cout<<pHead->val<<" ";
				pHead = pHead->next;
			}
			cout<<endl;
		}
};
