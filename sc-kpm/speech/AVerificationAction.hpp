/*
* This source file is part of an OSTIS project. For the latest info, see http://ostis.net
* Distributed under the MIT License
* (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
*/

#pragma once

#include "sc-memory/cpp/kpm/sc_agent.hpp"
#include "sc-memory/cpp/sc_struct.hpp"

#include "AVerificationAction.generated.hpp"

#include<vector>

using namespace std;

namespace speech
{

class AVerificationAction : public ScAgent
{
    SC_CLASS(Agent, Event(keynode_question_initiated, ScEvent::Type::AddOutputEdge))
    SC_GENERATED_BODY()

    SC_PROPERTY(Keynode("question_initiated"), ForceCreate)
    static ScAddr keynode_question_initiated;

    SC_PROPERTY(Keynode("action_of_verifying_the_desired_structure"), ForceCreate)
    static ScAddr keynode_action_verifying;

    SC_PROPERTY(Keynode("nrel_performer_class"), ForceCreate)
    static ScAddr keynode_nrel_performer_class;

    SC_PROPERTY(Keynode("nrel_object_class"), ForceCreate)
    static ScAddr keynode_nrel_object_class;

    SC_PROPERTY(Keynode("nrel_performer"), ForceCreate)
    static ScAddr keynode_nrel_performer;

    SC_PROPERTY(Keynode("nrel_object"), ForceCreate)
    static ScAddr keynode_nrel_object;

    SC_PROPERTY(Keynode("incorrect_structure"), ForceCreate)
    static ScAddr keynode_incorrect_structure;

    SC_PROPERTY(Keynode("question_finished"), ForceCreate)
    static ScAddr keynode_action_finished;

    SC_PROPERTY(Keynode("nrel_inclusion"), ForceCreate)
    static ScAddr keynode_nrel_inclusion;

    SC_PROPERTY(Keynode("question"), ForceCreate)
    static ScAddr keynode_action;

private:
    bool checkClass(ScAddr elem, ScAddr set, ScAddr *superclass);

};

} // namespace speech
