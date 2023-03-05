/*
 * Copyright 2023 Debby Nirwan
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string>

#include "options.h"
#include "sim_manager.h"

#include "spdlog/spdlog.h"
#include <QApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>

void ConfigureLogging()
{
    // Use the default logger (stdout, multi-threaded, colored)
    spdlog::set_level(spdlog::level::debug);
}

Options GetOptions(QApplication& app)
{
    QApplication::setApplicationName("pacman-ai-cpp");
    QApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("Pacman AI Framework");
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption layoutFileOption(
        QStringList() << "l"
                      << "layout-name",
        QCoreApplication::translate("main", "Load layout file <path to layout>."),
        QCoreApplication::translate("main", "path to layout"));
    parser.addOption(layoutFileOption);

    QCommandLineOption pacmanNameOption(
        QStringList() << "p"
                      << "pacman-name",
        QCoreApplication::translate("main", "Choose pacman agent to run <pacman name>."),
        QCoreApplication::translate("main", "pacman name"));
    parser.addOption(pacmanNameOption);

    QCommandLineOption autoExitOption(
        QStringList() << "a"
                      << "auto-exit",
        QCoreApplication::translate("main", "Automatically exit after the game has ended."));
    parser.addOption(autoExitOption);

    parser.process(app);

    Options options;
    options.pacmanName = parser.value(pacmanNameOption).toStdString();
    options.layoutFileName = parser.value(layoutFileOption).toStdString();
    options.autoExit = parser.isSet(autoExitOption);

    return options;
}

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    ConfigureLogging();
    auto options = GetOptions(app);

    spdlog::info("Starting pacman-ai-cpp. Pacman Agent is {}", options.pacmanName);

    SimulationManager sim(options.layoutFileName, options.pacmanName, options.autoExit);
    sim.Start();
    auto ret = app.exec();

    spdlog::info("Exiting pacman-ai-cpp");

    return ret;
}
