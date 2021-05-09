#include "widget.h"
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QDebug>
#include <QColorDialog>

widget::widget(QWidget *parent)
    : QWidget(parent)
{
  QFont labelFont("Times",20,QFont::Bold);

  QLabel *mLabel=new QLabel("This is My Sentence",this);

  mLabel->setFont(labelFont);

  mLabel->setMinimumSize(100,25);

  mLabel->move(50,25);

  QPalette label;

  label.setColor(QPalette::Window,Qt::yellow);

  label.setColor(QPalette::WindowText,Qt::red);

  mLabel->setAutoFillBackground(true);

  mLabel->setPalette(label);

  QTextEdit *text=new QTextEdit(this);

   text->move(70,55);

   connect(text,&QTextEdit::textChanged,[=](){

   qDebug()<<"Text Changed"; });

   QPushButton *cut=new QPushButton("Cut",this);

   cut->setMinimumSize(50,25);

   cut->move(10,250);

   connect(cut,&QPushButton::clicked,[=](){

    text->cut(); });

   QPushButton *copy=new QPushButton("Copy",this);

   copy->setMinimumSize(50,25);

   copy->move(110,250);

   connect(copy,&QPushButton::clicked,[=](){

    text->copy(); });

   QPushButton *paste=new QPushButton("Paste",this);

   paste->setMinimumSize(50,25);

   paste->move(210,250);

   connect(paste,&QPushButton::clicked,[=](){

    text->paste(); });

   QPushButton *undo=new QPushButton("Undo",this);

   undo->setMinimumSize(50,25);

   undo->move(10,280);

   connect(undo,&QPushButton::clicked,[=](){

    text->undo(); });

   QPushButton *redo=new QPushButton("Redo",this);

   redo->setMinimumSize(50,25);

   redo->move(110,280);

   connect(redo,&QPushButton::clicked,[=](){

    text->redo(); });

   QPushButton *html=new QPushButton("HTML",this);

   html->setMinimumSize(100,25);

   html->move(120,310);

   connect(html,&QPushButton::clicked,[=](){

    text->setHtml("<h1>Title</h1><p>Three districts:</br> <ul><li>X</li><li>Y</li><li>Z</li></ul></p>");  });

}

widget::~widget()
{
}

