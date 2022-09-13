#ifndef POINT_H
#define POINT_H

class Point{
private: 
  int x; 
  int y; 
public: 
  Point(int a, int b){
    x = a; 
    y = b; 
  }
  void print() const;
  void set(int, int); 
  int getX() {return x;}
  int getY() {return y;}

};

#endif

