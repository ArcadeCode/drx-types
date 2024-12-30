#include "Vector3.h"

float Vector3::get_norm() {
    return sqrtf(powf(this->x, 2)+powf(this->y, 2)+powf(this->z, 2));
}
Vector3 Vector3::get_normalized() {
    float norm = this->get_norm();
    return Vector3(this->x/norm, this->y/norm, this->z/norm);
}
/************************************************************
 *                   OPERATOR ARITHMETICS                   *
 ************************************************************/

Vector3 Vector3::operator+(const Vector3& vec) const {
    return Vector3(x + vec.x, y + vec.y, z + vec.z);
}
Vector3 Vector3::operator-(const Vector3& vec) const {
    return Vector3(x - vec.x, y - vec.y, z - vec.z);
}
Vector3 Vector3::operator*(const int& scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}
Vector3 Vector3::operator/(const int& scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return Vector3(x / scalar, y / scalar, z / scalar);
}
/************************************************************
 *                     OPERATOR LOGICS                      *
 ************************************************************/

bool Vector3::operator==(const Vector3& vec) const {
const float epsilon = 1e-6;  // tolerance threshold for the comparison
return (std::fabs(this->x - vec.x) < epsilon &&
        std::fabs(this->y - vec.y) < epsilon &&
        std::fabs(this->z - vec.z) < epsilon);
}
bool Vector3::operator!=(const Vector3& vec) const {
    return !(*this==vec);
}
bool Vector3::operator>(const Vector3& vec) const {
    if(this->x > vec.x && this->y > vec.y && this->z > vec.z) {
        return true;
    } else {
        return false;
    }
}
bool Vector3::operator<(const Vector3& vec) const {
    return !(*this>vec);
}
bool Vector3::operator>=(const Vector3& vec) const {
    if(this->x >= vec.x && this->y >= vec.y && this->z >= vec.z) {
        return true;
    } else {
        return false;
    }
}
bool Vector3::operator<=(const Vector3& vec) const {
    return !(*this>=vec);
}
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
Vector3::~Vector3() = default;