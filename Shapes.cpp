
#include "Shapes.h"
#include "graphics.h"

#include <math.h>
int CONSTANT = 100;
//***************************************************************************************************************//
//                                            Beginning of Shape Class                                           //
//***************************************************************************************************************//

Shape::Shape() {
    // default color: black
    fill = {0, 0, 0};
    position = {0, 0};
}

Shape::Shape(color f) : Shape() {
    fill = f;
    position = {0,0};
}

Shape::Shape(point p) : Shape() {
    set_position(p);
}

Shape::Shape(color f, point p) : Shape(f) {
    set_position(p);
}

Shape::Shape(color f, int x_in, int y_in) : Shape(f) {
    set_position(x_in, y_in);
}

Shape::Shape(int x_in, int y_in) : Shape() {
    set_position(x_in, y_in);
}

// copy constructor
Shape::Shape(const Shape &s) : fill(s.fill) , position(s.position){
}

Shape::~Shape() {
    // does nothing
}

double Shape::get_area() const {
    return calculate_area();
}

double Shape::get_perimeter() const {
    return calculate_perimeter();
}

color Shape::get_fill() const {
    return fill;
}

point Shape::get_position() const {
    return position;
}

double Shape::get_x() const {
    return position.x;
}

double Shape::get_y() const {
    return position.y;
}

void Shape::set_fill(color f) {
    fill = f;
}

void Shape::set_fill(double r, double g, double b) {
    fill = {r, g, b};
}

void Shape::set_position(point p) {
    position = p;
}

void Shape::set_position(int x_in, int y_in) {
    position.x = x_in;
    position.y = y_in;
}

void Shape::move(int delta_x, int delta_y) {
    // Note: if delta_x is negative, this will
    // in effect subtract from the x position.
    position.x += delta_x;
    // Note: if delta_y is negative, this will
    // in effect subtract from the y position.
    position.y += delta_y;
}

//***************************************************************************************************************//
//                                            Beginning of Circle Class                                          //
//***************************************************************************************************************//

Circle::Circle() : Shape(), radius(0) {
}

Circle::Circle(double r) : Shape() {
    set_radius(r);
}

Circle::Circle(double r, color f) : Shape(f) {
    set_radius(r);
}

Circle::Circle(color f) : Shape(f), radius(0) {
}

Circle::Circle(const Circle &c) {
    position = c.position;
    radius = c.radius;
    fill = c.fill;
}

Circle::Circle(double r, color f, point p) {
    position = p;
    radius = r;
    fill = f;
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    if (r < 0) {
        radius = 0;
    } else {
        radius = r;
    }
}

void Circle::draw() const {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(fill.red, fill.green, fill.blue);
    glVertex2i(position.x, position.y);
    const double PI = 3.141592653589793;
    for (double i = 0; i <= 2.0 * PI + 0.05; i += 2.0 * PI / 360.0) {
        glVertex2i(position.x + radius * cos(i), position.y + radius * sin(i));
    }
    glEnd();

    /*
    glBegin(GL_TRIANGLE_FAN);
    // center vertex will be white
    glColor3f(1,0,1);
    glVertex2i(position.x, position.y);
    for (double i = 0; i <= 2.0*M_PI+0.05; i += 2.0*M_PI/360.0) {
        // each vertex will be a different color
        glColor3f(fabs(sin(i)), 0.5, fabs(cos(i)));
        glVertex2i(position.x+radius*cos(i),position.y+radius*sin(i));
    }
    glEnd();
     */
}

bool Circle::is_overlapping(const point &p) const{
    return is_overlapping(p.x, p.y);
}

bool Circle::is_overlapping(int x, int y) const{
    // use Pythagorean Theorem to calculate distance between point and center of circle
    double distance = sqrt((x - position.x) * (x - position.x) + (y - position.y) * (y - position.y));
    // if the distance is <= radius, it overlaps. Otherwise, it doesn't.
    return (distance <= radius);
}


bool Circle::is_overlapping(const Circle &c) const{
    // if the distance between the centers is greater than the sum of the radius, they are not overlapping
    return !(sqrt(((c.get_x() - position.x) * (c.get_x() - position.x)) +
                  ((c.get_y() - position.y) * (c.get_y() - position.y)))
             > (radius + c.get_radius()));
}




