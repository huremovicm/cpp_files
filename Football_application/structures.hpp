#ifndef STRUCTURES_HPP_
#define STRUCTURES_HPP_

class Application;
#include "application.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <utility>

//////////////////////////////

//Funkcija za generisanje random vrijednosti int-a u odredjenom opsegu
int randrange(int low, int high)
{
    return rand() % (high - low + 1) + low;
}

// Struktura datum sa potrebnim operatorima
struct Date
{
    int day;
    int month;
    int year;

    friend std::ostream &operator<<(std::ostream &out, const Date &toPrint)
    {

        out << toPrint.day << "." << toPrint.month << "." << toPrint.year << ".";
        return out;
    }

    Date operator=(const Date &a)
    {
        day = a.day;
        month = a.month;
        year = a.year;

        return *this;
    }
};

// Struktura rezultat sa potrebnim operatorima
struct Result
{
    int home;
    int guest;

    friend std::ostream &operator<<(std::ostream &out, const Result &toPrint)
    {
        out << toPrint.home << " : " << toPrint.guest;
        return out;
    }

    Result operator=(const Result &b)
    {
        home = b.home;
        guest = b.guest;

        return *this;
    }
};
//////////////////////////////

//Struktura utakmica
struct Matches
{

    Team team1;
    Team team2;
    Referee mainReferee;
    Referee assistentReferee;
    Date date;
    Result result;
};

//Klasa Liga
class League
{
public:
    League() {}
    League(std::string name, std::string country) : name_(name), country_(country) {} //Konstruktor za kreiranje
                                                                                     //lige 
    void setTeam(const Team &t) // Setovanje tima
    {

        teams_.push_back(t);
    }
    void setReferee(const Referee &r) { referees_.push_back(r); } //Setovanje sudija

    std::vector<Referee> &getRefrees() { return referees_; }

    std::string getName() { return name_; }

    void pairsGeneration(); //dodano za generisanje parova

    void addNewTeam(Team &);
    void addReferee(Referee &);
    void addNewLeague();
    void playingMatches();
    void undoLastMatch();
    void teamInfo();
    void displayTable();
    void displayMatches();

    std::vector<std::pair<Team, Team>> pairs_; //vektor parova za utakmice

private:
    std::string name_;
    std::string country_;
    std::vector<Team> teams_;
    std::vector<Matches> matches_;
    std::vector<Referee> referees_; //dodano za sudije
};

std::vector<League> leagues_; //vektor liga za spremanje prilikom kreiranja liga

void League::addNewTeam(Team &newTeam)
{
    bool flag = false;
    for (size_t i = 0; i < teams_.size(); i++) //dodavanje tima i provjera u slucaju da se isti tim vec postoji
    {
        if (newTeam == teams_[i])
        {
            flag = true;
        }
    }
    if (flag == false)
    {
        setTeam(newTeam);
        std::cout << "TEAM ADDED!" << std::endl;
    }
    else
    {
        std::cout << "The club already exist!" << std::endl;
    }
}

void League::addReferee(Referee &newReferee)
{
    bool flag = false;
    for (size_t i = 0; i < getRefrees().size(); i++) //dodavanje sudije i provjera u slucaju da se isti tim vec postoji
    {
        if (newReferee == getRefrees()[i])
        {
            flag = true;
        }
    }
    if (flag == false)
    {
        setReferee(newReferee);
        std::cout << "REFEREE ADDED!" << std::endl;
    }
    else
    {
        std::cout << "The Referee already exist!" << std::endl;
    }
}

//Dodavanje lige
void League::addNewLeague()
{

    std::string name;
    std::string country;

    std::cout << "--------------------------" << std::endl;
    std::cout << "League name: ";
    std::cin >> name;

    std::cout << "League country: ";
    std::cin >> country;

    League tmp = League(name, country);
    leagues_.push_back(tmp);
}

//Generisanje tim parova za utakmice 
void League::pairsGeneration()
{

    for (size_t i = 0; i < teams_.size(); i++)
    {

        for (size_t j = 0; j < teams_.size(); j++)
        {

            if (teams_[i] == teams_[j])
            {
                continue;
            }
            else
            {
                pairs_.push_back(std::make_pair(teams_[i], teams_[j])); //push pair timova za utakmicu home - guest
                pairs_.push_back(std::make_pair(teams_[j], teams_[i])); //push pair timova za utakmicu obrnuto(svaki tim igra 2x sa dr. istim timom)
            }
        }

        for (size_t i = 0; i < pairs_.size(); i++) //random raspored utakmica
        {
            int r = rand() % pairs_.size();
            std::swap(pairs_[i], pairs_[r]);
        }
    }
}

