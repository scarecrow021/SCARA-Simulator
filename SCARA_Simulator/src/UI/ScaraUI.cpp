#include <./UI/ScaraUI.h>

void SCARA_UI::PreparePens(void)
{
	// Pen Colors
	redPen.setColor(Qt::red);
	blackPen.setColor(Qt::black);
	bluePen.setColor(Qt::blue);
	whiteBrush.setColor(Qt::white);
	// Pen Thickness
	redPen.setWidth(10);
	blackPen.setWidth(10);
	bluePen.setWidth(2);
}

SCARA_UI::SCARA_UI()
{
	PreparePens();
}

void SCARA_UI::DrawSCARA(SCARA _scara, QGraphicsScene* _scene)
{
	_scene->clear(); // Clear display area each time
	_scene->addLine(_scara.x0, _scara.y0, _scara.x1, _scara.y1, redPen);
	_scene->addLine(_scara.x1, _scara.y1, _scara.x2, _scara.y2, blackPen);

	if (workspaceCalculated)
	{
		DrawWorkspace(workspacePoints, _scene);
	}
	
}


void SCARA_UI::GetWorspacePoints(SCARA _scara, QGraphicsScene* _scene)
{
	
	double rad = 1;
	for (int i = 0; i < _scara.workspaceBoundaryX.size(); i++)
	{
		workspacePoints << QPointF(_scara.workspaceBoundaryX.at(i), _scara.workspaceBoundaryY.at(i));
		//_scene->addEllipse(_scara.workspaceBoundaryX.at(i) - rad, _scara.workspaceBoundaryY.at(i) - rad, rad * 2.0, rad * 2.0, bluePen);
	}
	workspaceCalculated = true;

	if (workspaceCalculated)
	{
		DrawWorkspace(workspacePoints, _scene);

	}

}

void SCARA_UI::DrawWorkspace(QPolygonF _points, QGraphicsScene* _scene)
{
	_scene->addPolygon(_points, bluePen);
}
