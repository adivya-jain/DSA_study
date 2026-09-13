using namespace std;
#include <iostream>
bool
Check (int A[], long long int n)
{
	long long int i;
	for (i = 0; i < n - 1; ++i)
		if (A[i] > A[i + 1])
		{
			cout << "\n" << A[i] << " " << A[i + 1];
			return false;
		}

	return true;
}

long long int
Merge (int A[], long long int l, long long int r)
{

	long long int mid, i, j, B[r - l + 1], p = 0, c = 0;
	mid = (l + r) / 2;
	i = l;
	j = mid + 1;

	while (i < mid + 1 && j < r + 1)
	{
		if (A[i] <= A[j])
			B[p++] = A[i++];
		else
		{
			c += mid - i + 1;

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
	return c;
}

void
MergeSort (int A[], long long int l, long long int r)
{
	if (l < r)
	{
		long long int mid;
		mid = (l + r) / 2;
		MergeSort (A, l, mid);
		MergeSort (A, mid + 1, r);
		Merge (A, l, r);
	}
}

long long int
CIP (int A[], long long int l, long long int r)
{
	if (l < r)
	{
		long long int mid;
		mid = (l + r) / 2;
		return (CIP (A, l, mid) + CIP (A, mid + 1, r) + Merge (A, l, r));
	}
	else
		return 0;
}
long long int
CIP1 (int A[], long long int l, long long int r)
{
	long long int i,j,c=0;
	for(i=l; i<=r; ++i)
		for(j=i+1; j<=r; ++j) if(A[i]>A[j]) c++;
	return c;
}
long long int
CIP2 (int A[], long long int l, long long int r)
{
	long long int i,j,c=0;
	for(i=l; i<=r; ++i)
		for(j=i+1; j<=r; ++j) if(A[i]<A[j]) c++;
	return c;
}
int main()
{
	int A[100000],n,i;
	cin>>n;
	for(i=0; i<n; ++i)
		A[i]=rand()%3426142;

	//	MergeSort(A,0,n-1);
	//	if(Check(A,n)) cout<<"Sorted";	else cout<<"Not Sorted";
	if(CIP1(A,0,n-1)==CIP(A,0,n-1)) cout<<"Good\n";

	char s[n];
	for(i=0; i<n; ++i)
		if(rand()%2) s[i]='0';
		else s[i]='1';
	s[n]='\0';
	A[0]=0;
	for(i=1; i<n+1; ++i)
		if(s[i-1]=='1') A[i]=A[i-1]+1;
		else A[i]=A[i-1]-1;

	if(CIP2(A,0,n)+CIP(A,0,n)==n*(n+1)/2) cout<<"Cool";
	return 0;
}