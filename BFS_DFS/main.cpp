//
//  main.cpp
//  BFS_DFS
//
//  Created by dongho on 2019/12/27.
//  Copyright © 2019 dongho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;



int main() {
    int n; // 정점개수
    int m; // 간선개수
    int s; // 시작점
    
    cin >> n >> m >> s;
    
    //엣지 vector
    vector<int> v[n+1]; //0은 사용 안해서
    
    //방문처리 위한 동적 배열
    bool *c = new bool[n+1]; //0은 사용 안해서
    
    //엣지 연결하기
    int *x = new int[m];
    int *y = new int[m];
    int z=0;
    //m만큼 일단 입력받아야됨
    
    for(int i=0; i<m; i++){
        cin >> x[i] >> y[i];
    }
    for(int i=0; i<m; i++){
        if(x[i]==x[i+1]){
            z++;
        }
        if(x[i] != x[i+1] && z>0){
            if(z==1)
                swap(y[i], y[i-1]);
            else{
                for(int j=i-z; j<i; j++){
                    for(int k=i-z+1; k<=i; k++){
                        if(y[j] > y[k])
                            swap(y[k], y[j]);
                    }
                }
            }
            z=0;
        }
    }
    
    for(int i=0; i<m; i++){
        v[x[i]].push_back(y[i]);
        v[y[i]].push_back(x[i]);
    }
    
    
    //DFS (스택이용)
    stack<int> st;
    for(int i=1; i<n+1; i++){
        c[i] = false;
    }
    //
    int t=s;
    int ini=0;//처음인지 확인
    int che=0; //
    st.push(t);
    c[t]=true;
    cout << t <<" ";
    while(st.top() != s || ini==0 ){
        ini++;
        
        for(vector<int>::size_type i=0; i<v[t].size(); i++){
            int tt = v[t][i];
            if(!c[tt]){
                c[tt] = true;
                cout << tt <<" ";
                st.push(tt);
                t = tt;
                che=1;
            }
        }
        //더이상 방문할 곳이 없는 노드일때
        if(che != 1){
            t = st.top();
            st.pop();
        }
        che = 0;
    }
    cout << endl;
    
    //BFS (큐이용)
    queue<int> q;
    for(int i=1; i<n+1; i++){
        c[i] = false;
    }
    q.push(s);
    c[s] = true;
    
    while(!q.empty()){
        
        int t = q.front();
        q.pop();
        cout << t << " ";
        for(vector<int>::size_type i=0; i<v[t].size(); i++){
            int tt = v[t][i];
            if(!c[tt]){
                q.push(tt);
                c[tt] = true;
            }
        }
    }
}

