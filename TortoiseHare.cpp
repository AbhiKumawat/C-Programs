/*
Name: Abhimanyu Kumawat
Class: CS 288-02
Homework Assignment #1
Date: 02/02/2018
*/

#include <time.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class TortoiseHare
{
  private:
     int t, h, finishLine, positions;

  public:
    void delay(unsigned int mseconds)
    {
        clock_t goal = mseconds + clock();
        while (goal > clock());
    }

    //Constructor 1
    TortoiseHare()
    {
      t = 1;
      h = 1;
      finishLine = 70;
      srand(time(NULL));
      system("cls");
      printf("BANG!!!\n AND THEY'RE OFF!!!\n");
      PrintCurrentPositions();
      delay(100);
      while(t!= finishLine && h!=finishLine)
      {
        MoveTortoise();
        MoveHare();
        delay(500);
        system("cls");
        PrintCurrentPositions();
      }//end while
    }//end Constructor

    void MoveHare()
    {
      positions = ((rand() % 10) + 1);

      if(positions >=1 && positions <=2){
        h+= 0;
      }
      else if(positions >= 3 && positions <= 4){
        h += 9;
      }
      else if(positions == 5){
        h -= 12;
      }
      else if(positions >= 6 && positions <= 8){
        ++h;
      }
      else if(positions >= 9 && positions <= 10){
        h -= 2;
      }
      if(h<1){
        h=1;
      }
      else if(h>finishLine){
        h = finishLine;
      }
    }

    void MoveTortoise()
    {
      positions = ((rand() % 10) + 1);

      if(positions>=1 && positions <=5)
      {
        t += 3;
      }
      else if(positions >=6 && positions <=7)
      {
        t -= 6;
      }
      else if(positions >=8 && positions <=10)
      {
        ++t;
      }
      if(t<1)
      {
        t=1;
      }
      else if(t>finishLine)
      {
        t = finishLine;
      }
    }//end method

    void PrintCurrentPositions()
    {
      printf("Start: ");
      for(int i = 1; i <= finishLine; i++)
      {
        if(i == t && i == h && i!=1)
        {
          printf("OUCH!");
          i += 6;
        }
        else if(i == t)
        {
          printf("T");
        }
        else if(i == h)
        {
          printf("H");
        }
        else
        {
          printf(" ");
        }
      }//end for
      if(t >= finishLine && h>= finishLine)
      {
          printf("| IT'S A TIE");
      }
      else if(t >= finishLine){
          printf("|T TORTOISE WINS!!! YAY!!!");
      }
      else if(h >= finishLine){
          printf("|H HARE WINS. YUCH.");
      }
      else{
          printf("Finish\n");
      }
    }//end method
};//end class

int main()
{
   TortoiseHare TH;
   return 0;
}
