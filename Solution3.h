
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };

	class Solution3 {
		public:
			int maxPoints(vector<Point> &points) {
				//find them on a same line
				if(points.size() <= 2)
				{
					return points.size();	
				}
				std::vector<std::pair<Point,int> >	mp;
				int maxn = 2;
				for(int i = 0;i < points.size(); ++i)
				{

					mp.clear();
					for(int j = i+1; j < points.size(); ++j)
					{
						Point pt(points[j].x-points[i].x , points[j].y - points[i].y);
						std::vector<std::pair<Point,int> >::iterator it = mp.begin();
						bool bFind = false;
						while(it != mp.end())
						{
							if(pt.x*(it->first.y) == pt.y*(it->first.x))
							{
								it->second++;	
								if(maxn < it->second)
								{
									maxn = it->second;
								}
								bFind = true;
							}
							it++;	
						}
						if(false == bFind)
						{
							mp.push_back(std::make_pair(pt,2));
						}
					}
				}
				return maxn;
			}
			void OnGetLine(string & line)
			{
				TokenNizer tn;
				vector<string> lst = tn.Split(line," ");
				vector<Point>	points;
				for(int i = 0; i < lst.size(); i+=2)
				 {
					Point pt(std::atoi(lst[i].c_str()),std::atoi(lst[i+1].c_str())); 
					points.push_back(pt);	
				}
				cout<<maxPoints(points)<<endl;	
			}
	};


