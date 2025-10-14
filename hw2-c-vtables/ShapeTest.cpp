#include <cstddef>
#include <stddef.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

// A vtable is an array of method pointers.
// The specific profile for each method will depend on how the programmer declared the parameters and return type.

// In this example, the methods all return type double, and they only take the this parameter.
// The methods draw() and area() from your HW1 have different return types (so I defined the union below for you
// to use in your homework).

typedef double (*double_method_type)(void *);
typedef void (*void_method_type)(void *);

typedef union {
	double_method_type double_method; // this is for area()
	void_method_type void_method;     // this is for draw() & print()
} VirtualTableEntry;

typedef VirtualTableEntry * VTableType;


// These are the indices of the virtual functions in this class hierarchy, starting 0, 1, ...
#define AREA_INDEX 0
#define PRINT_INDEX 1
#define DRAW_INDEX 2

#define PI 3.14159

/*
class Shape{
	String name;
	Shape(String newName){name = newName;}
	double area(){return 0;}//calculates and returns the area of this Shape
	void print(){}//prints this Shape’s name, dimensions, and area()
	void draw(){}//draws this Shape using character graphics
}
*/
struct Shape{
	VTableType VPointer;
	string name;
};

VirtualTableEntry Shape_VTable [] = {
	{.double_method = NULL},
	{.void_method = NULL},
	{.void_method = NULL}
};

Shape* Shape_Shape(Shape* _this, string newName){
	_this->VPointer = Shape_VTable;
	_this->name = newName;

	return _this;
}

/*
class Circle extends Shape{
	int radius;
	Circle(String newName, int newRadius){
		super(newName);
		radius = newRadius;
	}
	double area(){return Math.PI * radius * radius;}
	void print(){
		System.out.print(name + "(" + radius + ") : ");
		double result = area();
		if (result == (long)result){
			System.out.println((long)result);
		}
		else{
			System.out.println(Math.round(result * 100.0) / 100.0);
		}
	}
	void draw(){
		double margin = 0;
		if (radius <= 6 && radius > 0){
			margin = 1;
		}
		else if(radius > 6 && radius <= 15){
			margin = 0.8;
		}
		else if(radius > 15){
			margin = 0.5;
		}
		double centerX = radius;
		double centerY = radius;
		for (int y = 0; y < 2 * radius; y++){
			for (int x = 0; x < 2 * radius; x++){
				double distance = Math.sqrt(Math.pow((x-centerX), 2)+Math.pow((y-centerY), 2));
				if (distance > (radius - margin) && (distance < (radius + margin))){
					System.out.print("*");
				}
				else{
					System.out.print(" ");
				}
			}
			System.out.println();
		}
	}
}
*/
struct Circle{
	VTableType VPointer;
	string name;
	int radius;
};

double Circle_area(Circle* _this){
	return PI * _this->radius * _this->radius;
}
void Circle_print(Circle* _this){
	cout << _this->name << "(" << _this->radius << ") : " << Circle_area(_this) << endl;
}

void Circle_draw(Circle* _this){
	double margin = 0;
	if (_this->radius <= 6 && _this->radius > 0){
		margin = 1;
	}
	else if(_this->radius > 6 && _this->radius <= 15){
		margin = 0.8;
	}
	else if(_this->radius > 15){
		margin = 0.5;
	}
	double centerX = _this->radius;
	double centerY = _this->radius;
	for (int y = 0; y < 2 * _this->radius; y++){
		for (int x = 0; x < 2 * _this->radius; x++){
			double distance = sqrt(pow((x-centerX), 2)+pow((y-centerY), 2));
			if (distance > (_this->radius - margin) && (distance < (_this->radius + margin))){
				cout << "*";
			}
			else{
				cout << " ";
			}
		}
		cout << endl;
	}
}

VirtualTableEntry Circle_VTable [] = {
	{.double_method = (double_method_type)Circle_area},
	{.void_method = (void_method_type)Circle_print},
	{.void_method = (void_method_type)Circle_draw}
};

Circle* Circle_Circle(Circle* _this, string newName, int newRadius){
	Shape_Shape((Shape *)_this, newName);
	_this->VPointer = Circle_VTable;
	_this->name = newName;
	_this->radius = newRadius;

	return _this;
}

/*
class Triangle extends Shape{
    int base;
	int height;
	Triangle(String newName, int newBase, int newHeight){
		super(newName);
		base = newBase;
		height = newHeight;
	}
	double area(){return (double)base * height / 2;}
	void print(){
		System.out.print(name + "(" + base + ", " + height + ") : ");
		double result = area();
		if (result == (long)result){
			System.out.println((long)result);
		}
		else{
			System.out.println(result);
		}
	}
	void draw(){
		//
		// Loop over each row → print spaces first → then print stars → then newline.
		// Spaces = (height – row), stars = (2 × row – 1).
		//
		for (int row = 1; row <= height; row++){
			int spaces = height - row;
			int stars = 2 * row - 1;
			for (int i = 1; i <= spaces; i++){
				System.out.print(" ");
			}
			for (int j = 1; j <= stars; j++){
				System.out.print("*");
			}
			System.out.println();
		}
	}
}
*/
struct Triangle{
	VTableType VPointer;
	string name;
	int base;
	int height;
};

