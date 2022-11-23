//Question:- Given a string s. In one step you can insert any character at any index of the string.
// Return the minimum number of steps to make s palindrome.
// A Palindrome String is one that reads the same backward as well as forward.
//M1.Recursion
 int fun(string s,string str,int i,int j){
        if(i<0||j<0)return 0;
       if(s[i]==s[j])return 1+fun(s,str,i-1,j-1);
        return max(fun(s,str,i-1,j,dp),fun(s,str,i,j-1));
    }
 int minInsertions(string s) {
        string str=s;
        reverse(s.begin(),s.end());
        int n=s.size();
       return (n-fun(s,str,n-1,n-1));
    }

//M2.Meomisation
  int fun(string s,string str,int i,int j,vector<vector<int>>&dp){
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j])return dp[i][j]=1+fun(s,str,i-1,j-1,dp);
        return dp[i][j]=max(fun(s,str,i-1,j,dp),fun(s,str,i,j-1,dp));
    }
 int minInsertions(string s) {
        string str=s;
        reverse(s.begin(),s.end());
        int n=s.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return (n-fun(s,str,n-1,n-1,dp));
    }


//M3.Tabulation
int minInsertions(string s) {
        string str=s;
        reverse(s.begin(),s.end());
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<=n;i++)dp[0][i]=0;
        for(int j=0;j<=n;j++)dp[j][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==str[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return (n-dp[n][n]);
    }


//M4.
int minInsertions(string s) {
        string str=s;
        reverse(s.begin(),s.end());
        int n=s.size();
        vector<int>prev(n+1,0)cur(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==str[j-1])cur[j]=1+prev[j-1];
                else 
                  cur[j]=max(prev[j],cur[j-1]);
            }
          prev=cur;
        }
        return (n-prev[n]);
    }

