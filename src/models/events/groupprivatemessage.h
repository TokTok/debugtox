#pragma once

#include "src/models/bytes/bytearray.h"
#include "src/models/enums/messagetype.h"
#include "src/models/coreevent.h"

#include <cstdint>

class QString;
struct Tox_Event_Group_Private_Message;

namespace Events {
class GroupPrivateMessage final : public CoreEvent
{
public:
    explicit GroupPrivateMessage(const Tox_Event_Group_Private_Message* event);
    ~GroupPrivateMessage() override;
    QString toString() const override;

    const uint32_t groupNumber;
    const uint32_t peerId;
    const ::MessageType::Type messageType;
    const ByteArray message;
    const uint32_t messageId;
};
} // namespace Events
