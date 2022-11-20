// Copyright (c) 2022 Manuel Schneider

#pragma once
#include "config.h"
#include "extension.h"
#include "export.h"

#define ALBERT_PLUGIN Q_PLUGIN_METADATA(IID ALBERT_IID FILE "metadata.json")

namespace albert
{
class PluginSpec;
class ExtensionRegistry;

/// The plugin entry point class.
/// Qt requires plugin classes to be default constructible, inherit QObject and
/// contain a Q_OBJECT and the Q_PLUGIN_METADATA(…) macro. This is a Qt MOC
/// requirement and can not be omitted. Also the metadata is not accessible
/// inside the QtPlugin by default. This class inherits QObject and injects a
/// reference to the plugin spec while keeping default constructability.
/// @note Use the ALBERT_PLUGIN macro for convenience
class ALBERT_EXPORT Plugin : public QObject, virtual public Extension
{
public:
    Plugin();
    ~Plugin() override;

    void addExtension(Extension*);  /// Add a managed extension. Automatically removed on plugin destruction
    ExtensionRegistry &registry();
    PluginSpec &spec();

    QString id() const override;  /// Override using the plugin specification
    QString name() const override;  /// Override using the plugin specification
    QString description() const override;  /// Override using the plugin specification

private:
    class Private;
    std::unique_ptr<Private> d;
};
}
