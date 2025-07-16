import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Effects

ApplicationWindow {
    flags: Qt.Window | Qt.FramelessWindowHint | Qt.WindowDoesNotAcceptFocus | Qt.Tool
    opacity: 0.8
    visible: true
    width: Screen.width
    height: 50
    maximumHeight: 50
    title: "Ashire Panel"
    y: Screen.height - height
    color: darkmacdarkest
    background: Rectangle {
        color: titlebarcolor
        height: 2
    }
    // Window variable
    property string prevFocusedId: ""

    // Clock variable
    property string currentTime: ""

    // Color variables
    property string titlebarcolor: "#363636"
    property string darkmacdarkest: "#1e1e1e"
    property string darkmacdark: "#292929"

    RowLayout {
        spacing: 4
        height: parent.height
        anchors.fill: parent
        Layout.alignment: verticalCenter

        // Spacer between left side of screen and start menu
        Item {
          Layout.preferredWidth: 2
        }

        // Start button
        Button {
            text: "+"
            font.pixelSize: 30
            Layout.preferredWidth: 40
            Layout.preferredHeight: 40
            background: Rectangle {
                color: darkmacdark
            }
            onClicked: {
                panel.openStartMenu()
            }
        }

        // Timer for panel (updates panel elements)
        Timer {
          id: panelTimer
          interval: 100
          running: true
          repeat: true
          onTriggered: {
            panel.refreshWindows()
          }
        }

        // Pannel listing running programs
        Repeater {
            model: panel.windows
            delegate: Button {
                background: Rectangle {
                    color: darkmacdark
                }
                text: modelData.title
                focusPolicy: Qt.NoFocus
                property string winId: modelData.id
                Layout.preferredWidth: 175
                Layout.preferredHeight: 36

                onClicked: {
                    // Convert IDs to int for comparison
                    var prevIdHex = panel.getPrevFocusedId()
                    var prevIdInt = null
                    var btnIdInt = null

                    if (prevIdHex !== "" && prevIdHex !== null) {
                        prevIdInt = parseInt(prevIdHex, 16)
                    }
                    try {
                        btnIdInt = parseInt(winId, 16)
                    } catch(e) {
                        console.log("Error parsing window IDs");
                    }

                    if (prevIdInt !== null && btnIdInt !== null && prevIdInt === btnIdInt) {
                        // IDs match: minimize
                        panel.minimizeWindow(winId)
                    } else {
                        // IDs do not match: focus
                        panel.focusWindow(winId)
                    }

                    // Update previous focus
                    var newFocus = panel.getFocusedWindow()
                    if (newFocus !== "") {
                        panel.setPrevFocusedId(newFocus)
                        prevFocusedId = newFocus
                    }
                }
            }
        }

        // Spacer
        Item {
          Layout.fillWidth: true
        }

        // Timer for clock (updates time)
        Timer {
          id: timer
          interval: 500
          running: true
          repeat: true
          onTriggered: {
            // Update currentTime with the current system time
            var date = new Date()
            currentTime = Qt.formatTime(date, "hh:mm")
          }
        }

        // Clock
        Button {
          Layout.preferredWidth: 90
          Layout.preferredHeight: 40
          text: currentTime
          font.pixelSize: 20
          background: Rectangle {
              color: darkmacdark
          }
        }

        // Initialize time
        Component.onCompleted: {
          var date = new Date()
          currentTime = Qt.formatTime(date, "hh:mm")
        }

        // Spacer between clock and right side of screen
        Item {
          Layout.preferredWidth: 2
        }
    }
}
