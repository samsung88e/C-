#ifndef VECTOR2D_H_
#define VECTOR2D_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <iostream>
#include <cmath>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Represents a vector two-dimentional class.
 * 
 * This class will be used for non-moving targets / non-flying targets.
 * Setter, Getter, and operator functions for vector two-dimentional spaces.
 */

class Vector2D {
public:
    /**
    * @brief Default constructor for a Vector2D class.
    *
    * Set x, 0 and y, 0 and add to the vector2 vector class object. 
    */ 
    Vector2D();

    /**
    * @brief constructor for a Vector2D class.
    * @param x, y Coordinates of the position in 2D space.
    * 
    * set the x and y coordinates using vector2D class vector. 
    */ 
    Vector2D(float x, float y);

    /**
    * @brief Setter function for a Vector2D class.
    * @param x, y Coordinates of the position in 2D space.
    * 
    * set the x and y coordinates using vector2D class vector. 
    */ 
    void SetVector(float x, float y);

    /**
    * @brief Getter function for a 2D vector.
    * @return A 2D vector has x and y Coordinates.
    */ 
    std::vector<float> GetVector();

    /**
    * @brief Getter function for a normalized 2d vector.
    * @return A Normalized 2D vector.
    */
    Vector2D GetNormalizedVector();

    /**
    * @brief Getter function for magnitude of a 2d vector.
    * @return A Magnitude of the 2D vector.
    */
    float GetMagnitude();

    /**
    * @brief Getter function for magnitude of a 2d vector.
    * @param vec2 A Vector2D object.
    * @return A DotProduct of the 2D vector.
    */
    float DotProduct(Vector2D& vec2);

    /**
    * @brief + operator for Vector2D object.
    * @param other A Vector2D object.
    * @return A 2d Vector added to other 2d vector is copied to a designated object.
    */
    Vector2D operator+(const Vector2D& other);

    /**
    * @brief - operator for Vector2D object.
    * @param other A Vector2D object.
    * @return A 2d Vector subtracted from other 2d vector is copied to a designated object.
    */
    Vector2D operator-(const Vector2D& other);

    /**
    * @brief * operator for Vector2D object.
    * @param scalar A scalar value.
    * @return A 2d Vector multiplied by scalar is copied to a designated object.
    */
    Vector2D operator*(float scalar);

private:
    /// A basic data type, Vector that stores two-dimensional position.
    std::vector<float> vector2;

    /// A two-dimensional vector size static varible.
    static const int vectorSize = 2;
};

} // namespace csci3081

#endif