#pragma once
#include <iostream>
#include <string>
#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLabel>

using namespace std;

class HobbiesWidget: public QWidget {
   private:

   public:
      HobbiesWidget( QWidget *parent = 0 );
      ~HobbiesWidget() {}
};
