#pragma once
#include <QWidget>

#include "flowlayout.h"

using namespace std;

class Window: public QWidget
{
   Q_OBJECT

public:
   Window( QWidget *parent = 0 );
   ~Window();

   void addWidget( QWidget *item = 0 );
private:
   FlowLayout *layout;
   bool showWidgets;
};
