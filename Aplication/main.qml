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

	Row
	{
		spacing: 2
		Unit
		{
			imgSource: figure1.picture
			BishopFigure
			{
				id: figure1
			}
		}
		Unit
		{
			imgSource: figure2.picture
			RookFigure
			{
				id: figure2
			}
		}
		Unit
		{
			imgSource: figure3.picture
			KingFigure
			{
				id: figure3
			}
		}
		Unit
		{
			imgSource: figure4.picture
			QueenFigure
			{
				id: figure4
			}
		}
	}





}
