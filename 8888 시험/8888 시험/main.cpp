//
//  main.cpp
//  8888 시험
//
//  Created by Emma on 2020/02/22.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int check[2001][2001];
int point[2001];

struct info{
    int number;
    int score;
    int solved;
};

void Init(){
    memset(check, 0, sizeof(check));
    memset(point, 0, sizeof(point));
}

bool compare(info a, info b) {
    if(a.score == b.score){
        if(a.solved == b.solved){
            return a.number < b.number;
        }
        else
            return a.solved > b.solved;
    }
    else
        return a.score > b.score;
}


int main(){
    int Tc; scanf("%d", &Tc);
    int c = 1;
    while(Tc--) {
        int n, t, p;
        scanf("%d %d %d", &n, &t, &p);
        getchar();
        Init();
        
        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= t;j++){
                char achar = getchar();
                getchar();
                if(achar =='0')
                    point[j]++;
                else
                    check[i][j] = 1;
            }
        }
        
        vector<info> v1(n+1);
        for(int i = 1; i <= n;i++){
            v1[i].number = i;
            for(int j = 1; j <= t;j++){
                if(check[i][j]){
                    v1[i].score += point[j];
                    v1[i].solved++;
                }
            }
        }
        sort(v1.begin()+1 , v1.end(), compare);
        for(int i = 1; i <= n; i++){
            if(v1[i].number == p){
//                cout<<"#"<<c++<<' '<<v1[i].score<<' '<<i<<'\n';
                printf("#%d %d %d\n", c++, v1[i].score, i);
                break;
            }
        }
    }
    return 0;
}
