#include<bits/stdc++.h>
using namespace std;

ifstream fin("photo.in");
ofstream fout("photo.out");

map<int,int> mp[5];

int cmp(int a,int b){
	int cnt=0;
	for(int i=0;i<5;i++)
		if(mp[i][a]<mp[i][b])
			cnt++;
	return cnt>=3;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;fin>>n;
	int arr[5][20000];
	for(int i=0;i<n*5;i++){
		fin>>arr[i/n][i%n];
		mp[i/n][arr[i/n][i%n]]=i%n;
	}
	sort(arr[0],arr[0]+n,cmp);
	for(int i=0;i<n;i++)
		fout<<arr[0][i]<<'\n';
}
