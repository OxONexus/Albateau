#include <SFML/Window.hpp> // Librairie de fenetrage
#include <SFML/Graphics.hpp>
#include  "carte.h"
#include <iostream> // Librairie de base du C++
#include "Qtexplorateur.h"
#define GL3 _PROTOTYPES 1

#include <QApplication>
#define HAUTEUR 720
#define LARGEUR 1280
// cree les mask
// gere le redimensionnement
// gere les clique 
// afficher un HUD dans opengl 

using namespace std ;

int main(int argc, char *argv[])
{
	
	sf::ContextSettings setting ;
	setting.antialiasingLevel = 8;
	setting.depthBits = 32;

    	sf::RenderWindow window(sf::VideoMode(LARGEUR,HAUTEUR), "Albateau, Carte du fond",sf::Style::Resize,setting); 
	QApplication app(argc,argv);
	


	Map map("MapSimuler.csv",100,window);
	sf::Event	 event ;
	sf::Texture 	 fond;
	sf::Texture	 imgfleche ;
	sf::Sprite	 menu ;
	sf::Sprite	 fleche ;
	
	MaFenetre	 fenetre;

	int		 positionChoix = 2 ;
	QString 	 path = "MapSimuler.csv" ;

	menu.setPosition(0,0);
	fleche.setPosition(0,0);
	window.setMouseCursorVisible(true);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	
	int 	x = 485;
	int 	y = 190;
	int 	posMouseX;
	int 	posMouseY;

	fond.loadFromFile("image/fond.png");
	imgfleche.loadFromFile("image/fleche.png"); 

	
	menu.setTexture(fond);
	fleche.setTexture(imgfleche);
	window.setVerticalSyncEnabled(true);

    bool running = true;
    while (running)
    {

        while (window.pollEvent(event))
        {


		switch(event.type)
	{
		case sf::Event::Closed :
		window.close();
		running = false ;
		break;
		
		case sf::Event::Resized:
		window.setView(sf::View(sf::FloatRect(0,0, event.size.width , event.size.height)));
		break ;

		case sf::Event::MouseMoved:
		posMouseX = event.mouseMove.x ;
		posMouseY = event.mouseMove.y ;
		std::cout<<"x : " << posMouseX << std::endl ;
		std::cout<<"y : " << posMouseY << std::endl ;
		break;

		case sf::Event::MouseButtonPressed:
		std::cout << " bouton presser a -> x : " << posMouseX << " y : " << posMouseY << std::endl;

			if(posMouseX > 510 && posMouseX < 770
			&& posMouseY > 230 && posMouseY < 275)
			{
				path = fenetre.ouvrirDialogue();
			}

			else if(posMouseX > 510 && posMouseX < 770
			&& posMouseY > 320 && posMouseY < 360)
			{
					if(path == 0)
					{path = fenetre.ouvrirDialogue();}
					map.setFile(path.toStdString());
					map.loadFromFile();
					window.pushGLStates();
					window.setMouseCursorVisible(false);
				//	window.popGLStates();
					map.loop();
				//	window.setMouseCursorVisible(true);
					window.resetGLStates();
			}

			else if(posMouseX > 510 && posMouseX < 770
			&& posMouseY > 400 && posMouseY < 450)
			{
					window.setMouseCursorVisible(false);
					map.loop();
					window.setMouseCursorVisible(true);
					window.resetGLStates();
			}

			/*else if(posMouseX > 510 && posMouseX < 770
			&& posMouseY > 230 && posMouseY < 275)
			{
				path = fenetre.ouvrirDialogue();
			}*/

		break;

		case sf::Event::KeyPressed:
		   
			switch(event.key.code) 
			{

			case sf::Keyboard::Up :
			positionChoix --;
			if(positionChoix<1)
			{positionChoix = 1;}
			break ;

			case sf::Keyboard::Down :
			positionChoix ++;
			if(positionChoix>4)
			{positionChoix=4;}
			break;

			case sf::Keyboard::Escape :
			running = false ;
			break;

			case sf::Keyboard::Return :
				switch(positionChoix)
				{
					case 1:
					if(path == 0)
					{path = fenetre.ouvrirDialogue();}
					map.setFile(path.toStdString());
					map.loadFromFile();
					window.setMouseCursorVisible(false);
					map.loop();
					window.setMouseCursorVisible(true);
					window.resetGLStates();
					break;
					
					case 2:
					path = fenetre.ouvrirDialogue();
					break;

					case 3:

					break;

					case 4:
					running = false ;
					break;
					
					default:;
				}		
			break ;

			default :;
			}

		break; 
		
		default:;	
	}
        }

	switch(positionChoix)
	{
		case 1 :
		y = 185 ;
		break ;

		case 2 : 
		y = 245 ;
		break;

		case 3:
		y = 310 ;
		break ; 

		case 4: 
		y = 380 ;
		break;

		default:
		y = 190 ; 
		break;;
	}

	fleche.setPosition(x,y);

	window.clear(sf::Color::Black);
	window.draw(menu);
	window.draw(fleche); 
	window.display();	
    }
	window.close();
	return 0;

}
