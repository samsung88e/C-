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
    std::vector<float> GetNormalizedVector();
    float GetMagnitude();
    float DotProduct(Vector2D& vec2);
    //std::vector<float> AddVector();
    //std::vector<float> SubtractVector();
//  void PrintVector() const;
    
private:
    std::vector<float> vector2;
    static const int vectorSize = 2;
};

}




#endif