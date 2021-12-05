#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>
#include <gui/model/Model.hpp>

MainPresenter::MainPresenter(MainView& v)
    : view(v)
{
}

void MainPresenter::activate()
{

}

void MainPresenter::deactivate()
{

}

void MainPresenter::toggleLED()
{
}

void MainPresenter::buttonAlarmOn()
{
	view.test();
}
void MainPresenter::buttonAlarmOff()
{

}
