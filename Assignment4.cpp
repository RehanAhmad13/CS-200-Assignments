#include <iostream>
#include <limits>

using namespace std;
class character;
class move;
class player;
class Item;

string Weak_Type_setter(string a)
{
    string b;
    if (a == "Fire" || a == "fire" || a == "FIRE")
    {
        b = "Water";
    }
    else if (a == "Water" || a == "water" || a == "WATER")
    {
        b = "Lightning";
    }
    else if (a == "Lightning" || a == "lightning" || a == "LIGHTNING")
    {
        b = "Earth";
    }
    else if (a == "Earth" || a == "earth" || a == "EARTH")
    {
        b = "Fire";
    }
    return b;
}

class Move
{
    string movetype;
    string movename;
    string Use_type;

public:
    void set_movetype(string a);
    void set_movename(string b);
    void set_use_type(string c);
    string get_movetype();
    string get_movename();
    string get_use_type();
    virtual character use(character c1, character c2) = 0;

public:
    friend character;
    // friend Main_Game;
};

void Move::set_movetype(string a)
{
    movetype = a;
}

void Move::set_movename(string b)
{
    movename = b;
}

void Move::set_use_type(string c)
{
    Use_type = c;
}

string Move::get_movetype()
{
    return movetype;
}

string Move::get_movename()
{
    return movename;
}

string Move::get_use_type()
{
    return Use_type;
}

class character
{
    string name;
    string type;
    string weak_type;
    double max_health;
    double current_health;
    string status;
    double adrenaline;             // this is a functionality I am setting for myself;
    Move **moves = new Move *[10]; // since move is an abstract class we would have to make pointers
    Item **items = new Item *[5];
    double attack_booster;
    double defense_booster;
    double character_booster;

public:
    // constuctors

    character();
    character(string a, string b, string c, double d, double e, string f, double g, double h, double i, double j);

    // setters and getters

    void set_name(string a);
    void set_type(string b);
    void set_weak_type(string c);
    void set_max_health(double a);
    void set_current_health(double b);
    void set_status(string d);
    void set_adrenaline(double c);
    void set_attack_booster(double d);
    void set_defense_booster(double e);
    void set_character_booster(double f);

    string get_name();
    string get_type();
    string get_weak_type();
    double get_max_health();
    double get_current_health();
    string get_status();
    double get_adrenaline();
    double get_attack_booster();
    double get_defense_booster();
    double get_character_booster();

    character move(int index, character c1, character c2);
    character item(int index, character c1, character c2);

    friend class move;
    friend class Main_Game;
    friend class Item;
};

class fire_ball : public Move
{
public:
    character use(character c1, character c2);
};

character fire_ball::use(character c1, character c2)
{
    set_movetype("fire");
    set_movename("FireBall");
    set_use_type("Infinite"); // for now I will set all of them to infinite and later I will tweak
    double health = c1.get_current_health();
    cout << endl;
    cout << "Character " << c2.get_name() << " attacks with " << get_movename() << endl;

    if (c1.get_weak_type() == "earth" || c1.get_weak_type() == "Earth" || c1.get_weak_type() == "EARTH")
    {
        double damage = (25 * 1.5 * c2.get_attack_booster() * c2.get_character_booster()) / c1.get_defense_booster();
        health = health - damage;
        c1.set_current_health(health);

        cout << "The attack lands on " << c1.get_name() << endl;
        cout << "Character " << c2.get_name() << " deal a Total of " << damage << " damage" << endl;
        cout << "Your Opponent " << c1.get_name() << " now has health of " << c1.get_current_health() << endl;
        cout << "Your stamina is drained by " << 25 << endl;
    }
    else
    {
        double damage = (25 * c2.get_attack_booster() * c2.get_character_booster()) / c1.get_defense_booster();
        health = health - damage;
        c1.set_current_health(health);

        cout << "The attack lands on " << c1.get_name() << endl;
        cout << "Character " << c2.get_name() << " deal a Total of " << damage << " damage" << endl;
        cout << "Your Opponent " << c1.get_name() << " now has health of " << c1.get_current_health() << endl;
        cout << "Character " << c2.get_name() << " stamina is drained by " << 25 << endl;
    }
    cout << endl;

    double adrenaline = c2.get_adrenaline();
    adrenaline = adrenaline - 25;
    c2.set_adrenaline(adrenaline);

    return c1;
}

class Blizzard : public Move
{
public:
    character use(character c1, character c2);
};

character Blizzard::use(character c1, character c2)
{
    set_movetype("fire");
    set_movename("Blizzard");
    set_use_type("Infinite"); // for now I will set all of them to infinite and later I will tweak
    double health = c1.get_current_health();

    cout << endl;
    cout << "Character " << c2.get_name() << " attacks with " << get_movename() << endl;

    if (c1.get_weak_type() == "earth" || c1.get_weak_type() == "Earth" || c1.get_weak_type() == "EARTH")
    {
        double damage = (10 * 1.5 * c2.get_attack_booster() * c2.get_character_booster()) / c1.get_defense_booster();

        health = health - damage;
        c1.set_current_health(health);

        cout << "The attack lands on " << c1.get_name() << endl;
        cout << "Character " << c2.get_name() << " deal a Total of " << damage << " damage" << endl;
        cout << "Your Opponent " << c1.get_name() << " now has health of " << c1.get_current_health() << endl;
        cout << "Your stamina is drained by " << 15 << endl;
    }
    else
    {
        double damage = (10 * c2.get_attack_booster() * c2.get_character_booster()) / c1.get_defense_booster();
        health = health - damage;
        c1.set_current_health(health);

        cout << "The attack lands on " << c1.get_name() << endl;
        cout << "Character " << c2.get_name() << " deal a Total of " << damage << " damage" << endl;
        cout << "Your Opponent " << c1.get_name() << " now has health of " << c1.get_current_health() << endl;
        cout << "Your stamina is drained by " << 15 << endl;
    }

    double adrenaline = c2.get_adrenaline();
    adrenaline = adrenaline - 25;
    c2.set_adrenaline(adrenaline);
    return c1;
}

