#include "gtest/gtest.h"
#include "vector2D.h"
#include <cmath>
#include <vector>



namespace csci3081 {
class Vector2DTest : public ::testing::Test {
 public:
  void SetUp() { 

	vec2 = Vector2D(25.4f, 32.5f);
  vec3 = Vector2D(4.3f, 10.f);
  }
 protected:
  Vector2D vec2;       
  Vector2D vec3;           
};



TEST_F(Vector2DTest, MagnitudeTest) {
  Vector2D ZeroVec(0.f, 0.f);
  
  EXPECT_LT(fabs(vec3.GetMagnitude()) - 13.162447f, 0.001f);
  EXPECT_LT(fabs(vec2.GetMagnitude() - 41.24815f), 0.001f);
  EXPECT_EQ(ZeroVec.GetMagnitude(), 0.f);
}

TEST_F(Vector2DTest, NormalizedVectorTest) {
  Vector2D testVec(1.f, 10.f);
  float testVecMag = testVec.GetMagnitude();

  std::vector<float> normTest;
  normTest.push_back(testVec.GetVector().at(0) / testVecMag);
  normTest.push_back(testVec.GetVector().at(1) / testVecMag);
  Vector2D normvec = testVec.GetNormalizedVector();
  
  EXPECT_EQ(normvec.GetVector()[0], normTest[0]);
  EXPECT_EQ(normvec.GetVector()[1], normTest[1]);

}

TEST_F(Vector2DTest, ConstructorTest) {
  Vector2D vec_1(24.f, -1.2f);
  Vector2D vec_2(0.f,0.f);

  std::vector<float> test_1{24.f, -1.2f};
  std::vector<float> test_2{0.f, 0.f};

  EXPECT_EQ(vec_1.GetVector()[0], test_1[0]);
  EXPECT_EQ(vec_1.GetVector()[1], test_1[1]);
  EXPECT_EQ(vec_2.GetVector()[0], test_2[0]);
  EXPECT_EQ(vec_2.GetVector()[1], test_2[1]);

}

}


