class Solution {
    
    vector<int> groups;
    
    int findAndUpdateParent(int x){
        if(groups[x] == x){
            return x;
        }
        
        return groups[x] = findAndUpdateParent(groups[x]);
    }
    
public:
    bool equationsPossible(vector<string>& Eqs) {
        groups.resize(26);
        
        for(int i = 0; i < 26; ++i){
            groups[i] = i;
        }
        
        for(auto &eqn: Eqs){
            if(eqn[1] == '='){
                groups[findAndUpdateParent(eqn[3]-'a')] = findAndUpdateParent(eqn[0]-'a');
            }
        }
        
        for(auto &eqn: Eqs){
            if(eqn[1] == '!' && 
               findAndUpdateParent(eqn[3]-'a') == findAndUpdateParent(eqn[0]-'a')
            ){
                return false;
            }
        }

        return true;
    }
};