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
		id: tableView
		leftMargin: 140
		topMargin: 140
		model: _board
		anchors.fill: parent
		
		Board
		{
			id: _board

		}

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
				display.text = model.figure.yBoard + " " + model.figure.xBoard;
					if(!_board.getSelected())
					{
						model.figure.selected = true;
						_board.changeSelected();
						_bg.color = "#2b2b8c"
					}
					else if(_board.getSelected())
					{
						model.figure.selected = true;
						_board.swapElements();
						_board.changeSelected();
					}


				}
				
				
				Rectangle
				{
					id: _bg
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
					
					anchors.left: parent.left
					anchors.top: parent.top
	    			text: model.figure.yBoard+ ":" + model.figure.xBoard;
					color: "White"
				}
				
			}
		}
		
	}

	Text {
		id: display
		text: qsTr("text")
		color: "White"
		font.pointSize: 40
	}
}