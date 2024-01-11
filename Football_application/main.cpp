#include "application.hpp"
#include "structures.hpp"

// Menu function
void displayMenu()
{

    std::cout << "=======================================" << std::endl;
    std::cout << "=                 MENU                =" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "1. Dodavanje nove lige                =" << std::endl;
    std::cout << "2. Dodavanje novog tima               =" << std::endl;
    std::cout << "3. Dodavanje novog suca               =" << std::endl;
    std::cout << "4. Odigravanje utakmica               =" << std::endl;
    std::cout << "5. Informacije o timovima             =" << std::endl;
    std::cout << "6. Prikaz tabele                      =" << std::endl;
    std::cout << "7. Prikaz utakmica                    =" << std::endl;
    std::cout << "8. Ponistavanje zadnje utakmice       =" << std::endl;
    std::cout << "9. MENU                               =" << std::endl;
    std::cout << "0. Exit                               =" << std::endl;
    std::cout << "=======================================" << std::endl;
}

// Main function
int main(int argc, char const *argv[])
{
    int input;
    displayMenu();

    // Switch - case menu
    while (std::cin >> input)
    {
        switch (input)
        {

        // Add league
        case 1:
        {

            League L;
            L.addNewLeague();
            std::cout << "NEW LEAGUE ADDED!" << std::endl;
            std::cout << std::endl;

            std::cout << "For MENU type: 9" << std::endl;
            break;
        }

        // Add team
        case 2:
        {
            std::string club1;
            std::string league;

            std::cout << "Choose league: " << std::endl;
            for (size_t i = 0; i < leagues_.size(); i++)
            {

                std::cout << leagues_[i].getName() << std::endl;
            }

            std::cin >> league;

            for (size_t i = 0; i < leagues_.size(); i++)
            {

                if (league == leagues_[i].getName())
                {
                    std::cout << "--------------------------" << std::endl;
                    std::cout << "Team Name: ";
                    std::cin >> club1;
                    Team t1(club1);
                    leagues_[i].addNewTeam(t1);
                }
                else
                {
                    continue;
                }
            }
            std::cout << std::endl;

            std::cout << "For MENU type: 9" << std::endl;

            break;
        }

        // Add referee
        case 3:
        {
            std::string referee1;
            std::string league;

            std::cout << "Choose league: " << std::endl;
            for (size_t i = 0; i < leagues_.size(); i++)
            {

                std::cout << leagues_[i].getName() << std::endl;
            }

            std::cin >> league;

            for (size_t i = 0; i < leagues_.size(); i++)
            {

                if (league == leagues_[i].getName())
                {
                    std::cout << "--------------------------" << std::endl;
                    std::cout << "Referee Name: ";
                    std::cin >> referee1;
                    Referee r1(referee1);
                    leagues_[i].addReferee(r1);
                }
                else
                {
                    continue;
                }
            }
            std::cout << std::endl;

            std::cout << "For MENU type: 9" << std::endl;

            break;
        }

        // Generate pairs
        case 4:
        {
            std::string league;

            std::cout << "Choose league: " << std::endl;
            for (size_t i = 0; i < leagues_.size(); i++)
            {

                std::cout << leagues_[i].getName() << std::endl;
            }

            std::cin >> league;

            for (size_t i = 0; i < leagues_.size(); i++)
            {

                if (league == leagues_[i].getName())
                {

                    leagues_[i].pairsGeneration();
                    leagues_[i].playingMatches();
                }
                else
                {
                    continue;
                }
            }
            std::cout << "END OF ALL MATCHES!" << std::endl;
            std::cout << std::endl;
            std::cout << "For MENU type: 9" << std::endl;
            break;
        }

        // Show info about teams
        case 5:
        {
            std::string league;

            std::cout << "Choose league: " << std::endl;
            for (size_t i = 0; i < leagues_.size(); i++)
            {

                std::cout << leagues_[i].getName() << std::endl;
            }

            std::cin >> league;

            for (size_t i = 0; i < leagues_.size(); i++)
            {

                if (league == leagues_[i].getName())
                {

                    leagues_[i].teamInfo();
                }
                else
                {
                    continue;
                }
            }
            std::cout << std::endl;
            std::cout << "For MENU type: 9" << std::endl;
            break;
        }

        // Show table
        case 6:
        {
            std::string league;

            std::cout << "Choose league: " << std::endl;
            for (size_t i = 0; i < leagues_.size(); i++)
            {

                std::cout << leagues_[i].getName() << std::endl;
            }

            std::cin >> league;

            for (size_t i = 0; i < leagues_.size(); i++)
            {

                if (league == leagues_[i].getName())
                {

                    leagues_[i].displayTable();
                }
                else
                {
                    continue;
                }
            }
            std::cout << std::endl;
            std::cout << "For MENU type: 9" << std::endl;
            break;
        }

        // Show matches and results
        case 7:
        {
            std::string league;

            std::cout << "Choose league: " << std::endl;
            for (size_t i = 0; i < leagues_.size(); i++)
            {

                std::cout << leagues_[i].getName() << std::endl;
            }

            std::cin >> league;

            for (size_t i = 0; i < leagues_.size(); i++)
            {

                if (league == leagues_[i].getName())
                {

                    leagues_[i].displayMatches();
                }
                else
                {
                    continue;
                }
            }
            std::cout << std::endl;
            std::cout << "For MENU type: 9" << std::endl;
            break;
        }

        // Cancel last match
        case 8:
        {
            std::string league;

            std::cout << "Choose league: " << std::endl;
            for (size_t i = 0; i < leagues_.size(); i++)
            {

                std::cout << leagues_[i].getName() << std::endl;
            }

            std::cin >> league;

            for (size_t i = 0; i < leagues_.size(); i++)
            {

                if (league == leagues_[i].getName())
                {

                    leagues_[i].undoLastMatch();
                }
                else
                {
                    continue;
                }
            }
            std::cout << std::endl;
            std::cout << "For MENU type: 9" << std::endl;
            break;
        }
        case 9:
        {
            displayMenu();
            break;
        }

        case 0:
        {
            return 0;
        }
        }
    }
    return 0;
}
