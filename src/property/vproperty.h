// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PROPERTY_H__
#define __V_PROPERTY_H__

#include <QJsonObject>

class VPropertyEditable
{
  virtual void load(QJsonObject jobj);
  virtual void save(QJsonObject jobj);
};

#endif // __V_PROPERTY_H__