class IcyTentacles : public Move
{
public:
    character use(character c1, character c2);
};

character IcyTentacles::use(character c1, character c2)
{
    set_movetype("Water");
    set_movename("IcyTentacles");
    set_use_type("Infinite"); // for now I will set all of them to infinite and later I will tweak
    double health = c1.get_current_health();

    cout << endl;
    cout << "Character " << c2.get_name() << " attacks with " << get_movename() << endl;

    if (c1.get_weak_type() == "fire" || c1.get_weak_type() == "FIRE" || c1.get_weak_type() == "Fire")
    {
        double damage = (25 * 1.5 * c2.get_attack_booster() * c2.get_character_booster()) / c1.get_defense_booster();
        health = health - damage;
        c1.set_current_health(health);

        cout << "The attack lands on " << c1.get_name() << endl;
        cout << "Character " << c2.get_name() << " deal a Total of " << damage << " damage" << endl;
        cout << "Your Opponent " << c1.get_name() << " now has health of " << c1.get_current_health() << endl;
        cout << "Your stamina is drained by " << 25 << endl;
    }
    else
    {
        double damage = (25 * c2.get_attack_booster() * c2.get_character_booster()) / c1.get_defense_booster();
        health = health - damage;
        c1.set_current_health(health);

        cout << "The attack lands on " << c1.get_name() << endl;
        cout << "Character " << c2.get_name() << " deal a Total of " << damage << " damage" << endl;
        cout << "Your Opponent " << c1.get_name() << " now has health of " << c1.get_current_health() << endl;
        cout << "Your stamina is drained by " << 25 << endl;
    }
    double adrenaline = c2.get_adrenaline();
    adrenaline = adrenaline - 25;
    c2.set_adrenaline(adrenaline);
    return c1;
}

class IcyFreeze : public Move
{
public:
    character use(character c1, character c2);
};

character IcyFreeze::use(character c1, character c2)
{
    set_movetype("Water");
    set_movename("IcyFreeze");
    set_use_type("Infinite"); // for now I will set all of them to infinite and later I will tweak
    double health = c1.get_current_health();

    cout << endl;
    cout << "Character " << c2.get_name() << " attacks with " << get_movename() << endl;

    if (c1.get_weak_type() == "fire" || c1.get_weak_type() == "FIRE" || c1.get_weak_type() == "Fire")
    {
        double damage = (10 * 1.5 * c2.get_attack_booster() * c2.get_character_booster()) / c1.get_defense_booster();
        health = health - damage;
        c1.set_current_health(health);

        cout << "The attack lands on " << c1.get_name() << endl;
        cout << "Character " << c2.get_name() << " deal a Total of " << damage << " damage" << endl;
        cout << "Your Opponent " << c1.get_name() << " now has health of " << c1.get_current_health() << endl;
        cout << "Your stamina is drained by " << 15 << endl;
    }
    else
    {
        double damage = (10 * c2.get_attack_booster() * c2.get_character_booster()) / c1.get_defense_booster();
        health = health - damage;
        c1.set_current_health(health);
        double adrenaline = 15;

        cout << "The attack lands on " << c1.get_name() << endl;
        cout << "Character " << c2.get_name() << " deal a Total of " << damage << " damage" << endl;
        cout << "Your Opponent " << c1.get_name() << " now has health of " << c1.get_current_health() << endl;
        cout << "Your stamina is drained by " << 15 << endl;
    }
    double adrenaline = c2.get_adrenaline();
    adrenaline = adrenaline - 25;
    c2.set_adrenaline(adrenaline);
    return c1;
}

class Earthquake : public Move
{
public:
    character use(character c1, character c2);
};

character Earthquake::use(character c1, character c2)
{
    set_movetype("Earth");
    set_movename("Earthquake");
    set_use_type("Infinite"); // for now I will set all of them to infinite and later I will tweak
    double health = c1.get_current_health();

    cout << endl;
    cout << "Character " << c2.get_name() << " attacks with " << get_movename() << endl;
    if (c1.get_weak_type() == "lightning" || c1.get_weak_type() == "Lightning" || c1.get_weak_type() == "LIGHTNING")
    {
        double damage = (25 * 1.5 * c2.get_attack_booster() * c2.get_character_booster()) / c1.get_defense_booster();
        health = health - damage;
        c1.set_current_health(health);

        cout << "The attack lands on " << c1.get_name() << endl;
        cout << "Character " << c2.get_name() << " deal a Total of " << damage << " damage" << endl;
        cout << "Your Opponent " << c1.get_name() << " now has health of " << c1.get_current_health() << endl;
        cout << "Your stamina is drained by " << 25 << endl;
    }
    else
    {
        double damage = (25 * c2.get_attack_booster() * c2.get_character_booster()) / c1.get_defense_booster();
        health = health - damage;
        c1.set_current_health(health);
        cout << "The attack lands on " << c1.get_name() << endl;
        cout << "Character " << c2.get_name() << " deal a Total of " << damage << " damage" << endl;
        cout << "Your Opponent " << c1.get_name() << " now has health of " << c1.get_current_health() << endl;
        cout << "Your stamina is drained by " << 25 << endl;
    }

    double adrenaline = c2.get_adrenaline();
    adrenaline = adrenaline - 25;
    c2.set_adrenaline(adrenaline);

    return c1;
}

