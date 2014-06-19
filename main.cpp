
#include "SolutionBase.h"
#include "Solution1.h"
#include "Solution2.h"
#include "Solution3.h"
#include "Solution4.h"
#include "Solution5.h"


int main()
{
	Solution5	s;	
	char line[1024];
	while(gets(line))
	{
		string sline = line;
		s.OnGetLine(sline);
	}
	return 0;	
}
