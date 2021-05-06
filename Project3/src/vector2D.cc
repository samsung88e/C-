#include "vector2D.h"

namespace csci3081 {

Vector2D::Vector2D() {
    vector2.push_back(0.f);
    vector2.push_back(0.f);
}

Vector2D::Vector2D(float x, float y) {
    vector2.push_back(x);
    vector2.push_back(y);
}


void Vector2D::SetVector(float x, float y) {
    vector2.at(0) = x;
    vector2.at(1) = y;
}


std::vector<float> Vector2D::GetVector() {
    return vector2;
}

float Vector2D::GetMagnitude() {
    return sqrt(pow(vector2.at(0), 2) + pow(vector2.at(1), 2));
}

Vector2D Vector2D::GetNormalizedVector() {
    float mag = this->GetMagnitude();
    std::vector<float> normVector;

    if(mag == 0) {   
        for (int i = 0; i < vectorSize; i++) {
        normVector.push_back(0);
        }
    }
    else{
        for (int i = 0; i < vectorSize; i++) {
            normVector.push_back(vector2.at(i) / mag);
        }
    }

    Vector2D returnVect;
    for(int i = 0; i < vectorSize; i++)
    returnVect.vector2[i] = normVector[i];
    return returnVect;
}

float Vector2D::DotProduct(Vector2D& vec2) {
    std::vector<float> a = vector2;
    std::vector<float> b = vec2.GetVector();

    float dotProduct = 0;

    for(int i = 0; i < vectorSize; i++) {
        dotProduct += a.at(i) * b.at(i);
    }

    return dotProduct;

}

Vector2D Vector2D::operator+(const Vector2D& other) {
    float new_x = this->vector2[0] + other.vector2[0];
    float new_z = this->vector2[1] + other.vector2[1];

    Vector2D newVector;
    newVector.vector2[0] = new_x;
    newVector.vector2[1] = new_z;

    return newVector;
}

Vector2D Vector2D::operator-(const Vector2D& other) {
    float new_x = this->vector2[0] - other.vector2[0];
    float new_z = this->vector2[1] - other.vector2[1];

    Vector2D newVector;
    newVector.vector2[0] = new_x;
    newVector.vector2[1] = new_z;

    return newVector;
}

Vector2D Vector2D::operator*(float scalar){
    float new_x = this->vector2[0] * scalar;
    float new_z = this->vector2[1] * scalar;

    Vector2D newVector;
    newVector.vector2[0] = new_x;
    newVector.vector2[1] = new_z;

    return newVector;
}

}