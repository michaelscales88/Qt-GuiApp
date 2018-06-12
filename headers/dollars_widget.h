#pragma once
#include <iostream>
#include <string>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>

using namespace std;

class DollarsWidget: public QWidget
{

private:

public:
      DollarsWidget( QWidget *parent = 0 );
      ~DollarsWidget() {}
};
