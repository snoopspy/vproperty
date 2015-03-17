#ifndef __IP_H__
#define __IP_H__

#include <QMetaType>

class Ip
{
public:
  Ip();
  ~Ip();
  Ip(quint32 value);
  operator quint32();
protected:
  quint32 value;
};
Q_DECLARE_METATYPE(Ip)

#endif // __IP_H__
