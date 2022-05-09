#include <iostream>
#include <fstream>
#include <algorithm> 

struct Dalyvis {
  std::string vardas = "";
  int prad = 0;
  int pab = 0;
  int truko = 0;
  int numeris = 0;
  bool mergina = false;
  bool pabaige = false;
  int h = 0, min = 0, s = 0;
};

void rikiuoti(Dalyvis dalyviai[], int n, int m) {

  for (int i = 0; i < n - 1; i++) {
    bool apkeista = false;
    for (int j = 0; j < n - 1 - i; j++) {
      if (dalyviai[j].truko != dalyviai[j+1].truko) {
        if (dalyviai[j].truko > dalyviai[j+1].truko) {
          std::swap(dalyviai[j], dalyviai[j+1]);
          apkeista = true;
        }
      } else {
        if (dalyviai[j].vardas > dalyviai[j+1].vardas) {
          std::swap(dalyviai[j], dalyviai[j+1]);
          apkeista = true;
        }
      }

    }
    if (!apkeista) {
      break;
    }
  }
}

void spausdinti(Dalyvis dalyviai[], int n) {
  std::ofstream out("U2rez.txt");
  out << "Merginos" << std::endl;
  for (int i = 0; i < n; i++) {
    if (dalyviai[i].mergina && dalyviai[i].pabaige) {
      out << dalyviai[i].numeris << " " << dalyviai[i].vardas << " " << dalyviai[i].h << " " << dalyviai[i].min << " " << dalyviai[i].s << std::endl;
    }
  }

  out << "Vaikinai" << std::endl;
  for (int i = 0; i < n; i++) {
    if (!dalyviai[i].mergina && dalyviai[i].pabaige) {
      out << dalyviai[i].numeris << " " << dalyviai[i].vardas << " " << dalyviai[i].h << " " << dalyviai[i].min << " " << dalyviai[i].s << std::endl;
    }
  }
  out.close();

}
 
int main() {
  int n, m;
  Dalyvis dalyviai[30];
  std::ifstream in("U2.txt");
  in >> n;
  for (int i = 0; i < n; i++) {
    char eil[21] = "";
    in.ignore(10, '\n');
    in.read(eil, 20);
    dalyviai[i].vardas = eil;
    in >> dalyviai[i].numeris;
    int h, min, s;
    in >> h >> min >> s;
    dalyviai[i].prad = h*3600 + min*60 + s;
  }
  in >> m;
  for (int i = 0; i < m; i++) {
    int numeris;
    in >> numeris;
    int h, min, s;
    in >> h >> min >> s;
    for (int j = 0; j < n; j++) {
      if (dalyviai[j].numeris == numeris) {
        dalyviai[j].pabaige = true;
        dalyviai[j].pab = h*3600 + min*60 + s;
        int baudos = 0;
        if (numeris < 200) {
          int taskai = 0;
          in >> taskai;
          baudos += 5-taskai;
          in >> taskai;
          baudos += 5-taskai;
        } else {
          int taskai;
          for (int l = 0; l < 4; l++) {
            in >> taskai;
            baudos += 5-taskai;
          }
        }
        dalyviai[j].pab += baudos * 60;

        dalyviai[j].pabaige = true;
        dalyviai[j].truko = dalyviai[j].pab - dalyviai[j].prad;
        if (numeris < 200) {
          dalyviai[j].mergina = true;
        }
        dalyviai[j].h = dalyviai[j].truko / 3600;
        dalyviai[j].min = (dalyviai[j].truko % 3600) / 60;
        dalyviai[j].s = dalyviai[j].truko % 3600 % 60; 
      }
    }
  }

  rikiuoti(dalyviai, n, m);
  spausdinti(dalyviai, n);


  return 0;
}
