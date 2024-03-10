#include <iostream>
#include <string>

using namespace std;

struct spell // Structure to store the spells for the mage
{
    string name;
    int damage;
    int mana_cost;
};

class character // Base class for the characters
{
public:
    string name;
    int level;
    int health_points = 100;

    character() // Default constructor
    {
    }

    character(string n, int l) : name(n), level(l) // Constructor to initialize the character
    {
    }

    void display_info()
    {
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health  Points: " << health_points << endl;
    }
};

class warrior : public character // Derived class from character
{

public:
    int strength;
    int armor;
    int stamina;

    warrior() // Default constructor
    {
    }

    warrior(string n, int l, int s, int a, int st) // Constructor to initialize the warrior
    {
        character::name = n;
        character::level = l;
        stamina = st;
        strength = s;
        armor = a;
    }

    void battleWW(warrior &, warrior &); // Function to battle between two warriors
};

class mage : public character // Derived class from character
{
public:
    int intelligence;
    int mana;
    spell spells[5];

    mage() {} // Default constructor

    mage(string n, int l, int i, int m) // Constructor to initialize the mage
    {
        character::name = n;
        character::level = l;
        intelligence = i;
        mana = m;

        cout << "------------------- MAGE ARSENAL -------------------\n"; // To input the spells for the mage
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter spell " << i + 1 << ": ";
            cin.ignore();
            getline(cin, spells[i].name);
            cout << "Damage: ";
            cin >> spells[i].damage;
            cout << "Mana Cost: ";
            cin >> spells[i].mana_cost;
        }
    }

    friend void battleWM(warrior &, mage &); // Friend function to battle between warrior and mage
    void battleMM(mage &, mage &);           // Function to battle between two mages
};

class rogue : public character // Derived class from character
{
public:
    int agility;
    int evasion;
    int poison;

    rogue() {} // Default constructor

    rogue(string n, int l, int a, int e, int p) // Constructor to initialize the rogue
    {
        character::name = n;
        character::level = l;
        agility = a;
        evasion = e;
        poison = p;
    }

    friend void battleMR(mage &, rogue &);    // Friend function to battle between mage and rogue
    friend void battleWR(warrior &, rogue &); // Friend function to battle between warrior and rogue
    void battleRR(rogue &, rogue &);          // Function to battle between two rogues
};

void battleWM(warrior &w, mage &m) // Function to battle between warrior and mage
{

    cout << "\nBattle between Warrior and Mage" << endl; // Display the information of the warrior and mage
    cout << "\n-------------- WARRIOR --------------" << endl;
    w.display_info();
    cout << "Strength: " << w.strength << endl;
    cout << "Armor: " << w.armor << endl;
    cout << "Stamina: " << w.stamina << endl;

    cout << "\n-------------- MAGE --------------" << endl; // Display the information of the mage
    m.display_info();
    cout << "Intelligence: " << m.intelligence << endl;
    cout << "Mana: " << m.mana << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Spell " << i + 1 << ": " << m.spells[i].name << endl;
        cout << "Damage: " << m.spells[i].damage << endl;
        cout << "Mana Cost: " << m.spells[i].mana_cost << endl;
    }

    cout << "The battle begins!!!" << endl;

    bool wturn = false, mturn = false;

    if (w.strength > m.intelligence) // Check who will attack first
    {
        mturn = true;
        wturn = false;
    }
    else
    {
        wturn = true;
        mturn = false;
    }

    while (true)
    {

        if (wturn == false)
        {
            cout << "\n"
                 << w.name << "'s weapon lands a critical hit!"; // Display the attack of the warrior
            m.health_points -= w.strength * 0.5;
            cout << "\n-" << w.strength * 0.5 << " HP" << endl;
            w.strength -= (m.mana * 0.10);
            wturn = true;
            mturn = false;
        }
        if (mturn == false)
        {
            cout << "\n"
                 << m.name << " casts the "; // Display the attack of the mage
            int i = (rand() % 5) + 1;
            cout << m.spells[i].name << " !!!!" << endl;
            w.health_points -= (m.spells[i].damage / 2);
            cout << "\n-" << (m.spells[i].damage / 2) << " HP" << endl;
            w.armor -= (m.spells[i].damage / 2);
            m.mana -= m.spells[i].mana_cost;
            mturn = true;
            wturn = false;
        }

        if (w.strength < 5 || w.armor < 10 || w.health_points < 10) // Check if the warrior's strength is less than 5
        {
            cout << "\n"
                 << w.name << "'s attack failed...\n";
            cout << m.name << " casts a spell and " << w.name << " is forced to the ground!!" << endl;
            cout << "\nGAME OVER!! " << endl
                 << m.name << " wins this one!!" << endl;
            break;
        }
        if (m.mana < 5) // Check if the mage's mana is less than 5
        {
            cout << "\n"
                 << m.name << "'s attack failed...\n";
            cout << "No more mana left!!!\n";
            cout << w.name << " destroys " << m.name << " with thier weapon!!!!" << endl;
            cout << "\nGAME OVER!! " << w.name << " wins this one!!" << endl;
            break;
        }
    }
}

