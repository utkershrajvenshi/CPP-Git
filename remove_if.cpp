#include <bits/stdc++.h>
using namespace std;

#define f(i,a,b) for(int i=a;i<b;++i)

struct citizen{
	string name;
	int age;
};

ostream& operator<<(ostream& os, const citizen& c){
	return (os << "[Name: " << c.name << ", Age: " << c.age << "]");
}

int main(){
	forward_list<citizen> citizens = {{"Raj", 22}, {"Rohit", 25}, {"Rohan", 17}, {"Sachin", 16}};
	auto citizens_copy = citizens;
	cout << "All citizens: ";
	for(const auto &c : citizens){
		cout << c << " ";
	}
	cout << endl;
	
	citizens.remove_if(
		[](const citizen& c){
			return (c.age < 18);
		}
	);
	
	cout << "Eligible citizens for voting: ";
	for(const auto& c : citizens)
		cout << c << " ";
	cout << endl;
	
	citizens_copy.remove_if(
		[](const citizen& c){
			return (c.age != 17);
		}
	);
	cout << "Citizens that will be eligible for voting next year: ";
	for(const auto& c : citizens_copy){
		cout << c << " ";
	}
	cout << endl;
}
