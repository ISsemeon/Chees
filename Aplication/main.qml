import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12
import Figures 1.0


ApplicationWindow {
	width: 640
	height: 640
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
			implicitWidth: 80
			implicitHeight: 80
			
			MouseArea
			{

				id: _mouseArea;
				anchors.fill: _cellDelegate
				hoverEnabled: true

				onClicked:
				{
					if(!_board.getSelected())
					{
						model.figure.hovered = true;
						model.figure.selected = true;
						model.figure.itsTurn = true;
						_board.changeSelected();

						// show possible positions
						model.figure.hovered = true;
						_board.showPossiblePositions();

					}
					else if(_board.getSelected())
					{
						model.figure.selected = true;
						_board.tryMove();
						_board.changeSelected();

						//clear litening
						model.figure.hovered = false;
						_board.turnOfLightning();
					}
				}
				
				Rectangle
				{
					id: _bg
					color: 	model.figure.lightning ?  "#3b3b3b" : "#2b2b2b"
					anchors.fill: parent
					border.color:model.figure.lightning ? "#FF9818" : "grey"
				}
				
				Image {

					id: picture
					source: model.figure.alive ? model.figure.picture : ""
					anchors.centerIn: parent

					scale: 0.5

				}
				
			}
		}
		
	}
}