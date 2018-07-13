//
// Created by Joshua Newton on 11/16/17.
//

#ifndef CIRCLE_MANIA_SHAPES_H
#define CIRCLE_MANIA_SHAPES_H

#include <cmath>
#include <iostream>

/*
 Inheritance:

                                Shape(Abstract)
                                / | |       \
                               /  | |        \
                              /   | |         \
               Rectangle_Shape    | Circle     HollowCircle
                                  |
                               Triangle(Abstract)
                                 /  |    |   \
                                /   |    |    \
                               /    |    |     \
                            Left  Right  Down   Up
*/
using namespace std;

struct color {
    double red;
    double green;
    double blue;
};

struct point {
    int x;
    int y;
};

enum triangleDirection {Up, Right, Down, Left};

class Shape {
public:
    // Constructors
    Shape();
    Shape(color f);
    Shape(point p);
    Shape(int x_in, int y_in);
    Shape(color f, point p);
    Shape(color f, int x_in, int y_in);
    Shape(const Shape &s); // copy constructor

    // Destructor
    ~Shape();

    // getters
    double get_area() const;
    double get_perimeter() const;
    color get_fill() const;
    point get_position() const;
    double get_x() const;
    double get_y() const;

    // setters
    void set_fill(color f);
    void set_fill(double r, double g, double b);
    void set_position(point p);
    void set_position(int x_in, int y_in);

    void move(int delta_x, int delta_y);

    // will add canvas parameter when we learn graphics
    // pure virtual (class is abstract)
    virtual void draw() const = 0;

protected:
    color fill;
    point position;
    // helper methods
    // pure virtual
    virtual double calculate_area() const = 0;
    virtual double calculate_perimeter() const = 0;
};

class Circle : public Shape {
public:
    // Constructors
    // will call calculate_area and calculate_perimeter
    Circle();
    Circle(double r);
    Circle(double r, color f);
    Circle(color f);
    Circle(const Circle &c);
    Circle(double r, color f, point p);
    // getter
    double get_radius() const;

    // setter
    // will call calculate_area and calculate_perimeter
    void set_radius(double r);

    void draw() const override;

    // detect if the circle is overlapping with a coordinate point
    bool is_overlapping(const point &p) const;
    bool is_overlapping(int x, int y) const;
    // detect if a circle is ovelapping with this circle
    bool is_overlapping (const Circle &c) const;
    // detect if a circle is overlapping with a rectangle

private:
    double calculate_area() const override;
    double calculate_perimeter() const override;
    double radius;
    // Note: the inherited point will represent the
    // center of the circle
};

class Rectangle_Shape : public Shape {
public:
    // Constructors
    Rectangle_Shape();
    Rectangle_Shape(double b, double h);
    Rectangle_Shape(double b, double h, color f);
    Rectangle_Shape(color f);
    Rectangle_Shape(int x_in, int y_in);
    Rectangle_Shape(point p);
    Rectangle_Shape(double b, double h, color f, int x_in, int y_in);

    // getters
    double get_base() const;
    double get_height() const;
    // setters
    // want point to have x, y coordinates >= 0
    void set_top_left(int x_in, int y_in);
    // want base to be >= 0
    void set_base(double b);
    // want height to be >= 0
    void set_height(double h);
    void set_dimensions(double b, double h);

    void draw() const override;

    // detect if the rectangle is overlapping with a coordinate point
    bool is_overlapping(const point &p) const;
    bool is_overlapping(int x, int y) const;
    bool is_overlapping(const Circle &c) const;

private:
    double calculate_area() const override;
    double calculate_perimeter() const override;
    double base;
    double height;
    // Note: the inherited point will represent
    // the top left corner of the rectangle
};

class HollowCircle : public Shape {
public:
    //Constructors
    HollowCircle();
    HollowCircle(double radiusIn, double radiusOut, color f, int x, int y);
    // Copy Constructor
    HollowCircle(const HollowCircle &copy);
    //Getters
    double getRadiusInner() const;
    double getRadiusOuter() const;
    //Setters
    void setRadiusInner(int newRadius);
    void setRadiusOuter(int newRadius);

    //Other methods
    bool is_overlapping(int x, int y) const;
    bool is_overlapping(Circle circle) const;
    bool is_overlapping(Rectangle_Shape rectangle) const;
    bool is_overlapping(HollowCircle hollowCircle) const;

    void draw() const override;
private:
    double radiusInner;
    double radiusOuter;
    double calculate_area() const override;
    double calculate_perimeter() const override;
};

// Note these will be equilateral triangles only
class Triangle : public Shape {
public:
    // Constructors
    Triangle();
    Triangle(double sideLength);
    Triangle(double sideLength, color f, int x, int y);
    // Copy Conctructor
    Triangle(const Triangle &copy);
    // Getters
    double getSideLength() const;
    triangleDirection getTriangleDirection() const;
    // Setters
    void setSideLength(double newSideLength);

    // Functions
  //  virtual void draw()const override;
    virtual string getDirection() const = 0;

private:
    double sideLength;
    triangleDirection direction;
    double calculate_area() const override;
    double calculate_perimeter() const override;
};

class TriangleUp : public Triangle{
public:
    // Constructors
    TriangleUp();
    TriangleUp(double sideLength);
    TriangleUp(double sideLength, color f, int x, int y);
    // Copy Conctructor
    TriangleUp(const Triangle &copy);

    void draw() const;
    string getDirection() const;
};

class TriangleLeft : public Triangle{
public:
    // Constructors
    TriangleLeft();
    TriangleLeft(double sideLength);
    TriangleLeft(double sideLength, color f, int x, int y);
    // Copy Conctructor
    TriangleLeft(const Triangle &copy);

    void draw() const;
    string getDirection() const;
};

class TriangleDown : public Triangle{
public:
    TriangleDown();
    TriangleDown(double sideLength);
    TriangleDown(double sideLength, color f, int x, int y);
    // Copy Conctructor
    TriangleDown(const Triangle &copy);

    void draw() const;
    string getDirection() const;
};

class TriangleRight : public Triangle{
public:
    TriangleRight();
    TriangleRight(double sideLength);
    TriangleRight(double sideLength, color f, int x, int y);
    // Copy Conctructor
    TriangleRight(const Triangle &copy);

    void draw() const;
    string getDirection() const;
};

#endif //CIRCLE_MANIA_SHAPES_H
