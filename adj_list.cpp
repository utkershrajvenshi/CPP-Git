//Graph as adjacency list
//Review codebase to understand removeEdge()

#include <iostream>
#include <vector>
using namespace std;

#define f(i,a,b) for(int i=a;i<b;++i)
#define v vector

typedef vector<int> vi;

enum class city: int
{
	LONDON,
	MOSCOW,
	ISTANBUL,
	DUBAI,
	MUMBAI,
	SEATTLE,
	SINGAPORE
};

ostream& operator<<(ostream& os, const city c){
	switch(c){
		case city::LONDON : os << "LONDON";
							return os;
		case city::MOSCOW : os << "MOSCOW";
							return os;
		case city::ISTANBUL : os << "ISTANBUL";
							return os;
		case city::DUBAI : os << "DUBAI";
							return os;
		case city::MUMBAI : os << "MUMBAI";
							return os;
		case city::SEATTLE : os << "SEATTLE";
							return os;
		case city::SINGAPORE : os << "SINGAPORE";
							return os;
		
		default : return os;
	}
}

struct graph{
	v<v<pair<int,int>>> data;
	
	graph(int n){
		data = v<v<pair<int,int>>>(n, v<pair<int,int>>());
	}
	
	void addEdge(const city c1, const city c2, int dis){
		cout << "ADD: " << c1 << "-" << c2 << "=" << dis << endl;
		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1].push_back({n2, dis});
		data[n2].push_back({n1, dis});
	}
	
	void removeEdge(const city c1, const city c2){
		cout << "REMOVE: " << c1 << "-" << c2 << endl;
		
		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair){
			return pair.first == n2;
		});
		
		remove_if(data[n2].begin(), data[n2].end(), [n1](const auto& pair){
			return pair.first == n1;
		});
	}
};

int main(){
	graph g(7);
	g.addEdge(city::LONDON, city::MOSCOW, 900);
	g.addEdge(city::LONDON, city::ISTANBUL, 500);
	g.addEdge(city::LONDON, city::DUBAI, 1000);
	g.addEdge(city::ISTANBUL, city::MOSCOW, 1000);
	g.addEdge(city::ISTANBUL, city::DUBAI, 500);
	g.addEdge(city::DUBAI, city::MUMBAI, 200);
	g.addEdge(city::ISTANBUL, city::SEATTLE, 1500);
	g.addEdge(city::DUBAI, city::SINGAPORE, 500);
	g.addEdge(city::MOSCOW, city::SEATTLE, 1000);
	g.addEdge(city::MUMBAI, city::SINGAPORE, 300);
	g.addEdge(city::SEATTLE, city::SINGAPORE, 700);
	g.addEdge(city::SEATTLE, city::LONDON, 1800);
	
	g.removeEdge(city::SEATTLE, city::LONDON);
	
	return 0;
}
