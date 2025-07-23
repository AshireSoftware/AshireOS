import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Effects

ApplicationWindow {
    flags: Qt.Window | Qt.FramelessWindowHint | Qt.Tool | Qt.WindowStaysOnTopHint
    opacity: 0.9
    visible: true
    width: Screen.width
    height: 50
    maximumHeight: 50
    title: "Ashire Panel"
    y: Screen.height - height
    color: darkmacdarkest

    // panel top line
    background: Rectangle {
        y: 1
        color: titlebarcolor
        height: 1
    }

    // Window variable
    property string prevFocusedId:  ""

    // Clock variable
    property string currentTime:    ""

    // Date variable
    property string currentDate:    ""

    // Color variables
    property string titlebarcolor:  "#363636"
    property string darkmacdarkest: "#1e1e1e"
    property string darkmacdark:    "#292929"

    RowLayout {
        spacing: 4
        height: parent.height
        anchors.fill: parent
        Layout.alignment: verticalCenter

        // Spacer between left side of screen and start menu
        Item {
            Layout.preferredWidth: 4
        }

        // Start button
        Button {
            id: startButton
            font.pixelSize: 30
            Layout.preferredWidth: 40
            Layout.preferredHeight: 40
            background: Rectangle {
                color: startButton.hovered ? darkmacdark : darkmacdarkest
                radius: 4
            }
            onClicked: {
                panel.openStartMenu()
            }
            Image {
                height: 40
                width: 40
                source: "qrc:/Images/start.png"
                fillMode: Image.PreserveAspectFit
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
            id: panelButtons
            model: panel.windows
            delegate: Button {
                background: Rectangle {
                    // TODO: change color when hovering over button
                    color: panelButtons.hovered ? "red" : darkmacdark
                    radius: 4
                }
                text: modelData.title
                focusPolicy: Qt.NoFocus
                property string winId: modelData.id
                Layout.preferredWidth: 200
                Layout.preferredHeight: 36
                Image {
                    anchors.leftMargin: 8
                    height: 20
                    width: 20
                    source: "qrc:/Images/placeholder.png"
                    fillMode: Image.PreserveAspectFit
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                }
                contentItem: Text {
                        text: parent.text
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 32
                        elide: Text.ElideRight
                        color: "white"
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        width: parent.width
                    }
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

        // Battery
        Item {
            id: batteryArea
            Button {
                id: batteryButton
                x: -55
                width: 26
                height: 26
                anchors.verticalCenter: parent.verticalCenter
                background: Rectangle {
                    color: batteryButton.hovered ? darkmacdark : darkmacdarkest
                    radius: 4
                }
                contentItem: Image {
                    source: "qrc:/Images/battery.png"
                    anchors.centerIn: parent
                }
                onClicked: {
                    panel.openBatterySettings()
                }
            }
        }

        // Internet controls
        Item {
            id: internetArea
            Button {
                id: internetButton
                x: -35
                width: 24
                height: 24
                anchors.verticalCenter: parent.verticalCenter
                background: Rectangle {
                    color: internetButton.hovered ? darkmacdark : darkmacdarkest
                    radius: 4
                }
                contentItem: Image {
                    source: "qrc:/Images/signal.svg"
                    anchors.centerIn: parent
                }
                onClicked: {
                    panel.openNetworkManager()
                }
            }
        }

        // Audio controls
        Item {
            id: audioArea
            Button {
                id: audioButton
                x: -15
                width: 24
                height: 24
                anchors.verticalCenter: parent.verticalCenter
                background: Rectangle {
                    color: audioButton.hovered ? darkmacdark : darkmacdarkest
                    radius: 4
                }
                contentItem: Image {
                    source: "qrc:/Images/audio.svg"
                    horizontalAlignment: Button.AlignHCenter
                    verticalAlignment: Button.AlignVCenter
                }
                onClicked: {
                    panel.openAudioSettings()
                }
            }
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
            // Update clock
            currentTime = Qt.formatTime(date, "h:mm AP")
            // Update date
            currentDate = Qt.formatDate(date, "dd.MM.yyyy")
            }
        }

        // Display the clock
        Item {
            id: clockArea
            width: 100
            height: 40
            // Display the current time
            Text {
                text: currentTime
                color: "white"
                x: 0
                y: 2
                width: 100
                height: 20
                font.pixelSize: 14
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            // Display the currend date
            Text {
                text: currentDate
                color: "white"
                x: 0
                y: 20
                width: 100
                height: 20
                font.pixelSize: 14
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        // Initialize time
        Component.onCompleted: {
            var date = new Date()
            currentTime = currentTime
        }

        // Spacer between clock and right side of screen
        Item {
            Layout.preferredWidth: 2
        }
    }
}
