
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
									//////////////////////////////////////////

									bool b = (pt1.x * pt2.y) < (pt1.y * pt2.x);
									return b;
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
				int maxn = 0;
				Point tpt;
				for(int i = 0;i < points.size(); ++i)
				{
					mp.clear();
					for(int j = 0; j < points.size(); ++j)
					{
						if(i == j)
						{
							continue;	
						}
						Point pt(points[j].x-points[i].x , points[j].y - points[i].y);

		//				cout<<"befor <"<<points[i].x<<","<<points[i].y<<"> ----> <"<<points[j].x<<","<<points[j].y<<"> | <"<<pt.x<<","<<pt.y<<">:"<<mp[pt]<<endl;
						mp[pt]++;
						cout<<"after <"<<points[i].x<<","<<points[i].y<<"> ----> <"<<points[j].x<<","<<points[j].y<<"> | <"<<pt.x<<","<<pt.y<<">:"<<mp[pt]<<endl;
						if(maxn < mp[pt])
						{
							maxn = mp[pt];
							tpt = pt;
						}
					}
				}
				return maxn + 1;
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


