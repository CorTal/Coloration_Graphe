#ifndef MOTEUR_H
#define MOTEUR_H

#include "Graphe.h"

#include <list>
#include <ostream>

class Moteur{
private:
  Graphe Graph;
public:
  Moteur();
  Moteur(Graphe _Graph);
  
  void setGraph(Graphe gr);
  void Glouton();
  void Glouton_degre();
  void Glouton_largeur();
  void Glouton_profondeur();
  void Welsh_Powell();
  void DSATUR();
  void NoN();
  std::string Glouton_m();
  std::string Glouton_degre_m();
  std::string Glouton_largeur_m();
  std::string Glouton_profondeur_m();
  std::string Welsh_Powell_m();
  std::string DSATUR_m();
  std::string NoN_m();
};

  void tri_dsat(std::vector<Noeud*> & edges);
  bool dsat(Noeud* n1, Noeud* n2);
  std::vector<Noeud*> max_s(std::vector<std::vector<Noeud*> > s_edges);
  unsigned int compt_ar(std::vector<Noeud*> edges);

#endif