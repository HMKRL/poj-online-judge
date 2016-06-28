#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int cnt[5010];

struct Node
{
    double x;       
    double y;
}toy[5010], up[5010], down[5010];

double cross(Node a, Node b, Node c)
{
    return (a.x-c.x) * (b.y-c.y) - (b.x-c.x) * (a.y-c.y);    
}

bool cmp(Node &a,Node &b)
{
    return a.x < b.x;        
}

int main()
{
    int n, m, i, j;
    double u, l, x1, x2, y1, y2, tmp1, tmp2;

    while(scanf("%d", &n) != EOF && n)
    {
         scanf("%d %lf %lf %lf %lf", &m, &x1, &y1, &x2, &y2);
         memset(cnt,0,sizeof(cnt));
         up[0].x = x1;
         up[0].y = y1;
         down[0].x = x1;
         down[0].y = y2;
         up[n+1].x = x2;
         up[n+1].y = y1;
         down[n+1].x = x2;
         down[n+1].y = y2;
         for(i = 1;i <= n;i++) {
             scanf("%lf%lf", &u, &l);
             up[i].x = u;
             up[i].y = y1;
             down[i].x = l;
             down[i].y = y2;
         }
         for(i = 0;i < m;i++) {
             scanf("%lf%lf", &toy[i].x, &toy[i].y);
         }
         for(i = 0;i < m;i++) {
             for(j = 1;j <= n + 1;j++)
             {
                 tmp1 = cross(up[j-1], down[j-1], toy[i]);
                 tmp2 = cross(up[j], down[j], toy[i]);
                 if(tmp1 * tmp2 <= 0)
                 {                   
                     ++cnt[j-1];             
                     continue;
                 }
             }
         }
         for(i = 0;i <= n;i++) {
             printf("%d: %d\n", i, cnt[i]);
         }
         printf("\n");
    }
    return 0;
}
