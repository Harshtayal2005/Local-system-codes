#include<iostream>
#include<vector>
#include<string>
using namespace std;


    bool isSafe(int x, int y, vector<vector<int>>visited, int n, vector<vector<int>>m){
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(vector<vector<int>> m, int n, vector<vector<int>> visited, int x, int y, string path, 
    vector<string>&ans){
        // base case
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        visited[x][y]=1;
        //left
        int newx = x;
        int newy = y-1;
        if(isSafe(newx, newy, visited, n, m)){
            path.push_back('L');
            solve(m, n, visited, newx, newy, path, ans);
            path.pop_back();
        }
        //right
        newx = x;
        newy = y+1;
        if(isSafe(newx, newy, visited, n, m)){
            path.push_back('R');
            solve(m, n, visited, newx, newy, path, ans);
            path.pop_back();
        }
        //up
        newx = x-1;
        newy = y;
        if(isSafe(newx, newy, visited, n, m)){
            path.push_back('U');
            solve(m, n, visited, newx, newy, path, ans);
            path.pop_back();
        }
        //down
        newx = x+1;
        newy = y;
        if(isSafe(newx, newy, visited, n, m)){
            path.push_back('D');
            solve(m, n, visited, newx, newy, path, ans);
            path.pop_back();
        }
        visited[x][y]=0;
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        if(m[0][0]==0){
            return ans;
        }
        //initialising visited with 0
        vector<vector<int>> visited(n, vector<int>(n, 0));

        string path="";
        int srcx=0;
        int srcy=0;
        solve(m, n, visited, srcx, srcy, path, ans);
        return ans;
    }
int main(){
    vector<vector<int>> m;
    int n = 4;
    for(int i=0; i<n; i++){
    vector<int> row;
    for(int j=0; j<n; j++){
        int value;
        cin >> value;
        row.push_back(value);
    }
    m.push_back(row);
}
    vector<string>ans = findPath(m, n);
    for(string ele:ans){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
