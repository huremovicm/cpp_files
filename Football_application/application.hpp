#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include <iostream>

// Team structure with operators
struct Team
{
    std::string name;
    std::string country;
    std::string city;
    std::string stadium;

    int points;

    int playedMatches;
    int unplayedMatches;

    bool operator==(const Team &a)
    {
        bool tmp = (name == a.name && city == a.city);

        if (tmp == false)
            return false;
        else
            return tmp;
    }

    Team operator=(const Team &b)
    {
        name = b.name;
        country = b.country;
        city = b.city;
        stadium = b.stadium;
        points = b.points;
        playedMatches = b.playedMatches;
        unplayedMatches = b.unplayedMatches;

        return *this;
    }

    operator bool() { return true || false; }

    Team() {}

    Team(std::string club)
    {

        name = club;

        std::cout << "Team Country: ";
        std::cin >> country;

        std::cout << "Team City: ";
        std::cin >> city;

        std::cout << "Team Stadium: ";
        std::cin >> stadium;

        playedMatches = 0;
        unplayedMatches = 0;

        points = 0;
    }
};

// Referee structure with operators
struct Referee
{

    std::string name;
    std::string surname;
    std::string country;

    bool operator==(const Referee &a)
    {
        bool tmp = (name == a.name && surname == a.surname && country == a.country);
        if (tmp == false)
            return false;
        else
            return tmp;
    }

    Referee operator=(const Referee &b)
    {
        name = b.name;
        surname = b.surname;
        country = b.country;

        return *this;
    }

    Referee() {}

    Referee(std::string person)
    {

        name = person;

        std::cout << "Refree Surname: ";
        std::cin >> surname;

        std::cout << "Refree Country: ";
        std::cin >> country;
    }

    operator bool() { return true || false; }
};

// Application methods
class Application
{
public:
    virtual void addNewTeam(Team &) = 0;
    virtual void addReferee(Referee &) = 0;
    virtual void addNewLeague() = 0;
    virtual void playingMatches() = 0;
    virtual void undoLastMatch() = 0;
    virtual void teamInfo() = 0;
    virtual void displayTable() = 0;
    virtual void displayMatches() = 0;

    virtual void pairsGeneraation() = 0;
};

#endif // !APPLICATION_HPP_