double Circle::calculate_area() const {
    return 3.14 * radius * radius;
}

double Circle::calculate_perimeter() const {
    return 2.0 * 3.14 * radius;
}

//***************************************************************************************************************//
//                                          Beginning of Rectangle Class                                         //
//***************************************************************************************************************//

Rectangle_Shape::Rectangle_Shape() : Shape(), base(0), height(0) {
}

Rectangle_Shape::Rectangle_Shape(double b, double h) : Shape() {
    // NOT using initializer list with b and h
    // because we want to check for valid input
    // so we call setters instead.
    set_dimensions(b, h);
}

Rectangle_Shape::Rectangle_Shape(double b, double h, color f) : Shape(f) {
    set_dimensions(b, h);
}

Rectangle_Shape::Rectangle_Shape(color f) : Shape(f), base(0), height(0) {
}

Rectangle_Shape::Rectangle_Shape(int x_in, int y_in) : Shape(x_in, y_in), base(0), height(0) {
}

Rectangle_Shape::Rectangle_Shape(point p) : Shape(p), base(0), height(0) {
}

Rectangle_Shape::Rectangle_Shape(double b, double h, color f, int x_in, int y_in) : Shape(f, x_in, y_in) {
    set_dimensions(b, h);
}

double Rectangle_Shape::get_base() const{
    return base;
}

double Rectangle_Shape::get_height() const{
    return height;
}

void Rectangle_Shape::set_top_left(int x_in, int y_in) {
    if (x_in < 0) {
        x_in = 0;
    }
    if (y_in < 0) {
        y_in = 0;
    }
    position = {x_in, y_in};
    // Alternate:
    // position.x = x_in;
    // position.y = y_in;
}

void Rectangle_Shape::set_base(double b) {
    if (b < 0) {
        b = 0;
    }
    base = b;
}

void Rectangle_Shape::set_height(double h) {
    if (h < 0) {
        h = 0;
    }
    height = h;
}

void Rectangle_Shape::set_dimensions(double b, double h) {
    set_base(b);
    set_height(h);
}

void Rectangle_Shape::draw() const {

    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_QUADS);
    // top left corner
    glVertex2i(position.x, position.y);
    // top right corner
    glVertex2i(position.x + base, position.y);
    // bottom right corner
    glVertex2i(position.x + base, position.y + height);
    // bottom left corner
    glVertex2i(position.x, position.y + height);
    glEnd();

}

bool Rectangle_Shape::is_overlapping(const point &p) const{
    // this is not recursive
    // this calls the other is_overlapping method
    return is_overlapping(p.x, p.y);
}

bool Rectangle_Shape::is_overlapping(int x, int y) const{
    // check to see if x and y are in range of the rectangle
    return (x >= position.x && x <= (position.x + base) &&
            y >= position.y && y <= (position.y + height));
}


bool Rectangle_Shape::is_overlapping(const Circle &c) const {
    // either the center of the circle is in the rectangle
    if (is_overlapping(c.get_x(),c.get_y())) {
        return true;
    }
    // or one of the rectangle's edges overlaps with the circle
    // test the left side of the rectangle
    point bottom_left = {position.x, position.y + (int)height};
    if (c.is_overlapping(position) || c.is_overlapping(bottom_left)) {
        return true;
    }
    if (position.x >= (c.get_x()-c.get_radius()) &&
        position.x <= (c.get_x()+c.get_radius()) &&
        position.y <= c.get_y() &&
        bottom_left.y >= c.get_y()) {
        return true;
    }
    // test the right side of the rectangle
    point top_right = {position.x + (int)base, position.y};
    point bottom_right = {position.x + (int)base, position.y + (int)height};
    if (c.is_overlapping(top_right) || c.is_overlapping(bottom_right)) {
        return true;
    }
    if (top_right.x >= (c.get_x()-c.get_radius()) &&
        top_right.x <= (c.get_x()+c.get_radius()) &&
        top_right.y <= c.get_y() &&
        bottom_right.y >= c.get_y()) {
        return true;
    }
    // test the top side of the rectangle
    if (c.is_overlapping(position) || c.is_overlapping(top_right)) {
        return true;
    }
    if (top_right.y >= (c.get_y()-c.get_radius()) &&
        top_right.y <= (c.get_y()+c.get_radius()) &&
        position.x <= c.get_x() &&
        top_right.x >= c.get_x()) {
        return true;
    }
    // test the bottom side of the rectangle
    if (c.is_overlapping(bottom_left) || c.is_overlapping(bottom_right)) {
        return true;
    }
    if (bottom_right.y >= (c.get_y()-c.get_radius()) &&
        bottom_right.y <= (c.get_y()+c.get_radius()) &&
        bottom_left.x <= c.get_x() &&
        bottom_right.x >= c.get_x()) {
        return true;
    }
}

