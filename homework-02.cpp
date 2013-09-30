#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
#include<algorithm>
#include "BUAATonyShaw.h"
#pragma warning(disable:4996)//I will continue to use fopen
using namespace std;

int n(0),m(0);
long long f[MaxN][MaxN];
bool isHorizontal(false);

int ErrorHandle(char* errInfo){
	cerr<<errInfo<<endl;
	return -1;
}

int Init(char * fileDir) {
	//HAVE TO INIT n,m,f,horizontalConnection
	FILE *infile;
	infile=fopen(fileDir,"r");
	if (!(~fscanf(infile,"%d,",&n))) return ErrorHandle("File format error while read n");
	if (!(~fscanf(infile,"%d,",&m))) return ErrorHandle("File format error while read m");
	if (n<=0 || m<=0) return ErrorHandle("matrix's dimension isn't in the range");
	for (int i=0;i!=n;++i)
		for (int j=0;j!=m;++j) 
			if (!(~fscanf(infile,"%lld,",&f[i][j]))) return ErrorHandle("File format error while read the matrix");
	if (n>m) {//(n>2*m)
		for (int i=0;i!=n;++i)
			for (int j=i+1;j<n;++j) swap(f[i][j],f[j][i]);
		swap(n,m);
		isHorizontal=!isHorizontal;
	}
	return 0; 
}
int Print(long long ans) {
	printf("Answer: %lld\n",ans);
	return 0;
}

int main(int argc,char* argv[])
{
	long long ans;
	if (!(~Init(argv[argc-1]))) return -1;
	switch (argc) {
	case 1 : return ErrorHandle("Arguments not enough");
	case 2 : ans=Regular(n,m,f); break;
	case 4 : ans=Ring(n,m,f); break;
	case 5 : ans=Inregular2(n,m,f); break;
	case 3 : 
		switch (argv[argc-2][strlen(argv[argc-2])-1]) {
		case 'a' : ans=Inregular(n,m,f); break;
		case 'h' : isHorizontal=!isHorizontal; //No break 
		case 'v' : ans=isHorizontal?Horizontal(n,m,f):Vertical(n,m,f); break;
		default : return ErrorHandle("Can not excute with current arguments");
		}
		break;
	default : ErrorHandle("Can not excute with current arguments");
	}
	Print(ans);
	return 0;
}