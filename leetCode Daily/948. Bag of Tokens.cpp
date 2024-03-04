class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
       int n = tokens.size();
       int idx = n - 1 ;
       sort(tokens.begin(), tokens.end());
       int score = 0;
       map<int, bool>used;
       for(int i = 0 ; i < n ; i++){
           if(power >= tokens[i] && !used[i]){
               score++;
               power-=tokens[i];
               used[i] = true;
           }else if(power < tokens[i] && !used[idx] && score >= 1){
               power += tokens[idx--];
               score--;
               i--;
           }
       }
       return score;
    }
};