double Rectangle_Shape::calculate_area() const {
    return base * height;
}

double Rectangle_Shape::calculate_perimeter() const {
    return 2.0 * base + 2.0 * height;
}

/********** End of Rectangle class ****************/

//******************************************************************************************//
//                          Beginning of Hollow Circle Class (by Joshua Newton)             //
//******************************************************************************************//

HollowCircle::HollowCircle() : Shape(), radiusInner(0), radiusOuter(0) {

}

// TODO: VALIDATION FOR RADIUSIN < RADIUSOUT
HollowCircle::HollowCircle(double radiusIn, double radiusOut, color f, int x, int y) : Shape(f, x, y) {
    setRadiusInner(radiusIn);
    setRadiusOuter(radiusOut);
}
HollowCircle::HollowCircle(const HollowCircle &copy){
    setRadiusInner(copy.getRadiusInner());
    setRadiusOuter(copy.getRadiusOuter());
    set_fill(copy.get_fill());
    set_position(copy.get_position());
}

//Getters
double HollowCircle::getRadiusInner() const {
    return radiusInner;
}

double HollowCircle::getRadiusOuter() const {
    return radiusOuter;
}

//Setters
void HollowCircle::setRadiusInner(int newRadius) {
    radiusInner = newRadius;
}

void HollowCircle::setRadiusOuter(int newRadius) {
    radiusOuter = newRadius;
}

//Other methods
// is the hollow circle overlapping with a point
bool HollowCircle::is_overlapping(int x, int y) const {
    int distance;
    // Pythagorean theorem
    distance = sqrt((x - position.x) * (x - position.x) + (y - position.y) * (y - position.y));
    if (distance < radiusOuter && distance > radiusInner) {
        return true;
    } else {
        return false;
    }
}

// Is the hollow circle overlapping with a normal circles
bool HollowCircle::is_overlapping(Circle circle) const {
    // distance between the two circles' centers
    double distance = sqrt((circle.get_x() - position.x) * (circle.get_x() - position.x) +
                           (circle.get_y() - position.y) * (circle.get_y() - position.y));
    // If the circle is larger than or as large as the "inner circle"
    if (circle.get_radius() >= radiusInner) {
        if (distance <= radiusOuter + circle.get_radius()) {
            return true;
        } else {
            return false;
        }
    }
    // If the circle is smaller than the "inner circle"
    else if (circle.get_radius() < radiusInner) {
        // if the circle is inside the hollow part, and not touching the inside edge, return false
        if (distance + circle.get_radius() < radiusInner){
            return false;
        }
        // if the circle is outside the entire hollow circle
        else if (distance - circle.get_radius() > radiusOuter){
            return false;
        }
        // If the circle is touching
        else if ((distance + circle.get_radius() >= radiusInner)
                 && (distance - circle.get_radius() <= radiusOuter )){
            return true;
        }
    }

}

bool HollowCircle::is_overlapping(Rectangle_Shape rectangle) const{
    // TODO: finish this overlap


}

// TODO: test
bool HollowCircle::is_overlapping(HollowCircle hollowCircle) const{
    // If the distance between the two locations plus the outer radius of the second is
    // less than the inner radius of the first, then they do not overlap. (one is inside the other)
    double distance = sqrt(pow((hollowCircle.get_x() - position.x),2) + (pow((hollowCircle.get_y() - position.y),2)));
    if (distance + hollowCircle.getRadiusOuter() <= radiusInner){
        return false;
    }
    // If one is outside the other, and the distance the to outer perimeter of the second is greater
    // than the first's outer radius, then they do not overlap. (one is outside the other)
    else if (distance > radiusOuter && (distance - hollowCircle.getRadiusOuter()) > radiusOuter ){
        return false;
    }
    else {
        return true;
    }
}

