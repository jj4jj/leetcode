
#include "SolutionBase.h"
#include "Solution1.h"
#include "Solution2.h"
#include "Solution3.h"
//#include "Solution4.h"

int main()
{

#ifdef S1
	Solution1 s;
#endif
#ifdef S2
	Solution2 s;
#endif
#ifdef S3
	Solution3 s;
#endif
#ifdef S4
	Solution4 s;
#endif
#ifdef S5
	Solution5 s;
#endif
#ifdef S6
	Solution6 s;
#endif
	char line[1024];
	while(gets(line))
	{
		string sline = line;
		s.OnGetLine(sline);
	}
	return 0;	
}
