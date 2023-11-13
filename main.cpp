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
#include <fstream>

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

    void big() override {
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

    void big()  override{
        cout << "function C::big()" << endl;
    }

    void func() {
        cout << "function C::func()" << endl;
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

pair<string, int> get_max(const vector<int> &v) {
    if( v.empty() )
        return pair<string, int>();

    return pair<string, int>();
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int min = 1;
    sort( A.begin(), A.end() );
    for( const auto& elem : A ) {
        cout << "elem=" << elem << " min=" << min << endl;
        if( min == elem )
            ++min;
        cout << "1elem=" << elem << " 1min=" << min << endl;
    }

    return min;
}


bool isDigit( const char ch )
{
    if( (ch >='0' && ch <= '9') )
        return true;

return false;
}

bool noMinus( const char ch ) {
    if( ch != '-')
        return true;
    else
        return false;
}

int solution(string &S) {
    // write your code in C++

    if( S.empty() )
        return 0;

    auto str = S.data();

    while ( *str != '\0' && ( *str == '0' || noMinus(*str) ) && false == isDigit(*str)) {
        ++str;
    }

    bool minus = false;
    if( *str == '-' ) {
        minus = true;
        ++str;
    }

    int result;
    while( *str != '\0' && true == isDigit(*str) ) {
        result = result*10 + (*str-'0');
        ++str;
    }

    if( minus )
        result = -result;

    return result;
}


int main()
{
//    ifstream file("d:\\downloads\\passport_list.csv");

//    string s;
//    uint32_t i = 0;
//    if( file.is_open() ) {
//        cout << "OPEn!" << endl;
//        while( !file.eof() ) {
////            file >> s;
//            getline( file, s );
//            ++i;
//        }
//    } else {
//        cout << "Oi oi oi, не могу открыть файл" << endl;
//    }

//    cout << "Number lines = " << i << endl << "last line = " << s << endl ;

//    string  s = "   42";
//    cout << solution(s) << endl;

//    vector v = {1, 3, 6, 4, 1, 2};
//    cout << solution( v ) << endl;

//    unordered_map<string, int> m { {"s"s, 145}, {"q"s, 43}, {"d"s, 42}, {"a"s, 1}, {"f"s, -1}, {"g"s, 0}, {"h"s, 0}, {"j"s, 0}, {"x"s, 111} };

//    int maxElem = INT32_MIN;
//    if( m.size() )
//        maxElem = m.begin()->second;
//    for( const auto &[key, val] : m ) {
//        maxElem = max( maxElem, val );
//    }
//    cout << maxElem << endl;

//    vector v { 999, 11, 2, 3, 4, 5, 6, 7, 8, -1, -5, -7, 0, 99, 199, 200, 444, 1000 };
//    cout << *v.data() << ":" << *(v.data()+v.size()-1) << endl;

    // MSVC -- работает
//    cout << max( std::initializer_list<int>( v.data(), v.data() + v.size() ) ) << endl;
//    auto i_list = std::initializer_list<int>( v.data(), v.data()+v.size() );

//    for( auto const& elem : i_list ) {
//        cout << elem << ":";
//    }
//    cout << endl;

//    cout << *max_element( v.begin(), v.end() ) << endl;


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
////    A *a = new B;
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
    A *cp = new C();
    cp->big();
    cp->func();

return 0;
}
