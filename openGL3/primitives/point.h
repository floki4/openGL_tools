#ifndef POINT_H
#define POINT_H


class Point
{
private:
public:

    double x, y,  z;

    Point(){}

    void set(double x,double y, double z){
                this->x = x;
                this->y = y;
                this->z = z;
    }



    string toString(){
        string res = " "+to_string(x)+" "+to_string(y)+" "+to_string(z);
        return res;
    }

    void print(){
        cout<<toString()<<endl;
    }

};

#endif // POINT_H
