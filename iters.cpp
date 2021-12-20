//types of iterators

#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<string> vec = {"LH", "LH", "NR", "SV", "LH", "SV", "SV", "SV", "FA"};
	auto it = vec.begin();
	cout << "Latest winner: " << *it << endl;
	it += 8;
	cout << "Winner before 8 years: " << *it << endl;
	advance(it, -3);
	cout << "Winner before 3 years of that: " << *it << endl;
	
	//with forward list iterators
	forward_list<string> fwd(vec.begin(), vec.end());
	auto it1 = fwd.begin();
	cout << "Latest winner: " << *it1 << endl;
	advance(it1, 5);
	cout << "Winner before 5 years was: " << *it1 << endl;
}