void HollowCircle::draw() const{
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(fill.red, fill.green, fill.blue);
    glVertex2i( (position.x + radiusInner) , position.y);
    const double PI = 3.141592653589793;
    for (double i = 0; i <=2.0*PI + 0.05; i += 2.0 * PI / 360.0){
        glVertex2i( ( position.x + radiusOuter * cos(i) ) , (position.y + radiusOuter * sin(i)));
        glVertex2i(( position.x + radiusInner * cos(i) ) , (position.y + radiusInner * sin(i)));
    }
    glEnd();
}

double HollowCircle::calculate_area() const {
    const double PI = 3.141592653589793;
    // The large circle's area
    double areaLarge = PI * radiusOuter * radiusOuter;
    // The small circle's area
    double areaSmall = PI * radiusInner * radiusInner;
    // The Hollow circle's area
    return (areaLarge - areaSmall);
}

double HollowCircle::calculate_perimeter() const{
    // Same as perimeter for normal circle
    return 2.0 * 3.141592653589793 * radiusOuter;
}

/********** End of Hollow Circle class ****************/

//******************************************************************************************//
//                          Beginning of Triangle Class (by Joshua Newton)                  //
//******************************************************************************************//

/** Triangle (Abstract) begin **/
// Note these will be equilateral triangles only

// Constructors
Triangle::Triangle() : Shape(){

}

Triangle::Triangle(double sideLength) : Shape(){
    this->sideLength = sideLength;
}

Triangle::Triangle(double sideLength, color f) : Shape(f) {
    this->sideLength = sideLength;
}

Triangle::Triangle(double sideLength, color f, int x, int y) : Shape(f,x,y){
    this->sideLength = sideLength;
}
Triangle::Triangle(double sideLength, color f, Rectangle_Shape rectangle) : Shape(f){
    this->sideLength = sideLength;
    set_position(rectangle.get_position());
}


// Copy Constructor
Triangle::Triangle(const Triangle &copy){
    sideLength = copy.sideLength;
    fill = copy.fill;
    position = copy.position;
}
// Getters
double Triangle::getSideLength() const{
    return sideLength;
}

triangleDirection Triangle::getTriangleDirection() const{
    return direction;
}
// Setters
void Triangle::setSideLength(double newSideLength){
    sideLength = newSideLength;
}

// functions
double Triangle::calculate_area() const {
    return 2; // Fix this to return the proper number
}
double Triangle::calculate_perimeter() const {
    return sideLength * 3;
}

/** Triangle (Abstract) end **/

/** TriangleUp begin **/
TriangleUp::TriangleUp() : Triangle(){
}

TriangleUp::TriangleUp(double sideLength) : Triangle(sideLength){
}

TriangleUp::TriangleUp(double sideLength, color f) : Triangle(sideLength,f) {
}

TriangleUp::TriangleUp(double sideLength, color f, int x, int y) : Triangle(sideLength, f, x, y) {
}

TriangleUp::TriangleUp(double sideLength, color f, Rectangle_Shape rectangle) : Triangle(sideLength,f){
    // x position is set to the middle of the given rectangle
    // y position is set to sideLength above the rectangle
    set_position(rectangle.get_x() + (rectangle.get_base() / 2) , rectangle.get_y() - sideLength);
}

// Copy Constructor
TriangleUp::TriangleUp(const Triangle &copy) : Triangle(copy){
}

void TriangleUp::draw() const{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(fill.red, fill.green, fill.blue);
    glVertex2i(position.x, position.y);
    double deltaY = sin(60 * M_PI / 180) * (getSideLength() / 2);
    double deltaX = (getSideLength() / 2);
    glVertex2i(position.x - deltaX, position.y + deltaY);
    glVertex2i(position.x + deltaX, position.y + deltaY);
    glEnd();
}
string TriangleUp::getDirection() const{
    return "Up";
}
/** TriangleUp end **/

/** TriangleLeft begin **/