void battleWR(warrior &w, rogue &r) // Function to battle between warrior and rogue
{
    cout << "\nBattle between Warrior and Rogue" << endl;
    cout << "\n-------------- WARRIOR --------------" << endl;
    w.display_info();
    cout << "Strength: " << w.strength << endl;
    cout << "Armor: " << w.armor << endl;
    cout << "Stamina: " << w.stamina << endl;

    cout << "\n-------------- ROGUE --------------" << endl;
    r.display_info();
    cout << "Agility: " << r.agility << endl;
    cout << "Evasion: " << r.evasion << endl;
    cout << "Poison: " << r.poison << endl;

    cout << "The battle begins!!!" << endl;

    bool wturn = false, rturn = false;

    if (w.strength > r.agility)
    {
        rturn = true;
        wturn = false;
    }
    else
    {
        wturn = true;
        rturn = false;
    }

    while (true)
    {
        if (wturn == false)
        {
            cout << "\n"
                 << w.name << "'s weapon lands a critical hit!";
            r.health_points -= w.strength * 0.5;
            cout << "\n-" << w.strength * 0.5 << " HP" << endl;
            w.strength -= (r.evasion * 0.10);
            wturn = true;
            rturn = false;
        }
        if (rturn == false)
        {
            cout << "\n"
                 << r.name << " uses a poison attack!";
            w.health_points -= r.poison * 0.2;
            w.armor -= r.poison * 0.2;
            cout << "\n-" << r.poison * 0.2 << " HP" << endl;
            r.agility -= (w.armor * 0.05);
            rturn = true;
            wturn = false;
        }

        if (w.strength < 5)
        {
            cout << "\n"
                 << w.name << "'s attack failed...\n";
            cout << r.name << " dodges the attack and defeats " << w.name << "!" << endl;
            cout << "\nGAME OVER!! " << endl
                 << r.name << " wins this one!!" << endl;
            break;
        }
        if (r.agility < 5)
        {
            cout << "\n"
                 << r.name << "'s attack failed...\n";
            cout << w.name << " overpowers " << r.name << " with their weapon!" << endl;
            cout << "\nGAME OVER!! " << w.name << " wins this one!!" << endl;
            break;
        }
    }
}

