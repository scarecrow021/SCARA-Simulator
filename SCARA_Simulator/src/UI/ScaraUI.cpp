#include <./UI/ScaraUI.h>

void SCARA_UI::PrepareGraphics(void)
{
	// Pen Colors
	redPen.setColor(Qt::red);
	blackPen.setColor(Qt::black);
	// Pen Thickness
	redPen.setWidth(5);
	blackPen.setWidth(5);
}

SCARA_UI::SCARA_UI()
{
	PrepareGraphics();
}

void SCARA_UI::DrawSCARA(SCARA _scara, QGraphicsScene* _scene)
{
	_scene->clear(); // Clear display area each time
	_scene->addLine(_scara.x0, _scara.y0, _scara.x1, _scara.y1, redPen);
	_scene->addLine(_scara.x1, _scara.y1, _scara.x2, _scara.y2, blackPen);
}


