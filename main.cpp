#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <map>
#include <utility>
#include <unordered_map>
#include <array>
#include <cstring>

using namespace std;

class A {
public:
    A() {
        cout << "A" << endl;
    }

    A(const A *obj) {
        cout << "A copy" << endl;
    }

    A(A&& ) = default;

    virtual ~A() {
        static int i = 0;
        cout << "~A" << ++i <<  endl;
    }

    virtual void print() {
        cout << "A::print()" << endl;
    }

    virtual void f() {
        cout << "function A::f()" << endl;
    }

    void func() {
        cout << "function A::func()" << endl;
    }

    virtual void big() {
        cout << "function A::big()" << endl;
    }

    shared_ptr<A> getPtr() {
        return make_shared<A>(this);
        return shared_ptr<A>(this);
    }

    A& operator=( const A& obj ) {
        return *this;
    }

private:
    static int dist_count;
};

class B : public A {
public:

    B() {
        cout << "B" << endl;
    }

    ~B() {
        static int i = 0;
        cout << "~B" << ++i <<  endl;
    }

    void print() {
        cout << "B::print()" << endl;
    }

    void f() {
        cout << "function B::f()" << endl;
    }

    void func() {
        cout << "function B::func()" << endl;
    }

    void big() {
        cout << "function B::big()" << endl;
    }
};

class C : public B {
public:
    C() {
        cout << "C" << endl;
    }

    ~C() {
        static int i = 0;
        cout << "~C" << ++i <<  endl;
    }
    void big()  {
        cout << "function C::big()" << endl;
    }
};

bool withA( string s ) {
   if( s.size() > 0) {
       if(  s[0] == 'a' || s[0] =='A' )
           return true;
       else
           return false;
   }
   else return false;
}

int CountStartsWithA(const vector<string>& xs) {
    auto c = count_if( xs.begin(), xs.end(), withA );
    return c;
}

//class Foo {
//public:
//    Foo() = delete;
//    Foo(int i) {
//        cout << i << a << b << endl;
//    }
//
//    template< typename  T, typename ...Args >
//    void print( T t, Args... args) {
//        cout << t << std::forward<Args>(args) << endl;
//    }
//
//private:
//    int *a = nullptr;
//    int b = 5;
//};


class SomeClass {
public:
    SomeClass() {
        x1 = new char[SIZE_X1];
        x2 = new char[SIZE_X2];
        i1 = new int[SIZE_I1];

        for( int i = 0; i < SIZE_I1; ++i ) {
            i1[i] = i;
        }
    }

    SomeClass(const SomeClass& obj ) : SomeClass() {
        cpy(obj);
    }

    SomeClass & operator=(const SomeClass& obj ) {
        if( this != &obj )
            cpy(obj);
        cout << "operator=" << endl;
        return *this;
    }

    ~SomeClass() {
        if (x1)
            delete[] x1;
        if (x2)
            delete[] x2;
        if( i1 )
            delete[] i1;

        x1 = nullptr;
        x2 = nullptr;
        i1 = nullptr;
    }

    void print() {
        for( int i = 0 ; i < SIZE_I1; ++i ) {
            cout << i1[i] << "-";
        }
        cout << endl;
    }

    void modify() {
        for( int i = 0; i < SIZE_I1; ++i ) {
            i1[i] = i*10;
        }
    }

private:
    void cpy(const SomeClass & obj ) {
        memcpy_s( x1, SIZE_X1, obj.x1, SIZE_X1 );
        memcpy_s( x2, SIZE_X2, obj.x2, SIZE_X2 );
        memcpy_s( i1, SIZE_I1*sizeof(int), obj.i1, SIZE_I1 * sizeof(int));
    }

private:
    int SIZE_X1=1024;
    int SIZE_X2=1024*1024;
    int SIZE_I1=100;
    char *x1 = nullptr;
    char *x2 = nullptr;
    int *i1 = nullptr;
};

int main()
{

    SomeClass *a = new SomeClass();
    SomeClass *b = new SomeClass();

    a->modify();
    *b = *a;
    a->print();
    cout << a << endl;
    delete a;
    cout << b << endl;
    b->print();


//    unordered_map<int, int> m  { {1, 10}, {2, 15}, {3, 20}, };
//    m.insert( pair(4,22) );
//
//    for( auto&[key, val] : m ) {
//        cout << key << ":" << val << endl;
//    }

//    Foo f(1);

    //cout << CountStartsWithA({"And"s, "another"s, "one"s, "gone"s, "another"s, "one"s "bites"s, "the"s, "dust"s}) << endl;

//    B *a = new B;
//    A *a = new B;
//    a->print();
//    a->f();
//    a->func();
//    a->big();
////    shared_ptr<A> ptr = a->getPtr();
//    auto ptr = a->getPtr();
//    ptr->big();
//    auto ptr1 = ptr;
//    ptr1->big();

//    A *a1 = new C;
//    a1->big();
//    auto ptr = a1->getPtr();
//    auto ptr1 = ptr;
//    auto ptr2 = ptr1;
//
//    a1->big();
//    delete a1;

//    cout << sizeof( bool) << endl;
//    cout << sizeof( short ) << endl;
//    cout << sizeof( int ) << endl;
//    cout << sizeof( long ) << endl;
//    cout << sizeof( long long ) << endl;
//    cout << sizeof( size_t ) << endl;

//    C c;
//    c.big();

return 0;
}
