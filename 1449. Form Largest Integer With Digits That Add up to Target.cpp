//backtracking, combination of digits
//TLE
//4 / 96 test cases passed.
class Solution {
public:
    void backtrack(int target, vector<int>& cost, string& ans, string& cur){
        if(target == 0){
            if(cur.size() > ans.size()){
                ans = cur;
            }else if(cur.size() == ans.size() && cur > ans){
                ans = cur;
            }
            return;
        }
        
        if(target < 0){
            return;
        }
        
        //target > 0
        for(int i = 0; i < cost.size(); i++){
            if(cost[i] <= target){
                cur += (char)(i+1+'0');
                backtrack(target- cost[i], cost, ans, cur);
                cur.pop_back();
            }
        }
    }
    
    string largestNumber(vector<int>& cost, int target) {
        string ans;
        string cur;
        backtrack(target, cost, ans, cur);
        
        if(ans == "") ans = "0";
        
        return ans;
    }
};

//backtracking, combination of unique costs
//TLE
//31 / 96 test cases passed.
class Solution {
public:
    void backtrack(int target, set<int>& ucost, set<vector<int>>& results, vector<int>& result){
        if(target == 0){
            results.insert(result);
            return;
        }
        
        if(target < 0){
            return;
        }
        
        //target > 0
        for(int c : ucost){
            if(c <= target){
                result.push_back(c);
                backtrack(target-c, ucost, results, result);
                result.pop_back();
            }
        }
    }
    
    string largestNumber(vector<int>& cost, int target) {
        string ans;
        string cur;
        set<vector<int>> results;
        vector<int> result;
        
        map<int, int> cost2maxNum;
        for(int i = 0; i < cost.size(); i++){
            cost2maxNum[cost[i]] = max(cost2maxNum[cost[i]], i+1);
        }
        
        set<int> ucost(cost.begin(), cost.end());
        
        backtrack(target, ucost, results, result);
        
        if(results.size() == 0) ans = "0";
        
        for(vector<int> res : results){
            if(res.size() < ans.size()) continue;
            cur = "";
            for(int r : res){
                cur += (char)('0'+cost2maxNum[r]);
            }
            if(cur.size() > ans.size()){
                ans = cur;
            }else if(cur.size() == ans.size()){
                ans = max(ans, cur);
            }
        }
        
        // cout << "================" << endl;
        return ans;
    }
};