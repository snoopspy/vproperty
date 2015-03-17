#ifndef __NET_CLIENT_H__
#define __NET_CLIENT_H__

#include <QObject>
#include "ip.h"

class NetClient : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QString ip MEMBER ip)

public:
  NetClient(QObject* parent = 0);
  virtual ~NetClient();

public:
  Ip ip;
};

#endif // __NET_CLIENT_H__
