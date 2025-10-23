#ifndef VECTOR_H
#define VECTOR_H
#include <cassert>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <initializer_list>
using namespace std;
/* Commented by Safeeullah Saifuddin, Fall 2022 */
/** ADVISED ORDER OF IMPLEMENTATION
 * 1. Constructors
 * 2. Inserter (<<) -> allows you to print & see what is in the vector throughout development
 * 3. Write test cases that use some of the constructors and print those vectors out
 * 4. Write a test case for a function
 * 5. Implement the function and test until you are confident on its correctness
 * 6. Repeat from 4 until all methods are implemented and tested
 * 7. Implement the destructor last; if there are still errors,
      then you know it is due to memory management
*/
template <typename T> // We will only be testing int and double
class Vector {
 private:
  /**
   * size_t sz   size of the vector i.e the amount of elements in the vector
  */
  size_t sz;
  /**
   * T* buf  pointer to the base (first element) of a dynamically allocated array
   *    Be careful to manage its memory wisely (calling del[] when necessary)
  */
  T* buf;  
 public:
  /**
   * Constructs a vector of size sz
   *
   * ex: Vector v(10); -> constructs a 10 elem Vector
   * @param sz size of vector
  */
  Vector(size_t sz) {
    this->sz = sz;
    buf = new T[sz];
  }

  /**
   * Constructs a vector from a list of elements
   *
   * ex: Vector v1{1, 2, 3}; -> creates a vector with values 1, 2, 3 and size 3
   * @param L a list of values to initialize our vector
   *   - L.size() gives the list's size
   *   - You can iterate through it using an iterator
  */
  Vector(initializer_list<T> L) {
    sz = L.size();
    if (L.size() > 0){
      int itr = 0;
      buf = new T[sz];
      for (auto Litr = L.begin(); Litr != L.end(); Litr++){
        buf[itr] = *Litr;
        itr++;
      }
      assert(sz == itr);
    }
  }

/**
   * Destructs the object at the end of the object's lifecycle
   *  - Automatically called
   * Deallocate the array here.
   * Some versions of valgrind report 72704 bytes in one still-reachable block.  
   * You can ignore that.
  */
  ~Vector() {
    delete[] buf;
    sz = 0;
    buf = nullptr;
  }

  /**
   * Copy constructor; makes a new Vector by deep copying the vector passed to it
   * ex: Vector v2{v1};
  */
  Vector(const Vector & v) {
    sz = v.size();
    buf = new T[sz];
    for (int i = 0; i < v.size(); i++){
      buf[i] = v[i];
    }
  }

  /**
   * Returns the size of the vector
   * ex: Vector v1(10); v1.size(); -> will return 10
   * @return size of vector
  */
  size_t size() const {
    return sz;
  }

  /**
  * Overloads the [] operator and returns a reference to the value at index i in the
  * dynamically allocated array. This would be used to change the value at that index.
  * Throws an error when accessing index out of bounds
  * ex: v1[2] = 3;
  * @param i index of elem in buf that will be accessed
  */
  T & operator [] (const int i) {
    if (i >= sz){
      throw out_of_range("Index " + to_string(i) + " is out of range.");
    }
    else{
      return buf[i];
    }
  }

  /**
  * Overloads the [] operator and returns the value of the elem at index i in the
  * dynamically allocated array. This would be used to access the value at that index
  * without modifying it.
  * Throws an error when accessing index out of bounds
  * ex: T elemAtInd3 = v1[3];
  * @param i index of elem in buf that will be accessed
  */
  T operator [] (const int i) const {
    if (i >= sz){
      throw out_of_range("Index " + to_string(i) + " is out of range.");
    }
    else{
      return buf[i];
    }
  }
 
  /**
   * Dot products the current vector with the passed vector.
   * The dot product of two vectors is the sum of the products
   * of the corresponding entries of two sequences of numbers.
   *
   * ex: T x = V1 * V2;
   * dot product: [1, 2] * [3, 4, 5] = 1 * 3 + 2 * 4 + 0 = 11
   * Assume an empty Vector will cause the product to be 0.
   * @param v Vector on the right to dot product with
   * @return a scalar value with type T (not a vector!) that is the dot product of the
   *    two vectors
  */
  T operator * (const Vector & v) const {
    int longer_vector_length = 0;
    if (sz >= v.size()){
      longer_vector_length = sz;
    }
    else{
      longer_vector_length = v.size();
    }

    T result = 0;
    for (int i = 0; i < longer_vector_length; i++){
      T left_num = 0;
      T right_num = 0;
      if (buf[i]){
        left_num = buf[i];
      }
      else{
        left_num = 0;
      }
      if (v[i]){
        right_num = v[i];
      }
      else{
        right_num = 0;
      }
      result += left_num * right_num;
    }
    return result;
  }

