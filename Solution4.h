
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution4 {
	public:
		void	mergeSort(ListNode * head)
		{
			if(!head || !(head->next))
			{
				return;	
			}
			if(head->val > head->next->val)
			{

				cout<<"swap:"<<head->val<<","<<head->next->val<<endl;
				int v = head->val;
				head->val = head->next->val;
				head->next->val = v;	
			}
			ListNode* pNewLink = head->next->next;
			mergeSort(pNewLink);
			while(pNewLink)
			{
				if(head == pNewLink)
				{
					pNewLink = pNewLink->next;	
					continue;
				}
				if(head->val > pNewLink->val)
				{
					cout<<"swap:"<<head->val<<","<<pNewLink->val<<endl;
					int v = head->val;
					head->val = pNewLink->val;
					pNewLink->val = v;	
					head = head->next;
				}
				else
				{
					pNewLink = pNewLink->next;	
				}
			}
		}
		ListNode *sortList(ListNode *head) {
			mergeSort(head);
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
