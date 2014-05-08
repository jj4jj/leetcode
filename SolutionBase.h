#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;



class TokenNizer
{
public:
	vector<string>	Split(string s,const char* pszDelim)	
	{
		int len = strlen(pszDelim);
		const char* pStart , * pEnd;
		pEnd  = pStart = s.c_str();	
		vector<string> lst;
		cout<<"split the string:<"<<s<<"> result as follow"<<endl;
		while((pEnd = strstr(pStart,pszDelim)))
		{
			if(pEnd > pStart)
			{
				cout<<string(pStart,pEnd-pStart)<<",";
				lst.push_back(string(pStart,pEnd-pStart));	
			}
			pStart = pEnd + len;
		}
		if(pStart)
		{
			cout<<string(pStart);
			lst.push_back(string(pStart));	
		}
		cout<<endl;
		cout<<"split ok list len = "<<lst.size()<<endl;
		return lst;
	}
	
};

