
#include "stdafx.h"
#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;

#define M_LN2 0.693147180559945309417

int log2(int a)
{
	return (int)(log((double)a)/M_LN2);
}

int pow2(int a)
{
	int p=1;
	for(int i=0;i<a;i++) p*=2;
	return p;
}

void printnext(int* a, int &current)
{
	current++;
	cout<<a[current-1]<<" ";
}

int numberofupelements(int i)
{
	int k=1;
	for(int n=1;n<i;n++) k=2*k+1;
	return k;
}

void up(int &i)
{
	i=i/2;
}

void printdowntoend(int* a, int asize, int &current)
{
	while(current*2<=asize)
	{
		cout<<a[current-1]<<" ";
		current*=2;
	};
	cout<<a[current-1]<<" ";
}

void straightprint(int* a, int asize)
{
	if(a==NULL)
	{
		cout<<"The array is empty.";
		return;
	}
	if(asize<=3)
	{ 
		cout<<endl<<"The tree elements in straight order: "<<endl;
		for(int i=0;i<asize;i++) cout<<a[i]<<" ";
	}
	else
	{
		int z=numberofupelements(log2(asize)-1);
		int* n = new int[z];
		for(int i=0;i<z;i++) n[i]=1;
		for(int j=1;j<log2(asize)-1;j++) for(int i=numberofupelements(j);i<z;i+=pow2(j)) n[i]++;

		cout<<endl<<"The tree elements in straight order: "<<endl;
		int current=1, b=0;
		printdowntoend(a, asize, current);
		if(current==asize) b=1;
		else
		{
			printnext(a, current);
			if(current==asize) b=1;
		}
		for(int i=0;i<z;i++)
		{
			if(b==2 && i%2==0) continue;
			if(b==2) for(int j=0;j<n[i]-1;j++) up(current);
			else for(int j=0;j<n[i];j++) up(current);
			current++;
			if(b==1) b=2;
			printdowntoend(a, asize, current);
			if(current==asize) b=1;
			else if(current%2==0)
			{
				printnext(a, current);
				if(current==asize) b=1;
			}
		}
	}
	cout<<endl;
}

void main()
{
	int x=-1;
	cout<<"Enter number of tree elements: ";
	for(int i=1;x<0||x>1048575;i++)
	{
		if(i!=1&&x<0) cout<<"Wrong value of the variable, please re-enter it: ";
		if(i!=1&&x>1048575) cout<<"Too big value, please enter less than 1048575: ";
		cin>>x;
	}
	int *a, ch=0;
	if(x==0) a=NULL;
	else
	{
		a = new int[x];
		cout<<"Enter 1 to fill the array with elements' numbers or 2 to do it with keyboard: ";
		for(int i=1;(ch!=1 && ch!=2);i++)
		{
			if(i!=1) cout<<"Wrong value of the variable, please re-enter it: ";
			cin>>ch;
		}
		if(ch==1) for(int i=0;i<x;i++) a[i]=i+1;
		else for(int i=0;i<x;i++) cin>>a[i];
	}
	straightprint(a, x);
	getch();
}

