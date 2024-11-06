#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <algorithm>
using namespace std;

int Sum(vector<int>& v) {
	int sum = 0;
	for (int i = 0; i < v.size(); ++i)
		sum += v[i];
	return sum;
}

void Move(vector<int>& v)
{
	for (int i = v.size()-1; i > 0; i--)
		v[i] = v[i-1];
	v[0] = 0;
}

int main(void)
{
	int n, w, L;
	cin >> n >> w >> L;
	// n개 트럭, 다리길이 w , 최대 하중 L

	vector<int> v(n);
	vector<int> truck(w);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int i = 0;
	int time = 1;
	int sum_truck = 0;
	while (1) {
		Move(truck);
		if (i == n && Sum(truck) == 0)
			break;
		sum_truck = Sum(truck);
		if (i < n && sum_truck + v[i] <= L) {
			truck[0] = v[i];
			i++;
		}
		time++;
	}
	cout << time;

}