double Triangle_area(Triangle* _this){
	return (double)_this->base * _this->height / 2;
}
void Triangle_print(Triangle* _this){
	cout << _this->name << "(" << _this->base << ", " << _this->height << ") : " << Triangle_area(_this) << endl;
}
void Triangle_draw(Triangle* _this){
	//
	// Loop over each row → print spaces first → then print stars → then newline.
	// Spaces = (height – row), stars = (2 × row – 1).
	//
	for (int row = 1; row <= _this->height; row++){
		int spaces = _this->height - row;
		int stars = 2 * row - 1;
		for (int i = 1; i <= spaces; i++){
			cout << " ";
		}
		for (int j = 1; j <= stars; j++){
			cout << "*";
		}
		cout << endl;
	}
}

VirtualTableEntry Triangle_VTable [] = {
	{.double_method = (double_method_type)Triangle_area},
	{.void_method = (void_method_type)Triangle_print},
	{.void_method = (void_method_type)Triangle_draw}
};

Triangle* Triangle_Triangle(Triangle* _this, string newName, int newBase, int newHeight){
	Shape_Shape((Shape *)_this, newName);
	_this->VPointer = Triangle_VTable;
	_this->name = newName;
	_this->base = newBase;
	_this->height = newHeight;

	return _this;
}

/*
class Square extends Shape{
    int length;
	Square(String newName, int newlength){
		super(newName);
		length = newlength;
	}
	double area(){return length * length;}
	void print(){
		System.out.print(name + "(" + length + ") : ");
		double result = area();
		if (result == (long)result){
			System.out.println((long)result);
		}
		else{
			System.out.println(result);
		}
	}
	void draw(){
		//
		// Use two nested loops — one for rows, one for columns.
		// Print * if you’re on the first or last row, or the first or last column
		// Otherwise, print a space
		//
		for (int row = 1; row <= length; row++){
			for (int col = 1; col <= length; col++){
				if(row == 1 || row == length){
					System.out.print("*");
				}
				else if(col == 1 || col == length){
					System.out.print("*");
				}
				else{
					System.out.print(" ");
				}
			}
			System.out.println();
		}
	}
}
*/
struct Square{
	VTableType VPointer;
	string name;
	int length;
};

double Square_area(Square* _this){
	return _this->length * _this->length;
}

void Square_print(Square* _this){
	cout << _this->name << "(" << _this->length << ") : " << Square_area(_this) << endl;
}

void Square_draw(Square* _this){
	//
	// Use two nested loops — one for rows, one for columns.
	// Print * if you’re on the first or last row, or the first or last column
	// Otherwise, print a space
	//
	for (int row = 1; row <= _this->length; row++){
		for (int col = 1; col <= _this->length; col++){
			if(row == 1 || row == _this->length){
				cout << "*";
			}
			else if(col == 1 || col == _this->length){
				cout << "*";
			}
			else{
				cout << " ";
			}
		}
		cout << endl;
	}
}

VirtualTableEntry Square_VTable [] = {
	{.double_method = (double_method_type)Square_area},
	{.void_method = (void_method_type)Square_print},
	{.void_method = (void_method_type)Square_draw}
};

Square* Square_Square(Square* _this, string newName, int newLength){
	Shape_Shape((Shape *)_this, newName);
	_this->VPointer = Square_VTable;
	_this->name = newName;
	_this->length = newLength;

	return _this;
}

/*
class Rectangle extends Square{
	int width;
	Rectangle(String newName, int newLength, int newWidth){
		super(newName, newLength);
		width = newWidth;
	}
	double area(){return length * width;}
	void print(){
		System.out.print(name + "(" + length + ", " + width + ") : ");
		double result = area();
		if (result == (long)result){
			System.out.println((long)result);
		}
		else{
			System.out.println(result);
		}
	}
	void draw(){
		//
		// Use two nested loops — one for rows, one for columns.
		// Print * if you’re on the first or last row, or the first or last column
		// Otherwise, print a space
		//
		for (int row = 1; row <= length; row++){
			for (int col = 1; col <= width; col++){
				if(row == 1 || row == length){
					System.out.print("*");
				}
				else if(col == 1 || col == width){
					System.out.print("*");
				}
				else{
					System.out.print(" ");
				}
			}
			System.out.println();
		}
	}
}
*/
struct Rectangle{
	VTableType VPointer;
	string name;
	int length;
	int width;
};

double Rectangle_area(Rectangle* _this){
	return _this->length * _this->width;
}

void Rectangle_print(Rectangle* _this){
	cout << _this->name << "(" << _this->length << ", " << _this->width << ") : " << Rectangle_area(_this) << endl;
}

