#include <iostream>
#include <fstream>
#include <algorithm>

struct Dalyvis {
  std::string vardas = "";
  int n = 0;
  int taskai = 0;
};

struct Zuvis {
  int mase = 0;
  std::string pav = "";
  int verte = 0;
};

void rikiuoti(Dalyvis dalyviai[], int n, Zuvis zuvys[], int k) {
  for (int i = 0; i < n - 1; i++) {
    bool apkeista = false;
    for (int j = 0; j < n - 1 - i; j++) {
      if (dalyviai[j].taskai != dalyviai[j+1].taskai) {
        if (dalyviai[j].taskai < dalyviai[j + 1].taskai) {
          std::swap(dalyviai[j], dalyviai[j+1]);
          apkeista = true;
        }
      } else if (dalyviai[j].vardas > dalyviai[j+1].vardas) {
        std::swap(dalyviai[j], dalyviai[j+1]);
        apkeista = true;
      }
    }
    
    if (!apkeista) {
      break;
    }
  }


  for (int i = 0; i < k - 1; i++) {
    bool apkeista = false;
    for (int j = 0; j < k - 1 - i; j++) {
      if (zuvys[j].mase != zuvys[j+1].mase) {
        if (zuvys[j].mase < zuvys[j+1].mase) {
          std::swap(zuvys[j], zuvys[j+1]);
          apkeista = true;
        }
      } else if ( zuvys[j].pav > zuvys[j+1].pav) {
        std::swap(zuvys[j], zuvys[j+1]);
        apkeista = true;
      }
    }
    
    if (!apkeista) {
      break;
    }
  }
}

int main() {

  Dalyvis dalyviai[20];
  Zuvis zuvys[20];

  std::ifstream in("U2.txt");
  int n;
  int k;
  in >> n;
  in.ignore(10, '\n');
  for (int i = 0; i < n; i++) {
    char eil[21] = "";
    in.read(eil, 20);
    dalyviai[i].vardas = eil;
    in >> dalyviai[i].n;
    in.ignore(100, '\n');
    for (int j = 0; j < dalyviai[i].n; j++) {
      std::string line;
      std::getline(in, line);
    }
  }
  in >> k;
  in.ignore(10, '\n');
  for (int i = 0; i < k; i++) {
    char eil[21] = "";
    in.read(eil, 20);
    zuvys[i].pav = eil;
    in >> zuvys[i].verte;
    in.ignore(100, '\n');
  }

  in.clear();
  in.seekg(0, std::ios::beg);

  
  in.ignore(100, '\n');
  for (int i = 0; i < n; i++) {
    in.ignore(100, '\n');
    for (int j = 0; j < dalyviai[i].n; j++) {
      char eil[21] = "";
      in.read(eil, 20);
      int mase = 0;
      in >> mase;
      in.ignore(10, '\n');
      for (int l = 0; l < k; l++) {
        if (zuvys[l].pav == eil) {
          zuvys[l].mase += mase;
          if (mase >= 200) {
            dalyviai[i].taskai += zuvys[l].verte + 30;
          } else {
            dalyviai[i].taskai += zuvys[l].verte + 10;
          }
        }
      }
    }
  }
  in.close();

  
  rikiuoti(dalyviai, n, zuvys, k);
  std::ofstream out("U2rez.txt");

  out << "Dalyviai" << std::endl;
  for (int i = 0; i < n; i++) { 
    out << dalyviai[i].vardas << " " << dalyviai[i].taskai << std::endl;
  }
  
  out << "Laimikis" << std::endl;
  for (int i = 0; i < k; i++) {
    out << zuvys[i].pav << " " << zuvys[i].mase << std::endl;
  }
  out.close();
  return 0;
}
