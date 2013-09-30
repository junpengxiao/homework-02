#ifndef BUAATONYSHAW_H
#define BUAATONYSHAW_H
#define MaxN 512
#define NINF ((long long)-1E18)
#define INF ((long long)1E18)
inline long long max(long long a,long long b);
inline long long min(long long a,long long b);
long long Regular(int n,int m,long long f[][MaxN]);
long long Ring(int n,int m,long long f[][MaxN]);
long long Inregular(int n,int m,long long f[][MaxN]);
long long Vertical(int n,int m,long long f[][MaxN]);
long long Horizontal(int n,int m,long long f[][MaxN]);
long long Inregular2(int n,int m,long long a[][MaxN]);
int ErrorHandle(char* errInfo);
#endif