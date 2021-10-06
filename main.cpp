#include "mathLib2D.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

int main() 
{
    std::cout << "\nChecking base functionality of Point2D \n";
    Point2D p = Point2D();
    p.mX = 0;
    p.mY = 0;
    std::cout << "Coordinates of point p are (" << p.mX << "," << p.mY << ")\n";
    Point2D p1 = Point2D(3,4);
    std::cout << "Coordinates of point p1 are (" << p1.mX << "," << p1.mY << ")\n";
    std::cout << "Distance from p to p1 is " << p.distanceTo(p1) << "\n"; // should be 5
    std::cout << "Fast distance from p to p1 is " << p.fastDistanceTo(p1) << "\n\n"; // should be 25

    std::cout << "Checking base functionality of Vec2D \n";
    Vec2D v = Vec2D();
    v.mX = 0;
    v.mY = 0;
    std::cout << "Coordinates of vector v are (" << v.mX << "," << v.mY << ") and magnitude is " << v.length() << "\n"; //magnitude should be 0
    Vec2D v1 = Vec2D(5,12);
    std::cout << "Coordinates of vector v1 are (" << v1.mX << "," << v1.mY << ") and magnitude is " << v1.length() << "\n"; // magnitude should be 13
    Vec2D vNorm = v1.normalize();
    std::cout << "v1 normalized is (" << vNorm.mX << "," << vNorm.mY << ")\n"; // should equal to (5/13,12/13)
    Vec2D vMul = v1.multiply(2);
    std::cout << "v1x2 is equal to the vector (" << vMul.mX << "," << vMul.mY << ")\n"; // should equal to (10,24)
    Point2D targetP = v1.movePoint(p1);
    std::cout << "p1 moved by vector v1 becomes point (" << targetP.mX << "," << targetP.mY << ")\n"; // should equal to (8,16)
    Vec2D createdVec = Vec2D::createVector(p,p1);
    std::cout << "Coordinates of vector createdVec are (" << createdVec.mX << "," << createdVec.mY << ") and magnitude is " << createdVec.length() << "\n\n"; // coordinated should be (3,4) and magnitude should be 5 

    std::cout << "Dynamically allocated array of random 2D points \n";
    Point2D* arr = NULL; // Pointer to Point2D, initialize to nothing.
    int n; // Size of array
    std::cout << "Specify size of array(int): ";
    std::cin >> n; // Read in the size
    arr = new Point2D[n];
    srand (time(NULL));
    int range = 40;
    for (int i=0; i<n; i++) {
        arr[i].mX = static_cast<float>(rand() % range + 1); // Initialize x coordinate elements to random numbers.
        arr[i].mY = static_cast<float>(rand() % range + 1); // Initialize y coordinate elements to random numbers.
    }
    
    std::cout << "C++ vector of random 2D points \n";
    std::vector<Point2D> vec;
    int m; // Size of array
    std::cout << "Specify size of vector(int): ";
    std::cin >> m; // Read in the size
    vec.assign(m, Point2D());
    for (int i=0; i<m; i++) {
        vec[i].mX = static_cast<float>(rand() % range + 1); // Initialize x coordinate elements to random numbers.
        vec[i].mY = static_cast<float>(rand() % range + 1); // Initialize y coordinate elements to random numbers.
    }

    std::cout << "Output contents of array and vector \n";
    std::cout << "Contents of array \n";
    for (int i=0; i<n; i++) {
        std::cout << "Coordinates of point " << i << " are (" << arr[i].mX << "," << arr[i].mY << ")\n"; 
    }
    std::cout << "Contents of vector \n";
    for (int i=0; i<m; i++) {
        std::cout << "Coordinates of point " << i << " are (" << vec[i].mX << "," << vec[i].mY << ")\n"; 
    }

    delete [] arr;  // Free memory allocated for the a array.
    arr = NULL;
    vec.clear();
    vec.shrink_to_fit();
    std::cout << "Memory freed \n";

    return 0;
}