class Earthwall : public Move
{
public:
    character use(character c1, character c2);
};

character Earthwall::use(character c1, character c2)
{
    set_movetype("Earth");
    set_movename("Earthwall");
    set_use_type("Infinite"); // for now I will set all of them to infinite and later I will tweak
    double health = c1.get_current_health();

    cout << endl;
    cout << "Character " << c2.get_name() << " attacks with " << get_movename() << endl;
    if (c1.get_weak_type() == "lightning" || c1.get_weak_type() == "Lightning" || c1.get_weak_type() == "LIGHTNING")
    {
        double damage = (10 * 1.5 * c2.get_attack_booster() * c2.get_character_booster()) / c1.get_defense_booster();
        health = health - damage;
        c1.set_current_health(health);

        cout << "The attack lands on " << c1.get_name() << endl;
        cout << "Character " << c2.get_name() << " deal a Total of " << damage << " damage" << endl;
        cout << "Your Opponent " << c1.get_name() << " now has health of " << c1.get_current_health() << endl;
        cout << "Your stamina is drained by " << 15 << endl;
    }
    else
    {
        double damage = (10 * c2.get_attack_booster() * c2.get_character_booster()) / c1.get_defense_booster();
        health = health - damage;
        c1.set_current_health(health);

        cout << "The attack lands on " << c1.get_name() << endl;
        cout << "Character " << c2.get_name() << " deal a Total of " << damage << " damage" << endl;
        cout << "Your Opponent " << c1.get_name() << " now has health of " << c1.get_current_health() << endl;
        cout << "Your stamina is drained by " << 15 << endl;
    }

    double adrenaline = c2.get_adrenaline();
    adrenaline = adrenaline - 25;
    c2.set_adrenaline(adrenaline);

    return c1;
}

class LightningMagma : public Move
{
public:
    character use(character c1, character c2);
};

character LightningMagma::use(character c1, character c2)
{
    set_movetype("Lighning");
    set_movename("LightningMagma");
    set_use_type("Infinite"); // for now I will set all of them to infinite and later I will tweak
    double health = c1.get_current_health();

    cout << endl;
    cout << "Character " << c2.get_name() << " attacks with " << get_movename() << endl;
    if (c1.get_weak_type() == "water" || c1.get_weak_type() == "Water" || c1.get_weak_type() == "WATER")
    {
        double damage = (25 * 1.5 * c2.get_attack_booster() * c2.get_character_booster()) / c1.get_defense_booster();
        health = health - damage;
        c1.set_current_health(health);

        cout << "The attack lands on " << c1.get_name() << endl;
        cout << "Character " << c2.get_name() << " deal a Total of " << damage << " damage" << endl;
        cout << "Your Opponent " << c1.get_name() << " now has health of " << c1.get_current_health() << endl;
        cout << "Your stamina is drained by " << 25 << endl;
    }
    else
    {
        double damage = (25 * c2.get_attack_booster() * c2.get_character_booster()) / c1.get_defense_booster();
        health = health - damage;
        c1.set_current_health(health);

        cout << "The attack lands on " << c1.get_name() << endl;
        cout << "Character " << c2.get_name() << " deal a Total of " << damage << " damage" << endl;
        cout << "Your Opponent " << c1.get_name() << " now has health of " << c1.get_current_health() << endl;
        cout << "Your stamina is drained by " << 25 << endl;
    }

    double adrenaline = c2.get_adrenaline();
    adrenaline = adrenaline - 25;
    c2.set_adrenaline(adrenaline);

    return c1;
}

class LightningPincer : public Move
{
public:
    character use(character c1, character c2);
};

character LightningPincer::use(character c1, character c2)
{
    set_movetype("Lighning");
    set_movename("LightningPincer");
    set_use_type("Infinite"); // for now I will set all of them to infinite and later I will tweak
    double health = c1.get_current_health();

    cout << endl;
    cout << "Character " << c2.get_name() << " attacks with " << get_movename() << endl;
    if (c1.get_weak_type() == "water" || c1.get_weak_type() == "Water" || c1.get_weak_type() == "WATER")
    {
        double damage = (10 * 1.5 * c2.get_attack_booster() * c2.get_character_booster()) / c1.get_defense_booster();
        health = health - damage;
        c1.set_current_health(health);

        cout << "The attack lands on " << c1.get_name() << endl;
        cout << "Character " << c2.get_name() << " deal a Total of " << damage << " damage" << endl;
        cout << "Your Opponent " << c1.get_name() << " now has health of " << c1.get_current_health() << endl;
        cout << "Your stamina is drained by " << 15 << endl;
    }
    else
    {
        double damage = (10 * c2.get_attack_booster() * c2.get_character_booster()) / c1.get_defense_booster();
        health = health - damage;
        c1.set_current_health(health);

        cout << "The attack lands on " << c1.get_name() << endl;
        cout << "Character " << c2.get_name() << " deal a Total of " << damage << " damage" << endl;
        cout << "Your Opponent " << c1.get_name() << " now has health of " << c1.get_current_health() << endl;
        cout << "Your stamina is drained by " << 15 << endl;
    }

    return c1;
}

