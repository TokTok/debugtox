/* SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright © 2025 The TokTok team.
 */
#include "debugtox.h"
#include "logger.h"

#include <QApplication>
#include <QCommandLineParser>
#include <QDateTime>
#include <QDebug>

int main(int argc, char* argv[])
{
    Logger::install();
    QApplication a(argc, argv);

    QCommandLineParser parser;
    parser.setApplicationDescription(QStringLiteral("DebugTox"));
    parser.addHelpOption();
    parser.addVersionOption();
    parser.process(a);

    qDebug() << "Starting up...";
    DebugTox w;
    w.show();
    return QApplication::exec();
}
