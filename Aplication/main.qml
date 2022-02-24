import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12
import Figures 1.0


ApplicationWindow {
	width: 480
	height: 480
	visible: true
	title: qsTr("Chess")
	Board
	{
		id: _board
	}
	
	
	TableView
	{
		id: tableView

		model: _board
		anchors.fill: parent

		


		delegate: Item
		{
			id: _cellDelegate
			implicitWidth: 60
			implicitHeight: 60
			
			MouseArea
			{

				id: _mouseArea;
				anchors.fill: _cellDelegate
				hoverEnabled: true
				onHoveredChanged:
				{
					if(containsMouse)
					{
						model.figure.hovered = true;
						_board.showPossiblePositions();
					}
					else
					{
						model.figure.hovered = false;
						_board.turnOfLightning();
					}
				}

				onClicked:
				{
					if(!_board.getSelected())
					{
						model.figure.hovered = true;
						model.figure.selected = true;
						model.figure.itsTurn = true;
						_board.changeSelected();

					}
					else if(_board.getSelected())
					{
						model.figure.selected = true;
						_board.tryMove();
						_board.changeSelected();
					}
				}
				
				Rectangle
				{
					id: _bg
					color: 	model.figure.lightning ?  "#e34234" : "#2b2b2b"
					anchors.fill: parent
					border.color:"grey"
				}
				
				Image {

					id: picture
					source: model.figure.alive ? model.figure.picture : ""
					anchors.centerIn: parent

					scale: 0.4

				}
				Text {
					
					anchors.left: parent.left
					anchors.top: parent.top
					text: model.figure.xBoard+ ":" + model.figure.yBoard;
					color: "White"
				}
				
			}
		}
		
	}
}