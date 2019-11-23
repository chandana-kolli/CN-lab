#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#define bucketSize 512
using namespace std;

void bktInput(int a,int b)
{
	if(a>bucketSize)
		cout<<"\nBucket overflow";
	else
	{
		usleep(500);
		while(a>b)
		{
			cout<<"\n"<<b<<"bytes outputted.";
			a-=b;
			usleep(500);
		}
		if(a>0)
			cout<<"\n Last"<<a<<"bytes sent\t";
		cout<<"\n bucket output successful";
	}
}

int main()
{
	int op,pktSize;
	cout<<"enter output rate:";
	cin>>op;
	for(int i=1;i<=5;i++)
	{
		usleep(rand()%1000);
		pktSize=rand()%1000;
		cout<<"\nPacket no"<<i<<"\tPacket size"<<pktSize;
		bktInput(pktSize,op);
	}
}