
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };

	class Solution3 {
		public:
			int maxPoints(vector<Point> &points) {
				if(points.size() <= 2)
				{
					return points.size();	
				}
				//sope is Point
				std::vector<std::pair<Point,int> >	lineCounter;
				int maxn = 2;
				for(int i = 0;i < points.size(); ++i)
				{
					//past points[i] and slope is in counter
					lineCounter.clear();
					int iSlop0 = 0;
					int	iSlopNot0 = 0;
					for(int j = i+1; j < points.size(); ++j)
					{
						Point pt(points[j].x-points[i].x , points[j].y - points[i].y);
						std::vector<std::pair<Point,int> >::iterator it = lineCounter.begin();
						bool bFind = false;
						while(it != lineCounter.end() && !(pt.x == 0 && pt.y == 0))
						{
							//the line in the counter must pass points[i] and slop is lineCounter.first
							//if j is in a line (parrall with lineCounter.first) , so the lineCounter.second++; 
							if(pt.x*(it->first.y) == pt.y*(it->first.x))
							{
								it->second++;	
								if(iSlopNot0 < it->second)
								{
									iSlopNot0 = it->second;
									//cout<<points[i].x<<","<<points[i].y<<"->"<<(it->first).x<<","<<(it->first).y<<"->"<<endl;
								}
								bFind = true;
								break;
							}
							it++;	
						}
						if(false == bFind)
						{
							//the line slop is <i,j> and past i
							if(pt.x == 0 && pt.y == 0 )
							{
								iSlop0++;
								cout<<"0,0:i="<<i<<"slop0="<<iSlop0<<":"<<points[i].x<<","<<points[i].y<<"->"<<points[j].x<<","<<points[j].y<<endl;	
							}
							else
							{
								lineCounter.push_back(std::make_pair(pt,2));
								if(0 == iSlopNot0)
								{
									iSlopNot0 = 2;
								}
							}
						}
					}
					if(iSlopNot0 == 0)
					{
						iSlop0++;	
					}
					if(maxn < iSlopNot0 + iSlop0)
					{
						maxn = iSlopNot0 + iSlop0;	
					}
					
				}
				return maxn;
			}
			void OnGetLine(string & line)
			{
				TokenNizer tn;
				vector<string> lst = tn.Split(line," ");
				vector<Point>	points;
				for(int i = 0; i < lst.size()-1; i+=2)
				 {
					Point pt(std::atoi(lst[i].c_str()),std::atoi(lst[i+1].c_str())); 
					points.push_back(pt);	
				}
				cout<<maxPoints(points)<<endl;	
			}
	};


