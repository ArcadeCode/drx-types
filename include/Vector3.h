#pragma once
#include <valarray>
#include <cmath>
#include <stdexcept>

class Vector3 {
private:
    /* data */
public:
    float x = 0; // X coordinate of the vector in 3D space (Vector3)
    float y = 0; // Y coordinate of the vector in 3D space (Vector3)
    float z = 0; // Z coordinate of the vector in 3D space (Vector3)

    /**
     * @brief Calculates and returns the norm (magnitude) of the vector.
     * 
     * This function computes the Euclidean norm (length) of the Vector3 object,
     * which is the square root of the sum of the squares of its components (x, y, z).
     * 
     * @return The norm of the vector as a float.
     */
    float get_norm();

    /**
     * @brief Returns a normalized (unit) vector that is a copy of the original vector.
     * 
     * This function returns a new Vector3 object with the same direction as the original
     * vector, but with a length (magnitude) of 1. The original vector remains unchanged.
     * 
     * @return A new Vector3 object that is the normalized copy of the original vector.
     */
    Vector3 get_normalized();


    /************************************************************
     *                   OPERATOR ARITHMETICS                   *
     ************************************************************/

    Vector3 operator+(const Vector3& vec) const;
    Vector3 operator-(const Vector3& vec) const;
    Vector3 operator*(const int& scalar) const;
    Vector3 operator/(const int& scalar) const; 

    /************************************************************
     *                     OPERATOR LOGICS                      *
     ************************************************************/

    bool operator==(const Vector3& vec) const;
    bool operator!=(const Vector3& vec) const;
    bool operator>(const Vector3& vec) const;
    bool operator<(const Vector3& vec) const;
    bool operator>=(const Vector3& vec) const;
    bool operator<=(const Vector3& vec) const;

    Vector3(float x, float y, float z);
    ~Vector3();
};