class Item
{
    string itemtype;

public:
    void set_itemtype(string a);
    string get_itemtype();
    virtual character use(character c1, character c2) = 0;

public:
    friend character;
    // friend Main_Game;
};

void Item::set_itemtype(string a)
{
    itemtype = a;
}

string Item::get_itemtype()
{
    return itemtype;
}

class Attack_Boost : public Item
{
public:
    character use(character c1, character c2);
};

character Attack_Boost::use(character c1, character c2)
{
    set_itemtype("AttackBoost");
    c1.set_attack_booster(1.2);
    cout << "Player " << c1.get_name() << ": Your Attack stats have been bosted by 1.2!" << endl;
    return c1;
}

class Defense_Boost : public Item
{
public:
    character use(character c1, character c2);
};

character Defense_Boost::use(character c1, character c2)
{
    set_itemtype("DefenseBoost");
    c1.set_defense_booster(1.2);
    cout << "Player " << c1.get_name() << " Your Defense states have been boosted by 1.2!" << endl;
    return c1;
}

class Heal : public Item
{
public:
    character use(character c1, character c2);
};

character Heal::use(character c1, character c2)
{
    set_itemtype("Heal");
    double health = c1.get_current_health();
    health = health - 20;
    c1.set_current_health(health);
    cout << "Player " << c1.get_name() << ": You have been healed by 20 Lifepoints!" << endl;
    return c1;
}

class CharacterType_Boost : public Item
{
public:
    character use(character c1, character c2);
};

character CharacterType_Boost::use(character c1, character c2)
{
    set_itemtype("CharacterType_Boost");
    string type = c1.get_type();
    string weak_type = Weak_Type_setter(type);
    if (weak_type == c2.get_type())
    {
        cout << "Player " << c1.get_name() << " : A permenant boost has been applied to you!" << endl;
        c1.set_attack_booster(1.1);
    }
    else
    {
        cout << "The Opponent is Not Suceptible! " << endl;
    }

    return c1;
}

character::character()
{
    name = "";
    type = "";
    weak_type = "";
    max_health = 100;
    current_health = 100;
    status = "alive";
    adrenaline = 100;
    attack_booster = 1;
    defense_booster = 1;
    character_booster = 1;

    // Move** moves = new Move*[10]; // note that intializing this to 7 is a bad idea (took 1 hour of my life)
    moves[0] = new fire_ball();
    moves[1] = new Blizzard();
    moves[2] = new IcyTentacles();
    moves[3] = new IcyFreeze();
    moves[4] = new Earthquake();
    moves[5] = new Earthwall();
    moves[6] = new LightningMagma();
    moves[7] = new LightningPincer();

    items[0] = new Attack_Boost();
    items[1] = new Defense_Boost();
    items[2] = new Heal();
    items[3] = new CharacterType_Boost();
}

character::character(string a, string b, string c, double d, double e, string f, double g, double h, double i, double j)
{
    name = a;
    type = b;
    weak_type = c;
    max_health = d;
    current_health = e;
    status = f;
    adrenaline = g;
    attack_booster = h;
    defense_booster = i;
    character_booster = j;

    // Move** moves = new Move*[10];
    moves[0] = new fire_ball();
    moves[1] = new Blizzard();
    moves[2] = new IcyTentacles();
    moves[3] = new IcyFreeze();
    moves[4] = new Earthquake();
    moves[5] = new Earthwall();
    moves[6] = new LightningMagma();
    moves[7] = new LightningPincer();

    items[0] = new Attack_Boost();
    items[1] = new Defense_Boost();
    items[2] = new Heal();
    items[3] = new CharacterType_Boost();
}

void character::set_character_booster(double f)
{
    character_booster = f;
}

void character::set_name(string a)
{
    name = a;
}
void character::set_type(string b)
{
    type = b;
}

void character::set_weak_type(string c)
{
    weak_type = c;
}

void character::set_max_health(double a)
{
    max_health = a;
}
void character::set_current_health(double b)
{
    current_health = b;
}

void character::set_status(string d)
{
    status = d;
}
void character::set_adrenaline(double c)
{
    adrenaline = c;
}
void character::set_attack_booster(double d)
{
    attack_booster = d;
}
void character::set_defense_booster(double e)
{
    defense_booster = e;
}

string character::get_name()
{
    return name;
}
string character::get_type()
{
    return type;
}

string character::get_weak_type()
{
    return weak_type;
}
double character::get_max_health()
{
    return max_health;
}
double character::get_current_health()
{
    return current_health;
}
string character::get_status()
{
    return status;
}

double character::get_adrenaline()
{
    return adrenaline;
}
double character::get_attack_booster()
{
    return attack_booster;
}
double character::get_defense_booster()
{
    return defense_booster;
}

double character::get_character_booster()
{
    return character_booster;
}

character character::move(int index, character c1, character c2)
{
    character c3;
    c3 = moves[index]->use(c1, c2);
    return c3;
}

character character::item(int index, character c1, character c2)
{
    character c3;
    c3 = items[index]->use(c1, c2);
    return c3;
}

