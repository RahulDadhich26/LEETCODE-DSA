class Solution {
public:
    bool checkValid(vector<vector<int>>& m) {
        int n = m.size() ;

        for(int i=0;i<n;i++){
             unordered_set<int>rowSet ;
            for(int j=0;j<n;j++){
                int num = m[i][j];
                if(num < 1 || num > n || rowSet.count(num))return false;
                rowSet.insert(num);
            }
            
        }
      
            for(int j=0;j<n;j++){
              unordered_set<int>ColSet ;
           
                for(int i=0;i<n;i++){
                int num = m[i][j];
                if(num < 1 || num > n || ColSet.count(num))return false;
                 ColSet.insert(num);
            }
           
        }
        return true;
    }
};