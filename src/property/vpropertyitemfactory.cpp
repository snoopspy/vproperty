#include "vpropertyitemfactory.h"
#include "vpropertyitem_base.h"
#include "vpropertyitem_bool.h"
#include "vpropertyitem_unknowntype.h"

// ----------------------------------------------------------------------------
// VPropertyItemFactoryInstance
// ----------------------------------------------------------------------------
class VPropertyItemFactoryInstance : public VPropertyItemFactory
{
public:
  VPropertyItemFactoryInstance()
  {
    append(new VPropertyItemCreator_Bool);
    append(new VPropertyItemCreator_Base(QMetaType::Int));
    append(new VPropertyItemCreator_Base(QMetaType::UInt));
    append(new VPropertyItemCreator_Base(QMetaType::LongLong));
    append(new VPropertyItemCreator_Base(QMetaType::ULongLong));
    append(new VPropertyItemCreator_Base(QMetaType::Double));
    append(new VPropertyItemCreator_Base(QMetaType::QChar));

    append(new VPropertyItemCreator_Base(QMetaType::QString));

  }

  /*
        * Invalid = QMetaType::UnknownType,
        * Bool = QMetaType::Bool,
        * Int = QMetaType::Int,
        * UInt = QMetaType::UInt,
        * LongLong = QMetaType::LongLong,
        * ULongLong = QMetaType::ULongLong,
        * Double = QMetaType::Double,
        Char = QMetaType::QChar,
        Map = QMetaType::QVariantMap,
        List = QMetaType::QVariantList,
        String = QMetaType::QString,
        StringList = QMetaType::QStringList,
        ByteArray = QMetaType::QByteArray,
        BitArray = QMetaType::QBitArray,
        Date = QMetaType::QDate,
        Time = QMetaType::QTime,
        DateTime = QMetaType::QDateTime,
        Url = QMetaType::QUrl,
        Locale = QMetaType::QLocale,
        Rect = QMetaType::QRect,
        RectF = QMetaType::QRectF,
        Size = QMetaType::QSize,
        SizeF = QMetaType::QSizeF,
        Line = QMetaType::QLine,
        LineF = QMetaType::QLineF,
        Point = QMetaType::QPoint,
        PointF = QMetaType::QPointF,
        RegExp = QMetaType::QRegExp,
        RegularExpression = QMetaType::QRegularExpression,
        Hash = QMetaType::QVariantHash,
        EasingCurve = QMetaType::QEasingCurve,
        Uuid = QMetaType::QUuid,
        ModelIndex = QMetaType::QModelIndex,
        LastCoreType = QMetaType::LastCoreType,

        Font = QMetaType::QFont,
        Pixmap = QMetaType::QPixmap,
        Brush = QMetaType::QBrush,
        Color = QMetaType::QColor,
        Palette = QMetaType::QPalette,
        Image = QMetaType::QImage,
        Polygon = QMetaType::QPolygon,
        Region = QMetaType::QRegion,
        Bitmap = QMetaType::QBitmap,
        Cursor = QMetaType::QCursor,
        KeySequence = QMetaType::QKeySequence,
        Pen = QMetaType::QPen,
        TextLength = QMetaType::QTextLength,
        TextFormat = QMetaType::QTextFormat,
        Matrix = QMetaType::QMatrix,
        Transform = QMetaType::QTransform,
        Matrix4x4 = QMetaType::QMatrix4x4,
        Vector2D = QMetaType::QVector2D,
        Vector3D = QMetaType::QVector3D,
        Vector4D = QMetaType::QVector4D,
        Quaternion = QMetaType::QQuaternion,
        PolygonF = QMetaType::QPolygonF,
        Icon = QMetaType::QIcon,
        LastGuiType = QMetaType::LastGuiType,

        SizePolicy = QMetaType::QSizePolicy,

        UserType = QMetaType::User
   */
  virtual ~VPropertyItemFactoryInstance()
  {
    // memory leak // gilgil temp 2105.03.18
  }
};

// ----------------------------------------------------------------------------
// VPropertyItemFactory
// ----------------------------------------------------------------------------
VPropertyItem* VPropertyItemFactory::createItem(VPropertyEditor* editor, QObject* object, QMetaProperty mpro)
{
  VPropertyItem* item = nullptr;
  for (QList<VPropertyItemCreator*>::iterator it = begin(); it != end(); it++)
  {
    VPropertyItemCreator* creator = *it;
    item = creator->createItem(editor, object, mpro);
    if (item != nullptr) break;
  }
  return item;
}

VPropertyItemFactory& VPropertyItemFactory::instance()
{
  static VPropertyItemFactoryInstance factory;
  return factory;
}
