#pragma once
#include <windows.h>

class GUI;

class MainWindow
{
public:
	MainWindow(GUI* gui, HINSTANCE hInstance, const wchar_t* title, int width, int height);
	~MainWindow();
	void show(int showFlag = SW_SHOW);
	void refresh();
	HDC getDC();
private:
	MainWindow(const MainWindow&);
	MainWindow& operator=(const MainWindow&);
	void registerWindowClass(HINSTANCE hInstance);
	void createWindow(HINSTANCE hInstance);
	static LRESULT CALLBACK internal_windowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK windowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
protected:
	HWND hWnd;
	int width, height;
	wchar_t title[250];
	HDC hDC; // DC to be painted to - gets copied to the window on WM_PAINT
	HBITMAP hBMP; // bitmap associated with hDC
	GUI* gui;
};