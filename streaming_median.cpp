#include <iostream>
#include <queue>
#include <vector>

#define pq priority_queue

using namespace std;

struct median{
	pq<int> maxHeap;
	pq<int, vector<int>, greater<int>> minHeap;
	
	void insert(int data){
		//first element
		if(maxHeap.size() == 0){
			maxHeap.push(data);
			return;
		}
		
		if(minHeap.size() == maxHeap.size()){
			if(data <= get())
				maxHeap.push(data);
			else
				minHeap.push(data);
			return;
		}
		if(maxHeap.size() < minHeap.size()){
			if(data <= get())
				maxHeap.push(data);
			else{
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(data);
			}
		}
		else{
			if(data < get()){
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(data);
			}
			else
				minHeap.push(data);
		}
	}
	
	size_t size(){
		return maxHeap.size() + minHeap.size();
	}
	
	double get(){
		if(maxHeap.size() == minHeap.size())
			return (maxHeap.top() + minHeap.top()) / 2.0;
		if(maxHeap.size() < minHeap.size())
			return minHeap.top();
		return maxHeap.top();
	}
};

int main(){
	median med;
	while(true){
		cout << "Insert element: ";
		int ele;
		cin >> ele;
		med.insert(ele);
		cout << "Median after inserting " << ele << ": " << med.get() << endl;
		
		if(med.size() >= 6)
			break;
	}
	
	return 0;
}
