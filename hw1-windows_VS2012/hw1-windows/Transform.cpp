// Transform.cpp: implementation of the Transform class.


#include "Transform.h"
#include <iostream> 
//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
  // YOUR CODE FOR HW1 HERE
	float theta = degrees*0.0174532925;
	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	mat3 I(1.0);//identity 

	mat3 aa = mat3(x*x, x*y, x*z, x*y, y*y, y*z, x*z, y*z, z*z);

	mat3 A = mat3(0, z, -y, -z, 0, x, y, -x, 0);
	
	mat3 result;

	result = cos(theta)*I + (1 - cos(theta))*A + sin(theta)*A;

  // You will change this return call
  return result;
}


// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE

	//caculate rotation Matrix
	mat3 rotationMatrix = rotate(degrees, up);

	//calculate the eye
	eye = rotationMatrix*eye;
	std::cout << "eye = " << eye.x << " " << eye.y << " " << eye.z << "\n";
	std::cout << "up= " << up.x << " " << up.y << " " << up.z << "\n";
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE 
	
	//find vec3 that perpendicular to eye vector and up vector
	vec3 x = glm::cross(eye, up);
	x = glm::normalize(x);//normalize x vector

	//rotate matrix around x vector
	mat3 rotationMatrix = rotate(degrees, x);
	
	//re caculate up and eye
	eye = rotationMatrix*eye;
	up = rotationMatrix*up;
	up = glm::normalize(up);//normalize up vector
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE

  // You will change this return call
  return mat4();
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
