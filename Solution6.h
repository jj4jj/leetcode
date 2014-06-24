
#include "list"
#include "iterator"
#include "map"
using namespace std;
class LRUCache{
	public:
		typedef std::list<std::pair<int,int> > KL;
		typedef KL::iterator KLItr;
		typedef std::map<int,KLItr> KM;
		typedef KM::iterator KMItr;
		KM	km;
		KL kl;
		int n;
		LRUCache(int capacity) {
			n = capacity;
		}

		int get(int key) {
			KMItr it = km.find(key);
			if(it!=km.end())
			{
				int v = it->second->second;	
				kl.erase(it->second);
				kl.push_front(make_pair(key,v));
				it->second = kl.begin();
				return v;
			}
			return -1;
		}

		void set(int key, int value) {
			KMItr it = km.find(key);
			if(it == km.end())
			{
				if(kl.size() >= n)
				{
					km.erase(kl.back().first);	
					kl.pop_back();
				}
				kl.push_front(make_pair(key,value));
			}
			else
			{
				kl.push_front(*(it->second));
				kl.erase(it->second);	
			}
			km[key]=kl.begin();
		}
};

