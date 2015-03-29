#include <iostream>
#include "carte.h"

 using namespace std ;
GLuint chargerTexture(string fichier) 

{ 

	   GLuint identifiant_texture = 0; 
	   sf::Image Image; 
	   if (!Image.loadFromFile(fichier)) 
	   return EXIT_FAILURE; 
           glGenTextures(1, &identifiant_texture); 
           glBindTexture(GL_TEXTURE_2D, identifiant_texture); 
           gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, Image.getSize().x, Image.getSize().y, GL_RGBA, GL_UNSIGNED_BYTE, Image.getPixelsPtr()); 
           glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
           glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
           return identifiant_texture; 


}

Map::Map()
{
	m_qualite = 100;
	this->loadFromFile();cout<<"load file done"<<endl;
	this->findMax();cout<<"find max done"<<endl;
	this->createPoint();cout<<"create point done"<<endl;
	this->remplissage();cout<<"remplissage done"<<endl;
	//this->afficherMapTerminal();cout<<"afficherMapTerminal done"<<endl;
}
Map::Map(int qualiter)
{
	m_qualite = qualiter ;
	this->loadFromFile();cout<<"load file done"<<endl;
	this->findMax();cout<<"find max done"<<endl;
	this->createPoint();cout<<"create point done"<<endl;
	this->remplissage();cout<<"remplissage done"<<endl;
	//this->afficherMapTerminal();cout<<"afficherMapTerminal done"<<endl;
}
Map::Map(std::string file)
{
	m_fichier.open(file.c_str());
	m_qualite = 100 ;
	this->createPoint();cout<<"create point done"<<endl;
	this->remplissage();cout<<"remplissage done"<<endl;
	//this->afficherMapTerminal();cout<<"afficherMapTerminal done"<<endl;
}
void Map::setFile(string file)
{
	if(m_fichier != 0)
	{
	m_fichier.close();
	}
	m_fichier.open(file.c_str());
	this->findMax();cout<<"find max done"<<endl;
	this->createPoint();cout<<"create point done"<<endl;
	this->remplissage();cout<<"remplissage done"<<endl;
}

void Map::setQualiter(int qual)
{
	m_qualite = qual ;
	this->createPoint();cout<<"create point done"<<endl;
	this->remplissage();cout<<"remplissage done"<<endl;
}

Map::Map(std::string file, unsigned int qualite,sf::RenderWindow &window):m_window(window)
{
	// yolo
	m_qualite = qualite ;
        m_fichier.open(file.c_str());
	 this->loadFromFile();
	 this->findMax();
	 this->createPoint();
	 this->remplissage();
	 //this->afficherMapTerminal();
}

void Map::afficherMapTerminal()
{

for(int i = 0 ; i < m_qualite; ++i)
	{
		for(int y = 0 ; y < m_qualite/ratioCarte; ++y)
		{
		cout<<tab[i][y]<<" ";
		}
		cout<<endl;
	}
}

void Map::remplissage()
{
/*	float a,b,c;
	for(int i = 0 ; i<m_qualite ; ++i)
	{

		for(int y = 0; y<m_qualite/ratioCarte ; ++y)
		{

			if(i>2&&i<(m_qualite-2)&&y>2&&y<(m_qualite-2))
			{if(tab[i][y] == 0)
			{
			a = (tab[i+1][y]+tab[i-1][y]+tab[i][y+1]+tab[i][y-1])/4 ;
			b = (tab[i+2][y]+tab[i-2][y]+tab[i][y+2]+tab[i][y-2])/4 ;
			c = (2*a + b)/3;
			tab[i][y] = c ;
			}}

			else if(i>1&&i<(m_qualite-1)&&y>1&&y<(m_qualite-1))
			{
				if(tab[i][y] == 0)
				{
				a = (tab[i+1][y]+tab[i-1][y]+tab[i][y+1]+tab[i][y-1])/4 ;
				tab[i][y] = a ;
				}
			}


			else if(i!=0&&y==0)
			{
				if(tab[i][y] == 0)
				{
				a = (tab[i+1][y]+tab[i-1][y])/2 ;
				tab[i][y] = a ;
				}

			}
			else if(i==0&&y!=0)
			{
				if(tab[i][y] == 0)
				{
				a = (tab[i][y+1]+tab[i][y-1])/2 ;
				tab[i][y] = a ;
				}

			}

			else
		}
	}*/
}

Map::~Map()
{
	m_fichier.close();
}

unsigned int Map::loadFromFile()
{
	for(int i = 0;m_fichier.eof() != 1; i++)
	{
		m_fichier >> pt.x >> pt.y >> pt.z ;
		m_tableau.push_back(pt);
	}

return  m_tableau.size();
}


