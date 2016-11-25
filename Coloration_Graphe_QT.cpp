#include "Coloration_Graphe_QT.h"



Coloration_Graphe_QT::Coloration_Graphe_QT() : G(), M(), oG()
{
    topLayout = new QHBoxLayout();
    pb_selectFile = new QPushButton("File");
    le_selectedFile = new QLineEdit();
    le_selectedFile->setReadOnly(true);
    cb_selAlgo = new QComboBox();
    cb_selAlgo->addItem(QString::fromUtf8("NoN"));
    cb_selAlgo->addItem(QString::fromUtf8("Glouton"));
    cb_selAlgo->addItem(QString::fromUtf8("Glouton largeur"));
    cb_selAlgo->addItem(QString::fromUtf8("Glouton degré"));
    cb_selAlgo->addItem(QString::fromUtf8("Glouton profondeur"));
    cb_selAlgo->addItem(QString::fromUtf8("Welsh_Powell"));
    cb_selAlgo->addItem(QString::fromUtf8("DSATUR"));
    pb_exec = new QPushButton(QString::fromUtf8("Exécuter"));
    topLayout->addWidget(pb_selectFile);
    topLayout->addWidget(le_selectedFile);
    topLayout->addWidget(cb_selAlgo);
    topLayout->addWidget(pb_exec);
    te_result = new QTextEdit();
    te_result->setReadOnly(true);
    pb_export = new QPushButton("Export to txt");
    pb_export->setEnabled(false);
    mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(te_result);
    mainLayout->addWidget(pb_export);
    connect(pb_exec, SIGNAL(clicked()), SLOT(execAlgo()) );
    connect(pb_export, SIGNAL(clicked()), SLOT(exportTxt()) );
    connect(pb_selectFile, SIGNAL(clicked()), SLOT(fileclic()) );
    
}

Coloration_Graphe_QT::~Coloration_Graphe_QT()
{}

void Coloration_Graphe_QT::execAlgo()
{
  if(le_selectedFile->text() == ""){
    te_result->setText(QString::fromUtf8("Sélectionnez un graphe"));
  }else{
    te_result->setText(QString::fromUtf8("Algorithme en cours d'exécution..."));
    this->
    M.setGraph(G);
    int ind = cb_selAlgo->currentIndex();
    QString text;
     double duration;
   clock_t start;
   start = clock();
    switch(ind){
      case 0:
	text = QString::fromUtf8(M.NoN_m().c_str());
	break;
      case 1:
	text = QString::fromUtf8(M.Glouton_m().c_str());
	break;
      case 2:
	text = QString::fromUtf8(M.Glouton_largeur_m().c_str());
	break;
      case 3:
	text = QString::fromUtf8(M.Glouton_degre_m().c_str());
	break;
      case 4:
	text = QString::fromUtf8(M.Glouton_profondeur_m().c_str());
	break;
      case 5:
	text = QString::fromUtf8(M.Welsh_Powell_m().c_str());
	break;
      case 6:
	text = QString::fromUtf8(M.DSATUR_m().c_str());
	break;
    }
   
   duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
   std::ostringstream oss;
   oss << "temps pour exécution : " << duration << endl;
   text += QString::fromUtf8(oss.str().c_str());
  te_result->clear();
  te_result->setText(text);
  pb_export->setEnabled(true);
  result = text.toStdString();
  }
}

void Coloration_Graphe_QT::fileclic()
{
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                ".",
                                                tr("Text files (*.txt)"));
  le_selectedFile->setText(fileName);
  G.set_graphe(fileName.toStdString());
}

void Coloration_Graphe_QT::exportTxt()
{
  std::istringstream f(result);
  std::string line, txt; 
  int i = 0;
  while (std::getline(f, line)) {
    if(i == 0){
      ++i;
      continue;
    }else if(i == 1){
      auto it = line.find_first_of(":");
      line = line.erase(0,it+2);
      it = line.find_last_of(" ");
      txt += line.erase(it,line.npos);
      txt += "\n";
    }else{
      auto it = line.find_last_of(":");
      txt += line.erase(0, it+2);
      txt += " ";
    }
    
    ++i;
  }
  txt.pop_back();
  txt = txt.erase(txt.find_last_of(" "),txt.npos);
  std::string stdfile = le_selectedFile->text().toStdString();
  stdfile = stdfile.erase(0, stdfile.find_last_of("/")+1);
  QString qfile = QString::fromStdString(stdfile);
   QString filename=cb_selAlgo->currentText() + "_result_"+qfile;
   qDebug() << filename;
    QFile file( filename );
  if ( file.open(QIODevice::ReadWrite) )
  {
    qDebug() << "coucou";
    QTextStream stream( &file );
    stream << QString::fromStdString(txt) << endl;
  }
}



#include "Coloration_Graphe_QT.moc"
