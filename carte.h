#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include "FreeFlyCamera.h"

struct point
{
	float x;
	float y;
	float z;

};
using namespace sf ;

		class Map {

		public :
		Map();
		Map(int qualiter);
		Map(std::string file);
		Map(std::string file, unsigned int qualiter,sf::RenderWindow &window);
		~Map();
		unsigned int loadFromFile();
		bool createBitmap();
		void createPoint();
		void findMax();
		void loop();
		void remplissage();
		void afficherMapTerminal();
		void setQualiter(int qual);
		void setFile(std::string file);

		private :
		
		std::vector<point>	 m_tableau;
		std::ifstream 		 m_fichier;
		unsigned int		 m_qualite;
		point 			 m_max;
	 	point 			 pt;
		float			**tab;
		sf::RenderWindow	&m_window;
		FreeFlyCamera		m_camera ;
	};

GLuint chargerTexture(std::string fichier) ;
