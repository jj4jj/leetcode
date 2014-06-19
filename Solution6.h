
class LRUCache{
	public:
		typedef std::map<int,int>	KV;
		typedef std::map<int,int > KA;
		typedef KV::iterator KVItr;
		KV kv;
		KA ka;
		int n;
		int epoch;
		LRUCache(int capacity) {
			n = capacity;
			epoch = 0;
			kv.clear();
			ka.clear();
		}

		int get(int key) {
			KVItr it = kv.find(key);
			if(it == kv.end())
			{
				return -1;	
			}
			ka[key] = epoch++;
			return it->second;
		}

		void set(int key, int value) {
			KVItr it = kv.find(k);
			if(it == kv.end() &&
			  kv.size() >= n)
			{
				it = kv.begin();
				int iMin = 0xFFFFFFFF;
				KVItr t = kv.begin();
				while(it != kv.end())
				{
					if(*it < iMin)
					{
						iMin = *it;
						t = it;
					}
				}
				ka.erase(t->first);
				kv.erase(t);
			}
			kv[key]=value;
			ka[key]=epoch++;
		}
		void OnGetLine(string & line)
		{
			reverseWords(line);
			cout<<line<<endl;		
		}
};


