#include "netclient.h"

NetClient::NetClient(QObject* parent) : QObject(parent)
{
  Ip myIp("");
  ip = "";
  QString s = ip;
  //s = ip;
}

NetClient::~NetClient()
{

}
