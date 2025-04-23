#include "bytearray.h"

#include <QString>

ByteArray::ByteArray(const uint8_t* data, size_t size)
    : data(reinterpret_cast<const char*>(data), size)
{
}

QString ByteArray::toString() const
{
    QString result;
    for (QChar c : QString::fromUtf8(data.data(), data.size())) {
        if (c.isPrint() || c.isSpace()) {
            result += c;
        } else {
            result += QStringLiteral("\\x%1").arg(static_cast<quint16>(c.unicode()), 2, 16,
                                                  QLatin1Char('0'));
        }
    }
    return result;
}
