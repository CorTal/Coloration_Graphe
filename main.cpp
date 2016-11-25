#include <QtGui/QApplication>
#include "Coloration_Graphe_QT.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Coloration_Graphe_QT coloration_graphe_qt;
    coloration_graphe_qt.show();
    return app.exec();
}
