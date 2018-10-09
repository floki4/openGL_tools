#ifndef PRINT_H
#define PRINT_H

#include<primitives/item.h>

class Print
{
public:
    Print(){}

    void stroka(string txt){
        cout<<txt<<endl;
    }

    void num(double n){
        cout<<to_string(n)<<endl;
    }

    void num(int n){
        cout<<to_string(n)<<endl;
    }

    void num(unsigned int n){
        cout<<to_string(n)<<endl;
    }

    void vec(vec2 vec){
        cout<<to_string(vec.x)<<" "<<
              to_string(vec.y)<<" "<<
              endl;
    }

    void vec(vec3 vec){
        cout<<to_string(vec.x)<<" "<<
              to_string(vec.y)<<" "<<
              to_string(vec.z)<<" "<<
              endl;
    }

    void arr(int kupa[]){
        for(int i = 0;i<sizeof(kupa);i++){
            cout<<to_string(kupa[i])<<endl;
        }
    }

  //  typedef vector<Item> Asociative;


    void arr(vector<Item> arr){
        for (Item item:arr){
           item.print();
        }
    }

private:
};

#endif // PRINT_H