class Main_Game
{
    character arr[6]; // To store characters. It is not really needed in my functionality.
    int game_mode;    // Specifies the game type. If it is 1 vs 1, game_mode = 2. if it is 3 vs 3, game_mode = 6

public:
    // constructors and deconstructors
    Main_Game();
    Main_Game(int size);
    // setters and getters
    void set_character(character c1, int index);
    void set_game_mode(int n);
    int get_game_mode();
    character get_character(int n);

    // Functionalities
    string Weak_Type_setter(string a);           // automatically sets the weak type for a character
    int Main_Game_choice();                      // asks the user if they want to player 1 vs 1 Main_Game or 3 vs 3 Main_Game
    void character_specification(int game_mode); // note that n specifies the game type. If it is 1 vs 1, n = 2, if it is 3 vs 3, n = 6
    void Main_Game_screen();                     // where the main Main_Game is played
    void turn1();                                // turning functionality for 1 vs 1 Main_Game
    void switch_character1();                    // specifies the switch option for 1 vs 1 Main_Game
    void use_item1();                            // specifies the use item option for 1 vs 1 Main_Game
    void use_attack1();                          // specifies the attack option for 1 vs 1 Main_Game

    void switch_character2(); // specifies the switch option for 3 vs 3 Main_Game
    void use_item2();         // specifies the use item option for 3 vs 3 Main_Game
    void use_attack2();       // specifies the attack option for 3 vs 3 Main_Game
    int list_of_moves();      // shows the list of moves
    int list_of_items();      // shows the list of items

    friend character;
};

// Default and Parametrized Constructors

Main_Game::Main_Game()
{
    for (int i = 0; i < 6; i++) // initializing it to six because that is the maximum characters you need for both modes.
    {
        character l;
        arr[i] = l;
    }
}

Main_Game::Main_Game(int size)
{
    for (int i = 0; i < size; i++)
    {
        character l;
        arr[i] = l;
    }
}

// Setters and Getters

void Main_Game::set_character(character c1, int index)
{
    arr[index] = c1;
}

character Main_Game::get_character(int n)
{
    character c1 = arr[n];
    return c1;
}

void Main_Game::set_game_mode(int n)
{
    game_mode = n;
}

int Main_Game::get_game_mode()
{
    return game_mode;
}

string Main_Game::Weak_Type_setter(string a)
{
    string b;
    if (a == "Fire" || a == "fire" || a == "FIRE")
    {
        b = "Water";
    }
    else if (a == "Water" || a == "water" || a == "WATER")
    {
        b = "Lightning";
    }
    else if (a == "Lightning" || a == "lightning" || a == "LIGHTNING")
    {
        b = "Earth";
    }
    else if (a == "Earth" || a == "earth" || a == "EARTH")
    {
        b = "Fire";
    }
    return b;
}

int Main_Game::Main_Game_choice()
{
    cout << "Choose the Mode of the Game:" << endl;
    cout << "1) One vs One Mode" << endl;
    cout << "2) Three vs Three Mode" << endl;
    cout << "3) Exit" << endl;
    int choice;
    cin >> choice;
    return choice;
}

void Main_Game::character_specification(int game_mode)
{
    if (game_mode == 2)
    {
        cout << "You have chosen to Play One vs One Mode" << endl;
    }
    else if (game_mode == 6)
    {
        cout << "You have chosen to Play Three vs Three mode" << endl;
    }

    for (int i = 0; i < game_mode / 2; i++)
    {
        string name;
        cout << "Player 1: Please Specify the name of Character " << i + 1 << endl;
        cin >> name;
        arr[i].name = name;
        string type;
        cout << "Player 1: Please Specify the type of the Character " << i + 1 << endl;
        cin >> type;
        arr[i].type = type;
        string weak_type = Weak_Type_setter(type);
        arr[i].weak_type = weak_type;
        arr[i].adrenaline = 100;
        arr[i].max_health = 100;
        arr[i].status = "alive";
        arr[i].current_health = 100;
    }

    for (int i = game_mode / 2; i < game_mode; i++)
    {
        string name;
        cout << "Player 2: Please Specify the name of Character " << i + 1 << endl;
        cin >> name;
        arr[i].name = name;
        string type;
        cout << "Player 2: Please Specify the type of the Character " << i + 1 << endl;
        cin >> type;
        arr[i].type = type;
        string weak_type = Weak_Type_setter(type);
        arr[i].weak_type = weak_type;
        arr[i].adrenaline = 100;
        arr[i].max_health = 100;
        arr[i].status = "alive";
        arr[i].current_health = 100;
    }
}

void Main_Game::Main_Game_screen()
{
    cout << "Welcome to the Main_Game Screen" << endl;
    cout << "1) Attack" << endl;
    cout << "2) Switch Character" << endl;
    cout << "3) Use Item" << endl;
    //     int choice;
    //     cin >> choice;
    //     return choice;
    //
}

void Main_Game::switch_character1()
{
    cout << endl;
    cout << "There is only one character in 1 vs 1 mode" << endl;
    cout << endl;
}

