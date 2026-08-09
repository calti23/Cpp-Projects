#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Ability {
    string name;
    int manaCost;
    int power;
    int type; // 1 = Attack, 2 = Heal
};

struct Potion {
    string name;
    int healAmount;
    int quantity;
};

struct MainCharacter {
    string char_name;

    int hp = 1000;
    int max_hp = 1000;

    int xp = 0;
    int level = 1;
    int level_up_xp = 1000;

    int mp = 500;
    int max_mp = 500;

    int gold = 500;

    int attack = 100;
    int defence = 50;

    vector<Ability> abilities;
    vector<Potion> potions;
};

struct Villain {
    string char_name;

    int hp = 1000;
    int max_hp = 1000;

    int xp = 500;
    int level = 5;

    int mp = 400;

    int gold = 700;

    int attack = 100;
    int defence = 50;
};

int calculateDamage(int attack, int defence)
{
    int damage = attack - defence;

    if (damage < 1)
        damage = 1;

    return damage;
}

void levelUp(MainCharacter& player)
{
    while (player.xp >= player.level_up_xp)
    {
        player.xp -= player.level_up_xp;

        player.level++;

        player.level_up_xp += 500;

        player.max_hp += 200;
        player.max_mp += 100;

        player.attack += 50;
        player.defence += 30;

        player.hp = player.max_hp;
        player.mp = player.max_mp;

        cout << "\n=============================\n";
        cout << "       YOU LEVELLED UP!\n";
        cout << "=============================\n";

        cout << "New Level: " << player.level << endl;
        cout << "New Max HP: " << player.max_hp << endl;
        cout << "New Max MP: " << player.max_mp << endl;
        cout << "New Attack: " << player.attack << endl;
        cout << "New Defence: " << player.defence << endl;
    }
}

void showCharacterInformation(const MainCharacter& player)
{
    cout << "\n------ CHARACTER INFORMATION ------\n";

    cout << "Name       : " << player.char_name << endl;
    cout << "Level      : " << player.level << endl;

    cout << "HP         : "
         << player.hp << "/" << player.max_hp << endl;

    cout << "MP         : "
         << player.mp << "/" << player.max_mp << endl;

    cout << "XP         : "
         << player.xp << "/" << player.level_up_xp << endl;

    cout << "Gold       : " << player.gold << endl;
    cout << "Attack     : " << player.attack << endl;
    cout << "Defence    : " << player.defence << endl;
}

void useAbility(MainCharacter& player, Villain& enemy)
{
    if (player.abilities.empty())
    {
        cout << "You don't have any abilities!\n";
        return;
    }

    cout << "\n------ ABILITIES ------\n";

    for (int i = 0; i < player.abilities.size(); i++)
    {
        cout << i + 1 << " - "
             << player.abilities[i].name
             << " | Mana: "
             << player.abilities[i].manaCost
             << " | Power: "
             << player.abilities[i].power
             << endl;
    }

    cout << "0 - Back\n";

    int choice;
    cout << "Choose Ability: ";
    cin >> choice;

    if (choice == 0)
        return;

    if (choice < 1 || choice > player.abilities.size())
    {
        cout << "Invalid ability!\n";
        return;
    }

    Ability& ability = player.abilities[choice - 1];

    if (player.mp < ability.manaCost)
    {
        cout << "Not enough MP!\n";
        return;
    }

    player.mp -= ability.manaCost;

    cout << "\nYou used " << ability.name << "!\n";

    if (ability.type == 1)
    {
        int damage = calculateDamage(
            ability.power,
            enemy.defence
        );

        enemy.hp -= damage;

        cout << "You dealt "
             << damage
             << " damage!\n";
    }

    else if (ability.type == 2)
    {
        player.hp += ability.power;

        if (player.hp > player.max_hp)
            player.hp = player.max_hp;

        cout << "You recovered "
             << ability.power
             << " HP!\n";
    }

    cout << "Enemy HP: "
         << enemy.hp << endl;

    cout << "Your MP: "
         << player.mp << endl;
}

void usePotion(MainCharacter& player)
{
    if (player.potions.empty())
    {
        cout << "You don't have any potions!\n";
        return;
    }

    cout << "\n------ POTIONS ------\n";

    for (int i = 0; i < player.potions.size(); i++)
    {
        cout << i + 1 << " - "
             << player.potions[i].name
             << " | Heal: "
             << player.potions[i].healAmount
             << " | Quantity: "
             << player.potions[i].quantity
             << endl;
    }

    cout << "0 - Back\n";

    int choice;
    cout << "Choose Potion: ";
    cin >> choice;

    if (choice == 0)
        return;

    if (choice < 1 || choice > player.potions.size())
    {
        cout << "Invalid potion!\n";
        return;
    }

    Potion& potion = player.potions[choice - 1];

    if (potion.quantity <= 0)
    {
        cout << "You don't have this potion anymore!\n";
        return;
    }

    player.hp += potion.healAmount;

    if (player.hp > player.max_hp)
        player.hp = player.max_hp;

    potion.quantity--;

    cout << "\nPotion used!\n";
    cout << "Your new HP: "
         << player.hp << "/" << player.max_hp
         << endl;
}

void inventoryMenu(MainCharacter& player)
{
    cout << "\n========== INVENTORY ==========\n";

    cout << "\nABILITIES:\n";

    for (int i = 0; i < player.abilities.size(); i++)
	{
    cout << "- "
         << player.abilities[i].name
         << endl;
	}

    cout << "\nPOTIONS:\n";

    for (int i = 0; i < player.potions.size(); i++)
	{
    cout << "- "
         << player.potions[i].name
         << " x"
         << player.potions[i].quantity
         << endl;
	}
}

