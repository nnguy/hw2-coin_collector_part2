#ifndef POINT_H
#define POINT_H

class Point{
private: 
  int x; 
  int y; 
public: 
  Point(){
    x = 0; 
    y = 0;
  }
  Point(int a, int b){
    x = a; 
    y = b; 
  }
  void print() const;
  void set(int, int); 
  int getX() const {return x;}
  int getY() const {return y;}

};

#endif

