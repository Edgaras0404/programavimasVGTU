#include <iostream>
#include <fstream>

int dienos(int menuo, int diena) {
  int sarase = 0;
  if (menuo == 6) {
    sarase = diena;
  } else if (menuo == 7) {
    sarase = diena + 30;
  } else {
    sarase = diena + 61;
  }
  return sarase;
}

void data(int sarase, std::ofstream& out) {
  int menuo, diena;
  if (sarase > 61) {
    menuo = 8;
    diena = sarase - 61;
  } else if (sarase > 30) {
    menuo = 7;
    diena = sarase - 30;
  } else {
    menuo = 6;
    diena = sarase;
  }
  out << menuo << " " << diena << std::endl;
}

int daugiausiaPr(int sk[]) {
  int max = 0;
  for (int i = 0; i < 92; i++) {
    if (sk[i] > max) {
      max = sk[i];
    }
  }
  
  for (int i = 0; i < 92; i++) {
    if (sk[i] == max) {
      return i + 1;
    }
  }

  return -1;
}

int main() {

  int geles[92] = { 0 };
  int sk[92] = { 0 };
  int n = 0;

  std::ifstream in ("U1.txt");
  in >> n;
  
  for (int i = 0; i < n; i++) {
    int prM, prD, pabM, pabD;
    int kiekis;
    in >> kiekis >> prM >> prD >> pabM >> pabD;

    for (int j = dienos(prM, prD); j < dienos(pabM, pabD); j++) {
      geles[j]++;
      sk[j] += kiekis;
    }
  }

  in.close();

  std::ofstream out ("U1rez.txt");
  
  int diena = daugiausiaPr(sk) - 1;

  out << geles[diena] << std::endl;
  data(diena, out);
  
  for (int i = diena + 1; i < 92; i++) {
    if (sk[i] != sk[diena]) {
      data(i, out);
      break;
    }
  }

  out.close();


  return 0;
}