void rest(MainCharacter& player)
{
    player.hp += 200;

    if (player.hp > player.max_hp)
        player.hp = player.max_hp;

    player.mp += 200;

    if (player.mp > player.max_mp)
        player.mp = player.max_mp;

    cout << "\nYOU DECIDED TO REST!\n";

    cout << "Your HP: "
         << player.hp << "/"
         << player.max_hp << endl;

    cout << "Your MP: "
         << player.mp << "/"
         << player.max_mp << endl;
}

bool battle(MainCharacter& player)
{
    Villain enemy;

    cout << "\nEnter Villain's Name: ";
    cin >> enemy.char_name;

    cout << "\n================================\n";
    cout << "         BATTLE START!\n";
    cout << "================================\n";

    cout << enemy.char_name
         << " appeared!\n";

    while (true)
    {
        cout << "\n--------------------------------\n";

        cout << player.char_name
             << " HP: "
             << player.hp << "/"
             << player.max_hp << endl;

        cout << player.char_name
             << " MP: "
             << player.mp << "/"
             << player.max_mp << endl;

        cout << enemy.char_name
             << " HP: "
             << enemy.hp << "/"
             << enemy.max_hp << endl;

        cout << "\n1 - Attack\n";
        cout << "2 - Use Ability\n";
        cout << "3 - Use Potion\n";
        cout << "4 - Escape\n";

        int choice;

        cout << "Your Decision: ";
        cin >> choice;

        bool playerActionCompleted = false;

        switch (choice)
        {
            case 1:
            {
                int damage = calculateDamage(
                    player.attack,
                    enemy.defence
                );

                enemy.hp -= damage;

                cout << "\nYou attacked "
                     << enemy.char_name
                     << "!\n";
                cout << "Damage: "
                     << damage << endl;

                playerActionCompleted = true;
                break;
            }
            case 2:
            {
                int oldEnemyHP = enemy.hp;
                int oldPlayerHP = player.hp;
                int oldMP = player.mp;

                useAbility(player, enemy);

                if (enemy.hp != oldEnemyHP ||
                    player.hp != oldPlayerHP ||
                    player.mp != oldMP)
                {
                    playerActionCompleted = true;
                }

                break;
            }
            case 3:
            {
                int oldHP = player.hp;

                usePotion(player);

                if (player.hp != oldHP)
                {
                    playerActionCompleted = true;
                }

                break;
            }
            case 4:
            {
                cout << "\nYou escaped from the battle!\n";
                return true;
            }

            default:
            {
                cout << "\nInvalid choice!\n";
                break;
            }
        }
        if (!playerActionCompleted)
            continue;

        if (enemy.hp <= 0)
        {
            cout << "\n================================\n";
            cout << "       ENEMY DESTROYED!\n";
            cout << "          YOU WIN!\n";
            cout << "================================\n";

            player.xp += enemy.xp;
            player.gold += enemy.gold;

            cout << "You gained "
                 << enemy.xp
                 << " XP!\n";

            cout << "You gained "
                 << enemy.gold
                 << " Gold!\n";

            levelUp(player);

            return true;
        }

        int enemyDamage = calculateDamage(
            enemy.attack,
            player.defence
        );

        player.hp -= enemyDamage;

        cout << "\n"
             << enemy.char_name
             << " attacked you!\n";

        cout << "You received "
             << enemyDamage
             << " damage!\n";

        if (player.hp <= 0)
        {
            player.hp = 0;
            cout << "\n================================\n";
            cout << "          GAME OVER\n";
            cout << "================================\n";
            return false;
        }
        cout << "Your HP: "
             << player.hp
             << "/" << player.max_hp
             << endl;
    }
    return true;
}

int main()
{
    srand(time(NULL));

    MainCharacter main_gamer;

    cout << "Enter Character Name: ";
    cin >> main_gamer.char_name;

    // Starting abilities
    main_gamer.abilities.push_back(
        {"Fireball", 50, 200, 1}
    );

    main_gamer.abilities.push_back(
        {"Power Strike", 30, 300, 1}
    );

    main_gamer.abilities.push_back(
        {"Heal", 70, 250, 2}
    );

    // Starting potion
    main_gamer.potions.push_back(
        {"Health Potion", 300, 5}
    );

    int main_menu_code;

    while (true)
    {
        cout << "\n====================================\n";
        cout << " Welcome "
             << main_gamer.char_name
             << " to RPG Game!\n";
        cout << "====================================\n";

        cout << "1 - Explore\n";
        cout << "2 - War\n";
        cout << "3 - Inventory\n";
        cout << "4 - Character Informations\n";
        cout << "5 - Market\n";
        cout << "6 - Rest\n";
        cout << "7 - Quit\n";

        cout << "\nPlease Enter Your Decision (1-7): ";
        cin >> main_menu_code;

        switch (main_menu_code)
        {
            case 1:
            {
                cout << "\nYou explored the area...\n";
                cout << "Nothing interesting happened.\n";
                break;
            }
            case 2:
            {
                bool survived = battle(main_gamer);

                if (!survived)
                    return 0;
                break;
            }
            case 3:
            {
                inventoryMenu(main_gamer);
                break;
            }

            case 4:
            {
                showCharacterInformation(main_gamer);
                break;
            }
            case 5:
            {
                cout << "\nMarket system is under development.\n";
                break;
            }
            case 6:
            {
                rest(main_gamer);
                break;
            }

            case 7:
            {
                cout << "\nGood Luck Gamer!\n";
                cout << "Thanks for playing!\n";
                return 0;
            }
            default:
            {
                cout << "\nInvalid number!\n";
                break;
            }
        }
    }

    return 0;
}
