
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };

	class Solution3 {
		public:
			struct Line
			{
				Point slope;
				Point p0;	
				Line(Point s,Point p):slope(s.x,s.y),p0(p.x,p.y){}
			};
			int maxPoints(vector<Point> &points) {
				//find them on a same line
				if(points.size() <= 2)
				{
					return points.size();	
				}
				std::vector<std::pair<Line,int> >	mp;
				int maxn = 2;
				for(int i = 0;i < points.size(); ++i)
				{

					mp.clear();
					for(int j = i+1; j < points.size(); ++j)
					{
						Point pt(points[j].x-points[i].x , points[j].y - points[i].y);
						std::vector<std::pair<Line,int> >::iterator it = mp.begin();
						bool bFind = false;
						while(it != mp.end())
						{
							//y = kx+b
							//y2-y1 = k(x2-x1) = pt.y/pt.x(x2-x1)
							//y2-kx2 = y1 - kx1 -> y2 - y1 = k(x2 - x1)
							//y1,x1 -> first
							//y2,x2 -> points j
							if(pt.x*(it->first.slope.y) == pt.y*(it->first.slope.x) &&
							   (points[j].y - it->first.p0.y)*pt.x == (points[j].x - it->first.p0.x)*pt.y )
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
							mp.push_back(std::make_pair(Line(pt,points[i]),2));
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