void Rectangle_draw(Rectangle* _this){
	//
	// Use two nested loops — one for rows, one for columns.
	// Print * if you’re on the first or last row, or the first or last column
	// Otherwise, print a space
	//
	for (int row = 1; row <= _this->length; row++){
		for (int col = 1; col <= _this->width; col++){
			if(row == 1 || row == _this->length){
				cout << "*";
			}
			else if(col == 1 || col == _this->width){
				cout << "*";
			}
			else{
				cout << " ";
			}
		}
		cout << endl;
	}
}

VirtualTableEntry Rectangle_VTable [] = {
	{.double_method = (double_method_type)Rectangle_area},
	{.void_method = (void_method_type)Rectangle_print},
	{.void_method = (void_method_type)Rectangle_draw}
};

Rectangle* Rectangle_Rectangle(Rectangle* _this, string newName, int newLength, int newWidth){
	Square_Square((Square *)_this, newName, newLength);
	_this->VPointer = Rectangle_VTable;
	_this->name = newName;
	_this->length = newLength;
	_this->width = newWidth;

	return _this;
}

/*
void printAll(){
	//void printAll() traverses the list and calls print() on each shape
	for (ListNode i = head; i != null; i = i.next){
		i.info.print();
	}
}
*/
void printAll(Shape* sh[], int size){
	for (int i = 0; i < size; i++){
		sh[i]->VPointer[PRINT_INDEX].void_method(sh[i]);
	}
	cout << endl;
}

/*
void drawAll(){
	//void drawAll() traverses the list and calls draw() on each shape
	for (ListNode i = head; i != null; i = i.next){
		i.info.draw();
	}
}
*/
void drawAll(Shape* sh[], int size){
	for (int i = 0; i < size; i++){
		sh[i]->VPointer[DRAW_INDEX].void_method(sh[i]);
	}
	cout << endl;
}

/*
double totalArea(){
	//double totalArea() returns the total sum of all the areas of all the shapes in this Picture
	double sum = 0;
	for (ListNode i = head; i != null; i = i.next){
		sum += i.info.area();
	}
	return sum;
}
*/
double totalArea(Shape* sh[], int size){
	double sum = 0;
	for (int i = 0; i < size; i++){
		sum += sh[i]->VPointer[AREA_INDEX].double_method(sh[i]);
	}
	return sum;
}

/*
public class mainClass
{
	public static void main(String[] args) {

		int arg1 = Integer.parseInt(args[0]);
		int arg2 = Integer.parseInt(args[1]);
		Picture newPic = new Picture();
		newPic.add(new Triangle("FirstTriangle", arg1, arg2));
		newPic.add(new Triangle("SecondTriangle", arg1 - 1, arg2 -1));
		newPic.add(new Circle("FirstCircle", arg1));
		newPic.add(new Circle("SecondCircle", arg1 - 1));
		newPic.add(new Square("FirstSquare", arg1));
		newPic.add(new Square("SecondSquare", arg1 - 1));
		newPic.add(new Rectangle("FirstRectangle", arg1, arg2));
		newPic.add(new Rectangle("SecondRectangle", arg1 - 1, arg2 -1));
		newPic.printAll();
		newPic.drawAll();
		System.out.println("Total: " + Math.round(newPic.totalArea() * 100.0) / 100.0);
	}
}
*/
int main(int argc, char* arga[]){
	if (argc < 3){
		return 1;
	}

	int arg1 = stoi(arga[1]);
	int arg2 = stoi(arga[2]);
	Shape* shapes[] = {
		(Shape*)Triangle_Triangle((Triangle*) malloc(sizeof(Triangle)), "FirstTriangle", arg1, arg2),
		(Shape*)Triangle_Triangle((Triangle*) malloc(sizeof(Triangle)), "SecondTriangle", arg1 - 1, arg2 - 1),
		(Shape*)Circle_Circle((Circle*) malloc(sizeof(Circle)), "FirstCircle", arg1),
		(Shape*)Circle_Circle((Circle*) malloc(sizeof(Circle)), "SecondCircle", arg1 - 1),
		(Shape*)Square_Square((Square*) malloc(sizeof(Square)), "FirstSquare", arg1),
		(Shape*)Square_Square((Square*) malloc(sizeof(Square)), "SecondSquare", arg1 - 1),
		(Shape*)Rectangle_Rectangle((Rectangle*) malloc(sizeof(Rectangle)), "FirstRectangle", arg1, arg2),
		(Shape*)Rectangle_Rectangle((Rectangle*) malloc(sizeof(Rectangle)), "SecondRectangle", arg1 - 1, arg2 - 1),
	};
	printAll(shapes, sizeof(shapes) / sizeof(shapes[0]));
	drawAll(shapes, sizeof(shapes) / sizeof(shapes[0]));
	cout << "Total: " << totalArea(shapes, sizeof(shapes) / sizeof(shapes[0]));

	for (size_t i = 0; i < (int) sizeof(shapes) / sizeof(shapes[0]); i++) {
		free(shapes[i]);
	}
	
	return 0;
}