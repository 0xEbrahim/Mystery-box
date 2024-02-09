class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int, int>, bool>vis;
        pair<int, int>curr = {0,0};
        vis[{0,0}]= true;
        for(int i = 0 ; i < path.size() ; i++){
            if(path[i] == 'N'){
                curr.second+=1;
                if(!vis[curr]){
                    vis[curr] = true;
                }else{
                    return true;
                }
            }else if(path[i] == 'E'){
                 curr.first+=1;
                if(!vis[curr]){
                    vis[curr] = true;
                }else{
                    return true;
                }
            }else if(path[i] == 'S'){
                 curr.second-=1;
                if(!vis[curr]){
                    vis[curr] = true;
                }else{
                    return true;
                }
            }else if(path[i] == 'W'){
                 curr.first-=1;
                if(!vis[curr]){
                    vis[curr] = true;
                }else{
                    return true;
                }
            }
        }
        return false;
    }
};
