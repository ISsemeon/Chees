import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12
import Figures 1.0
import Game 1.0


ApplicationWindow {
	width: 1200
	height: 1200
	visible: true
	title: qsTr("Chess")


	ListView
	{
	id: _lv
	model: Game.model
	anchors.fill: parent
	spacing: 4


	delegate: Rectangle
	{
		implicitHeight: picture.height
		implicitWidth: picture.width

	Image {
		id: picture
		source: model.figure.picture
	}
	Text {

		anchors.fill: parent
		text: model.figure.picture;
	}

	}
	}

}
