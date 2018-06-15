/* Graphical User Interface Assignment Interface1 (I1)
 * Developer: Michael Scales
 */
#pragma once
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

#include "flowlayout.h"
#include "output_widget.h"
#include "base.h"

using namespace std;

class Window: public QWidget
{
   Q_OBJECT

public:
   Window( QWidget *parent = 0 );
   ~Window() {}

   void addWidget( Base *item = 0 );
   void initView();
   void setOutput( OutputWidget *item = 0 );

private:
   FlowLayout *wLayout;
   QHBoxLayout *rLayout;
   QHBoxLayout *hLayout;
   OutputWidget *outputWidget;
};
