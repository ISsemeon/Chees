import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12
import Figures 1.0
import Game 1.0


ApplicationWindow {
	width: 1400
	height: 1400
	visible: true
	title: qsTr("Chess")


	TableView
	{
		leftMargin: 140
		topMargin: 140
		id: _lv
		model: Game.model
		anchors.fill: parent


		delegate: Item
		{
			id: _cellDelegate
			implicitWidth: 140
			implicitHeight: 140

			MouseArea
			{
			id: _mouseArea;
			anchors.fill: _cellDelegate
			hoverEnabled: true
			onClicked:
			{
				model.figure.move()
			}


			Rectangle
			{
				color: _mouseArea.containsMouse ?  "#3b3b3b" : "#2b2b2b"
				anchors.fill: parent
				border.color:"grey"
			}

			Image {
				id: picture
				source: model.figure.picture
				anchors.centerIn: parent
				Component.onCompleted:
				{
					if(picture.sourceSize.height > _cellDelegate.height)
					{
						picture.scale = 0.9;
					}
				}
			}
			Text {

				anchors.fill: parent
				//				text: model.figure.xBoard+ ":" + model.figure.yBoard;
				color: "White"
			}

		}
	}

}
}