int Main_Game::list_of_moves()
{
    cout << endl;
    cout << "ATTACK LIST" << endl;
    cout << "1) Fire-Ball -> Adrenaline: 25, Damage 25 " << endl;
    cout << "2) Blizzard -> Adrenaline: 15, Damage 10" << endl;
    cout << "3) Icy Tentacles -> Adrenaline 25, Damage 25" << endl;
    cout << "4) Ice Freeze -> Adrenaline 15, Damage 10" << endl;
    cout << "5) Earthquake -> Adrenaline 25, Damage 25" << endl;
    cout << "6) Earth Wall -> Adrenaline 15, Damage 10" << endl;
    cout << "7) Lightning Magma: Adrenaline 25, Damage 25" << endl;
    cout << "8) Lightning Pincer: Adrenaline 15, Damage 10" << endl;
    int choice;
    cin >> choice;
    return choice;
    cout << endl;
}

int Main_Game::list_of_items()
{
    cout << endl;
    cout << "ITEM LIST" << endl;
    cout << "1) Attack Boost --> Boosts Attack by 1.2 " << endl;
    cout << "2) Defense Boost --> Bosts Defense by 1.2 " << endl;
    cout << "3) Heal --> Heals the Player by 1.2" << endl;
    cout << "4) Character Boost --> A permenant Boost of 1.1 if Opponent is of Suceptible Element Type" << endl;
    int choice;
    cin >> choice;
    return choice;
    cout << endl;
}

class Player
{
    string playername;

    character arr1[10];
    Item **arr2 = new Item *[5];
    int active_character_counter;
    int total_character;

public:
    Player();
    Player(int n);

    // setters and getters
    void set_playername(string s);
    string get_playername();
    void set_activecharacter_counter(int n);
    int get_activecharacter_counter();
    void set_ActiveCharacter(character c1);
    character get_ActiveCharacter(int active_character_counter);
    string inp_validation(string inp);

    int status_setter(int active_character_counter);
    int swap_character();
    character useItem(int index, character c1, character c2);
    bool player_life(); // to check if all characters are alive or dead
    void player_list(); // to print all the characters a player has

    friend class move;
    friend class Main_Game;
    friend class Item;
    friend character;
};

Player::Player()
{
    // by default, Player() class makes player for 1 vs 1 game
    int game_mode = 2;
    for (int i = 0; i < game_mode / 2; i++)
    {
        string name;
        cout << "Please Specify the name of Character " << i + 1 << endl;
        cin >> name;
        arr1[i].set_name(name);
        string type;
        cout << "Please Specify the type of the Character " << i + 1 << endl;
        cin >> type;
        type = inp_validation(type);

        arr1[i].set_type(type);
        string weak_type = Weak_Type_setter(type);
        arr1[i].set_weak_type(weak_type);
        arr1[i].set_adrenaline(100);
        arr1[i].set_max_health(100);
        arr1[i].set_status("alive");
        arr1[i].set_current_health(100);
    }
    total_character = 1;
}

Player::Player(int game_mode)
{

    for (int i = 0; i < game_mode / 2; i++)
    {
        string name;
        cout << "Please Specify the name of Character " << i + 1 << endl;
        cin >> name;
        arr1[i].set_name(name);
        string type;
        cout << "Please Specify the type of the Character " << i + 1 << endl;
        cin >> type;
        type = inp_validation(type);
        arr1[i].set_type(type);
        string weak_type = Weak_Type_setter(type);
        arr1[i].set_weak_type(weak_type);
        arr1[i].set_adrenaline(100);
        arr1[i].set_max_health(100);
        arr1[i].set_status("alive");
        arr1[i].set_current_health(100);
    }
    total_character = 3;
}

void Player::set_playername(string s)
{
    playername = s;
}

string Player::get_playername()
{
    return playername;
}

void Player::set_activecharacter_counter(int n)
{
    active_character_counter = n;
}
int Player::get_activecharacter_counter()
{
    return active_character_counter;
}

void Player::set_ActiveCharacter(character c1)
{
    arr1[active_character_counter] = c1;
}

character Player::get_ActiveCharacter(int active_character_counter)
{
    return arr1[active_character_counter];
}

character Player::useItem(int index, character c1, character c2)
{
    character c3;
    c3 = arr2[index]->use(c1, c2);
    return c3;
}

int Player::status_setter(int active_character_counter)
{
    if (active_character_counter == 0)
    {
        if (arr1[0].get_current_health() < 2)
        {
            arr1[0].set_name("Not Available");
            arr1[0].set_status("dead");

            active_character_counter++;
        }
    }
    else if (active_character_counter == 1)
    {
        if (arr1[1].get_current_health() < 2)
        {

            arr1[1].set_name("Not Available");
            arr1[1].set_status("dead");
            active_character_counter++;
        }
    }
    else if (active_character_counter == 2)
    {
        if (arr1[2].get_current_health() < 2)
        {

            arr1[2].set_name("Not Available");
            arr1[2].set_status("dead");
            active_character_counter = 0;
        }
    }

    return active_character_counter;
}

int Player::swap_character()
{
    cout << "You have chosen to swap characters" << endl;
    character c1;

    cout << "Player " << playername << " make your choice" << endl;
    cout << "1) " << arr1[0].get_name() << endl;
    cout << "2) " << arr1[1].get_name() << endl;
    cout << "3) " << arr1[2].get_name() << endl;
    int choice;
    cin >> choice;
    if (choice == 1 && arr1[0].get_status() == "alive")
    {
        cout << "The active player is now " << arr1[0].get_name() << endl;
        active_character_counter = 0;
    }
    else if (arr1[0].get_status() == "dead")
    {
        cout << "This Character has died and is no longer available!" << endl;
    }

    if (choice == 2 && arr1[1].get_status() == "alive")
    {
        cout << "The active player is now " << arr1[1].get_name() << endl;
        active_character_counter = 1;
    }
    else if (arr1[1].get_status() == "dead")
    {
        cout << "This Character has died and is no longer available!" << endl;
    }

    if (choice == 3 && arr1[2].get_status() == "alive")
    {
        cout << "The active player is now " << arr1[2].get_name() << endl;
        active_character_counter = 2;
    }
    else if (arr1[2].get_status() == "dead")
    {
        cout << "This character has died and is no longer available! " << endl;
    }

    return active_character_counter;
}

