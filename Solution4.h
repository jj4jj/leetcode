
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
			ListNode* p = pHead;
			cout<<"quick sort sub list :"<<endl;
			while(p != pTail)
			{
				cout<<p->val<<" ";
				p = p->next;	
			}
			cout<<endl;
			p = pHead;
			ListNode* pPivot = pHead;
			cout<<"pivot :"<<pPivot->val<<endl;
			while(p->next && p->next != pTail )
			{
				if(p->next->val < pPivot->val)
				{
					cout<<"val:"<<p->next->val<<" swap insert into head "<<endl;
					ListNode* t = p->next->next;
					//delete p->next and insert into list head
					p->next->next = pHead;
					pHead = p->next;
					p->next = t; 
				}
				else
				{
					p = p->next;	
				}
			}
			quickSort(pHead,pPivot);
			quickSort(pPivot->next,pTail);
			
		}
		ListNode *sortList(ListNode *head) {
			quickSort(head,NULL);
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
			ListNode* pNode = pHead;
			while(pNode)
			{
				cout<<pNode->val<<" ";	
				pNode = pNode->next;
			}
			cout<<endl;
			sortList(pHead);
			pNode = pHead;
			while(pNode)
			{
				cout<<pNode->val<<" ";	
				pNode = pNode->next;
			}

			cout<<endl;
		}
};
