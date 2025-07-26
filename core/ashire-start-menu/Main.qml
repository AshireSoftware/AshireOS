import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Effects

ApplicationWindow {
    flags: Qt.Window | Qt.WindowDoesNotAcceptFocus | Qt.FramelessWindowHint
    opacity: 0.9
    visible: true
    height: 600
    width: 500
    maximumHeight: 600
    maximumWidth: 500
    minimumHeight: 600
    minimumWidth: 500
    title: "Ashire Start Menu"
    y: Screen.height - height - 50
    color: darkmacdarkest

    // Color variables
    property string titlebarcolor:  "#363636"
    property string darkmacdarkest: "#1e1e1e"
    property string darkmacdark:    "#292929"

    property int rightsidebuttonspos: 343

    // Start Menu outline #1
    Rectangle {
        x: 1
        y: 1
        width: parent.width - 2
        height: parent.height - 2
        color: titlebarcolor
    }

    // Start Menu outline #2
    Rectangle {
        x: 2
        y: 2
        width: parent.width - 4
        height: parent.height - 4
        color: darkmacdarkest
    }

    // Pinned programs list
    Item {
        id: pinnedProgramsList
        // Pinned program list outline
        Rectangle {
            x: 12
            y: 12
            width: 300 + 4
            height: 600 - x * 2
            color: darkmacdark
        }
        // Pinned program list background
        Rectangle {
            x: 14
            y: 14
            width: 300
            height: 600 - x * 2
            color: darkmacdarkest
        }
        // Web Browser
        Button {
            id: browserButton
            x: 24
            y: 24
            width: 280
            height: 60
            text: "Web Browser"
            background: Rectangle {
                color: browserButton.hovered ? darkmacdark : darkmacdark
                border.color: browserButton.hovered ? "white" : titlebarcolor
                radius: 4
            }
            contentItem: Text {
                text: parent.text
                color: "white"
                font.pixelSize: 16
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 16
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }
            onClicked: {
                startmenu.runDefaultBrowser()
                startmenu.killStartMenu()
            }
        }
        // Terminal Emulator
        Button {
            id: terminalButton
            x: 24
            y: 94
            width: 280
            height: 60
            text: "Terminal"
            background: Rectangle {
                color: terminalButton.hovered ? darkmacdark : darkmacdark
                border.color: terminalButton.hovered ? "white" : titlebarcolor
                radius: 4
            }
            contentItem: Text {
                text: parent.text
                color: "white"
                font.pixelSize: 16
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 16
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }
            onClicked: {
                startmenu.runTerminal()
                startmenu.killStartMenu()
            }
        }
    }

    // PFP
    Item {
    id: pfp
        // PFP outline
        Rectangle {
            x: 365 - 8
            y: 12 + 12
            width: 96 + 4
            height: 96 + 4
            color: darkmacdark
        }
        // PFP background
        Rectangle {
            x: 367 - 8
            y: 14 + 12
            width: 96
            height: 96
            color: darkmacdarkest
        }
        // PFP
        Image {
            x: 367 - 8
            y: 14 + 12
            width: 90
            height: 90
            source: "qrc:/Images/pfp.png"
            smooth: true
            fillMode: Image.PreserveAspectFit
        }
    }

    // Right side buttons
    Item {
    id: rightButtons
        // Display username
        Button {
            id: usernameButton
            x: rightsidebuttonspos
            y: 144
            width: 128
            height: 40
            text: "Kiwi"
            // TODO: Use a template or array
            background: Rectangle {
                color: usernameButton.hovered ? darkmacdark : darkmacdark
                border.color: usernameButton.hovered ? "white" : titlebarcolor
                radius: 4
            }
            contentItem: Text {
                text: parent.text
                color: "white"
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 10
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }
            onClicked: {
                startmenu.openHomeFolder()
                startmenu.killStartMenu()
            }
        }

        // Link Documents
        Button {
            id: documentsButton
            x: rightsidebuttonspos
            y: 144 + 50 * 1
            width: 128
            height: 40
            text: "Documents"
            background: Rectangle {
                color: documentsButton.hovered ? darkmacdark : darkmacdark
                border.color: documentsButton.hovered ? "white" : titlebarcolor
                radius: 4
            }
            contentItem: Text {
                text: parent.text
                color: "white"
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 10
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }
            onClicked: {
                console.log("Opening Documents folder");
                onClicked: {
                    startmenu.openDocumentsFolder()
                    startmenu.killStartMenu()
                }
            }
        }
        // Link Pictures
        Button {
            id: picturesButton
            x: rightsidebuttonspos
            y: 144 + 50 * 2
            width: 128
            height: 40
            text: "Pictures"
            background: Rectangle {
                color: picturesButton.hovered ? darkmacdark : darkmacdark
                border.color: picturesButton.hovered ? "white" : titlebarcolor
                radius: 4
            }
            contentItem: Text {
                text: parent.text
                color: "white"
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 10
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }
            onClicked: {
                console.log("Opening Pictures folder");
                onClicked: {
                    startmenu.openPicturesFolder()
                    startmenu.killStartMenu()
                }
            }
        }
        // Link Videos
        Button {
            id: videosButton
            x: rightsidebuttonspos
            y: 144 + 50 * 3
            width: 128
            height: 40
            text: "Videos"
            background: Rectangle {
                color: videosButton.hovered ? darkmacdark : darkmacdark
                border.color: videosButton.hovered ? "white" : titlebarcolor
                radius: 4
            }
            contentItem: Text {
                text: parent.text
                color: "white"
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 10
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }
            onClicked: {
                console.log("Opening Videos folder");
                onClicked: {
                    startmenu.openVideosFolder()
                    startmenu.killStartMenu()
                }
            }
        }
        // Link Music
        Button {
            id: musicButton
            x: rightsidebuttonspos
            y: 144 + 50 * 4
            width: 128
            height: 40
            text: "Music"
            background: Rectangle {
                color: musicButton.hovered ? darkmacdark : darkmacdark
                border.color: musicButton.hovered ? "white" : titlebarcolor
                radius: 4
            }
            contentItem: Text {
                text: parent.text
                color: "white"
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 10
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }
            onClicked: {
                console.log("Opening Music folder");
                onClicked: {
                    startmenu.openMusicFolder()
                    startmenu.killStartMenu()
                }
            }
        }
        // Shutdown button
        Button {
            id: shutdownButton
            x: rightsidebuttonspos + 24
            y: 600 - 64
            width: 80
            height: 30
            Text {
                x: 6
                y: 6
                text: "Shutdown"
                color: "white"
            }
            background: Rectangle {
                color: shutdownButton.hovered ? darkmacdark : darkmacdark
                border.color: shutdownButton.hovered ? "white" : titlebarcolor
                radius: 4
            }
            onClicked: {
                console.log("Shutting down");
                startmenu.shutdownComputer()
            }
        }
    }
}
