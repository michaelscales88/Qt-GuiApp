#pragma once
#include <QWidget>
#include <QHBoxLayout>
#include <iostream>

using namespace std;

class Base: public QWidget
{
public:
   Base( QWidget *parent = 0 ):QWidget(parent) {};
   ~Base() {}
   virtual QHBoxLayout* getOutput() { return new QHBoxLayout; }
};
