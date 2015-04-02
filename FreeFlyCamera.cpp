#include "FreeFlyCamera.h"


FreeFlyCamera::FreeFlyCamera(const Vector3D & position)
: _speed(0.08), _sensivity(0.05), _theta(0), _phi(0), _position(position)
{ VectorsFromAngles(); }

void FreeFlyCamera::setWindowSize(int x,int y)
{
	windowX = x;
	windowY = y;
}
void FreeFlyCamera::update(const sf::Event& input, float timestep)
{

	switch(input.type)
	{
		case sf::Event::MouseMoved :
	_phi -= (input.mouseMove.y - 360 ) * _sensivity;
	_theta -= (input.mouseMove.x -640) * _sensivity;	
	VectorsFromAngles();
	break;

		case sf::Event::KeyPressed:
	switch(input.key.code)
	{
	case sf::Keyboard::Z :
	 _position += _forward * _speed * timestep;
		break;
	case sf::Keyboard::S :
	 _position -= _forward * _speed * timestep;
		break;
	case sf::Keyboard::Q :
 	_position += _left * _speed * timestep;
		break;
	case sf::Keyboard::D :
	 _position -= _left * _speed * timestep;
		break;
	default:;
	}
	break;
	_target = _position + _forward;
		default:;
	}
	this->VectorsFromAngles();
}
void FreeFlyCamera::setPosition(const  Vector3D &position)
{
	_position = position ;
	_target = _position + _forward ;
}

void FreeFlyCamera::VectorsFromAngles()
{
	static const Vector3D up(0.f,0.f,1.f);
	if(_phi>89)
	 _phi = 89 ;
	else if(_phi< -89)
	 _phi = -89 ;

    float r_temp = cos((_phi*M_PI)/180.f);
    _forward.Z = sin((_phi*M_PI)/180.f);
    _forward.X = r_temp*cos((_theta*M_PI)/180.f);
    _forward.Y = r_temp*sin((_theta*M_PI)/180.f);

    _left = up.crossProduct(_forward);
    _left.normalize();

    _target = _position + _forward;
  }


  void FreeFlyCamera::look()
{
  gluLookAt(_position.X,_position.Y,_position.Z,
  _target.X,_target.Y,_target.Z,
  0.f, 0.f, 1.f);

  std::cout <<_position.X << " " << _position.Y << " " << _position.Z << " " << _target.X << " " << _target.Y << "" << _target.Z << std::endl ;
}

FreeFlyCamera::~FreeFlyCamera()
{}
