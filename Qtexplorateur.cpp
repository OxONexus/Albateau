#include "Qtexplorateur.h"
   
 MaFenetre::MaFenetre(): QWidget()  
 {
    setFixedSize(230, 120);
 }
                      
 QString MaFenetre::ouvrirDialogue()
 {
	       QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Carte du Fond (*.csv)");
	       QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" + fichier);
	     	close();
	       return fichier;  
 }
