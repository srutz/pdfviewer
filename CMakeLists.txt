cmake_minimum_required(VERSION 3.5)

project(pdfviewer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets PdfWidgets)

set(PROJECT_SOURCES
	main.cpp
	mainwindow.cpp
	mainwindow.h
	mypdfview.cpp
	mypdfview.h
        mainwindow.ui
)

qt_add_executable(pdfviewer MANUAL_FINALIZATION ${PROJECT_SOURCES})

target_link_libraries(pdfviewer PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Widgets
    Qt::PdfWidgets
)
qt_finalize_executable(pdfviewer)

