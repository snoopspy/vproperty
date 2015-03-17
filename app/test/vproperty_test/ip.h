#ifndef __IP_H__
#define __IP_H__

#include <QMetaType>
#include <QString>

class Ip
{
public:
  Ip() { value = 0; }
  ~Ip() {}
  Ip(const quint32 rhs) { value = rhs; }
  Ip(const QString rhs) { value = rhs.toInt(); }
  operator quint32() const { return value; }
  operator QString() const { return QString::number(value); }
  Ip operator = (const QString& rhs) { value = rhs.toInt(); return *this; }
protected:
  quint32 value;
};
Q_DECLARE_METATYPE(Ip)

#endif // __IP_H__
