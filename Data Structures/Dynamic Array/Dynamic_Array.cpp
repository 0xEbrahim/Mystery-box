#include <bits/stdc++.h>
using namespace std;
namespace secret
{
template <typename T>
class default_t
{
public:
    operator T() const { return T(); }
};
}


template<typename T>
class Array {

    // size -> whole size of array
    // len -> length of the array
    int size, len;

    // The main array
    T* arr;

    // temp array
    T* tmp_array;

    // default value
    T _default;

    // copy main array into tmp
    void copy(int sz){
        int i ;

        // copying values from the main array to the tmp
        for(i = 0 ; i <= len ; i++)
            tmp_array[i] = arr[i];

        // return tmp values to the default
        for(; i < sz ; i++){
            tmp_array[i] = _default;

        }
    }

    void allocator(int sz){

        // resize the tmp array
        tmp_array = new T[sz];

        // copy the data
        copy(sz);

        arr = nullptr;
        // delete old array
        delete[] arr;

        // copy the tmp into the main
        arr = tmp_array;

        // set the tmp into nullptr
        tmp_array = nullptr;
    }

    void init(){

        // set initial values to variables and pointers
        size = 0;
        len = -1;
        arr = tmp_array = nullptr;

        // sets container element to it's default value
        _default = secret::default_t<T>();
    }

public:
    T operator [] (int i)
    {
        return *(arr + i);
    }

    Array()
    {
        init();
    }

    Array(int size)
    {
        init();

        allocator(size);
    }

    Array(int size, T fill_with)
    {
        init();

        // override deafult value which provided value
        _default = fill_with;

        allocator(size);
    }
    void push(T val){
        if(len == size - 1){
            int nLen;
            if(len == -1)
                nLen = 1 + (1 >> 1);
            else
                nLen = len + (len >> 1);
            size = nLen;
            allocator(size);
        }
        len++;
        arr[len] = val;
    }

    int length(){
        return len + 1;
    }

    void remove(int idx){
        for(int i = 0 ; i <= len ; i++){
            if(i > idx){
                arr[i - 1] = arr[i];
            }
        }
        len--;
        size = len + 1;
        allocator(size);
    }
};

int main() {
Array<int>v;
    v.push(1);
    v.push(2);
    v.push(3);
    v.push(4);
    v.push(5);
    v.push(6);
    v.push(7);
for(int i = 0 ; i < v.length() ;  i++)
    cout << v[i] << ' ';
cout << endl;
v.remove(2);
for(int i = 0 ; i < v.length() ;  i++)
    cout << v[i] << ' ';
v.push(3);
    cout << endl;
    for(int i = 0 ; i < v.length() ;  i++)
        cout << v[i] << ' ';
}
