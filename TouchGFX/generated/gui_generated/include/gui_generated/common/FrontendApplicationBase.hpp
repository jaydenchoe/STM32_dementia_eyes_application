/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    // Main
    void gotoMainScreenNoTransition();

    // Screen1
    void gotoScreen1ScreenSlideTransitionEast();

    // Screen2
    void gotoScreen2ScreenSlideTransitionEast();

    // Screen3
    void gotoScreen3ScreenNoTransition();

    // Screen4
    void gotoScreen4ScreenNoTransition();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // Main
    void gotoMainScreenNoTransitionImpl();

    // Screen1
    void gotoScreen1ScreenSlideTransitionEastImpl();

    // Screen2
    void gotoScreen2ScreenSlideTransitionEastImpl();

    // Screen3
    void gotoScreen3ScreenNoTransitionImpl();

    // Screen4
    void gotoScreen4ScreenNoTransitionImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
