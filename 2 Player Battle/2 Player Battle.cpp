#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player
{
protected:
    int health;
    int base_damage;
    int Max_health;


public:

    int gethealth() { return health; }

    bool isalive() { return(health > 0); }

    virtual void take_damage(int damage) = 0;
    virtual void give_base_damage(Player* player) = 0;
    virtual void give_add_damage(Player* player) = 0;
    virtual void heal() = 0;
    string HeroName;
    virtual ~Player() {};
};

class Sigma : public Player
{
private:
    int Add_Damage;
    int Max_Add_Damage;
    int Mini_Add_Damage;
    int Healing;
    int Max_healing;
    int Mini_healing;

public:
    Sigma()
    {
        Max_health = 200;
        health = Max_health;
        base_damage = 10;
        Max_Add_Damage = 10;
        Mini_Add_Damage = 1;
        Max_healing = 5;
        Mini_healing = 1;
        HeroName = "Sigma";
    }

    void take_damage(int damage)
    {
        health -= damage;
        cout << "\n" << HeroName << " health after receiving damage " << health << "\n" << endl;
    }
    void give_base_damage(Player* player)
    {
        cout << " give damage of " << base_damage << endl;
        player->take_damage(base_damage);
    }
    void give_add_damage(Player* player)
    {
        Add_Damage = (rand() % (Max_Add_Damage - Mini_Add_Damage + 1)) + Mini_Add_Damage;
        cout << "\n" << HeroName << " gave additional damage " << Add_Damage << "\n" << endl;
        player->take_damage(Add_Damage);
    }
    void heal()
    {
        Healing = (rand() % (Max_healing - Mini_healing + 1)) + Mini_healing;
        health += Healing;
        if (health > Max_health)
        {
            cout << "\n" << HeroName << " have Full Health " << "\n" << endl;
        }
        else
        {
            cout << "\n" << HeroName << " got healing of " << Healing << " now Health is " << health << "\n" << endl;
        }
    }

    ~Sigma() {}

};

class Zenyatta : public Player
{
private:
    int Add_damage;
    int Max_add_damage;
    int Mini_add_damage;
    int Healing;
    int Max_healing;
    int Mini_healing;

public:
    Zenyatta()
    {
        Max_health = 100;
        health = Max_health;
        base_damage = 20;
        Max_add_damage = 20;
        Mini_add_damage = 5;
        Max_healing = 7;
        Mini_healing = 1;
        HeroName = "Zenyatta";
    }

    void take_damage(int damage)
    {
        health -= damage;
        cout << "\n" << HeroName << " after taking damage, health is " << health << "\n" << endl;
    }

    void give_base_damage(Player* player)
    {
        cout << "\n" << " give damage of " << base_damage << "\n" << endl;
        player->take_damage(base_damage);
    }
    void give_add_damage(Player* player)
    {
        Add_damage = (rand() % (Max_add_damage - Mini_add_damage + 1)) + Mini_add_damage;
        cout << "\n" << HeroName << " gave additional damage " << Add_damage << "\n" << endl;
        player->take_damage(Add_damage);
    }
    void heal()
    {
        Healing = (rand() % (Max_healing - Mini_healing + 1)) + Mini_healing;
        health += Healing;
        if (health > Max_health)
        {
            cout << "\n" << HeroName << " have Full Health " << health << "\n" << endl;
        }
        else
        {
            cout << "\n" << HeroName << " got healing of " << Healing << " now Health is " << health << "\n" << endl;
        }
    }
    ~Zenyatta() {}
};

class Symmetra : public Player
{
private:
    int Add_damage;
    int Max_add_damage;
    int Mini_add_damage;
    int Healing;
    int Max_healing;
    int Mini_healing;

public:
    Symmetra()
    {
        Max_health = 50;
        health = Max_health;
        base_damage = 30;
        Max_add_damage = 30;
        Mini_add_damage = 10;
        Max_healing = 7;
        Mini_healing = 1;
        HeroName = "Symmetra";
    }

    void take_damage(int damage)
    {
        health -= damage;
        cout << "\n" << HeroName << " after taking damage health is " << health << "\n" << endl;
    }

