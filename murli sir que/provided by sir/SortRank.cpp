
#include <iostream>
using namespace std;

void
Merge (int A[], int l, int r)
{

	long long int mid, i, j, B[r - l + 1], p = 0;
	mid = (l + r) / 2;
	i = l;
	j = mid + 1;

	while (i < mid + 1 && j < r + 1)
	{
		if (A[i] <= A[j])
			B[p++] = A[i++];
		else
		{

			B[p++] = A[j++];
		}
	}

	while (i < mid + 1)
		B[p++] = A[i++];

	while (j < r + 1)
		B[p++] = A[j++];

	i = l;
	p = 0;
	while (i < r + 1)
		A[i++] = B[p++];
}

void printArray(int A[],int n) {
	int i;
	for(i=0; i<n; ++i)
		cout<<A[i]<<" ";
	cout<<"\n";
}
int Rank(int A[],int n, int B[], int m, int k) {
	//cout<<k<<"\n";
	if (m+n<k || k< 1) return -1;


	else if(n==0) return B[m-k];
	else if(m==0) return A[n-k];
	else if (k==1) {
		if (A[n-1]>B[m-1]) return A[n-1];
		else return B[m-1];
	}
	else {
		int i=n-k/2, j=m-k/2;

		if(i<0) i=0;
		if(j<0) j=0;

		if(A[i]>B[j]) return Rank(A,i,B,m,k-n+i);
		else return Rank(A,n,B,j,k-m+j);


	}
}

int  main() {
	int n=91100,m=85001,k=170511,A[n],B[m],i,j;
	A[0]=2;
	B[0]=3;
	for(i=1; i<n; ++i) A[i]=A[i-1]+rand()%100+1;
	for(i=1; i<m; ++i) B[i]=B[i-1]+rand()%100+1;

	// printArray(A,n);
	//    printArray(B,m);
	cout<<Rank(A,n,B,m,k)<<"\n";

	i=n-1;
	j=m-1;
	while(k>1& i>-1 & j>-1) {
		k--;
		if (A[i]>B[j]) i--;
		else j--;
	}

	while(k>1 &i >-1 ) {
		k--;
		i--;
	}
	while(k>1 &j >-1 ) {
		k--;
		j--;
	}
	if(i<0) cout<<B[j-k+1];
	else if(j<0) cout<<A[i-k+1];

	else if(A[i]>B[j]) cout<<A[i];
	else cout<<B[j];

	return 0;
}