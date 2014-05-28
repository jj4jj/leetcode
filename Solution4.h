
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution4 {
	public:
		ListNode * mergeSort(ListNode * head)
		{
			ListNode* p = head;
			int n  = 0;
			while(p)
			{
				++n;
				p=p->next;	
			}
			if(!head || n < 2)
			{
				return head;	
			}
			if(n == 2 )
			{
				if(head->val > head->next->val)
				{
					int t = head->val;
					head->val = head->next->val;
					head->next->val = t;	
				}
				return head;	
			}
			ListNode* pHead2nd = head;
			int i = 0;
			while((i < n/2) && pHead2nd)
			{
				++i;
				p = pHead2nd;
				pHead2nd = pHead2nd->next;	
			}
			p->next = NULL;
			head = mergeSort(head);
			pHead2nd = mergeSort(pHead2nd);
			///////////////////////////////
			//merge head and middle
			ListNode * pTail = NULL, *pHead = NULL;
			while(head != NULL && pHead2nd != NULL)
			{
				if(head->val > pHead2nd->val)
				{
					if(NULL == pHead)
					{
						pHead = pHead2nd;	
					}
					if(pTail)
					{
						pTail->next = pHead2nd;
					}
					pTail = pHead2nd;
					p = pHead2nd->next;
					pHead2nd->next = head;
					pHead2nd = p;

				}
				else
				{
					if(NULL == pHead)
					{
						pHead = head;	
					}
					pTail = head;
					head = head->next;	
				}
			}
			if(!head && pHead2nd)
			{
				pTail->next = pHead2nd;
			}
			if( !pHead2nd && head)
			{
				pTail->next = head;
			}
			return pHead;
		}
		ListNode *sortList(ListNode *head) {
			
			return mergeSort(head);
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
			pHead = sortList(pHead);
			while(pHead)
			{
				
				cout<<pHead->val<<" ";
				pHead = pHead->next;
			}
			cout<<endl;
		}
};
