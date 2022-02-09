import QtQuick 2.0

Item {
	required property string imgSource
	implicitWidth: img.width
	implicitHeight: img.height

	Rectangle
	{
		id: bg
		anchors.fill: img
		color: "grey"
	}
	Image {
		id: img
		source: imgSource
		Component.onCompleted:
		{

		}
	}
}