bool Player::player_life()
{

    bool check = true;

    if ((arr1[0].get_status() == "alive") && (arr1[1].get_status() == "alive") && (arr1[2].get_status() == "alive"))
    {
        check = true;
    }
    else if ((arr1[0].get_status() == "dead") && (arr1[1].get_status() == "dead") && (arr1[2].get_status() == "dead"))
    {
        check = false;
    }
    return check;
}

void Player::player_list()
{
    for (int i = 0; i < total_character; i++)
    {
        cout << "The name of the Character is " << arr1[i].get_name() << endl;
        cout << "The Status of the Character is " << arr1[i].get_status() << endl;
    }
}

string Player::inp_validation(string inp)
{
    while (1)
    {
        if ((inp != "fire") && (inp != "FIRE") && (inp != "Fire") && (inp != "water") && (inp != "WATER") && (inp != "Water") && (inp != "Lightning") && (inp != "LIGHTNING") && (inp != "lightning") && (inp != "earth") && (inp != "EARTH") && (inp != "Earth"))
        {
            cout << "Please enter a valid elemental type" << endl;
            cin >> inp;
            inp = inp_validation(inp);
        }
        break;
    }
    return inp;
}

int main()
{
    Main_Game instance;

    bool check = true;

    while (check == true)
    {
        int choice = instance.Main_Game_choice();

        if (choice == 1)
        {
            int turn_counter = 1;
            cout << "You have Chosen to Play One vs One Mode" << endl;
            // instance.character_specification(2);

            cout << "Player 1: Please Make your Choices" << endl;
            Player p1(2);
            cout << endl;
            cout << "Player 2: Please Make your Choices" << endl;
            Player p2(2);

            character c1 = p1.get_ActiveCharacter(0);
            character c2 = p2.get_ActiveCharacter(0);

            while (c1.get_current_health() >= 1 || c2.get_current_health() >= 1)
            {
                if (turn_counter == 1)
                {
                    cout << "Player 1 make your choice" << endl;
                }
                else if (turn_counter == 2)
                {
                    cout << "Player 2 make your choice" << endl;
                }
                int choice1;
                instance.Main_Game_screen();
                cin >> choice1;

                if (turn_counter == 1)
                {
                    if (choice1 == 1)
                    {
                        int choice2 = instance.list_of_moves();
                        for (int i = 1; i < 9; i++)
                        {
                            if (choice2 == i)
                            {
                                c2 = c1.move(i - 1, c2, c1);
                                turn_counter++;
                            }
                        }

                        if (c2.get_current_health() < 1)
                        {
                            cout << "Player " << c1.get_name() << " Wins!" << endl;
                            break;
                        }
                    }
                    else if (choice1 == 2)
                    {
                        instance.switch_character1();
                    }
                    else if (choice1 == 3)
                    {
                        int choice2 = instance.list_of_items();
                        for (int i = 1; i < 4; i++)
                        {
                            if (choice2 == i)
                            {
                                c1 = c1.item(i - 1, c1, c2);
                                turn_counter++;
                            }
                        }
                        if (choice2 == 4)
                        {
                            c1 = c1.item(3, c1, c2);
                            if (c1.get_character_booster() == 1.1)
                            {
                                cout << "The boost has already been applied!" << endl;
                            }
                            else
                            {
                                turn_counter++;
                            }
                        }
                    }
                }
                else if (turn_counter == 2)
                {

                    if (choice1 == 1)
                    {
                        int choice2 = instance.list_of_moves();

                        for (int i = 1; i < 9; i++)
                        {
                            if (choice2 == i)
                            {
                                c1 = c2.move(i - 1, c1, c2);
                                turn_counter--;
                            }
                        }

                        if (c1.get_current_health() < 1)
                        {
                            cout << "Player " << c2.get_name() << " Wins!" << endl;
                            break;
                        }
                    }
                    else if (choice1 == 2)
                    {
                        instance.switch_character1();
                    }
                    else if (choice1 == 3)
                    {
                        int choice2 = instance.list_of_items();
                        for (int i = 1; i < 4; i++)
                        {
                            if (choice2 == i)
                            {
                                c2 = c2.item(i - 1, c2, c1);
                                turn_counter--;
                            }
                        }
                        if (choice2 == 4)
                        {
                            c2 = c2.item(3, c2, c1);
                            if (c2.get_character_booster() == 1.1)
                            {
                                cout << "";
                            }
                            else
                            {
                                turn_counter--;
                            }
                        }
                    }
                }
            }
        }
        else if (choice == 2)
        {
            cout << "You have Chosen to Play Three vs Three Mode" << endl;

            // instance.character_specification(6);
            int turn_counter = 1;

            cout << "Player 1: Please Decide your name" << endl;
            string name;
            cin >> name;

            cout << "Player 1: Please Make your Choices" << endl;
            Player p1(6);
            cout << endl;
            p1.set_playername(name);

            cout << "Player 2: Please Decide your name" << endl;
            string name1;
            cin >> name1;

            cout << "Player 2: Please Make your Choices" << endl;
            Player p2(6);
            cout << endl;
            p2.set_playername(name1);

            int active_character_counter1 = 0;
            int active_character_counter2 = 0;
            p1.set_activecharacter_counter(0);
            p2.set_activecharacter_counter(0);
            character c1 = p1.get_ActiveCharacter(0);
            character c2 = p2.get_ActiveCharacter(0);

            cout << "The default active character for Player 1 is " << c1.get_name() << endl;
            cout << "The default active character for Player 2 is " << c2.get_name() << endl;
            cout << endl;

            bool check1 = p1.player_life();
            bool check2 = p2.player_life();

            while (check1 == true || check2 == true)
            {
                check1 = p1.player_life();
                check2 = p2.player_life();
                if (turn_counter == 1)
                {
                    cout << "Player " << p1.get_playername() << " make your choice" << endl;
                }
                else if (turn_counter == 2)
                {
                    cout << "Player " << p2.get_playername() << " make your choice" << endl;
                }
                int choice1;
                instance.Main_Game_screen();
                cin >> choice1;

                if (turn_counter == 1)
                {
                    if (choice1 == 1)
                    {
                        int choice2 = instance.list_of_moves();
                        for (int i = 1; i < 9; i++)
                        {
                            if (choice2 == i)
                            {
                                c1 = p1.get_ActiveCharacter(active_character_counter1);
                                c2 = p2.get_ActiveCharacter(active_character_counter2);
                                c2 = c1.move(i - 1, c2, c1);
                                p1.set_ActiveCharacter(c1);
                                p2.set_ActiveCharacter(c2);
                                turn_counter++;
                            }
                        }

                        active_character_counter1 = p1.status_setter(active_character_counter1); // working fine. the value of the array is being overridden
                        active_character_counter2 = p2.status_setter(active_character_counter2);
                        p1.set_activecharacter_counter(active_character_counter1); // you have no idea how important this was...
                        p2.set_activecharacter_counter(active_character_counter2);
                       

                        if (check2 == false)
                        {
                            cout << "Player 1: " << p1.get_playername() << " Wins!" << endl;
                            break;
                        }
                    }
                    else if (choice1 == 2)
                    {
                        active_character_counter1 = p1.swap_character();
                    }
                    else if (choice1 == 3)
                    {
                        int choice2 = instance.list_of_items();
                        c1 = p1.get_ActiveCharacter(active_character_counter1);
                        c2 = p2.get_ActiveCharacter(active_character_counter2);

                        for (int i = 1; i < 4; i++)
                        {
                            if (choice2 == i)
                            {
                                c1 = c1.item(i - 1, c1, c2);
                                p1.set_ActiveCharacter(c1);
                                p2.set_ActiveCharacter(c2);
                                turn_counter++;
                            }
                        }
                        if (choice2 == 4)
                        {
                            c1 = c1.item(3, c1, c2);
                            p1.set_ActiveCharacter(c1);
                            p2.set_ActiveCharacter(c2);
                            if (c1.get_character_booster() == 1.1)
                            {
                                cout << "";
                            }
                            else
                            {
                                turn_counter++;
                            }
                        }
                    }
                }
                else if (turn_counter == 2)
                {

                    if (choice1 == 1)
                    {
                        int choice2 = instance.list_of_moves();

                        for (int i = 1; i < 9; i++)
                        {
                            if (choice2 == i)
                            {

                                c1 = p1.get_ActiveCharacter(active_character_counter1);
                                c2 = p2.get_ActiveCharacter(active_character_counter2);

                                c1 = c2.move(i - 1, c1, c2);

                                p1.set_ActiveCharacter(c1);
                                p2.set_ActiveCharacter(c2);

                                turn_counter--;
                                active_character_counter1 = p1.status_setter(active_character_counter1);
                                active_character_counter2 = p2.status_setter(active_character_counter2);
                                p1.set_activecharacter_counter(active_character_counter1);
                                p2.set_activecharacter_counter(active_character_counter2);
                            }
                        }

                        if (check1 == false)
                        {
                            cout << "Player 2: " << p2.get_playername() << " Wins!" << endl;

                            break;
                        }
                    }
                    else if (choice1 == 2)
                    {
                        active_character_counter2 = p2.swap_character();
                    }
                    else if (choice1 == 3)
                    {
                        int choice2 = instance.list_of_items();
                        c1 = p1.get_ActiveCharacter(active_character_counter1);
                        c2 = p2.get_ActiveCharacter(active_character_counter2);
                        for (int i = 1; i < 4; i++)
                        {
                            if (choice2 == i)
                            {
                                c2 = c2.item(i - 1, c2, c1);
                                p1.set_ActiveCharacter(c1);
                                p2.set_ActiveCharacter(c2);
                                turn_counter--;
                            }
                        }
                        if (choice2 == 4)
                        {
                            c2 = c2.item(3, c2, c1);
                            p1.set_ActiveCharacter(c1);
                            p2.set_ActiveCharacter(c2);
                            if (c1.get_character_booster() == 1.1)
                            {
                                cout << "";
                            }
                            else
                            {
                                turn_counter--;
                            }
                        }
                    }
                }
            }
        }
        else if(choice == 3)
        {
            check = false; 
        }
    }
}
