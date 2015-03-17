#include "netclient.h"

NetClient::NetClient(QObject* parent) : QObject(parent)
{
  ip = 0;
}

NetClient::~NetClient()
{

}
