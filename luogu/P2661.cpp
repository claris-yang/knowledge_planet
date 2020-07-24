//
// Created by yangtao on 19-11-5.
//
d
int main(){
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        cin>>ti[i];
        orderjsdxxxxxk[i]=MAX_VAL;
        color[i]=-1;
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i);
    }
    cout<<min_loop<<endl;
    return 0;
}