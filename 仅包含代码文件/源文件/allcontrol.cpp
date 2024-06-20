#include "allcontrol.h"

AllControl::AllControl(QObject* parent):QObject(parent)
{
    DisplayList* display = new DisplayList(this);
    ControlPlayList* controlPlay = new ControlPlayList(this);
    StartPlayMusic* startPlayMusic = new StartPlayMusic(this);
}
