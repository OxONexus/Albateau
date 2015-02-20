#include <iostream>
#include "carte.h"

 using namespace std ;

Map::Map()
{
	m_qualite = 100;
	tab = malloc(sizeof(float*)*m_qualite);
	for(unsigned int i = 0 ; i< m_qualite ; ++i)
	{
		tab[i] =  malloc(sizeof(float)*m_qualite);
	}

	for(int y = 0; y<m_qualite; ++y)
	{
	for(int z = 0; z<m_qualite; ++z)
	{
		tab[y][z] = 0;
	}
	this->loadFromFile();cout<<"load file done"<<endl;
	this->findMax();cout<<"find max done"<<endl;
	this->createPoint();cout<<"create point done"<<endl;
	this->remplissage();cout<<"remplissage done"<<endl;
	this->afficherMapTerminal();cout<<"afficherMapTerminal done"<<endl;

	}
}
Map::Map(int qualiter)
{
	m_qualite = qualiter ;

	tab = malloc(sizeof(float*)*m_qualite);
	for(unsigned int i = 0 ; i< m_qualite ; ++i)
	{
		tab[i] =  malloc(sizeof(float)*m_qualite);
	}

	for(int y = 0; y<m_qualite; ++y)
	{
	for(int z = 0; z<m_qualite; ++z)
	{
		tab[y][z] = 0;
	}

	}
	this->loadFromFile();cout<<"load file done"<<endl;
	this->findMax();cout<<"find max done"<<endl;
	this->createPoint();cout<<"create point done"<<endl;
	this->remplissage();cout<<"remplissage done"<<endl;
	this->afficherMapTerminal();cout<<"afficherMapTerminal done"<<endl;
}
Map::Map(std::string file)
{
	m_fichier.open(file.c_str());
	m_qualite = 100 ;
	tab = malloc(sizeof(float*)*m_qualite);
	for(unsigned int i = 0 ; i< m_qualite ; ++i)
	{
		tab[i] =  malloc(sizeof(float)*m_qualite);
	}

	for(int y = 0; y<m_qualite; ++y)
	{
	for(int z = 0; z<m_qualite; ++z)
	{
		tab[y][z] = 0;
	}

	}
	this->loadFromFile();cout<<"load file done"<<endl;
	this->findMax();cout<<"find max done"<<endl;
	this->createPoint();cout<<"create point done"<<endl;
	this->remplissage();cout<<"remplissage done"<<endl;
	this->afficherMapTerminal();cout<<"afficherMapTerminal done"<<endl;
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
	m_qualite = qualite ;
        m_fichier.open(file.c_str());
	tab = malloc(sizeof(float*)*m_qualite);
        for(unsigned int i = 0 ; i< m_qualite ; ++i)
	        {
       		  tab[i] =  malloc(sizeof(float)*m_qualite);
       		}
       for(int y = 0; y<m_qualite; ++y)
      	 {
      		 for(int z = 0; z<m_qualite; ++z)
      		 {
        	        tab[y][z] = 0;
       		 }
      	}
	 this->loadFromFile();
	 this->findMax();
	 this->createPoint();
	 this->remplissage();
	 this->afficherMapTerminal();
}

void Map::afficherMapTerminal()
{

for(int i = 0 ; i < m_qualite; ++i)
	{
		for(int y = 0 ; y < m_qualite; ++y)
		{
		cout<<tab[i][y]<<" ";
		}
		cout<<endl;
	}
}

void Map::remplissage()
{
	float a,b,c;
	for(int i = 0 ; i<m_qualite ; ++i)
	{

		for(int y = 0; y<m_qualite ; ++y)
		{

			if(i>2&&i<(m_qualite-2)&&y>2&&y<(m_qualite-2))
			{if(tab[i][y] == 0)
			{
			a = (tab[i+1][y]+tab[i-1][y]+tab[i][y+1]+tab[i][y-1])/4 ;
			b = (tab[i+2][y]+tab[i-2][y]+tab[i][y+2]+tab[i][y-2])/4 ;
			c = (2*a + b)/3;
			tab[i][y] = c ;
			}}/*

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

			else*/
		}
	}
}

Map::~Map()
{
	m_fichier.close();
	for(unsigned int i = 0 ; i< m_qualite ; ++i)
	{
		free(tab[i]);
	}
	free(tab);
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
}

