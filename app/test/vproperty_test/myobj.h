#ifndef MYOBJ_H
#define MYOBJ_H

#include <QObject>

class MyObj : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QChar ch MEMBER ch)
public:
  explicit MyObj(QObject *parent = 0) : QObject(parent)
  {
    ch = 'a';
  }

  virtual ~MyObj() {}

public:
  QChar ch;
};

#endif // MYOBJ_H