void battleMR(mage &m, rogue &r) // Function to battle between mage and rogue
{
    cout << "\nBattle between Mage and Rogue" << endl;
    cout << "\n-------------- MAGE --------------" << endl;
    m.display_info();
    cout << "Intelligence: " << m.intelligence << endl;
    cout << "Mana: " << m.mana << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Spell " << i + 1 << ": " << m.spells[i].name << endl;
        cout << "Damage: " << m.spells[i].damage << endl;
        cout << "Mana Cost: " << m.spells[i].mana_cost << endl;
    }

    cout << "\n-------------- ROGUE --------------" << endl;
    r.display_info();
    cout << "Agility: " << r.agility << endl;
    cout << "Evasion: " << r.evasion << endl;
    cout << "Poison: " << r.poison << endl;

    cout << "The battle begins!!!" << endl;

    bool mturn = false, rturn = false;

    if (m.intelligence > r.agility)
    {
        rturn = true;
        mturn = false;
    }
    else
    {
        mturn = true;
        rturn = false;
    }

    while (true)
    {
        if (mturn == false)
        {
            cout << "\n"
                 << m.name << " casts the ";
            int i = (rand() % 5);
            cout << m.spells[i].name << " !!!!" << endl;
            r.health_points -= m.spells[i].damage;
            cout << "\n-" << m.spells[i].damage << " HP" << endl;
            m.mana -= m.spells[i].mana_cost;
            mturn = true;
            rturn = false;
        }
        if (rturn == false)
        {
            cout << "\n"
                 << r.name << " uses a poison attack!";
            m.health_points -= r.poison * 0.2;
            cout << "\n-" << r.poison * 0.2 << " HP" << endl;
            r.agility -= (m.intelligence * 0.05);
            rturn = true;
            mturn = false;
        }

        if (m.mana < 5)
        {
            cout << "\n"
                 << m.name << "'s attack failed...\n";
            cout << "No more mana left!!!\n";
            cout << r.name << " defeats " << m.name << " with their agility!" << endl;
            cout << "\nGAME OVER!! " << r.name << " wins this one!!" << endl;
            break;
        }
        if (r.agility < 5)
        {
            cout << "\n"
                 << r.name << "'s attack failed...\n";
            cout << m.name << " casts a powerful spell and defeats " << r.name << "!" << endl;
            cout << "\nGAME OVER!! " << m.name << " wins this one!!" << endl;
            break;
        }
    }
}

void warrior::battleWW(warrior &w1, warrior &w2) {
    cout << "\nBattle between Warrior and Warrior" << endl;

    bool w1Turn = true; // Flag to track whose turn it is
    while (w1.health_points > 0 && w2.health_points > 0) {
        if (w1Turn) {
            // Warrior 1's turn
            cout << w1.name << " uses their stamina to attack " << w2.name << "!" << endl;
            w2.health_points -= w1.stamina * 0.2;
            cout << w2.name << " takes " << w1.stamina * 0.2 << " damage." << endl;

            // Check if w2 is defeated
            if (w2.health_points <= 0) {
                cout << w1.name << " wins!" << endl;
                break;
            }
        } else {
            // Warrior 2's turn
            cout << w2.name << " uses their armor to defend against " << w1.name << "'s attack!" << endl;
            w1.strength -= w2.armor * 0.1;

            // Check if w1's strength is reduced to 0 or below
            if (w1.strength <= 0) {
                cout << w2.name << "'s armor has weakened " << w1.name << "!" << endl;
                w1.strength = 0;
            }
        }
        
        // Toggle turn
        w1Turn = !w1Turn;
    }
}

void rogue::battleRR(rogue &r1, rogue &r2) {
    cout << "\nBattle between Rogue and Rogue" << endl;

    bool r1Turn = true; // Flag to track whose turn it is
    while (r1.health_points > 0 && r2.health_points > 0) {
        if (r1Turn) {
            // Rogue 1's turn
            cout << r1.name << " uses their poison to attack " << r2.name << "!" << endl;
            r2.health_points -= r1.poison * 0.2;
            cout << r2.name << " takes " << r1.poison * 0.2 << " damage." << endl;

            // Check if r2 is defeated
            if (r2.health_points <= 0) {
                cout << r1.name << " wins!" << endl;
                break;
            }
        } else {
            // Rogue 2's turn
            cout << r2.name << " uses their agility to evade " << r1.name << "'s attack!" << endl;
            r1.agility -= r2.evasion * 0.1;

            // Check if r1's agility is reduced to 0 or below
            if (r1.agility <= 0) {
                cout << r2.name << "'s evasion has weakened " << r1.name << "!" << endl;
                r1.agility = 0;
            }
        }
        
        // Toggle turn
        r1Turn = !r1Turn;
    }
}


