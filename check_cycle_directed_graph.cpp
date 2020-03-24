bool dfs(int s){
    if(vis[s]) return false;
    vis[s] = true;
    bool flag = true;
    for(auto x:adj[s]){
        flag = dfs(x);
        if(!flag) return flag;
    }
    vis[s] = false;
    return flag;
}
