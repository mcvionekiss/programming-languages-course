//A class hierarchy of Shapes: a base class, Shape,  
//     and derived classes Circle, Square, Rectangle, and Triangle
class Shape{
	String name;
	Shape(String newName){name = newName;}
	void print(){}//prints this Shape’s name, dimensions, and area()
	void draw(){}//draws this Shape using character graphics
	double area(){return 0;}//calculates and returns the area of this Shape
}

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
		/*
		* Loop over each row → print spaces first → then print stars → then newline.
		* Spaces = (height – row), stars = (2 × row – 1).
		*/
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
		/*
		 * Use two nested loops — one for rows, one for columns.
		 * Print * if you’re on the first or last row, or the first or last column
		 * Otherwise, print a space
		 */
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
		/*
		 * Use two nested loops — one for rows, one for columns.
		 * Print * if you’re on the first or last row, or the first or last column
		 * Otherwise, print a space
		 */
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

class ListNode{
	Shape info;
	ListNode next;
	ListNode(Shape newInfo, ListNode newNext){
		info = newInfo;
		next = newNext;
	}
}

//A class Picture which is implemented as a linked list of Shapes 
class Picture{
	ListNode head;
	Picture(){
		//A constructor that creates an empty Picture list (i.e., the linked list is empty)
		head = null;
	}
	void add(Shape sh){
		//add(Shape sh) adds the Shape sh to this Picture at the front of the linked list
		ListNode newNode = new ListNode(sh, head);
		head = newNode;
	}
	void printAll(){
		//void printAll() traverses the list and calls print() on each shape
		for (ListNode i = head; i != null; i = i.next){
			i.info.print();
		}
	}
	void drawAll(){
		//void drawAll() traverses the list and calls draw() on each shape
		for (ListNode i = head; i != null; i = i.next){
			i.info.draw();
		}
	}
	double totalArea(){
		//double totalArea() returns the total sum of all the areas of all the shapes in this Picture
		double sum = 0;
		for (ListNode i = head; i != null; i = i.next){
			sum += i.info.area();
		}
		return sum;
	}
}

//A main() method, which creates a Picture object, fills it with different Shapes, 
//     prints the Shapes, and prints the total area of all the Shapes in the Picture
public class mainClass
{
	public static void main(String[] args) {
		/*System.out.println("Hello World running!");
		Shape a_Shape = new Triangle("FirstTriangle", 7, 3);
		a_Shape.print();
		a_Shape.draw();
		Shape b_Shape = new Triangle("SecondTriangle", 6, 2);
		b_Shape.print();
		b_Shape.draw();
		Shape c_Shape = new Circle("FirstCircle", 7);
		c_Shape.print();
		c_Shape.draw();
		Shape d_Shape = new Circle("SecondCircle", 6);
		d_Shape.print();
		d_Shape.draw();
		Shape e_Shape = new Square("FirstSquare", 7);
		e_Shape.print();
		e_Shape.draw();
		Shape f_Shape = new Square("SecondSquare", 6);
		f_Shape.print();
		f_Shape.draw();
		Shape g_Shape = new Rectangle("FirstRectangle", 7, 3);
		g_Shape.print();
		g_Shape.draw();
		Shape h_Shape = new Rectangle("SecondRectangle", 6, 2);
		h_Shape.print();
		h_Shape.draw();*/

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