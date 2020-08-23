#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define RE_MAX 100000000
float fun1(float roughness, float prev, ll reynolds)
{
	float a = roughness / 3.7;
	float b = 2.51 / reynolds;
	float temp = a + b * prev;
	float present = (2 * b * prev - 2 * temp * log(temp)) / (temp + 2 * b);
}
void display(vector<float> v)
{
	for (float k : v)
		cout << k << endl;
	cout << endl;
}
void fun(float roughness)
{
	vector<float> f1, reyn;
	float previous = 1 / sqrt(0.1);
	for (ll re = 2001; re <= RE_MAX; re += 100500)
	{
		float val = fun1(roughness, previous, re);
		float f = 1 / (val * val);
		f1.push_back(f);
		reyn.push_back(re);
		previous = val;
	}
	display(f1);
	//display(reyn);
	cout << endl;
	cout << "*" << endl;
}
int main()
{
	//roughness is varying from 0.00001 to 0.05
	//reynolds number is varying from  2*10^3 to 10^8
	//float prev=float(1)/sqrt(0.1);
	ll reynolds = 1;
	float roughness = 0.00001;
	//now doing for reynolds number less than 2000
	vector<float> rey;
	for (float re = 400; re <= 2000; re += 1.6)
	{
		rey.push_back(re);
		float fr = float(64) / re;
		cout << fr << endl;
	}
	display(rey);
	cout << "************************" << endl;
	while (roughness <= 0.05)
	{
		fun(roughness);
		roughness += 0.005;
	}
	return 0;
}