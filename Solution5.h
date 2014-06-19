
/*struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};*/
class Solution5
 {
	public:
		ListNode * insertionSortList(ListNode * head)
		{
			if(!head)
			{
				return head;	
			}
			ListNode* stail = head,*uhead = head->next;
			while(uhead)
			{
				if(uhead->val >= stail->val)
				{
					stail = stail->next;
					uhead =	stail->next;
				}
				else
				{
					ListNode* prev = NULL,* pos = head;
					while(uhead->val >= pos->val)
					{
						prev = pos;	
						pos = pos->next;
					}
					if(NULL == prev)
					{
						stail->next = uhead->next;
						uhead->next = pos;	
						head = uhead;
					}
					else
					{
						stail->next = uhead->next;
						uhead->next = prev->next;
						prev->next = uhead;	
					}
					uhead = stail->next;
				}
			}
			return head;
		}
		ListNode *sortList(ListNode *head) {
			
			ListNode* p = insertionSortList(head);
			cout<<"result:";
			while(p)
			{
				cout<<p->val<<" ";	
				p = p->next;
			}
			cout<<endl;
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
				//cout<<"new node :"<<pNode->val<<"->"<<pNode->next<<endl;
				if(!pHead)
				{
					pHead = pTail = pNode;
				}
				else
				{
					pTail->next = pNode;
					pTail = pNode;
				}
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
