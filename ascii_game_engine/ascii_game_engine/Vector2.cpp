#include "Vector2.h"

// taking int value cuz this is an ascii game
Vector2::Vector2(int x, int y) : x(x), y(y)
{

}

Vector2::~Vector2()
{

}

// check the two value to see if its the same
bool Vector2::IsEqual(float a, float b) const
{
    return a - b <= 0.00001f && b - a <= 0.00001f;
}

// Set all data
void Vector2::Set(int x, int y)
{
    this->x = x;
    this->y = y;
}

 //Set all data to zero
void Vector2::SetZero(void)
{
    x = y = 0;
}

//Check if data is zero
bool Vector2::IsZero(void) const
{
    return IsEqual(x, 0.f) && IsEqual(y, 0.f);
}

//Vector addition
Vector2 Vector2::operator+(const Vector2& rhs) const
{
    return Vector2(x + rhs.x, y + rhs.y);
}

Vector2& Vector2::operator+=(const Vector2& rhs)
{             
    x += rhs.x;
    y += rhs.y;
    return *this;
}

//Vector subtraction
Vector2 Vector2::operator-(const Vector2& rhs) const
{
    return Vector2(x - rhs.x, y - rhs.y);
}

Vector2& Vector2::operator-=(const Vector2& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

//Unary negation
Vector2 Vector2::operator-(void) const
{
    return Vector2(-x, -y);
}

//Scalar multiplication
Vector2 Vector2::operator*(float scalar) const
{
    return Vector2(x * scalar, y * scalar);
}

Vector2& Vector2::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

//Equality check
bool Vector2::operator==(const Vector2& rhs) const
{
    return IsEqual(x, rhs.x) && IsEqual(y, rhs.y);
}

//Inequality check
bool Vector2::operator!= (const Vector2& rhs) const
{
    return !IsEqual(x, rhs.x) || !IsEqual(y, rhs.y);
}

//Assignment operator
Vector2& Vector2::operator=(const Vector2& rhs)
{
    x = rhs.x;
    y = rhs.y;
    return *this;
}