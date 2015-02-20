#include <SFML/Window.hpp> // Librairie de fenetrage
#include <SFML/Graphics.hpp>
#include  "carte.h"
#include <iostream> // Librairie de base du C++
#include "Qtexplorateur.h"
#define GL3 _PROTOTYPES 1

#include <QApplication>
#define HAUTEUR 720
#define LARGEUR 1280

using namespace std ;

int main(int argc, char *argv[])
{
	// Variable
    	sf::RenderWindow window(sf::VideoMode(LARGEUR,HAUTEUR), "Albateau, Carte du fond",sf::Style::Resize, sf::ContextSettings(32));
	QApplication app(argc,argv);
	


	Map		 map("MapSimuler.csv",40,window);
	sf::Event	 event ;
	sf::Texture	 fond;
	sf::Texture	 imgfleche ;
	sf::Sprite	 menu ;
	sf::Sprite	 fleche ;
	
	MaFenetre	 fenetre;

	int		 positionChoix = 2 ;
	QString 	 path= NULL;

	menu.setPosition(0,0);
	fleche.setPosition(0,0);
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);
	window.setVerticalSyncEnabled(true);
	
	int x(100), y( 100) ;
	// Initialisation

	if(fond.loadFromFile("image/fond.png")!=1 ) 
{ 
cout << "Erreur lors du chargement du fond "<< endl  ;
}
	else if(imgfleche.loadFromFile("image/fleche.png")!=1) 
{
 cout << "Erreur lors du chargement de la fleche"<< endl  ;
}
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

			case sf::Keyboard::Left :

			break;

			case sf::Keyboard::Right :

			break;

			case sf::Keyboard::Escape :
			running = false ;
			break;

			case sf::Keyboard::Return :
				switch(positionChoix)
				{
					case 1:
					path = fenetre.ouvrirDialogue();
					break;
					
					case 2:
					if(path == 0)
					{path = fenetre.ouvrirDialogue();}
					map.setFile(path.toStdString());
					map.loadFromFile();
					map.loop();
					window.resetGLStates();
					break;

					case 3:
					map.loop();
					window.resetGLStates();
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
		y = 100 ;
		break ;

		case 2 : 
		y = 200 ;
		break;

		case 3:
		y = 300 ;
		break ; 

		case 4: 
		y = 400 ;
		break;

		default:
		y = 100 ; 
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
