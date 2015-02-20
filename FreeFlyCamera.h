#ifndef FREEFLYCAMERA_HPP
#define FREEFLYCAMERA_HPP

#include "vector3d.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <GL/glu.h>


class FreeFlyCamera
{
public:
    FreeFlyCamera(const Vector3D & position = Vector3D(0,0,0));
    virtual ~FreeFlyCamera();

    void update(const sf::Event& input, float timestep);

    inline void setSpeed(const float& speed) { _speed = speed; }
    inline void setSensivity(const float& sensivity) { _sensivity = sensivity; }
    void setPosition(const Vector3D & position);

    void look();

private:
    float _speed;
    float _sensivity;
    float _theta;
    float _phi;
    Vector3D _position;
    Vector3D _target;
    Vector3D _forward;
    Vector3D _left;

    void VectorsFromAngles();
//void Init();
};

#endif
