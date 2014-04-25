///////////////////////////////////////////////////
class Solution2 {
	public:
	    int evalRPN(vector<string> &tokens) {
			stack<int> nums;
			stack<string> ops;
			for(int i = 0; i < tokens.size(); ++i)
			{
				if(tokens[i] == "+")
				{
					int n1 = nums.top();
					nums.pop();
					int n2 = nums.top();
					nums.pop();
					nums.push(n2+n1);
					continue;
				}
				else if(tokens[i] == "-")
				{
						int n1 = nums.top();
					nums.pop();
					int n2 = nums.top();
					nums.pop();
					nums.push(n2-n1);
					continue;
					
				}
				else if(tokens[i] == "*")
				{
							int n1 = nums.top();
					nums.pop();
					int n2 = nums.top();
					nums.pop();
					nums.push(n2*n1);
					continue;
				
				}
				else if(tokens[i] == "/")
				{
								int n1 = nums.top();
					nums.pop();
					int n2 = nums.top();
					nums.pop();
					nums.push(n2/n1);
					continue;
			
				}
				int n = std::atoi(tokens[i].c_str());	
				nums.push(n);
			}
			return nums.top();
		}
		void OnGetLine(string & line)
		{
				TokenNizer tn;
				vector<string> lst = tn.Split(line," ");
				cout<<evalRPN(lst)<<endl;	
		}
};