TriangleLeft::TriangleLeft() : Triangle(){
}

TriangleLeft::TriangleLeft(double sideLength) : Triangle(sideLength){
}

TriangleLeft::TriangleLeft(double sideLength, color f) : Triangle(sideLength,f) {
}

TriangleLeft::TriangleLeft(double sideLength, color f, int x, int y) : Triangle(sideLength, f, x, y) {
}

TriangleLeft::TriangleLeft(double sideLength, color f, Rectangle_Shape rectangle) : Triangle(sideLength,f){
    // x position is set to sideLength to the left of the given rectangle
    // y position is set to middle of the rectangle's height
    set_position(rectangle.get_x() - sideLength , rectangle.get_y() + (rectangle.get_height() / 2) );
}
// Copy Constructor
TriangleLeft::TriangleLeft(const Triangle &copy) : Triangle(copy){
}

void TriangleLeft::draw() const{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(fill.red, fill.green, fill.blue);
    glVertex2i(position.x, position.y);
    double deltaY = sin(60 * M_PI / 180) * (getSideLength() / 2);
    double deltaX = (getSideLength() / 2);
    glVertex2i(position.x + deltaX, position.y - deltaY);
    glVertex2i(position.x + deltaX, position.y + deltaY);
    glEnd();
}
string TriangleLeft::getDirection() const{
    return "Left";
}

/** TriangleLeft end **/

/** TriangleDown begin **/

TriangleDown::TriangleDown() : Triangle(){
}

TriangleDown::TriangleDown(double sideLength) : Triangle(sideLength){
}

TriangleDown::TriangleDown(double sideLength, color f) : Triangle(sideLength,f) {
}

TriangleDown::TriangleDown(double sideLength, color f, int x, int y) : Triangle(sideLength, f, x, y) {
}
TriangleDown::TriangleDown(double sideLength, color f, Rectangle_Shape rectangle) : Triangle(sideLength,f){
    // x position is set to middle of the rectangle's width
    // y position is set to sideLength below the rectangle
    set_position(rectangle.get_x() + (rectangle.get_base() / 2) , rectangle.get_y() + rectangle.get_height() + sideLength);
}

// Copy Constructor
TriangleDown::TriangleDown(const Triangle &copy) : Triangle(copy){
}

void TriangleDown::draw() const{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(fill.red, fill.green, fill.blue);
    glVertex2i(position.x, position.y);
    double deltaY = sin(60 * M_PI / 180) * (getSideLength() / 2);
    double deltaX = (getSideLength() / 2);
    glVertex2i(position.x - deltaX, position.y - deltaY);
    glVertex2i(position.x + deltaX, position.y - deltaY);
    glEnd();
}
string TriangleDown::getDirection() const{
    return "Down";
}
/** TriangleDown end **/

/** TriangleRight begin **/

TriangleRight::TriangleRight() : Triangle(){
}

TriangleRight::TriangleRight(double sideLength) : Triangle(sideLength){
}

TriangleRight::TriangleRight(double sideLength, color f) : Triangle(sideLength, f){
}

TriangleRight::TriangleRight(double sideLength, color f, int x, int y) : Triangle(sideLength, f, x, y) {
}

TriangleRight::TriangleRight(double sideLength, color f, Rectangle_Shape rectangle) : Triangle(sideLength,f){
    // x position is set to sideLength to the right of the given rectangle
    // y position is set to middle of the rectangle's height
    set_position(rectangle.get_x() + rectangle.get_base() + sideLength , rectangle.get_y() + (rectangle.get_height() / 2) );
}
// Copy Constructor
TriangleRight::TriangleRight(const Triangle &copy) : Triangle(copy){
}

void TriangleRight::draw() const{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(fill.red, fill.green, fill.blue);
    glVertex2i(position.x, position.y);
    double deltaY = sin(60 * M_PI / 180) * (getSideLength() / 2);
    double deltaX = (getSideLength() / 2);
    glVertex2i(position.x - deltaX, position.y + deltaY);
    glVertex2i(position.x - deltaX, position.y - deltaY);
    glEnd();
}
string TriangleRight::getDirection() const{
    return "Right";
}

/** TriangleRight end **/

/********** End of Triangle class ****************/