void mage::battleMM(mage &m1, mage &m2)
{
    cout << "\nBattle between Mage and Mage" << endl;

    bool m1Turn = true; // Flag to track whose turn it is
    while (m1.health_points > 0 && m2.health_points > 0)
    {
        if (m1Turn)
        {
            // Mage 1's turn
            int spellIndex = rand() % 5; // Randomly choose a spell
            cout << m1.name << " casts " << m1.spells[spellIndex].name << " on " << m2.name << "!" << endl;
            m2.health_points -= m1.spells[spellIndex].damage;
            cout << m2.name << " takes " << m1.spells[spellIndex].damage << " damage." << endl;
            m1Turn = false;

            // Check if m2 is defeated
            if (m2.health_points <= 0)
            {
                cout << m1.name << " wins!" << endl;
                break;
            }
        }
        else
        {
            // Mage 2's turn
            int spellIndex = rand() % 5; // Randomly choose a spell
            cout << m2.name << " casts " << m2.spells[spellIndex].name << " on " << m1.name << "!" << endl;
            m1.health_points -= m2.spells[spellIndex].damage;
            cout << m1.name << " takes " << m2.spells[spellIndex].damage << " damage." << endl;

            // Check if m1 is defeated
            if (m1.health_points <= 0)
            {
                cout << m2.name << " wins!" << endl;
                break;
            }
        }


    }
}

int main()
{

    // Declaration of the variables
    int choice, opponent;
    string name;
    int level, strength, armor, stamina, intelligence, mana, agility, evasion, poison;

    warrior player_warrior;
    mage player_mage;
    rogue player_rogue;

    warrior enemy_warrior;
    mage enemy_mage;
    rogue enemy_rogue;

    // Display the menu to choose the character

    cout << "========== WELCOME TO THE RPG ARENA ==========" << endl;
    cout << "Choose your character:" << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Rogue" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter your character's name: ";
    cin.ignore();
    getline(cin, name);

    // Switch case to initialize the character

    switch (choice)
    {
    case 1:
        cout << "Enter level: ";
        cin >> level;
        cout << "Enter strength: ";
        cin >> strength;
        cout << "Enter armor: ";
        cin >> armor;
        cout << "Enter stamina: ";
        cin >> stamina;
        player_warrior = warrior(name, level, strength, armor, stamina);
        break;
    case 2:
        cout << "Enter level: ";
        cin >> level;
        cout << "Enter intelligence: ";
        cin >> intelligence;
        cout << "Enter mana: ";
        cin >> mana;
        player_mage = mage(name, level, intelligence, mana);
        break;
    case 3:
        cout << "Enter level: ";
        cin >> level;
        cout << "Enter agility: ";
        cin >> agility;
        cout << "Enter evasion: ";
        cin >> evasion;
        cout << "Enter poison: ";
        cin >> poison;
        player_rogue = rogue(name, level, agility, evasion, poison);
        break;
    default:
        cout << "Invalid choice! Exiting..." << endl;
        return 0;
    }

    cout << "\nChoose your opponent:" << endl; // Display the menu to choose the opponent
    cout << "1. Warrior" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Rogue" << endl;
    cout << "Enter your choice: ";
    cin >> opponent;

    switch (opponent) // Switch case to initialize the opponent's attributes based on user input
    {
    case 1:
        enemy_warrior = warrior("Brutal Warrior", 120, 60, 80, 90);
        if (choice == 1)
        {
            player_warrior.battleWW(player_warrior, enemy_warrior);
        }
        else if (choice == 2)
        {
            battleWM(enemy_warrior, player_mage);
        }
        else if (choice == 3)
        {
            battleWR(enemy_warrior, player_rogue);
        }
        break;
    case 2:
        enemy_mage = mage("Mystical Mage", 90, 30, 40);
        if (choice == 1)
        {
            battleWM(player_warrior, enemy_mage);
        }
        else if (choice == 2)
        {
            player_mage.battleMM(player_mage, enemy_mage);
        }
        else if (choice == 3)
        {
            battleMR(enemy_mage, player_rogue);
        }
        break;
    case 3:
        enemy_rogue = rogue("Sly Rogue", 90, 40, 60, 60);
        if (choice == 1)
        {
            battleWR(player_warrior, enemy_rogue);
        }
        else if (choice == 2)
        {
            battleMR(player_mage, enemy_rogue);
        }
        else if (choice == 3)
        {
            player_rogue.battleRR(player_rogue, enemy_rogue);
        }
        break;
    default:
        cout << "Invalid choice!" << endl;
        return 0;
    }

    return 0;
}