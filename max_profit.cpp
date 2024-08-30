#include <bits/stdc++.h>
using namespace std;
struct Data{
   int s,e,c;
   Data(int x, int y, int z){
      s= x;
      e= y;
      c = z;
   }
};
bool cmp(Data a, Data b){
   return a.e<b.e;
}
class Solution {
   public:
   int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p){
      vector<Data> j;
      int n = s.size();
      for (int i = 0; i < n; i++) {
         Data temp(s[i], e[i], p[i]);
         j.push_back(temp);
      }
      sort(j.begin(), j.end(), cmp);
      vector<int> dp(n);
      dp[0] = j[0].c;
      for (int i = 1; i < n; i++) {
         int temp = 0;
         int low = 0;
         int high = i - 1;
         while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (j[mid].e <= j[i].s)
               low = mid;
            else
               high = mid - 1;
         }
         dp[i] = j[i].c;
         if (j[low].e <= j[i].s)
            dp[i] += dp[low];
         dp[i] = max(dp[i], dp[i - 1]);
      }
      return dp[n - 1];
   }
};
int main(){
   Solution ob;
   vector<int> startTime = {1,2,3,3},
    endTime = {3,4,5,6},
     profit ={500,100,400,700};
   cout << (ob.jobScheduling(startTime, endTime, profit));
   return 0;
}
/*
int main() {
    Solution ob;
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<int> startTime(n), endTime(n), profit(n);

    cout << "Enter the start times of the jobs: ";
    for (int i = 0; i < n; ++i) {
        cin >> startTime[i];
    }

    cout << "Enter the end times of the jobs: ";
    for (int i = 0; i < n; ++i) {
        cin >> endTime[i];
    }

    cout << "Enter the profits of the jobs: ";
    for (int i = 0; i < n; ++i) {
        cin >> profit[i];
    }

    cout << (ob.jobScheduling(startTime, endTime, profit));
    return 0;
}
*/
