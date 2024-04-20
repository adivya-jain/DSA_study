// Finding Missing in Second Array without considering the order
//gfg 19 april potd
// class Solution
// {

// public:
//     vector<int> findMissing(int a[], b[], int n, int m)
//     {
//         sort(a, a + n);
//         sort(b, b + m);

//         int i = 0;
//         int j = 0;
//         vector<int> c;
//         while (i < n && j < m)
//         {
//             if (a[i] < b[j])
//             {
//                 c.push_back(a[i]);
//                 i++;
//             }
//             else if (b[j] < a[i])
//             {
//                 j++;
//             }
//             else
//             {
//                 i++;
//                 j++;
//             }
//         }
//         while (i < n)

//         {
//             c.push_back(a[i]);
//             i++;
//         }
//         return c;
//     }
// };


	public:
	vector<int> findMissing(int a[], int b[], int n, int m) 
	{ 
	    // Your code goes here
	  unordered_set<int> checker;
	  
	  for(int i=0;i<m;i++)
	  {
	      checker.insert(b[i]);
	  }
	  
	  vector<int> ans;
	  
	  for(int i=0;i<n;i++)
	  {
	      if(checker.find(a[i])==checker.end())
	      {
	          ans.push_back(a[i]);
	      }
	  }
	  
	  return ans;
	}