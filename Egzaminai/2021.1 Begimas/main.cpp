#include <iostream>
#include <fstream>

int uztruko (int prH, int prMin, int pH, int pMin) {
  return (pH * 60 + pMin - prH * 60 - prMin);
}

int main() {
  int dienos[31] = { 0 };
  int d = 0;

  std::ifstream in("U1.txt");
  in >> d;
  for (int i = 0; i < 31; i++ ) {
    in >> d;

    int prH, prMin, pH, pMin;
    in >> prH >> prMin >> pH >> pMin;

    int ryte = uztruko(prH, prMin, pH, pMin);

    in >> prH >> prMin >> pH >> pMin;

    int vakare = uztruko(prH, prMin, pH, pMin);

    if (vakare  != 0 && ryte != 0) {
      dienos[d] = vakare + ryte;
    }
  }

  in.close();

  std::ofstream out("U1rez.txt");

  out << "Minimalus laikas\n";

  int min = 1440;

  for(int i = 0; i < 31; i++) {
    if(dienos[i] < min && dienos[i] != 0) {
      min = dienos[i];
    }
  }

  out << min << std::endl;

  out << "Dienos\n";
  for (int i = 0; i < 31; i++) {
    std::cout << dienos[i] << std::endl;
    if (dienos[i] == min) {
      out << i << " ";
    }
  }
  
  out << std::endl;
  out.close();

  return 0;
}
