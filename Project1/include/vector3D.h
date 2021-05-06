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
    std::vector<float> GetNormalizedVector();
    float GetMagnitude();
    float DotProduct(Vector3D& vec3);
    std::vector<float> AddVector(Vector3D& vec);
    std::vector<float> SubtractVector(Vector3D& vec);
    bool Equals(Vector3D& vec);
//  void PrintVector() const;
    
private:
    std::vector<float> vector3;
    static const int vectorSize = 3;
};

}


#endif