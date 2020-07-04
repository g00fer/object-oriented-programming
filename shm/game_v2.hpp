#pragma once

#include "game_engine.hpp"
#include "map.hpp"
#include "store.hpp"
#include "ship.hpp"
#include "player.hpp"
#include "time.hpp"
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


constexpr uint32_t DEFAULT_CAPACITY = 1000;
constexpr uint32_t DEFAULT_MAXCREW  = 100;
constexpr uint32_t DEFAULT_SPEED = 10;
const std::string DEFAULT_NAME = "BlackPearl";
constexpr uint32_t DEFAULT_ID = 1;


class GameV2 : public Time, private StateMachine<Initialize, Travel, Merchandise, Finalize>
{
public:
    GameV2 (uint32_t days, uint32_t target, uint32_t startmoney) 
    : deadline_(days), targetgold_(target)
    {
        map_ = std::make_unique<Map>(this);
        player_ = std::make_unique<Player>(std::make_shared<Ship>(DEFAULT_CAPACITY, DEFAULT_MAXCREW, DEFAULT_SPEED, DEFAULT_NAME, DEFAULT_ID, this), 
            startmoney, DEFAULT_CAPACITY);
        
        store_= std::make_unique<Store>(this);

    }
    void init(){
        std::cout<<"Initializing...\n";

    }

private:
    const uint32_t deadline_;
    const uint32_t targetgold_;

    std::unique_ptr<Player> player_; 
    std::unique_ptr<Map> map_;      
    std::unique_ptr<Store> store_;
};
