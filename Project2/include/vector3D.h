#ifndef VECTOR3D_H_
#define VECTOR3D_H_
#include <vector>


namespace csci3081 {

class Vector3D {
public:
    Vector3D();
    Vector3D(float x, float y, float z);
    Vector3D(std::vector<float> vec);
    void SetVector(float x, float y, float z);
    std::vector<float> GetVector();
    Vector3D GetNormalizedVector();
    float GetMagnitude();
    float DotProduct(Vector3D& vec3);
    Vector3D operator+(const Vector3D& other);
    Vector3D operator-(const Vector3D& other);
    Vector3D operator*(float scalar);
    bool Equals(Vector3D& vec);
//  void PrintVector() const;
    
private:
    std::vector<float> vector3;
    static const int vectorSize = 3;
};

}


#endif