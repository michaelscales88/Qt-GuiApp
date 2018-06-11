#pragma once
#include <iostream>
#include <string>
#include <QWidget>


using namespace std;

class GpaWidget: public QWidget
{
   Q_OBJECT

public:
   GpaWidget( QWidget *parent = 0 );
   ~GpaWidget();

signals:
};
