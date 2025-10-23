# C++ Template Vector ADT

This project implements a **generic Vector Abstract Data Type (ADT)** in C++ using templates.  
It demonstrates object-oriented design, operator overloading, deep vs. shallow copying, and memory management.  
The project also includes a comprehensive `main()` test driver that validates each implemented method.

---

## 🧩 Overview

The `Vector` class provides a lightweight, dynamic array that supports any element type `T`.  
It showcases language constructs such as:

- **Templates** for type generalization  
- **Constructors and destructors** for resource management  
- **Copy constructors and assignment operators** for deep copying  
- **Operator overloading** for arithmetic and comparison  
- **Friend functions** for external operator definitions  
- **Const correctness** and **exception handling**

---

## 🧠 Key Features

| Feature | Description |
|----------|--------------|
| **Parameterized ADT** | Defined as a C++ template class supporting any type `T` |
| **Dynamic Allocation** | Uses heap-allocated arrays with manual memory management |
| **Deep Copy Semantics** | Copy constructor and assignment operator perform deep copies |
| **Operator Overloading** | Implements `+`, `*`, `==`, `!=`, `[]`, and `<<` |
| **Friend Functions** | Enables `20 * Vector` and `20 + Vector` syntax |
| **Safety Checks** | Throws `std::out_of_range` for invalid index access |
| **Output Formatting** | Overloaded `<<` to print vectors in human-readable format |

---

## 🧪 Example Usage

```cpp
#include "vector.h"

int main() {
    Vector<int> intVec{1, 3, 5, 7, 9};
    Vector<double> doubleVec{1.5, 2.5, 3.5, 4.5};
    Vector<int> iv{intVec};
    Vector<int> newIntVec{1, 2, 3};

    cout << "intVec" << intVec << endl;        // (1, 3, 5, 7, 9)
    cout << "iv" << iv << endl;                // (1, 3, 5, 7, 9)
    cout << "intVec * iv = " << intVec * iv << endl;  // 140
    cout << "intVec + iv = " << intVec + iv << endl;  // (2, 6, 10, 14, 18)
    cout << "2 * newIntVec = " << 2 * newIntVec << endl;  // (2, 4, 6)
    cout << "2 + newIntVec = " << 2 + newIntVec << endl;  // (3, 4, 5)
}
```

---

## ⚙️ Implementation Details

Files:
```
vector.h      # Implementation of Vector<T>
vectest.cpp   # Main driver for testing all methods
```

Compilation:
```
g++ vectest.cpp -o vectest -std=c++11
./vectest
```

Memory Checking (Valgrind):
```
valgrind ./vectest
```

---

## 🧭 Concepts Illustrated

- Template-based ADTs

- Static vs. Dynamic Scoping (conceptual questions)

- Deep vs. Shallow Copy

- Friend and Const usage

- Operator overloading and polymorphism

---

## 🧰 Tools Used

Language: C++11

Compiler: g++ v7.4.0
