/*
	클래스 템플릿 
*/

#include <iostream>
using namespace std;
template <typename T>

class CTemplate {
private: 
	T data;
public:
	CTemplate(T d) { data = d;}
	T getData() { return data; }
};


int main() {
	CTemplate<int> obj(100);
	printf("data: %d\n", obj.getData());

	CTemplate<std::string> obj2("클래스 템플릿 테스트");
	cout << obj2.getData() << endl;


	return 0;
}