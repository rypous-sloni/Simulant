#pragma once
#include "SimulantCore/Simulator.h"
#include "SimulantCore/JSON/JSON.h"
#include "SimulantCore/SpinSourceGenerator.h"

class GUI;

class Controller
{
public:
	Controller(wchar_t* jsonGameDescription);
	~Controller();
	void assignGUI(GUI* gui);
	void userStartClicked();
protected:
	Simulator* simulator;
	SymbolSet* symbolSet;
	SpinSourceGenerator* spinSourceGenerator;
	GUI* gui;
};