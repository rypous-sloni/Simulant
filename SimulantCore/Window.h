#pragma once
#include "Symbol.h"
#include "StatDelegate.h"

// A visible set of symbols on the screen
// Different types of win can be evaluated
class Window
{
public:
	Window(int maxWidth, int maxHeight);

	// In case of non-rectangular window, returns the maximum possible indexes
	int getWidth() const;
	int getHeight() const;

	const Symbol& getSymbol(int x, int y) const;
	void setSymbol(int x, int y, const Symbol& symbol);

	// Evaluate the win, with optional stats reported to the StatDelegate
	int winCrissCross(StatDelegate* stat = nullptr);

protected:
	int maxWidth, maxHeight;
	std::vector<std::vector<const Symbol*>> matrix;
};