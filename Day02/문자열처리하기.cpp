#define _CTR_SECURE_NO_WARNINGS
#include <iostream> // 입력(cin)과 출력(cout)을 사용하려면 필요하다.
using namespace std; // std::cout 대신 그냥 cout 이라고 쓸 수 있게 해준다.
/*
*  문자열 처리하기
*/

int main() {

	char str[20] = "홍길동";
	cout << str << endl;

	char str2[20];
	//str2 = "김영희"; --> 에러발생!!! 문자 배열의 주소를 변경하려고 하기 때문에 컴파일 오류가 발생. 
	//str2는 문자 배열의 주소인데, '김영희'라는 문자열의 주소를 바꾸려고 해서 오류발생
	strcpy(str2, "김영희");	//배열의 주소는 변경할 수 없지만, 내부 값을 복사하는 것은 가능
	cout << str2 << endl;

	//char* str3 = nullptr;
	char str3[100];
	cout << "이름입력 > ";
	cin >> str3;  // 사용자가 입력한 내용을 str3에 저장,하지만 띄어쓰기(공백) 있는 이름을 입력하면, 공백 이후는 잘림
	cout << str3 << endl;
	
	const char* name;	//name이라는 문자열 포인터를 만든다
	name = "홍당무";	//홍당무"는 읽기 전용 메모리에 저장
	cout << name << endl;
	return 0;
}
// 왜 "홍당무"는 읽기 전용 메모리에 저장?
// c++에서는 문자열 리터럴이 "읽기 전용" 메모리에 저장되기 때문!!!
// 그래서 "홍당무"같은 문자열을 수정하려고 하면 오류 발생!
//ex) const char* name = "홍당무";
//	  name[0] = '김'  //-> 읽기 전용 메모리에서는 수정이 불가능 하기 때문에 오류 발생~!
// -- 읽기 전용이 아닌 문자열을 사용하려면 ---
//ex) char name[] = "홍당무";  //-> 배열을 사용하면 수정가능!!
//	  name[0] = '김';	// -> "김당무"로 변경