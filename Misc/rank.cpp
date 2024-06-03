#include <cstdio>

#include <iostream>

using namespace std;

int N;

int Si[300005];

int ranking[32001];

int repeat[32001];

int maxValue;

int minValue;

int main(int argc, char** argv)

{

  int tc, T, i;

  cin >> N;

  int rank = 1;

  fill_n(repeat, 32001, 0);

  maxValue = minValue = 0;

  for (i = 1; i <= N; i++) {

   cin >> Si[i];

   repeat[Si[i]]++;

   maxValue = maxValue < Si[i] ? Si[i] : maxValue;

   minValue = minValue < Si[i] ? minValue : Si[i];

  }

  while (maxValue >= minValue){

   if (repeat[maxValue] > 0){

    ranking[maxValue] = rank;

    rank += repeat[maxValue];

   }


   maxValue--;


  }

  for (int i = 1; i <= N; i++){

   cout << ranking[Si[i]] << " ";

  }

  cout << endl;


 return 0;//Your program should return 0 on normal termination.

}
