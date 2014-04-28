
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution4 {
	public:
		ListNode *sortList(ListNode *head) {

			LintNode* pSorted = head;
			while(
			

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
					pHead = pTai = pNode;	
				}
				pTail->next = pNode;
			}
			sortList(pHead);
			pNode = pHead;
			while(pNode)
			{
				cout<<pNode->val<<" ";	
				pNode = pNode->next;
			}
			cout<<endl;

		}

		points.push_back(pt)[[]
			]
};
