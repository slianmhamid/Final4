
#include "MatamStory.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Players/Warrior.h"
#include "Players/Magician.h"
#include "Players/Archer.h"
#include "Players/RiskTaking.h"
#include "Players/Responsible.h"
#include "Events/Encounter.h"
#include "Events/SolarEclipse.h"
#include "Events/PotionsMerchant.h"
//#include "Event.h"

static const int MAXLEN = 15;
static const int MINLEN = 3;
static const int MINPLAYER = 2;
static const int MAXPLAYER = 6;


MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) {
    std::deque<std::string> tmp;
    streamToDeque(eventsStream,tmp);
    createEvents(tmp);
    createPlayers(playersStream);

    winner = nullptr;
    // for (shared_ptr<Player> &player : m_players) {
    //    LeaderBoard.insert(player);
    // }
    this->m_turnIndex = 1;
}
void MatamStory::createPlayers(std::istream &playersStream) {
    string name,job,character;
    shared_ptr<Job> j;
    shared_ptr<CharacterType> c;

    while(playersStream >> name)
    {
        if(name.length()<MINLEN|| name.length()>MAXLEN || !AreLetters(name)){
            throw std::runtime_error("Invalid Players File");
        }
        if(!(playersStream >> job >> character)){
            throw std::runtime_error("Invalid Players File");
        }
        try {
            j = std::move(createJob(job));
            c = std::move(createCharacter(character));
            m_players.push_back(std::make_shared<Player>(Player(name, j, c)));
        }catch (...){
            throw std::runtime_error("Invalid Players File");
        }
    }
    if (m_players.size()>MAXPLAYER||m_players.size()<MINPLAYER){
        throw std::runtime_error("Invalid Players File");
    }
}

shared_ptr<Job> MatamStory ::createJob(const std::string &job) {
    if(job == "Warrior"){
        return std::make_shared<Warrior>(Warrior(job));
    }
    else if(job == "Magician"){
        return std::make_shared<Magician>(Magician(job));
    }
    else if(job == "Archer"){
        return std::make_shared<Archer>(Archer(job));
    }
    else {
        throw std::runtime_error("Invalid Players File");
    }
}

shared_ptr<CharacterType> MatamStory::createCharacter(const std::string &character) {
    if(character == "RiskTaking"){
        return std ::make_shared<RiskTaking>(RiskTaking(character));
    }
    else if(character == "Responsible"){
        return std ::make_shared<Responsible>(Responsible(character));
    }
    else throw std::runtime_error("Invalid Players File");
}

void MatamStory::createEvents(std::deque<string> &words){
    for(int index = 0; index < static_cast<int>(words.size()); ++index){
        if(words[index] != "Pack"){
            m_events.push_back(createNonPack(words[index]));
        } else{
            m_events.push_back(createPack(words,index));
            index--;
        }
    }
    if (m_events.size() < 2) {
        throw std::runtime_error("Invalid Events File");
    }
}

shared_ptr<Pack> MatamStory::createPack(const std::deque<std::string> & words,int &index){
    unsigned int tmp = index + 1;
    const std::string &eventStr = words[tmp];
    for (char ch : eventStr) {
        if (ch == '.') {
            throw std::runtime_error("Invalid Events File");
        }
    }
    unsigned int length = std::stoi(words[++index]);
    if (length < 2) {
        throw std::runtime_error("Invalid Events File");
    }
    std::vector<std::shared_ptr<Encounter>> packMembers;
    ++index;
    for (unsigned int i = 0; i < length; ++i) {
        if (index >= static_cast<int>(words.size())) {
            throw std::runtime_error("Invalid Events File");
        }
        if (words[index] == "Pack") {
            std::shared_ptr<Pack> nestedPack = createPack(words, index);
            const auto &nestedMembers = nestedPack->getEncounters();
            packMembers.insert(packMembers.end(), nestedMembers.begin(), nestedMembers.end());
        } else {
            packMembers.push_back(createEncounter(words[index]));
            ++index;
        }
    }
    return std::make_shared<Pack>(Pack(packMembers));
}

