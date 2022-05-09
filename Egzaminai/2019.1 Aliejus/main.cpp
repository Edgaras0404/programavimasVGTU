#include <iostream>
#include <fstream>

void papildomi(int papildomi[], int k) {
  while (k >= 5) {
    papildomi[2]++;
    k -= 5;
  }
  while (k>= 3) {
    papildomi[1]++;
    k -= 3;
  }
  while (k) {
    papildomi[0]++;
    k--;
  }
}

int liko (int indas[], int &k, int pripilti[]) {
  int i = 0;
  for (i = 0; i < indas[2]; i++) {
    if (k >=5) {
      k -= 5;
    } else { break; }
  }
  pripilti[2] += i;

  for ( i = 0; i < indas[1]; i++) {
    if (k >= 3) {
      k -= 3;
    } else { break; }
  }
  pripilti[1] += i;

  for (i = 0; i < indas[0]; i++) {
    if (k >= 1) {
      k--;
    } else { break; }
  }
  pripilti[0] += i;

  return k;
}

int main() {
  int indas[3];
  int sunaudota[3];
  int truksta[3] = { 0 };
  int verte[4];
  int pripilti[3] = { 0 };
  int k;
  
  std::ifstream in ("U1.txt");
  in >> indas[0] >> indas[1] >> indas[2] >> k;
  in >> verte [0] >> verte[1] >> verte[2] >> verte[3];
  in.close();

  int truko = liko(indas, k, pripilti);

  for (int i = 0; i < 3; i++) {
    sunaudota[i] = pripilti[i];
  }
  papildomi(truksta, k);
  std::ofstream out ("U1rez.txt");
  out << pripilti[0] << " " << pripilti[1] << " " << pripilti[2] << " " << k << std::endl;
  out << indas[0] - pripilti[0] << " " << indas[1] - pripilti[1] << " " << indas[2] - pripilti[2] << std::endl;
  out << truksta[0] << " " << truksta[1] << " " << truksta[2] << std::endl;
  out << (pripilti[0] + truksta[0]) * verte[1] +
      (pripilti[1] + truksta[1]) * verte[2] +
      (pripilti[2] + truksta[2]) * verte[3] -
      verte[0];




  return 0;
}