//Odigravanje utakmica
void League::playingMatches()
{

    Matches match;
    std::vector<Date> dates;

    if (referees_.size() == 0) //provjera da li ima sudija
    {
        std::cout << "No Referees! Please enter the referees." << std::endl;
    }

    int numOfPairs = pairs_.size();
    int numOfDates = numOfPairs / 4; //najvise cetiri utakmice na jedan datum

    for (size_t i = 0; i <= numOfDates; i++) //random generisanje datuma
    {
        Date datetoPush;
        datetoPush.day = randrange(1, 30);
        datetoPush.month = randrange(1, 12);
        datetoPush.year = 2020;

        dates.push_back(datetoPush);
    }

    int counter = 0;
    int dateNum = -1;

    for (size_t j = 0; j < pairs_.size(); j++)
    {
        if (j % 4 == 0)
            dateNum++;
        std::cout << "-----------------" << std::endl;
        std::cout << "Date: " << dates[dateNum] << std::endl;

        match.team1 = pairs_[j].first;
        match.team2 = pairs_[j].second;
        match.date = dates[dateNum];

        //random generisnje sudija za utakmice
        Referee randomMainReferee = referees_[randrange(0, referees_.size() - 1)]; 
        Referee randomAssistentRefree = referees_[randrange(1, referees_.size() - 1)];

        while (randomAssistentRefree == randomMainReferee)//glavni sudija ne moze biti i pomocni sudija na istoj utakmici
        {
            randomAssistentRefree = referees_[randrange(0, referees_.size() - 1)];
        }

        match.mainReferee = randomMainReferee;
        match.assistentReferee = randomAssistentRefree;

        int home;
        int guest;

        //unos rez. utakmica
        std::cout << match.team1.name << " - " << match.team2.name << std::endl;
        std::cout << "Enter Match Result:  " << std::endl;
        std::cin >> home >> guest;

        //dodijela bodova u zavisnosti na ishod utakmice
        if (home > guest)
        {
            for (size_t i = 0; i < teams_.size(); i++)
            {
                if (teams_[i] == match.team1)
                    teams_[i].points = teams_[i].points + 3;
                else
                {
                    continue;
                }
            }
        }
        else if (home < guest)
        {
            for (size_t i = 0; i < teams_.size(); i++)
            {
                if (teams_[i] == match.team2)
                    teams_[i].points = teams_[i].points + 3;
                else
                {
                    continue;
                }
            }
        }
        else if (home == guest)
        {
            for (size_t i = 0; i < teams_.size(); i++)
            {
                if (teams_[i] == match.team2 || teams_[i] == match.team2)
                    teams_[i].points = teams_[i].points + 1;
                else
                {
                    continue;
                }
            }
        }
        Result tmp;
        tmp.home = home;
        tmp.guest = guest;

        match.result = tmp;
        for (size_t i = 0; i < teams_.size(); i++) //inkrement odigranih utakmica
        {
            if (teams_[i] == match.team1 || teams_[i] == match.team2)
                teams_[i].playedMatches = teams_[i].playedMatches + 1;
            else
            {
                continue;
            }
        }

        matches_.push_back(match);
    }
}

//Prikaz informacija o timovima
void League::teamInfo()

{
    //Formatiranje ispisa prikaza
    std::string name = "NAME           ";
    std::string country = "COUNTRY        ";
    std::string city = "CITY           ";
    std::string stadium = "STADIUM        ";
    std::string played = "PLAYED         ";
    std::string unplayed = "UNPLAYED       ";

    for (size_t i = 0; i < 90; i++)
    {
        std::cout << "=";
    }
    std::cout << std::endl;

    std::cout << name << country << city << stadium << played << unplayed << std::endl;
    for (size_t i = 0; i < 90; i++)
    {
        std::cout << "-";
    }
    std::cout << std::endl;

    for (auto it = teams_.begin(); it != teams_.end(); it++)
    {
        std::string aftername(15 - (it->name.size()), ' ');
        std::string aftercountry(15 - (it->country.size()), ' ');
        std::string aftercity(15 - (it->city.size()), ' ');
        std::string afterstadium(15 - (it->stadium.size()), ' ');

        std::cout << it->name << aftername << it->country << aftercountry << it->city << aftercity << it->stadium << afterstadium << it->playedMatches << "               " << it->unplayedMatches << std::endl;
    }
}

