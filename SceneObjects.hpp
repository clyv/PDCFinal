//
//  SceneObjects.hpp
//  RayTracer
#include "glm/glm/glm.hpp"
#include "glm/glm/gtx/io.hpp"
#include <stdio.h>
#include <vector>

#ifndef SceneObjects_hpp
#define SceneObjects_hpp

class Light
{
public:
    glm::vec3 color;
    glm::vec3 direction;
    bool point;
    float constantTerm;
    float linearTerm;
    float quadraticTerm;
    glm::vec3 position;
    bool area;
    float radius;
};

class SceneObject
{
public:
    int objNum;
    glm::vec3 position;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    glm::vec3 reflective;
    float radius;
    glm::vec3 center;
    float shininess;
    bool sphere;
};


#endif /* SceneObjects_hpp */
