#include<bits/stdc++.h>
#include <cstdio>
using namespace std;

class Geometry{

    public:
    string color = "blue";
    Geometry(){

    }
    void printColor(){
        cout<<color<<endl;
    }
    virtual void calArea(){
        cout<<"Area: 0 \nshape: unknown\n";
    }
};

class Circle : public Geometry{
    float radius;
    float area = 0;
    public:
    Circle(){
        radius = 5;
    }
    void calArea(){
        area = 3.14 * radius * radius;
        cout<<"Area: "<<area<<", Shape: Circle, Radius: "<<radius<<endl;
    }

};

class Square : public Geometry{
    float side;
    float area = 0;
    public:
    Square(){
        side = 5.3;
    }
    void calArea(){
        area = side * side;
        cout<<"Area: "<<area<<", Shape: Square, Side: "<<side<<endl;
    }

};

class Cube : public Geometry{
    float length;
    float width;
    float height;
    float area;
    public:
    Cube(){
        length = 5;
        width = 5;
        height = 5;
    }

    void calArea(){
        area = length * width * 2 + length * height * 2 + width * height * 2;
        cout<<"Area: "<<area<<", Shape: Cube, Length: "<<length<<" Height: "<<height<<" width: "<<width<<endl;
    }
};

int main(){
    Geometry* ar[10];
    for(int i = 0; i < 10; i++){
        int choice = 1 + rand()%3;
        if(choice == 1){
            ar[i] = new Circle();
        }
        else if(choice == 2){
            ar[i] = new Square();
        }
        else if(choice == 3){
            ar[i] = new Cube();
        }
        
    }
    for(int i = 0; i < 10; i++){
        ar[i]->calArea();
    }


    return 0;
}
