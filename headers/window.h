#pragma once
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "flowlayout.h"

using namespace std;

class Window: public QWidget
{
   Q_OBJECT

public:
   Window( QWidget *parent = 0 );
   ~Window() {}

   void addWidget( QWidget *item = 0 );
   void initView();

private:
   FlowLayout *wLayout;
   QHBoxLayout *hLayout;
   bool showWidgets;
};