shared_ptr<Event> MatamStory::createNonPack(const std::string &event) {
    if(event == "Snail"){
        return std::make_shared<Snail>(Snail());
    }else if(event == "Slime"){
        return std::make_shared<Slime>(Slime());
    }else if(event == "Balrog"){
        return std::make_shared<Balrog>(Balrog());
    }else if(event == "SolarEclipse"){
        return std::make_shared<SolarEclipse>(SolarEclipse());
    }else if(event == "PotionsMerchant"){
        return std::make_shared<PotionsMerchant>(PotionsMerchant());
    }
    throw std::runtime_error("Invalid Events File");
}
std::shared_ptr<Encounter> MatamStory::createEncounter(const std::string &event) {
    if (event == "Snail") {
        return std::make_shared<Snail>();
    } else if (event == "Slime") {
        return std::make_shared<Slime>();
    } else if (event == "Balrog") {
        return std::make_shared<Balrog>();
    }
    throw std::runtime_error("Invalid Events File");

}
void MatamStory::streamToDeque(std::istream &stream,std::deque<string> &words) {
    string word;
    while (stream >> word) {
        words.push_back(word);
    }
}

void MatamStory::playTurn(Player& player) {
    shared_ptr<Event> currEvent = m_events[(m_turnIndex -1) % m_events.size() ];
    printTurnDetails(m_turnIndex,player,*currEvent);
    int res = currEvent->applyEffect(player);
    printTurnOutcome(currEvent->getResult(player,res));
    /**
     * Steps to implement (there may be more, depending on your design):
     * 1. Get the next event from the events list
     * 2. Print the turn details with "printTurnDetails"
     * 3. Play the event
     * 4. Print the turn outcome with "printTurnOutcome"
    */
    m_turnIndex++;
}

void MatamStory::playRound() {
    printRoundStart();

    for(const shared_ptr<Player>& player1 : m_players){
        if (player1->canPlay()) {
            playTurn(*player1);
            if(player1->getHealthPoints() <= 0){
                player1->setStatus();
            }
        }
    }


    /*===== TODO: Play a turn for each player =====*/

    /*=============================================*/

    printRoundEnd();

    printLeaderBoardMessage();
    std::set<shared_ptr<Player>, PlayerCompare> LeaderBoard;
    for (const shared_ptr<Player>& player1 :m_players) {
        LeaderBoard.insert(player1);
    }

    unsigned int i =1;
    for (const shared_ptr<Player>& player1 :LeaderBoard) {
        printLeaderBoardEntry(i,*player1);
        i++;
    }
    winner = *LeaderBoard.begin();


    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/

    /*=======================================================================================*/

    printBarrier();
}

bool MatamStory::isGameOver() const {
    if(winner) {
        if (winner->isMaxLevel()) {
            return true;
        }
    }
    if (areAllElemenated()) {
        return true;
    }
    return false;
}

/*===== TODO: Implement the game over condition =====*/
/*===================================================*/

void MatamStory::play() {
    printStartMessage();

//        unsigned int j =1;
//        for (const shared_ptr<Player>& player1 :LeaderBoard) {
//            printLeaderBoardEntry(j,*player1);
//            j++;
//        }

    unsigned int i = 1;
    for (const shared_ptr<Player> &player1: m_players) {
        printStartPlayerEntry(i, *player1);
        i++;
    }
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/

    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    if (!winner->isMaxLevel() && areAllElemenated()) {// need to change
        printNoWinners();
    } else {
        printWinner(*winner);
    }
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/

    /*========================================================================*/
}

bool MatamStory::areAllElemenated()const {
    for (const auto &player: m_players) {
        if (player->getHealthPoints() > 0) {
            return false;
        }
    }
    return true;
}
bool MatamStory::AreLetters(const std::string& name) const {
    for (const auto& c : name) {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            return false;
        }
    }
    return true;
}