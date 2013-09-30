#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include "BUAATonyShaw.h"
using namespace std;
inline long long max(long long a,long long b) { return a>b?a:b; }
inline long long min(long long a,long long b) { return a<b?a:b; }
/*long long Prepare(int f[][MaxN],long long a[][MaxN],int n,int m)
{
	queue<pair<int,int>> que;
	pair<int,int> h,t;
	int lab=0;
	for (int i=0;i!=n;++i) 
		for (int j=0;j!=m;++j) 
			if (a[i][j]<0) {
				if (PrCkRow(i-1,j,n,m)+PrCkRow(i,j,n,m)-a[i][j]<=a[i][j]) {
					f[i][j]=0;
					continue;
				}
				if (PrCkRow(i+1,j,n,m)+PrCkRow(i,j,n,m)-a[i][j]<=a[i][j]) {
					f[i][j]=0;
					continue;
				}
				if (PrCkCol(i,j-1,n,m)+PrCkCol(i,j,n,m)-a[i][j]<=a[i][j]) {
					f[i][j]=0;
					continue;
				}
				if (PrCkCol(i,j+1,n,m)+PrCkCol(i,j,n,m)-a[i][j]<=a[i][j]) {
					f[i][j]=0;
					continue;
				}
				f[i][j]=-1;
			} else f[i][j]=0;
	for (int i=0;i!=n;++i) 
		for (int j=0;j!=m;++j) if (a[i][j]>=0 && f[i][j]==0) {
			++lab;
			h.first=i; h.second=j;
			que.push(h);
			while (!que.empty()) {
				h=que.front();
				que.pop();
				if (h.first>0) {
					if (a[h.first-1][h.second]>0 && f[h.first-1][h.second]==0) {
						f[h.first-1][h.second]=lab;
						t.first=h.first-1;
						t.second=h.second;
						que.push(t);
					}
				}
				if (h.first+1<n) {
					if (a[h.first+1][h.second]>0 && f[h.first+1][h.second]==0) {
						f[h.first+1][h.second]=lab;
						t.first=h.first+1;
						t.second=h.second;
						que.push(t);
					}
				}
				if (h.second>0) {
					if (a[h.first][h.second-1]>0 && f[h.first][h.second-1]==0) {
						f[h.first][h.second-1]=lab;
						t.first=h.first;
						t.second=h.second-1;
						que.push(t);
					}
				}
				if (h.second+1<m) {
					if (a[h.first][h.second+1]>0 && f[h.first][h.second+1]==0) {
						f[h.first][h.second+1]=lab;
						t.first=h.first;
						t.second=h.second+1;
						que.push(t);
					}
				}
			}
		}				
	return 0;
}*/
long long Solve(int n,int lmt,int m,long long f[][MaxN],bool isHorizontal)
{
	long long ans(NINF),tmp(0),seq(0),hrAns(INF),hrTot(0),hrMax(NINF),hrSeq(0);//hr used for horizontal mode
	for (int i=1;i!=lmt;++i) for (int j=0;j!=m;++j) f[i][j]+=f[i-1][j];
	for (int i=-1;i!=n;++i) 
		for (int j=i+1;j!=lmt && j-i<=n;++j) {
			for (int k=0;k!=m;++k) {
				if (i==-1) tmp=f[j][k]-0; else tmp=f[j][k]-f[i][k];
				ans=ans>(seq=seq>0?seq+tmp:tmp)?ans:seq;
				if (isHorizontal) {
					hrTot+=tmp;
					hrMax=max(hrMax,tmp);
					hrAns=hrAns<(hrSeq=hrSeq<0?hrSeq+tmp:tmp)?hrAns:hrSeq;
				}
			}
			if (isHorizontal) {
				if (ans<0 && hrTot==hrAns && hrMax<0) ans=max(ans,hrMax); 
				else ans=max(ans,hrTot-hrAns);
				hrAns=INF;
				hrMax=NINF;
				hrTot=0;
				hrSeq=0;
			}
			seq=0;
		}
	return ans;
}
long long Regular(int n,int m,long long f[][MaxN])
{
	return Solve(n,n,m,f,false);
}
long long Horizontal(int n,int m,long long f[][MaxN])
{
	return Solve(n,n,m,f,true);
}
long long Vertical(int n,int m,long long f[][MaxN])
{
	for (int i=0;i!=n;++i)
		for (int j=0;j!=m;++j) f[i+n][j]=f[i][j];
	return Solve(n,n<<1,m,f,false);
	return 0;
}
long long Ring(int n,int m,long long f[][MaxN])
{
	for (int i=0;i!=n;++i)
		for (int j=0;j!=m;++j) f[i+n][j]=f[i][j];
	return Solve(n,n<<1,m,f,true);
	return 0;
}
long long Inregular(int n,int m,long long a[][MaxN])//Notice in this function we changed f to a
{
	cout<<"Oops! I don't know how to solve this problem."<<endl
		<<"I found a rectangle which have the maxi-sub-sum."<<endl
		<<"You can use this value as an approximate answer..."<<endl<<endl;
	return Regular(n,m,a);
}
long long Inregular2(int n,int m,long long a[][MaxN])//Notice in this function we changed f to a
{
	cout<<"Oops! I don't know how to solve this problem."<<endl
		<<"I found a rectangle which have the maxi-sub-sum."<<endl
		<<"You can use this value as an approximate answer..."<<endl<<endl;
	return Ring(n,m,a);
}