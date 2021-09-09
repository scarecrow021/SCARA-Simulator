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
// User Defined Libraries
#include <./BackEnd/SCARA.h>

class SCARA_UI
{
private:
	QGraphicsLineItem *arm1, *arm2; // Graphical Arms of the SCARA Robot.
	QPen redPen, blackPen;
	
	void PrepareGraphics(void);

public:
	SCARA_UI();
	void DrawSCARA(SCARA , QGraphicsScene* );

};

#endif // SCARA_UI_H