    void give_base_damage(Player* player)
    {
        cout << "\n" << " give damage of " << base_damage << "\n" << endl;
        player->take_damage(base_damage);

    }
    void give_add_damage(Player* player)
    {
        Add_damage = (rand() % (Max_add_damage - Mini_add_damage + 1)) + Mini_add_damage;
        cout << "\n" << HeroName << " gave additional damage " << Add_damage << "\n" << endl;
        player->take_damage(Add_damage);
    }
    void heal()
    {
        Healing = (rand() % (Max_healing - Mini_healing + 1)) + Mini_healing;
        health += Healing;
        if (health > Max_health)
        {
            cout << "\n" << HeroName << " have Full Health " << health << "\n" << endl;
        }
        else
        {
            cout << "\n" << HeroName << " got healing of " << Healing << " now Health is " << health << "\n" << endl;
        }
    }
    ~Symmetra() {}
};
class gameloop
{
public:
    void game()
    {
        char input;
        Player* player1 = heros(1);
        Player* player2 = heros(2);

        Player* PlayerOne = player1;
        Player* PlayerTwo = player2;

        bool isPlayerOneTurn = true;

        while ((PlayerOne->isalive()) && (PlayerTwo->isalive()))
        {
            if (isPlayerOneTurn) {
                cout << "______________________________________________________" << endl;
                cout << "\n" << PlayerOne->HeroName << " press 'A' to attack " << PlayerTwo->HeroName << " or press 'H' to heal" << "\n" << endl;
                cin >> input;
                if (input == 'A' || input == 'a') {
                    PlayerOne->give_base_damage(PlayerTwo);
                    PlayerOne->give_add_damage(PlayerTwo);
                }
                else if (input == 'H' || input == 'h') {
                    PlayerOne->heal();
                }
            }
            else {
                cout << "\n" << PlayerTwo->HeroName << " press 'A' to attack " << PlayerOne->HeroName << " or press 'H' to heal" << "\n" << endl;
                cin >> input;
                if (input == 'A' || input == 'a') {
                    PlayerTwo->give_base_damage(PlayerOne);
                    PlayerTwo->give_add_damage(PlayerOne);
                }
                else if (input == 'H' || input == 'h') {
                    PlayerTwo->heal();
                }
            }

            isPlayerOneTurn = !isPlayerOneTurn;
        }

        if (!PlayerOne->isalive())
        {
            cout << PlayerTwo->HeroName << " wins , game over !!!! " << endl;
        }
        else if (!PlayerTwo->isalive())
        {
            cout << PlayerOne->HeroName << " wins , game over !!!! " << endl;
        }
    }


    Player* heros(int i)
    {
        int heros;
        Player* player = nullptr;

        cout << "Hero" << i << " Select your Hero - \n1. Sigma \n2. Zenyatta \n3. Symmetra"
            << endl;
        cout << "______________________________________________________" << endl;
        cin >> heros;

        switch (heros)
        {
        case 1:
            cout << "\n" "Sigma, a Dutch scientist have ability like Hyperspheres, Accretion & Kinetic Grasp. \nHighlights (High Health, Low Damage, Low Healing.)""\n" << endl;

            player = new Sigma();
            break;
        case 2:
            cout << "\n" "Zenyatta, a Wandering guru have ability like Snap Kick, Orb of Destruction & Orb of Harmony. \nHighlights (Avg Health, Avg Damage, Avg Healing.)""\n" << endl;
            player = new Zenyatta();
            break;
        case 3:
            cout << "\n""Symmetra, an Indian Architect have ability like Photon Projector, Sentry Turret & Teleporter. \nHighlights (Avg Health, Avg Damage, Avg Healing.)""\n" << endl;
            player = new Symmetra();
            break;
        }

        return player;
    }
    ~gameloop() {}
};

int main()
{
    cout << "\n Welcome to OVERWATCH 1 v 1" << endl;

    cout << "\nRules" << endl;

    cout << "\n1. Each Player has only one turn at a time" << endl;
    cout << "\n2. Each Player has different damage, additional damage and heal" << endl;
    cout << "\n3. When Player's health goes below 0, the player dies" << endl;
    cout << "\n4. Player can either attack by pressing 'a' or heal by pressing 'h', at each turn" << endl;
    cout << "______________________________________________________" << endl;

    gameloop gameplay;
    gameplay.game();

    return 0;
}
