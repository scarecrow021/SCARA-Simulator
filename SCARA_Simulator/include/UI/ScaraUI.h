/**
*	\class		ScaraUI
*	\brief		Graphics for SCARA 
*	\author		Soumik SARKAR
*	\version	SCARA-Simulator_v1
*	\date		09/09/2021
*/

#ifndef SCARA_UI_H
#define SCARA_UI_H

// Qt Libraries
#include <Qt>
#include <qpen.h>
#include <QGraphicsScene>
#include <qdebug.h>
// User Defined Libraries
#include <./BackEnd/SCARA.h>

class SCARA_UI
{
private:
	QPen redPen, blackPen, bluePen;
	QBrush whiteBrush;
	void PreparePens(void);
	bool workspaceCalculated = false;
	QPolygonF workspacePoints;

public:
	SCARA_UI();
	void DrawSCARA(SCARA , QGraphicsScene* );
	void GetWorspacePoints(SCARA, QGraphicsScene*);
	void DrawWorkspace(QPolygonF, QGraphicsScene*);

};

#endif // SCARA_UI_H