void Map::findMax()
{

	m_max.x = 0;
	m_max.y = 0;
	m_max.z = 0;

	for(unsigned int i = 0; i < m_tableau.size() ; i++)
	{
	if(m_tableau[i].x> m_max.x){m_max.x= m_tableau[i].x;}
	if(m_tableau[i].y> m_max.y){m_max.y= m_tableau[i].y;}
	if(m_tableau[i].z> m_max.z){m_max.z= m_tableau[i].z;}

	}

	ratioCarte = float(m_max.x/m_max.y);
	
	std::vector<float> vide(2+(m_qualite/ratioCarte),0) ;	
	
	for(int x = 0 ; x < m_qualite+2 ;  ++x)
	{
		tab.push_back(vide);
	}
	 
}
void Map::createPoint()
{

	float coefx =float(m_qualite)/float(m_max.x);
	float coefy = (float(m_qualite/ratioCarte)/(m_max.y)) ;
	

	int tabx, taby ;
	for(unsigned int i = 0; i< m_tableau.size(); ++i)
	{

	tabx = (int)(m_tableau[i].x * coefx) ;
	taby = (int)(m_tableau[i].y * coefy) ;
	if(tabx>m_qualite-1){tabx=m_qualite-1;}
	if(taby>(m_qualite/ratioCarte)-1){taby=(m_qualite/ratioCarte)-1;}
	tab[1+tabx][1+taby] = m_tableau[i].z ;
	}
	
}

void Map::loop()
{
	Event 			event ;
 	bool  			running = true;
	int	     		x;
	int			y;
	int		     	z;
	GLuint 			txHerbe;
	GLuint			skybox[6] ;

				glEnable(GL_TEXTURE_2D);
				txHerbe = chargerTexture("image/herbe.jpg");
				glDisable(GL_TEXTURE_2D);

	glEnable(GL_DEPTH_TEST);
	 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70,(double)1280/720,1,1000);

    while (running)
    {
        while (m_window.pollEvent(event))
        {
        		switch(event.type)
          		{
          			case sf::Event::Closed :
          			m_window.close();
          			break;

          			case sf::Event::KeyPressed :
          				if(event.key.code == sf::Keyboard::Escape)
          					{
          					running=false;
          					}
        		    	m_camera.update(event,10);
          			break;

				case sf::Event::MouseMoved:
				m_camera.update(event,10);
				break;

          			default:;
          		}
          }
				sf::Mouse::setPosition(sf::Vector2i(640,360),m_window);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	m_camera.look();

				for(int i = 0; i< tab.size()-1 ; ++i)
				{
					for(int y= 0; y < tab[y].size()-1 ; ++y )
					{
					glBegin(GL_TRIANGLE_FAN);
					glColor3ub((tab[i][y]/m_max.z)*200,(tab[i][y]/m_max.z)*200,(tab[i][y]/m_max.z)*200);
					glVertex3d(i,y,-tab[i][y]/10);
					glColor3ub((tab[i+1][y]/m_max.z)*25,(tab[i+1][y]/m_max.z)*255,(tab[i+1][y]/m_max.z)*255);
					glVertex3d(i+1,y,-tab[i+1][y]/10);
					glColor3ub((tab[i+1][y+1]/m_max.z)*55,(tab[i+1][y+1]/m_max.z)*255,(tab[i+1][y+1]/m_max.z)*255);
					glVertex3d(i+1,y+1,-tab[i+1][y+1]/10);
					glColor3ub((tab[i][y+1]/m_max.z)*25,(tab[i][y+1]/m_max.z)*255,(tab[i][y+1]/m_max.z)*255);
					glVertex3d(i,y+1,-tab[i][y+1]/10);
					glEnd();
					}
				}
				
				

				glBegin(GL_QUADS);
				glColor3ub(0,255,255);
				glVertex3d(-200,0,0);
				glVertex3d(200+tab.size(),0,0);
				glVertex3d(200+tab.size(),-200,0);
				glVertex3d(-200,-200,0);

				glVertex3d(-200,0,0);
				glVertex3d(-200,200+tab[1].size(),0);
				glVertex3d(0,200+tab[1].size(),0);
				glVertex3d(0,0,0);

				glVertex3d(0,tab[1].size()-1,0);
				glVertex3d(0,tab[1].size()+200,0);
				glVertex3d(tab.size()+200,tab[1].size()+200,0);
				glVertex3d(tab.size()+200,tab[1].size()-1,0);


				glVertex3d(tab.size()+200,tab[1].size(),0);
				glVertex3d(tab.size()+200,0,0);
				glVertex3d(tab.size(),0,0);
				glVertex3d(tab.size(),tab.size(),0);
				glEnd(); 
				
				/*glEnable(GL_TEXTURE_2D);
				glDisable(GL_DEPTH_TEST);
				glDisable(GL_BLEND);
				glDisable(GL_LIGHTING);
				skybox[0] = chargerTexture("image/back.jpg");
				skybox[1] = chargerTexture("image/front.jpg");
				skybox[2] = chargerTexture("image/top.jpg");
				skybox[3] = chargerTexture("image/left.jpg");
				skybox[4] = chargerTexture("image/right.jpg");
				
				glBindTexture(GL_TEXTURE_2D,skybox[1]); //front
				glBegin(GL_QUADS);
				glTexCoord2f(0,0); glVertex3d( 0.5f,-0.5f,-0.5f);
				glTexCoord2f(1,0); glVertex3d( -0.5f,-0.5f,-0.5f);
				glTexCoord2f(1,1); glVertex3d( -0.5f,0.5f,-0.5f);
				glTexCoord2f(0,1); glVertex3d( 0.5f,0.5f,-0.5f);
				glEnd(); */
    			
		glFlush();
	       	m_window.display();
  }
}
