#include <gui/main_screen/MainView.hpp>

MainView::MainView()
{

}

void MainView::setupScreen()
{

}

void MainView::tearDownScreen()
{

}

void MainView::test() {
	application().gotoScreen1ScreenSlideTransitionEast();
}

/**
 * Start the animation in the same direction as it was stopped.
 * Change the label text to reflect the state
 */
void MainView::startAnimation()
{

}

/**
 * Stop, or pause, the animation.
 * Change the label text to reflect the state
 */
void MainView::stopAnimation()
{

}

void MainView::toggleLED()
{
    presenter->toggleLED();
}
