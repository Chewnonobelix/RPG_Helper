import QtQuick 2.0
import QtQuick.Controls 2.15

import Bestiary.Generic 1.0

Item {
    property AbstractCreature model: null

    onModelChanged: description.text = model ? model.description : ""
    ScrollView {
        anchors.fill: parent
        Column {
            Label {
                id: name
                text: "Name " + (model ? model.name : "")
            }
            Label {
                id: race
                text: "Race " + (model ? model.race : "")
            }
            TextEdit {
                id: description
                onTextChanged: model.description = text
            }

        }
    }
}
