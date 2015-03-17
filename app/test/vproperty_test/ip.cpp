#include "ip.h"

Ip::Ip()
{
  value = 0;
}

Ip::~Ip()
{

}

Ip::Ip(quint32 value)
{
  this->value = value;
}

Ip::operator quint32()
{
  return value;
}
