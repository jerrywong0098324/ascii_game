// 2D Vector
#ifndef VECTOR2_H
#define VECTOR2_H



class Vector2
{
public:
	int x, y;

	// taking int value cuz this is an ascii game
	Vector2(int x = 0, int y = 0);
	~Vector2();

	// check the two value to see if its the same
	bool IsEqual(float a, float b) const;

	// Set all data
	void Set(int x = 0, int y = 0);
	//Set all data to zero
	void SetZero(void); 
	//Check if data is zero
	bool IsZero(void) const; 

	//Vector addition
	Vector2 operator+(const Vector2& rhs) const;
	Vector2& operator+=(const Vector2& rhs);

	//Vector subtraction
	Vector2 operator-(const Vector2& rhs) const; 
	Vector2& operator-=(const Vector2& rhs);

	//Unary negation
	Vector2 operator-(void) const; 

	//Scalar multiplication
	Vector2 operator*(float scalar) const; 
	Vector2& operator*=(float scalar);

	//Equality check
	bool operator==(const Vector2& rhs) const; 
	//Inequality check
	bool operator!= (const Vector2& rhs) const; 

	//Assignment operator
	Vector2& operator=(const Vector2& rhs); 
};

#endif