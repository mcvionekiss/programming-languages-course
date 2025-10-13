# Homework 1 — Java: A Class Hierarchy of Shapes

## 📘 Overview

This program implements a **class hierarchy of geometric shapes** in Java and demonstrates **object-oriented programming** concepts including:
- Inheritance  
- Dynamic method binding (virtual methods)  
- Encapsulation  

The program builds a `Picture` — a linked list of various `Shape` objects (`Circle`, `Triangle`, `Square`, and `Rectangle`) — and performs the following:
1. Draws each shape using simple character graphics (ASCII art)  
2. Prints each shape’s name, dimensions, and computed area  
3. Calculates and prints the **total area** of all shapes in the picture  

---

## 🧩 Class Structure

| Class | Description |
|--------|--------------|
| `Shape` | Base class containing a `name` field and virtual methods `print()`, `draw()`, and `area()` |
| `Circle` | Derived from `Shape`; stores radius and computes circular area |
| `Triangle` | Derived from `Shape`; stores base and height |
| `Square` | Derived from `Shape`; stores side length |
| `Rectangle` | Derived from `Square`; adds `width` data member |
| `ListNode` | Node class for singly linked list implementation |
| `Picture` | Linked list of `Shape` objects; includes `add()`, `printAll()`, `drawAll()`, and `totalArea()` methods |
| `mainClass` | Public class containing `main()` — constructs shapes and runs the program |

---

## 🧠 Key Concepts Demonstrated

- **Object-Oriented Design:** inheritance and method overriding  
- **Dynamic Binding:** runtime polymorphism through virtual method calls  
- **Data Structures:** manually implemented singly linked list (`Picture`)  
- **Encapsulation:** shape-specific area and draw methods  
- **Procedural control:** iteration, conditionals, and arithmetic operations  

---

## ⚙️ How to Compile and Run

The program runs on any Java 8 (or newer) environment.

### Compile & Run:
```bash
javac mainClass.java
java mainClass <x> <y>
#Where <x> and <y> are integer dimensions (e.g., base/height for triangles).
