// Section 16
// Pure virtual functions and abstract base classes
#include <iostream>
#include <vector>

// Abstract class는 instance를 만들 수 없는 클래스다.
// 그걸 기반으로 밑의 Concrete class를 만들어야 한다.
// Abstract class는 Pure Virtual Function하나쯤은 있어야 한다.
// 애는 그냥 virtual void 함수()  = 0; 이런식으로 써주면 된다. 
// 그럼 implement 쉽다.

class Shape {			// Abstract Base class
// I_Shape 라고 하면, 이 클래스가 interface로 쓰이는걸 알 수 있다.
private:
       // attributes common to all shapes
public:
      virtual void draw() = 0;	 // pure virtual function
      virtual void rotate() = 0;   // pure virtual function
      virtual ~Shape() { }
};

class Open_Shape: public Shape {    // Abstract class
public:
    virtual ~Open_Shape() { }
};

class Closed_Shape : public Shape {  // Abstract class
public:
    virtual ~Closed_Shape() { };
};

class Line: public Open_Shape {     // Concrete class
public:
    virtual void draw() override {
        std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a line" << std::endl;
    }
    virtual ~Line() {}
};

class Circle: public Closed_Shape {     // Concrete class
public:
    virtual void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a circle" << std::endl;
    }
    virtual ~Circle() {}
};

class Square: public Closed_Shape {     // Concrete class
public:
    virtual void draw() override {
        std::cout << "Drawing a square" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a square" << std::endl;
    }
    virtual ~Square() {}
};


void screen_refresh(const std::vector<Shape *> &shapes) {
    std::cout << "Refreshing" << std::endl;
    for (const auto p: shapes) 
        p->draw();
}

int main() {
//    Shape s;
//    Shape *p = new Shape();

//        Circle c;
//        c.draw();

//    Shape *ptr = new Circle();
//    ptr->draw();
//    ptr->rotate();

    Shape *s1 = new Circle();
    Shape *s2 = new Line();
    Shape *s3 = new Square();
    
    std::vector<Shape *> shapes {s1,s2,s3};
    
//    for (const auto p: shapes) 
//        p->draw();
        
    screen_refresh(shapes);
    
    delete s1;
    delete s2;
    delete s3;
    
    return 0;
}

