#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> PP;

bool is_notused(string s, string t, int index, bool isUsed[]){
    for(int i=0;i<t.size();i++){
        if(t[i]==s[index]&&!isUsed[t[i]-'a'])return true;
    }
     return false;
}
bool isComplete(string t, bool isUsed[]){
    for(int i=0;i<t.size();i++){
        if(!isUsed[t[i]-'a'])return false;
    }
    return true;
}

string findMinSubString(string s, string t){
    sort(t.begin(),t.end());
    vector<int> indices;  
    vector<PP> v;
    bool isUsed[26];
    fill(isUsed,isUsed+26,0);
    for(int i=0;i<s.size();i++){
        if(is_notused(s, t, i, isUsed)){
            indices.push_back(i);
            sort(indices.begin(),indices.end());
            isUsed[s[i]-'a']=true;
            if(isComplete(t,isUsed)){
                v.push_back(PP(indices.back()-indices.front()+1,P(indices.front(),indices.back())));
                isUsed[s[indices[0]]-'a'] = false;
                i = indices[0]+1;
                indices.erase(indices.begin());
            }
        }
    }
    sort(v.begin(),v.end());
    PP pp = v[0];
    P p = pp.second;
    string ans = s.substr(p.first,p.second);
    return ans;
}

int main(){
    string s = "adobecodebanc";
    string t = "abc";
    string ret = findMinSubString(s,t);
    cout << ret << endl;
}
