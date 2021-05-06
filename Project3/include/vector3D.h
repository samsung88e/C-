#ifndef VECTOR3D_H_
#define VECTOR3D_H_


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
 * @brief Represents a vector three-dimentional class.
 * 
 * This class will be used for moving targets / flying targets.
 * Setter, Getter, and operator functions for vector three-dimentional spaces.
 */

class Vector3D {
public:
    /**
    * @brief Default constructor for a Vector3D class.
    *
    * Set x, 0, y, 0, and z, 0 and add to the vector3 vector class object. 
    */
    Vector3D();

    /**
    * @brief constructor for a Vector3D class.
    * @param x, y, z Coordinates of the position in 3D space.
    * 
    * set the x, y, and z coordinates using vector3D class vector. 
    */ 
    Vector3D(float x, float y, float z);

    /**
    * @brief constructor for a Vector3D class.
    * @param vec float vector 3D space.
    * 
    * set the x, y, and z coordinates using vector3D class vector. 
    */ 
    Vector3D(std::vector<float> vec);

    /**
    * @brief Setter function for a Vector3D class.
    * @param x, y, z Coordinates of the position in 3D space.
    * 
    * set the x, y, and z coordinates using vector3D class vector. 
    */ 
    void SetVector(float x, float y, float z);

    void SetVector(std::vector<float> &vec);

    /**
    * @brief Getter function for a 3D vector.
    * @return A 3D vector has x, y, and z Coordinates.
    */
    std::vector<float> GetVector();

    /**
    * @brief Getter function for a normalized 3d vector.
    * @return A Normalized 3D vector.
    */
    Vector3D GetNormalizedVector();

    /**
    * @brief Getter function for magnitude of a 3d vector.
    * @return A Magnitude of the 3D vector.
    */
    float GetMagnitude();

    /**
    * @brief Getter function for magnitude of a 3d vector.
    * @param vec3 A Vector3D object.
    * @return A DotProduct of the 3D vector.
    */
    float DotProduct(Vector3D& vec3);

    /**
    * @brief + operator for Vector3D object.
    * @param other A Vector3D object.
    * @return A 3d Vector added to other 3d vector is copied to a designated object.
    */
    Vector3D operator+(const Vector3D& other);

    /**
    * @brief - operator for Vector3D object.
    * @param other A Vector3D object.
    * @return A 3d Vector subtracted from other 3d vector is copied to a designated object.
    */
    Vector3D operator-(const Vector3D& other);

    /**
    * @brief * operator for Vector3D object.
    * @param scalar A scalar value.
    * @return A 3d Vector multiplied by scalar is copied to a designated object.
    */
    Vector3D operator*(float scalar);

    /**
    * @brief check if the vectors are same
    * @param vec A Vector3D object.
    * @return A 3d Vector added to other 3d vector is copied to a designated object.
    */
    bool Equals(Vector3D& vec);
    
private:
    /// A basic data type, Vector that stores three-dimensional position.
    std::vector<float> vector3;

    /// A three-dimensional vector size static varible.
    static const int vectorSize = 3;
};

} // namespace csci3081


#endif