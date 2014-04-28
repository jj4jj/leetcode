
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
     void print(const char* s) const
	{
		cout<<s<<":"<<x<<","<<y<<endl;
	}
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
				int maxn = 2;
				for(int i = 0;i < points.size(); ++i)
				{
					mp.clear();
					for(int j = i+1; j < points.size(); ++j)
					{
						Point pt(points[j].x-points[i].x , points[j].y - points[i].y);

						/*
						if(mp.find(pt) != mp.end())
						{
							mp[pt]++;
						}
						else
						{
							mp[pt] = 2;
						}
						*/
						std::map<Point,int>::iterator it = mp.begin();
						bool bFind = false;
						while(it != mp.end())
						{
							if(pt.x*it->first.y == pt.y*it->first.x)
							{
								it->first.print("inc");
								it->second++;
								bFind = true;
								
								if(maxn < it->second)
								{
									maxn = it->second;
								}

							}
							++it;
						}
						if(false == bFind)
						{
							pt.print("add");
							mp[pt] = 2;
						}
					}
				}
				return maxn ;
			}
			void OnGetLine(string & line)
			{
				TokenNizer tn;
				vector<string> lst = tn.Split(line," ");

				vector<Point>	points;
				for(int i = 0; i < lst.size() - 1; i+=2)
				 {
					cout<<"----------"<<i<<endl;
					Point pt(std::atoi(lst[i].c_str()),std::atoi(lst[i+1].c_str())); 
					points.push_back(pt);	
				}

				cout<<maxPoints(points)<<endl;	
			}
	};