void Map::createPoint()
{
	float coefx =float(m_qualite)/float(m_max.x);
	float coefy = float(m_qualite)/(m_max.y);
	int tabx, taby ;
	for(unsigned int i = 0; i< m_tableau.size(); ++i)
	{

	tabx = (int)(m_tableau[i].x * coefx) ;
	taby = (int)(m_tableau[i].y * coefy) ;
	if(tabx>m_qualite-1){tabx=m_qualite-1;}
	if(taby>m_qualite-1){taby=m_qualite-1;}
	tab[tabx][taby] = m_tableau[i].z ;
	}

}

void Map::loop()
{
	Event 			event ;
 	bool  			running = true;
	int	     		x;
	int			y;
	int		     	z;

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
          					running=0;
          					}
          			break;
          			default:;
          		}
        		    m_camera.update(event,10);
          }

		sf::Mouse::setPosition(sf::Vector2i(1280/2,720/2),m_window);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	m_camera.look();

	for(int a = 0; a<7; ++a)
	{
		for(int z =0; z<7; ++z)
		{
			if(a==3 && z ==3 )
			{
				for(int i = 0; i< m_qualite-1 ; ++i)
				{
					for(int y= 0; y < m_qualite-1 ; ++y )
					{
					glBegin(GL_TRIANGLE_FAN);
					glColor3ub((tab[i][y]/1000)*255,0,0);
					glVertex3d((3*m_qualite)+i,(3*m_qualite)+y,-tab[i][y]/100);
					glColor3ub((tab[i+1][y]/1000)*255,0,0);
					glVertex3d((3*m_qualite)+i+1,(3*m_qualite)+y,-tab[i+1][y]/100);
					glColor3ub((tab[i+1][y+1]/1000)*255,0,0);
					glVertex3d((3*m_qualite)+i+1,(3*m_qualite)+y+1,-tab[i+1][y+1]/100);
					glColor3ub((tab[i][y+1]/1000)*255,0,0);
					glVertex3d((3*m_qualite)+i,(3*m_qualite)+y+1,-tab[i][y+1]/100);
					glEnd();
					}
				}
			}

			else
      		{
    			glBegin(GL_QUADS);
    			glColor3ub(222,222,222);
    			glVertex3d(a*m_qualite,z*m_qualite,0);
    			glVertex3d((a+1)*m_qualite,z*m_qualite,0);
    			glVertex3d((a+1)*m_qualite,(z+1)*m_qualite,0);
    			glVertex3d(a*m_qualite,(z+1)*m_qualite,0);
    			glEnd();

    		}
		 }
    }

		// COntour de l'etang a ameliorer 
		// cree des trangle et ameliorer a couleur 
		glBegin(GL_QUADS);
		glColor3ub(255,0,0);
		glVertex3d(3*m_qualite,3*m_qualite,0);
		glVertex3d(3*m_qualite,4*m_qualite,0);
		glVertex3d(3*m_qualite,4*m_qualite,-m_max.z/100);
		glVertex3d(3*m_qualite,3*m_qualite,-m_max.z/100);
		glEnd();

		glBegin(GL_QUADS);
		glColor3ub(255,0,0);
		glVertex3d(3*m_qualite,3*m_qualite,0);
		glVertex3d(4*m_qualite,3*m_qualite,0);
		glVertex3d(4*m_qualite,3*m_qualite,-m_max.z/100);
		glVertex3d(3*m_qualite,3*m_qualite,-m_max.z/100);

		glBegin(GL_QUADS);
		glColor3ub(255,0,0);
		glVertex3d(4*m_qualite,3*m_qualite,0);
		glVertex3d(4*m_qualite,4*m_qualite,0);
		glVertex3d(4*m_qualite,4*m_qualite,-m_max.z/100);
		glVertex3d(4*m_qualite,3*m_qualite,-m_max.z/100);
		glEnd();
		
		glBegin(GL_QUADS);
		glColor3ub(255,0,0);
		glVertex3d(4*m_qualite,4*m_qualite,0);
		glVertex3d(3*m_qualite,4*m_qualite,0);
		glVertex3d(3*m_qualite,4*m_qualite,-m_max.z/100);
		glVertex3d(4*m_qualite,4*m_qualite,-m_max.z/100);
		glEnd();
		
		glFlush();
	       	m_window.display();
  }
}
