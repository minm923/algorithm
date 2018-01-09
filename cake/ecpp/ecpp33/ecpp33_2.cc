#include<iostream>
using namespace std;

class People {
public:
 // 隐藏:是指派生类的函数屏蔽基类函数
// 隐藏规则1：
// 1) 函数名相同 && 参数不同
// 2) virtual不影响
void getId_different_params() {cout << "People::getId_different_params" << endl;}
 virtual void getName_different_params() {cout << "People::getName_different_params" << endl;}

 // 隐藏规则2:
 // 1) 函数名相同 && 参数相同
// 2) 无virtual
 void getPhone_same_params() {cout << "People::getPhone_same_params" << endl;}

 // 覆盖规则:
 // 1) 函数名相同 && 参数相同
// 2) 有virtual
 virtual void getAddress_same_params() {cout << "People::getAddress_same_params" << endl;}
};

class Children : public People {
public:
 // 隐藏:是指派生类的函数屏蔽基类函数
// 隐藏规则1：
// 1) 函数名相同 && 参数不同
// 2) virtual不影响
void getId_different_params(int) {cout << "Children::getId_different_params(int)" << endl;}
 virtual void getName_different_params(int) {cout << "Children::getName_different_params(int)" << endl;}

 // 隐藏规则2:
 // 1) 函数名相同 && 参数相同
// 2) 无virtual
 void getPhone_same_params() {cout << "Children::getPhone_same_params" << endl;}

 // 覆盖规则:
 // 1) 函数名相同 && 参数相同
// 2) 有virtual
 virtual void getAddress_same_params() {cout << "Children::getAddress_same_params" << endl;}
};

int main(int argc, char * argv[])
{

 Children *c = new Children();
 c->getId_different_params(1);
 c->getName_different_params(1);
 c->getPhone_same_params();
 c->getAddress_same_params();
 /*输出为：
Children::getId_different_params(int)
Children::getName_different_params(int)
Children::getPhone_same_params
Children::getAddress_same_params
*/


 People *p = new Children();
 p->getId_different_params();
 p->getName_different_params();
 p->getPhone_same_params();
 p->getAddress_same_params();

/*输出为：
People::getId_different_params         //由于子类中的函数只是隐藏了基类中的函数而没有覆盖，因为指针为基类指针，故调用基类函数
People::getName_different_params    //由于子类中的函数只是隐藏了基类中的函数而没有覆盖，因为指针为基类指针，故调用基类函数
People::getPhone_same_params       //由于子类中的函数只是隐藏了基类中的函数而没有覆盖，因为指针为基类指针，故调用基类函数
Children::getAddress_same_params // 由于子类中的函数覆盖了基类中的函数，虽然指针为基类指针，但是会调用子类函数
*/

    return 0;
}
