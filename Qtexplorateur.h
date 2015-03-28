// MaFenetre.h
//  
#ifndef DEF_MAFENETRE
#define DEF_MAFENETRE
   
#include <QApplication>
#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>

    class MaFenetre : public QWidget
    {
        Q_OBJECT
         
             public:
             MaFenetre();
             QString ouvrirDialogue();
     };
                              
#endif
