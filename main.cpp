// Copyright 2025 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

#include "Test_CI.h"

#include "ArcGISRuntimeEnvironment.h"
#include "MapQuickView.h"

#include <QDir>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

//------------------------------------------------------------------------------

using namespace Esri::ArcGISRuntime;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Use of ArcGIS location services, such as basemap styles, geocoding, and routing services,
    // requires an access token. For more information see
    // https://links.esri.com/arcgis-runtime-security-auth.

    // The following methods grant an access token:

    // 1. User authentication: Grants a temporary access token associated with a user's ArcGIS account.
    // To generate a token, a user logs in to the app with an ArcGIS account that is part of an
    // organization in ArcGIS Online or ArcGIS Enterprise.

    // 2. API key authentication: Get a long-lived access token that gives your application access to
    // ArcGIS location services. Go to the tutorial at https://links.esri.com/create-an-api-key.
    // Copy the API Key access token.

    const QString accessToken = QString(
        "AAPTxy8BH1VEsoebNVZXo8HurDamo2caLSJhO25vDYgu0ZQFM88vCIgyn2iIPDM9_8K4dLGkcHSi_"
        "sBjEViEia9pQYrMx1KGIMDpsCZfjHnZwgDcSUv6eDkUVi-69t7sD0batC3FR6D6DTq158kQ2cP4CXIfIXBHG-"
        "7srOithWQgbBvl0oVKcHfidCANXRxSNIuEUzKeFQhSABIN5pHAlvHhkNMH2r-S2Plv17xZcVT3vF8.AT1_"
        "0tvclNxh");

    if (accessToken.isEmpty()) {
        qWarning()
            << "Use of ArcGIS location services, such as the basemap styles service, requires"
            << "you to authenticate with an ArcGIS account or set the API Key property.";
    } else {
        ArcGISRuntimeEnvironment::setApiKey(accessToken);
    }

    // Production deployment of applications built with ArcGIS Maps SDK requires you to
    // license ArcGIS Maps SDK functionality. For more information see
    // https://links.esri.com/arcgis-runtime-license-and-deploy.

    // ArcGISRuntimeEnvironment::setLicense("Place license string in here");

    // Register the map view for QML
    qmlRegisterType<MapQuickView>("Esri.Test_CI", 1, 0, "MapView");

    // Register the Test_CI (QQuickItem) for QML
    qmlRegisterType<Test_CI>("Esri.Test_CI", 1, 0, "Test_CI");

    // Initialize application view
    QQmlApplicationEngine engine;

    // Add the import Path
    engine.addImportPath(QDir(QCoreApplication::applicationDirPath()).filePath("qml"));

    // Set the source
    engine.load(QUrl("qrc:/qml/main.qml"));

    return app.exec();
}

//------------------------------------------------------------------------------
