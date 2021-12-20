#include <bits/stdc++.h>
using namespace std;

#define f(i,a,b) for(int i=a;i<b;++i)

template <typename T>
class dynamic_array{
	T* data;
	size_t n;
	public:
		dynamic_array(int n){
			this->n = n;
			data = new T[n];
		}
		dynamic_array(const dynamic_array<T>& other){
			this->n = other.n;
			data = new T[n];
			f(i,0,n)
				data[i] = other[i];
		}
		
		T& operator[](int idx){
			return data[idx];
		}
		const T& operator[](int idx) const{
			return data[idx];
		}
		T& at(int idx){
			if(idx < n)
				return data[idx];
			throw "Index Out of Range";
		}
		
		size_t size() const{
			return n;
		}
		~dynamic_array(){
			delete[] data;
		}
		
		T* begin(){
			return data;
		}
		const T* begin() const{
			return data;
		}
		T* end(){
			return data + n;
		}
		const T* end() const{
			return data + n;
		}
		
		friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, const dynamic_array<T>& arr2){
			dynamic_array<T> result(arr1.size()+arr2.size());
			copy(arr1.begin(), arr1.end(), result.begin());
			copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());
			
			return result;
		}
		
		string to_string(const string& sep = ", "){
			if(n==0)
				return "";
			ostringstream os;
			os << data[0];
			f(i,1,n){
				os << sep << data[i];
			}
			return os.str();
		}
};

struct student{
	string name;
	int standard;
};

ostream& operator<<(ostream& os, const student& s){
	return (os << "[Name : " << s.name << ", Standard : " << s.standard << "]");
}

int main(){
	int nStudents;
	cout << "Enter number of students in class 1: ";
	cin >> nStudents;
	
	dynamic_array<student> class1(nStudents);
	f(i,0,nStudents){
		cout << "Enter name and class of student " << i+1 << ": ";
		string name;
		int standard;
		cin >> name >> standard;
		class1[i] = student{name, standard};
	}
	
	try{
		//class1[nStudents] = student{"John", 8};
		cout << "OORange without exception" << endl;
		class1.at(nStudents) = student{"John", 8};
	}
	catch(...){
		cout << "Caught exception" << endl;
	}
	
	auto class2 = class1; //Deep copy
	cout << "Second class after initialising using first array: " << class2.to_string() << endl;
	
	dynamic_array<student> class4(class1);
	cout << "Class4 constructer-ized(original) : " << class4.to_string() << endl;
	
	class4[1] = student{"John", 8};
	cout << "Class4 constructer-ized(new) : " << class4.to_string() << endl;
	
	auto class3 = class1 + class2;
	cout << "Combined class : ";
	cout << class3.to_string() << endl;
	return 0;
}