//Prikaz tabele
void League::displayTable()
{

    std::string name = "NAME           ";
    std::string points = "POINTS         ";

    //sortiranje od tima sa najvise bodova ka timu sa najmanj bodova
    sort(teams_.begin(), teams_.end(), [](const Team &a, const Team &b) { return a.points > b.points; });

    //formatiranje ispisa/prikaza
    for (size_t i = 0; i < 30; i++)
    {
        std::cout << "=";
    }
    std::cout << std::endl;

    std::cout << name << points << std::endl;
    for (size_t i = 0; i < 30; i++)
    {
        std::cout << "-";
    }
    std::cout << std::endl;

    for (auto it = teams_.begin(); it != teams_.end(); it++)
    {
        std::string aftername(15 - (it->name.size()), ' ');

        std::cout << it->name << aftername << it->points << std::endl;
    }
}

//Prikaz utakmica i ostalih informacija vezanih za utakmicu
void League::displayMatches()
{

    std::string home = "HOME           ";
    std::string result = "RESULT         ";
    std::string guest = "GUEST          ";
    std::string main = "MAIN REFEREE        ";
    std::string assistent = "ASSISTENT REFEREE   ";
    std::string date = "DATE           ";

    //Formatiranje ispisa/prikaza
    for (size_t i = 0; i < 96; i++)
    {
        std::cout << "=";
    }
    std::cout << std::endl;

    std::cout << home << result << guest << main << assistent << date << std::endl;
    for (size_t i = 0; i < 96; i++)
    {
        std::cout << "-";
    }
    std::cout << std::endl;

    for (auto it = matches_.begin(); it != matches_.end(); it++)
    {
        std::string afterhome(15 - (it->team1.name.size()), ' ');
        std::string afterresult(10, ' ');
        std::string afterguest(15 - (it->team2.name.size()), ' ');
        std::string aftermain(20 - (it->mainReferee.name.size() + 1 + it->mainReferee.surname.size()), ' ');
        std::string afterassistent(20 - (it->assistentReferee.name.size() + 1 + it->assistentReferee.surname.size()), ' ');

        std::cout << it->team1.name << afterhome << it->result << afterresult << it->team2.name << afterguest << it->mainReferee.name << " " << it->mainReferee.surname
                  << aftermain << it->assistentReferee.name << " " << it->assistentReferee.surname << afterassistent << it->date << std::endl;
    }
}

//Ponistavanje zadnje utakmice
void League::undoLastMatch()
{

    int lastIndex = matches_.size() - 1;
    //ako su domaci pobijedili
    if (matches_[lastIndex].result.home > matches_[lastIndex].result.guest)
    {

        for (size_t i = 0; i < teams_.size(); i++)
        {
            if (matches_[lastIndex].team1 == teams_[i])
            {
                teams_[i].points = teams_[i].points - 3; //oduzimanje bodova
                teams_[i].playedMatches--; //dekrement odigranih utakmica
            }
            else
            {
                continue;
            }
        }
    }
    //ako su gosti pobjedili
    else if (matches_[lastIndex].result.home < matches_[lastIndex].result.guest)
    {

        for (size_t i = 0; i < teams_.size(); i++)
        {
            if (matches_[lastIndex].team2 == teams_[i])
            {
                teams_[i].points = teams_[i].points - 3;
                teams_[i].playedMatches--;
            }
            else
            {
                continue;
            }
        }
    }
    //ako je utkamica zavrsila nerijeseno
    else if (matches_[lastIndex].result.home == matches_[lastIndex].result.guest)
    {

        for (size_t i = 0; i < teams_.size(); i++)
        {
            if (matches_[lastIndex].team1 == teams_[i] || matches_[lastIndex].team2 == teams_[i])
            {
                teams_[i].points = teams_[i].points - 1;
                teams_[i].playedMatches--;
            }
            else
            {
                continue;
            }
        }
    }

    matches_[lastIndex].team1.playedMatches--;
    matches_[lastIndex].team2.playedMatches--;

    matches_.pop_back(); //pop za zadnju utakmicu
}

#endif // !APPLICATION_HPP_