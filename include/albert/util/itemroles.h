// Copyright (C) 2014-2018 Manuel Schneider

#pragma once
#include <Qt>
#include "../core_globals.h"

namespace Core {

/**
 * @brief The ItemRoles enum. This enum is used for QML model view.
 */
enum EXPORT_CORE ItemRoles {
    TextRole = 0,
    ToolTipRole,
    DecorationRole,
    CompletionRole = Qt::UserRole, // Note this is used as int in QML
    ActionRole,
    AltActionRole,
    FallbackRole
};

}