  /**
   * Adds the current vector with the passed vector and returns a new vector.
   * ex: V3 = V1 + V2;
   * addition: [1, 2, 3] + [4, 5, 6, 7] = [5, 7, 9, 7]
   * @param v Vector on the right to perform addition with
   * @return new vector where index i is the result of this[i] + v[i]
  */
  Vector operator + (const Vector & v) const {
    int longer_vector_length = 0;
    if (sz >= v.size()){
      longer_vector_length = sz;
    }
    else{
      longer_vector_length = v.size();
    }

    Vector<T> new_vector(longer_vector_length);
    for (int i = 0; i < longer_vector_length; i++){
      T result = 0;
      T left_num = 0;
      T right_num = 0;
      if (buf[i]){
        left_num = buf[i];
      }
      else{
        left_num = 0;
      }
      if (v[i]){
        right_num = v[i];
      }
      else{
        right_num = 0;
      }
      new_vector[i] = left_num + right_num;
    }

    return new_vector;
  }

  /**
   * Destructs the current vector and deep copies the passed vector
   * ex: V1 = V2;
   * V1 could be an already existing vector, be sure to clean it up before the deep copy
   * @param v Vector on the right to deep copy
   * @return reference to the current object
  */
  const Vector & operator = (const Vector & v) {
    if (this != &v){
      delete[] buf;
      sz = v.sz;
      buf = new T[sz];
      for (int i = 0; i < sz; i++){
        buf[i] = v[i];
      }
    }
    return *this;
  }
 
  /**
   * Determines whether the current vector is equivalent to the passed vector
   * ex: bool isV1AndV2Same = V1 == V2;
   * @param v Vector on the right to compare current with
   * @return true if both vectors are deeply equivalent (elem by elem comparison)
   * and false otherwise
  */
  bool operator == (const Vector & v) const {
    for (int i = 0; i < v.size(); i++){
      if (buf[i] && v[i]){
        if (buf[i] != v[i]){
          return false;
        }
      }
    }
    return true;
  }

  /**
   * Determines whether the current vector is not equivalent to the passed vector
   * ex: bool isV1AndV2Different = V1 != V2;
   * @param v Vector on the right to compare current with
   * @return false if both vectors are deeply equivalent (elem by elem comparison)
   * and true otherwise
  */
  bool operator != (const Vector & v) const {
    for (int i = 0; i < v.size(); i++){
      if (!buf[i] || !v[i]){
        return true;
      }
      else{
        if (buf[i] != v[i]){
          return true;
        }
      }
    }
    return false;
  }

  /**
   * Multiplies each element in current vector with the passed integer and returns a new vector.
   * ex: V1 = 20 * V2; it is important that 20 is on the left!
   * 20 * [1, 2, 3] = [20, 40, 60]
   * @param scale integer to multiple each element of vector v
   * @param v Vector on the right to perform multiplication on
   * @return new vector where index i is the result of v[i] * scale
  */
  inline friend Vector operator * (const int scale, const Vector & v) {
    Vector new_vector(v.size());
    for (int i = 0; i < v.size(); i++){
      new_vector[i] = v[i] * scale;
    }
    return new_vector;
  }

  /**
   * Adds each element in the current vector with the passed integer and returns a new vector.
   * ex: V1 = 20 + V2; it is important that 20 is on the left!
   * 20 + [1, 2, 3] = [21, 22, 23]
   * @param adder integer to add to each element of vector v
   * @param v Vector on the right to perform addition on
   * @return new vector where index i is the result of v[i] + adder
  */
  inline friend Vector operator + (const int adder, const Vector & v) {
    Vector new_vector(v.size());
    for (int i = 0; i < v.size(); i++){
      new_vector[i] = v[i] + adder;
    }
    return new_vector;
  }

  /**
   * Allows the << operator to correctly print out the vector.
   * ex: cout << V2; -> (v[0], v[1], v[2], ... v[sz-1])
   * @param o ostream to print the elems of the array, usage is o << thingToPrint;
   * @param v vector that will be printed out
   * @return the ostream passed in
  */
  inline friend ostream& operator << (ostream & o, const Vector & v) {
    o << "(";
    for (int i = 0; i < v.size(); i++){
      o << v[i];
      if (i + 1 < v.size()){
        o << ", ";
      }
    }
    o << ")";
    return o;
  }
};

#endif