#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#define INF 75
using namespace std;

struct transicao {
  string str;
  int d;
  char c;
  transicao () {}
  transicao (string a, int x, char y) {
    str = a;
    d = x;
    c = y;
  }
};

class estado {
public:
  map <char, transicao > trans;
  estado () {
    trans.clear ();
  }
  pair <estado, int> transitar (int pos);
};

map <string, estado> dict;
char fita[INF];

void popula_dict () {
  estado q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11;
  q0.trans['1'] = transicao ("q1", +1, '1');
  q1.trans['0'] = transicao ("q2", +1, '0');
  q2.trans['1'] = transicao ("q3", +1, '1');
  q3.trans['0'] = transicao ("q3", +1, '0');
  q3.trans['B'] = transicao ("q4", -1, '1');
  q4.trans['B'] = transicao ("q4", -1, 'B');
  q4.trans['0'] = transicao ("q5", +1, 'B');
  q4.trans['1'] = transicao ("q8", -1, '1');
  q5.trans['B'] = transicao ("q5", +1, 'B');
  q5.trans['1'] = transicao ("q6", +1, '1');
  q6.trans['0'] = transicao ("q6", +1, '0');
  q6.trans['B'] = transicao ("q7", -1, '0');
  q7.trans['0'] = transicao ("q7", -1, '0');
  q7.trans['1'] = transicao ("q4", -1, '1');
  q8.trans['B'] = transicao ("q8", -1, 'B');
  q8.trans['0'] = transicao ("q9", +1, 'B');
  q8.trans['1'] = transicao ("q10", +1, '1');
  q9.trans['B'] = transicao ("q9", +1, 'B');
  q9.trans['1'] = transicao ("q5", +1, '1');
  q10.trans['B'] = transicao ("q10", +1, '0');
  q10.trans['1'] = transicao ("q11", +1, '1');
  q11.trans['B'] = transicao ("q11", +1, '0');
  q11.trans['1'] = transicao ("q3", +1, '1');
  dict["q0"] = q0;
  dict["q1"] = q1;
  dict["q2"] = q2;
  dict["q3"] = q3;
  dict["q4"] = q4;
  dict["q5"] = q5;
  dict["q6"] = q6;
  dict["q7"] = q7;
  dict["q8"] = q8;
  dict["q9"] = q9;
  dict["q10"] = q10;
  dict["q11"] = q11;
}

void print () {
  for (int i = 0; i < INF; i++) 
    printf ("%c", fita[i]);
  printf ("\n");
  
}

pair <estado, int> estado::transitar (int pos) {
  char now = fita[pos];
  fita[pos] = trans[now].c;
  return pair <estado, int> (dict[trans[now].str], trans[now].d);
}

int main () {
  dict.clear ();
  popula_dict();
  for (int i = 0; i < INF; i++) 
    fita[i] = 'B';
  fita[0] = '1';
  fita[1] = '0';
  fita[2] = '1';
  fita[3] = '0';
  int pos = 0;
  estado now = dict["q0"];
  print ();
  while (pos < INF) {
    pair <estado, int> next = now.transitar (pos);
    pos += next.second;
    now = next.first;
  }
  print ();
  return 0;
}
