#include <iostream>
#include <fstream>
#include <algorithm>

struct Mokinys {
  double vidurkis = 0;
  std::string vardas = "";
  std::string dalykas = "";
};


void rikiuoti(std::string dalykai[], int dalSk[], int dal, Mokinys mokiniai[], int n) {
  for(int i = 0; i < n - 1; i++) {
    bool apkeista = false;
    for(int j = 0; j < n - 1- i; j++) {
      if(mokiniai[j].vardas > mokiniai[j+1].vardas) {
        std::swap(mokiniai[j], mokiniai[j+1]);
        apkeista = true;
      }

    }
    if(!apkeista) {
      break;
    }
  }
  
  for(int i = 0; i < dal - 1; i++) {
    bool apkeista = false;
    for (int j = 0; j < dal - 1 - i; j++) {
      if(dalSk[j] == dalSk[j+1]) {
        if (dalykai[j] > dalykai[j+1]) {
          std::swap(dalSk[j], dalSk[j+1]);
          std::swap(dalykai[j], dalykai[j+1]);
        }
      }
      else if (dalSk[j] < dalSk[j+1]) {
        std::swap(dalSk[j], dalSk[j+1]);
        std::swap(dalykai[j], dalykai[j+1]);
        apkeista = true;
      }
    }
    if (!apkeista) {
      break;
    }
  }
}


int main() {
  int n = 0;
  Mokinys mokiniai[50];
  std::string dalykai[50];
  int dalSk[50] = {0};
  int dal = 0;

  std::ifstream in("U2.txt");
  in >> n;
  for (int i = 0; i < n; i++) {
    in >> mokiniai[i].vardas >> mokiniai[i].dalykas;
    int pazymiai = 0;
    in >> pazymiai;
    bool yra = false;

    int suma = 0;
    for (int j = 0; j < pazymiai; j++) {
      int temp;
      in >> temp;
      suma += temp;
    }
    mokiniai[i].vidurkis = double(suma) / double(pazymiai);

    for (int j = 0; j < dal; j++) {
      if (mokiniai[i].dalykas == dalykai[j] && mokiniai[i].vidurkis >= 9.0 ) {
        dalSk[j]++;
        yra = true;
      }  
    }
    if (!yra && mokiniai[i].vidurkis >= 9.0) {
      dalSk[dal]++;
      dalykai[dal] = mokiniai[i].dalykas;
      dal++;
    }
    
  }

  in.close();

  rikiuoti(dalykai, dalSk, dal, mokiniai, n);

  std::ofstream out("U2rez.txt");
  if (dal) {
    for (int i = 0; i < dal; i++) {
      out << dalykai[i] << " " << dalSk[i] << std::endl;
      for (int j = 0; j < n; j++) {
         if (mokiniai[j].dalykas == dalykai[i] && mokiniai[j].vidurkis >= 9.0) {
           out << mokiniai[j].vardas << std::endl;
         }
      }
    }
  } else {
    out << "Neatitinka vidurkis" << std::endl;
  }

  out.close();
  return 0;
}
