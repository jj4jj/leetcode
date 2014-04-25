
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };
 namespace std{
	 template<>
	 struct less<Point> 
	 {
		bool operator()(const Point & pt1,const Point & pt2)
		{
			return 	(pt1.x * pt2.y) < (pt1.y * pt2.x);
		}	 
	};
	 
	 };
	class Solution3 {
		public:
			int maxPoints(vector<Point> &points) {
				//find them on a same line
				if(points.size() <= 2)
				{
					return points.size();	
				}
				std::map<Point,int>	mp;
				int maxn = 2;
				for(int i = 0;i < points.size(); ++i)
				{
					for(int j = i; j < points.size(); ++j)
					{
						Point pt(points[j].x-points[i].x , points[j].y - points[i].y);
						mp[pt]++;
						if(maxn < mp[pt])
						{
							maxn = mp[pt];
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


