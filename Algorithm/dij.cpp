﻿#include <iostream>
#include <vector>
using namespace std;

const int NUM = 10;
const int MAXINT = 99999;

unsigned int Dij(vector<vector<int> > subGraph,unsigned int start,unsigned int end)
{
    int dist[NUM];
    bool vistFlag[NUM];

    //初始化图
    for(int i = 0;i < NUM;i++)
    {
        dist[i] = subGraph[start][i];
        vistFlag[i] = false;
    }
    dist[start] = 0;
    vistFlag[start] = true;
    
    for(int i = 1;i < NUM;i++)
    {
        int mindist = MAXINT;
        int u = start;

        for(int j = 1;j != NUM;j++)
        {
            if(vistFlag[j] == false && dist[j] < mindist)
            {
                mindist = dist[j];
                u = j;
            }
        }

        vistFlag[u] = true;
        //更新u的邻接点
        for(int j = 1;j != NUM;j++)
        {
            if(vistFlag[j] == false && subGraph[u][j] < MAXINT)
            {
                if(dist[j] > dist[u] + subGraph[u][j])
                    dist[j] =  dist[u] + subGraph[u][j];
            }
        }
    }
    return dist[end];
}


int main(void)
{
    vector<vector<int> > subGraph(10,vector<int>(100,MAXINT));
    subGraph[0][1] = 6;
    subGraph[0][2] = 3;
    subGraph[1][0] = 6;
    subGraph[1][2] = 2;
    subGraph[1][3] = 5;
    subGraph[2][0] = 3;
    subGraph[2][1] = 2;
    subGraph[2][3] = 3;
    subGraph[3][1] = 5;
    subGraph[3][2] = 3;

    cout << Dij(subGraph,0,3) << endl;

}