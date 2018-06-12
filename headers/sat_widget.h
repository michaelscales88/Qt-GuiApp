#pragma once
#include <iostream>
#include <string>
#include <QWidget>
#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QStringList>
#include <QString>

using namespace std;

class SatWidget: public QWidget {
   private:

   public:
      SatWidget( QWidget *parent = 0 );
      ~SatWidget() {}
};
