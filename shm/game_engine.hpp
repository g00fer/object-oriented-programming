/**
 * \file
 * \author g00fer (bargot@o2.pl)
 * \brief Game engine. 
 * State machine proposal from https://sii.pl/blog/implementing-a-state-machine-in-c17/
 *
 * @date 2020-07-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once

#include <iostream>
#include <tuple>
#include <variant>
#include <functional>

template <typename... States>
class StateMachine
{
public:
    template <typename State>
    void transitionTo()
    {
        currentState = &std::get<State>(states);
    }

    template <typename Event>
    void handle(const Event& event)
    {
        auto passEventToState = [this, &event] (auto statePtr) {
            statePtr->handle(event).execute(*this);
        };
        std::visit(passEventToState, currentState);
    }

private:
    std::tuple<States...> states;
    std::variant<States*...> currentState{ &std::get<0>(states) };
};

template <typename State>
struct TransitionTo
{
    template <typename Machine>
    void execute(Machine& machine)
    {
        machine.template transitionTo<State>();
    }
};

struct Nothing
{
    template <typename Machine>
    void execute(Machine&)
    {
    }
};

