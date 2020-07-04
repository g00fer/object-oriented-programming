#pragma once

#include "game_engine.hpp"
#include <iostream>


struct VisitShopEvent {};
struct LeaveIslandEvent {};
struct LeaveGameEvent{};
class Initialize;
class Travel;
class Merchandise;
class Finalize;
class Leave;


class Initialize
{
    TransitionTo<Travel> handle(const LeaveIslandEvent&) const
    {   
        return {};
    }

    TransitionTo<Travel> handle(const VisitShopEvent&) const
    {
        return {};
    }

    TransitionTo<Leave> handle(const LeaveGameEvent&) const
    {
        return {};
    }

};

class Travel
{


};

class Merchandise
{

};

class Finalize
{

};

class Leave
{

};


class GameV2 : private StateMachine<Initialize, Travel, Merchandise, Finalize>
{
public:
    void init(){
        std::cout<<"Initialize\n";
        
    }


};
