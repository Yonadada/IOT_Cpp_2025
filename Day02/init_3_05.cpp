#include <iostream>
using namespace std;
/* 멤버초기화 3. 객체를 멤버로 가지는 경우*/
class Position {
private:
    int m_x;
    int m_y;
public:
    Position(int x, int y) {         // 3. 객체 생성되면서 출력됨
        printf("Position 생성자!\n");
        m_x = x, m_y = y;
    }
    void getData() {               // 7. getData() 실행되면서 출력
        cout << "x: " << m_x << ", y: " << m_y << endl;
    }
};

class ObjClass {
private:
    Position pos;               // 객체 멤버변수 (객체화가 미리 되어 있어야 함!!)
public:
    ObjClass(int x, int y) : pos(x, y) /* 2. pos 생성하러 감! */ {   // 4. ObjClass 생성되면서 출력됨
        printf("ObjClass constructor!\n ");
    }

    void showValue() {            // 6. 함수 실행 -> pos.getData()로 들어감
        pos.getData();            // 여기서 m_x, m_y 직접 사용 불가 -> getData()만들어서 접근
    }
};
int main() {

    ObjClass o(3, 6);      // 1. 실행 -> ObjClass로 들어감
    // 2. pos 생성하러 감! (Position 객체 생성)
    o.showValue();         // 5. o객체의 함수 실행
    // 6. 함수 실행 -> pos.getData()로 들어감
    // 7. getData() 실행되면서 출력

    return 0;
}