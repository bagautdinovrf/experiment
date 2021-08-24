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
#include <unordered_map>
#include <cstdint>
#include <initializer_list>
#include <type_traits>
#include <stdexcept>


using namespace std;

class A {
public:
    A() {
        cout << "A::A()" << endl;
    }

    A(const A *obj) {
        cout << "A::A Copy Constructor" << endl;
    }

    A(A&& ) = default;

    virtual ~A() {
        static int i = 0;
//        throw runtime_error("Error");
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
        return shared_ptr<A>(this);
    }

    A& operator=( const A& obj ) {
        return *this;
    }

    void setNum( int num ) {
        mNum = num;
    }

    int num() {
        return mNum;
    }

private:
    static int dist_count;
    int mNum = 0;
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
    auto c = static_cast<int>( count_if( xs.begin(), xs.end(), withA ) );
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


class Y: public enable_shared_from_this<Y>
{
public:

    shared_ptr<Y> getPtr()
    {
        return shared_from_this();
    }

    void exe() {
        throw std::runtime_error("Error!");
    }
};


int main()
{
    shared_ptr<A> sa = make_shared<A>();
    sa->big();

    auto y = make_shared<Y>();
    auto y1 = y.get();
    try {
        y1->exe();
    }  catch (...) {
        cout << "exeption!" << endl;
    }


//    shared_ptr<Y> p( new Y );
//    shared_ptr<Y> q = p->f();

//    assert( p == q );
//    assert( !(p < q || q < p) );


//    unordered_map< unsigned, int > map { {1,2}, {2,1}, {4,1} };
//    cout << is_same< int, unsigned >::value << endl;
//    cout << is_same< signed char, int8_t >::value << endl;

//    long double num1 = 1.0;
//    long double num2 = 2.0;
//    cout << is_same_v<decltype(num1), decltype(num2)> << '\n';

//    unordered_map<string, int> m { {"s"s, 145}, {"q"s, 43}, {"d"s, 42}, {"a"s, 1}, {"f"s, -1}, {"g"s, 0}, {"h"s, 0}, {"j"s, 0}, {"x"s, 111} };

//    int maxElem = INT32_MIN;
//    if( m.size() )
//        maxElem = m.begin()->second;
//    for( const auto &[key, val] : m ) {
//        maxElem = max( maxElem, val );
//    }
//    cout << maxElem << endl;

//    vector v { 999, 11, 2, 3, 4, 5, 6, 7, 8, -1, -5, -7, 0, 99, 199, 200, 444, 1000 };
////    cout << *v.data() << ":" << *(v.data()+v.size()-1) << endl;
//    cout << max( std::initializer_list<int>( v.data(), v.data()+v.size() ) ) << endl;
//    auto i_list = std::initializer_list<int>( v.data(), v.data()+v.size() );
//    for( auto const& elem : i_list ) {
//        cout << elem << ":";
//    }
//    cout << endl;


//    auto [a, b] = tuple{5,6};
//    int a1, b1;
//    tie(a1,b1) = tuple{7,8};
//    cout << a << ":" << b << endl;
//    cout << a1 << ":" << b1 << endl;

//    cout << "abracatabra"s.size() << endl;

    //    cout << count_if( begin(m), end(m), [&maxElem](auto val){ return max( maxElem, val.second); } );

//    SomeClass *a = new SomeClass();
//    SomeClass *b = new SomeClass();

//    a->modify();
//    *b = *a;
//    a->print();
//    cout << a << endl;
//    delete a;
//    cout << b << endl;
//    b->print();


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

//    A a;
//    auto a1 = a.getPtr();

//    a1->setNum( -1 );

//    cout << a.num() << endl;
//    cout << a1->num() << endl;

return 0;
}
