#include "vector3D.h"

namespace csci3081 {

Vector3D::Vector3D() {
    vector3.push_back(0.f);
    vector3.push_back(0.f);
    vector3.push_back(0.f);
}

Vector3D::Vector3D(float x, float y, float z) {
    vector3.push_back(x);
    vector3.push_back(y);
    vector3.push_back(z);

}

Vector3D::Vector3D(std::vector<float> vec) {
    for (int i = 0; i < vec.size(); i++) {
     vector3.push_back(vec.at(i));
    }
}

void Vector3D::SetVector(float x, float y, float z) {
    vector3.at(0) = x;
    vector3.at(1) = y;
    vector3.at(2) = z;
}

void Vector3D::SetVector(std::vector<float> &vec) {
    vector3 = vec;
}

std::vector<float> Vector3D::GetVector() {
    return vector3;
}

float Vector3D::GetMagnitude() {
    return sqrt(pow(vector3.at(0), 2) + pow(vector3.at(1), 2) + pow(vector3.at(2), 2));
}

Vector3D Vector3D::GetNormalizedVector() {
    float mag = this->GetMagnitude();
    std::vector<float> normVector;

    if(mag == 0) {   
        for (int i = 0; i < vectorSize; i++) {
        normVector.push_back(0);
        }
    }
    else{
        for (int i = 0; i < vectorSize; i++) {
            normVector.push_back(vector3.at(i) / mag);
        }
    }

    Vector3D returnVect;
    for(int i = 0; i < vectorSize; i++){
        returnVect.vector3[i] = normVector[i];
    }

    return returnVect;
}

float Vector3D::DotProduct(Vector3D& vec3) {
    std::vector<float> a = vector3;
    std::vector<float> b = vec3.GetVector();

    float dotProduct = 0;

    for(int i = 0; i < vectorSize; i++) {
        dotProduct += a.at(i) * b.at(i);
    }

    return dotProduct;

}

Vector3D Vector3D::operator+(const Vector3D& other) {
    float new_x = this->vector3[0] + other.vector3[0];
    float new_y = this->vector3[1] + other.vector3[1];
    float new_z = this->vector3[2] + other.vector3[2];

    Vector3D newVector;
    newVector.vector3[0] = new_x;
    newVector.vector3[1] = new_y;
    newVector.vector3[2] = new_z;

    return newVector;
}

Vector3D Vector3D::operator-(const Vector3D& other) {
    float new_x = this->vector3[0] - other.vector3[0];
    float new_y = this->vector3[1] - other.vector3[1];
    float new_z = this->vector3[2] - other.vector3[2];

    Vector3D newVector;
    newVector.vector3[0] = new_x;
    newVector.vector3[1] = new_y;
    newVector.vector3[2] = new_z;

    return newVector;
}

Vector3D Vector3D::operator*(float scalar){
    float new_x = this->vector3[0] * scalar;
    float new_y = this->vector3[1] * scalar;
    float new_z = this->vector3[2] * scalar;

    Vector3D newVector;
    newVector.vector3[0] = new_x;
    newVector.vector3[1] = new_y;
    newVector.vector3[2] = new_z;

    return newVector;
}

bool Vector3D::Equals(Vector3D& vec) {
    std::vector<float> vect = vec.GetVector();

    bool isEqual = true;

    for(int i = 0; i < vectorSize; i++) {
        if(fabs(vector3.at(i) - vect.at(i)) > 0.5f) {
            isEqual = false;
        }
    }

    return isEqual;


}

}
