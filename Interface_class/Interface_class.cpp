#include <iostream>

// Abstract class
class Shape{
public:
    virtual void draw() = 0; // Pure virtual function
    virtual void area() = 0; // Pure virtual function
};

class Circle : public Shape {
    public:
        const double PI = 3.14;
        int m_radius;

        /* Defualt constructor */
        Circle()
        : m_radius(0) { std::cout << "Circle Defualt constructor" << std::endl; }

        /* Parameterized constructor */
        Circle(int radius)
        : m_radius(radius) { std::cout << "Circle Parameterized constructor" << std::endl; }

        void draw(void) override { std::cout << "Draw Circle" << std::endl; }

        void area(void) override { std::cout << "Circle Area " << PI * m_radius * m_radius << std::endl; }

        ~Circle() { std::cout << "Circle Distructor" << std::endl; }
};

class Rectangle : public Shape {
    public:
        int m_length, m_width;

        /* Defualt constructor */
        Rectangle()
        : m_length(0), m_width(0) { std::cout << "Rectangle Defualt constructor" << std::endl; }

        /* Parameterized constructor */
        Rectangle(int length, int width)
        : m_length(length), m_width(width) { std::cout << "Rectangle Parameterized constructor" << std::endl; }

        void draw(void) override { std::cout << "Draw Rectangle" << std::endl; }

        void area(void) override { std::cout << "Rectangle Area " << m_length * m_width << std::endl; }

        ~Rectangle() { std::cout << "Rectangle Distructor" << std::endl; }
};



int main() {
    Circle C(12);
    Rectangle R(2, 3);

    // Shape* ShapesArr[] = {&c, &r}; // Array of pointer

    // for(Shape* Shape_var : ShapesArr) { 
    //     Shape_var->draw(); 
    //     Shape_var->area();
    // }

    Shape* ShapeOne = &C; 
    Shape* ShapeTwo = &R; 

    ShapeOne->area();
    ShapeTwo->area();
    
    return 0;
}