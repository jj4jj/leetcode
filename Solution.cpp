#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;


class Solution1 {
	public:
	    void reverseWords(string &s) {
			//split with space
			//reverse all word
			vector<string> list;
			int i = 0;
			string word;
			word.clear();
			for(;i < s.length();++i)
			{
				if(s[i] == ' ')
				{
					if(!word.empty())
					{
						list.push_back(word);
						word.clear();
					}		
				}
				else
				{
					word.push_back(s[i]);	
				}
			}
			if(!word.empty())
			{
				list.push_back(word);
			}
			s.clear();
			for(i = list.size() - 1; i>=0 ;--i)
			{
				s.append(list[i]);	
				if(i>0)
				{
					s.push_back(' ');
				}
			}
		}
};


int main()
{
	Solution1 s1;
	
	char line[1024];
	while(gets(line))
	{
		string s = line;
		s1.reverseWords(s);
		cout<<s<<endl;		
	}
	
	return 0;	
}
