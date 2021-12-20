//fast data storage container builder

#include <bits/stdc++.h>
using namespace std;

#define f(i,a,b) for(int i=a;i<b;++i)

template<typename ... Args>
auto build_array(Args&&... args) -> array<typename std::common_type<Args...>::type, sizeof...(args)>
{
	using commonType = typename std::common_type<Args...>::type;
	return {std::forward<commonType>(args)...};
}

int main(){
	auto data = build_array(1,0u,'a',3.2f,false);
	for(auto i : data)
		cout << i << " ";
	cout << endl;
}
