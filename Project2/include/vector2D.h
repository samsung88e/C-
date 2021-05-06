#ifndef VECTOR2D_H_
#define VECTOR2D_H_
#include <vector>


namespace csci3081 {

class Vector2D {
public:
    Vector2D();
    Vector2D(float x, float y);
    void SetVector(float x, float y);
    std::vector<float> GetVector();
    Vector2D GetNormalizedVector();
    float GetMagnitude();
    float DotProduct(Vector2D& vec2);
    Vector2D operator+(const Vector2D& other);
    Vector2D operator-(const Vector2D& other);
    Vector2D operator*(float scalar);
//  void PrintVector() const;
    
private:
    std::vector<float> vector2;
    static const int vectorSize = 2;
};

}




#endif