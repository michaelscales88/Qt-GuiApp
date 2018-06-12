#pragma once
#include <QGroupBox>
#include <QWidget>
#include <QVBoxLayout>
#include <QRadioButton>

using namespace std;

class StudentSelector: public QWidget
{

public:
   StudentSelector( QWidget *parent = 0 );
   ~StudentSelector() {}
};
