// Transform.cpp: implementation of the Transform class.


#include "Transform.h"
#include <iostream> 
//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
  // YOUR CODE FOR HW1 HERE
	float theta = glm::radians(degrees);
	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	mat3 I = mat3(1,0,0,
				0,1,0,
				0,0,1);//identity 

	mat3 aa = mat3(x*x, x*y, x*z,
		x*y, y*y, y*z,
		x*z, y*z,z*z);

	mat3 A = mat3(0, z, -y,
		-z, 0, x,
		y, -x, 0);
	
	mat3 result;

	result = cos(theta)*I + (1 - cos(theta))*aa + sin(theta)*A;

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

	/*
	debug code
	std::cout << "eye = " << eye.x << " " << eye.y << " " << eye.z << "\n";
	std::cout << "up= " << up.x << " " << up.y << " " << up.z << "\n";
	*/

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
	
	vec3 a = eye;// a is vector from origin (0,0,0) to eye, default value (0,0,5)
	vec3 b = up; // b is vector up

	vec3 w = glm::normalize(a);//w is normalize of vector a 
	
	vec3 u = glm::cross(b, w);// vector u is orthogonal to vector b and vector w
	u = glm::normalize(u);

	vec3 v = glm::cross(w, u);// v, u, w are orthogonal to each other
	
	
	mat4 result = mat4(u.x,v.x,w.x,0,
		u.y,v.y,w.y,0,
		u.z,v.z,w.z,0,
		-u.x*eye.x - u.y*eye.y - u.z*eye.z,
		-v.x*eye.x - v.y*eye.y - v.z*eye.z,
		-w.x*eye.x - w.y*eye.y - w.z*eye.z,
		1
		);
		
  // You will change this return call
  return result;
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
