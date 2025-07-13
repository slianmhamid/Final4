
#pragma once

#include <iostream>

#include "Players/Player.h"
#include "Events/Event.h"
//#include "specialEvents.h"
#include "Events/Encounter.h"
#include "Utilities.h"
#include <vector>
#include <memory>
#include <list>
#include <deque>
#include <set>

using std::vector;
using std::shared_ptr;
using std::list;

struct PlayerCompare {
    bool operator()(const shared_ptr<Player> &p1, const shared_ptr<Player> &p2) const {
        return *p1 > *p2;
    }
};

class MatamStory{
private:
    vector<shared_ptr<Event>> m_events;
    vector<shared_ptr<Player>> m_players;
    //  std::set<shared_ptr<Player>, PlayerCompare> LeaderBoard;
    shared_ptr<Player> winner;
    unsigned int m_turnIndex;

    /**
     * Playes a single turn for a player
     *
     * @param player - the player to play the turn for
     *
     * @return - void
    */
    void playTurn(Player& player);

    /**
     * Plays a single round of the game
     *
     * @return - void
    */
    void playRound();

    /**
     * Checks if the game is over
     *
     * @return - true if the game is over, false otherwise
    */
    bool isGameOver() const;


public:
    /**
     * Constructor of MatamStory class
     *
     * @param eventsStream - events input stream (file)
     * @param playersStream - players input stream (file)
     *
     * @return - MatamStory object with the given events and players
     *
    */
    MatamStory(std::istream& eventsStream, std::istream& playersStream);//done
    void createEvents(std::deque<string> &words);
    void createPlayers(std::istream& playersStream);//done
    shared_ptr<Job> createJob(const string& job);//done
    shared_ptr<CharacterType> createCharacter(const string& character);//done
    void streamToDeque(std::istream &stream,std::deque<string> &words);//done
    shared_ptr<Event> createNonPack(const string& event);//done
    shared_ptr<Pack> createPack(const std::deque<std::string> & deque_,int &index);
    std::shared_ptr<Encounter> createEncounter(const std::string &event);//done
    bool areAllElemenated()const;
    bool AreLetters(const string& name)const;


    /**
     * Plays the entire game
     *
     * @return - void
    */
    void play();
};