// MaFenetre.h
//  
#ifndef DEF_MAFENETRE
#define DEF_MAFENETRE
   
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>

    class MaFenetre : public QWidget
    {
        Q_OBJECT
         
             public:
             MaFenetre();
             QString ouvrirDialogue();
                    
             private:
             QPushButton *m_boutonDialogue;
     };
                              
#endif
