#include "Window.hpp"

Window::Window(/* args */)
{
	Create();
}

Window::~Window()
{
}


void	Window::Create()
{
	mWindow.create(mMode, mTitle, (mFullscreen) ? sf::Style::Fullscreen : sf::Style::Default);
	mWindow.setKeyRepeatEnabled(false);
	mf::GUI::Init(&mWindow);
}

void	Window::Destroy()
{
	mWindow.close();
}

void	Window::Draw(sf::Drawable &tDrawable)
{
	mWindow.draw(tDrawable);
}

void	Window::Draw(sf::Drawable &tDrawable, sf::Shader *tShader)
{
	mWindow.draw(tDrawable, tShader);
}

void	Window::Clear()
{
	mWindow.clear();
}

void	Window::Clear(sf::Color tColor)
{
	mWindow.clear(tColor);
}

void	Window::Render()
{
	mWindow.display();
}

bool	Window::HandleEvent(sf::Event &tEvent)
{
	return (mWindow.pollEvent(tEvent));
}

void	Window::ToggleFullscreen()
{
	mFullscreen = !mFullscreen;
	Destroy();
	Create();
}

void	Window::ChangeResolution(int tWidth, int tHeight)
{
	mMode = sf::VideoMode(tWidth, tHeight);
	Destroy();
	Create();
}

void	Window::HideCursor()
{
	mWindow.setMouseCursorVisible(false);
}

void	Window::ShowCursor()
{
	mWindow.setMouseCursorVisible(true);
}

void	Window::GrabCursor()
{
	mWindow.setMouseCursorGrabbed(true);
}

void	Window::ReleaseCursor()
{
	mWindow.setMouseCursorGrabbed(false);
}

