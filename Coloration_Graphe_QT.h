#ifndef Coloration_Graphe_QT_H
#define Coloration_Graphe_QT_H

#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include <QtGui/QBoxLayout>
#include <QtGui/QLineEdit>
#include <QtGui/QComboBox>
#include <QtGui/QTextEdit>
#include <QtGui/QFileDialog>
#include <QtCore/QDebug>
#include <QtCore/QString>

#include "ctime"
#include <ostream>
#include <sstream>
#include <iostream>

#include "Moteur.h"

class Coloration_Graphe_QT : public QWidget
{
    Q_OBJECT

private:

  QVBoxLayout* mainLayout;
  QHBoxLayout* topLayout;
  QPushButton* pb_selectFile;
  QPushButton* pb_exec;
  QPushButton* pb_export;
  QLineEdit* le_selectedFile;
  QComboBox* cb_selAlgo;
  QTextEdit* te_result;
  
  Graphe G, oG;
  Moteur M;
  std::string result;
  
public:
    Coloration_Graphe_QT();
    virtual ~Coloration_Graphe_QT();
    
private slots:
  void fileclic();
  void execAlgo();
  void exportTxt();
  
};

#endif // Coloration_Graphe_QT_H
