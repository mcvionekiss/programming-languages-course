# 🧮 Homework 2 — C: Implementing a Class Hierarchy of Shapes with Vtables

## 📘 Overview

This project re-implements the **Java class hierarchy** from Homework 1 in the **C programming language**, simulating object-oriented behavior using **structs**, **vtables (virtual method tables)**, and **function pointers**.

The program dynamically constructs an array of various `Shape` objects — `Circle`, `Triangle`, `Square`, and `Rectangle` — and performs the following actions:

- Prints each shape’s **name**, **dimensions**, and **computed area**  
- Draws each shape using **ASCII-based character graphics**  
- Calculates and prints the **total area** of all shapes  

---

## 🧩 Structure and Design

| Component | Description |
|------------|--------------|
| **Shape** | Base struct containing a `name` field and a `VPointer` (pointer to the class’s virtual method table). |
| **Circle** | Derived struct that adds `radius`; overrides `area()`, `print()`, and `draw()`. |
| **Triangle** | Derived struct with `base` and `height`; implements its own geometric methods. |
| **Square** | Derived struct with `length`; implements its own `area()`, `print()`, and `draw()`. |
| **Rectangle** | Derived from `Square`; adds `width`; overrides virtual methods. |
| **VirtualTableEntry** | Union containing either a `double_method` or `void_method` pointer to support different return types. |
| **VTableType** | Array of `VirtualTableEntry` entries representing each struct’s virtual methods. |
| **Utility Functions** | `printAll()`, `drawAll()`, and `totalArea()` operate on an array of `Shape*` using dynamic dispatch. |
| **main()** | Creates and stores shapes, calls their methods through vtables, and outputs the total area. |

---

## 🧠 Key Concepts Demonstrated

- **Manual Object-Oriented Implementation:** Inheritance, overriding, and polymorphism expressed in plain C  
- **Dynamic Binding:** Calling overridden methods at runtime via vtable indices  
- **Vtables and Vpointers:** Emulating the compiler’s mechanism for virtual functions  
- **Dynamic Memory Allocation:** Each shape allocated with `malloc()` and freed manually  
- **Low-Level Simulation of Java OOP:** Mirrors the structure and behavior of Homework 1 without Java’s syntax  

Example of a dynamic function call:

```c
sh[i]->VPointer[AREA_INDEX].double_method(sh[i]);
```

## ⚙️ Compilation and Execution

Compile with any modern C++ compiler (C++17 recommended) since the program uses <iostream> and std::string:
```
g++ -std=c++17 ShapeTest.cpp -o main
./main <arg1> <arg2>
```

Example:
```
./main 12 15
```
## 🧾 Sample Output
```
FirstTriangle(12, 15) : 90
SecondTriangle(11, 14) : 77
FirstCircle(12) : 452.39
SecondCircle(11) : 380.13
FirstSquare(12) : 144
SecondSquare(11) : 121
FirstRectangle(12, 15) : 180
SecondRectangle(11, 14) : 154
Total: 1598.52
```

## 🧮 How It Works

Each struct stores a pointer to its vtable (VPointer), and each vtable stores function pointers for
area(), print(), and draw().
When a virtual method is called, the program looks up the appropriate function pointer in the vtable and executes it —
mimicking dynamic dispatch in C++ or Java.

## 🧰 Makefile Example
```
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
TARGET = main
SRC = ShapeTest.cpp

all: $(TARGET)
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET) 12 15

clean:
	rm -f $(TARGET)
```

## 💡 Lessons Learned

How virtual function tables underpin polymorphism in compiled OOP languages

Translating high-level inheritance and method overriding into low-level C constructs

The relationship between memory layout, function pointers, and runtime binding

Managing manual memory allocation (malloc / free) alongside polymorphic behavior
